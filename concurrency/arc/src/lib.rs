use std::ops::Deref;
use std::sync::atomic::{fence, Ordering};
use std::usize;
use std::{ptr::NonNull, sync::atomic::AtomicUsize};

#[allow(dead_code)]

pub struct ArcData<T> {
    // Amount of references that exist
    ref_count: AtomicUsize,
    v: T,
}

impl<T> Drop for Arc<T> {
    fn drop(&mut self) {
        // fetch_sub returns the previous value in case there was only 1 ref_count left, there are 0 now so we can drop the data on the heap
        // Ordering::Release because we need to have a happen-before relationship with all the drop
        // operations that happened before this to make sure that there are really 0 refs left.
        if self.data().ref_count.fetch_sub(1, Ordering::Release) == 1 {
            // We create a happens before relationship only when the ref_count = 1
            // Otherwise the release above can be considered relaxed and can happen simultaneously
            // across threads.
            fence(Ordering::Acquire);
            unsafe {
                // We cannot drop a raw ptr so we make a box which becomes the owner.
                // We can now drop the box, freeing the heap.
                drop(Box::from_raw(self.ptr.as_ptr()))
            }
        }
    }
}

pub struct Arc<T> {
    ptr: std::ptr::NonNull<ArcData<T>>,
}

// Sending an Arc<T> across threads results in a T object being shared, requiring T to be Sync.
// Sending an Arc<T> across threads could result in another thread dropping that T, effectively
// transferring it to the other thread, requiring T to be send.
unsafe impl<T: Send + Sync> Send for Arc<T> {}
unsafe impl<T: Send + Sync> Sync for Arc<T> {}

impl<T> Arc<T> {
    pub fn new(data: T) -> Arc<T> {
        Arc {
            // Box::new allocates data on the heap
            // Box::leak results in heap data without owner and static (raw pointer)
            ptr: NonNull::from(Box::leak(Box::new(ArcData {
                ref_count: AtomicUsize::new(1),
                v: data,
            }))),
        }
    }

    pub fn data(&self) -> &ArcData<T> {
        // returns a shared reference pointer (which points to data structured as ArcData)
        unsafe { self.ptr.as_ref() }
    }

    pub fn get_mut(arc: &mut Self) -> Option<&mut T> {
        if arc.data().ref_count.load(Ordering::Relaxed) == 1 {
            fence(Ordering::Acquire);
            // Safety: Nothing else can access the data, since
            // there's only one Arc, to which we have exclusive access.
            unsafe { Some(&mut arc.ptr.as_mut().v) }
        } else {
            None
        }
    }
}

impl<T> Clone for Arc<T> {
    fn clone(&self) -> Self {
        if self.data().ref_count.fetch_add(1, Ordering::Relaxed) > usize::MAX / 2 {
            std::process::abort()
        }
        // clone is cheap here as it is only a shared reference
        Arc { ptr: self.ptr }
    }
}
// As an arc consumer you do not want to manage or know the underlying Arc data structure.
// We are only interested in using
impl<T> Deref for Arc<T> {
    type Target = T;
    fn deref(&self) -> &Self::Target {
        &self.data().v
    }
}

#[cfg(test)]
mod tests {

    use super::*;

    #[test]
    fn test_basic_arc() {
        static NUM_DROPS: AtomicUsize = AtomicUsize::new(0);
        struct DropDetector;
        impl Drop for DropDetector {
            fn drop(&mut self) {
                NUM_DROPS.fetch_add(1, Ordering::Relaxed);
            }
        }

        // 2 shared refs
        let a = Arc::new(("hello", DropDetector));
        let b = a.clone();

        // Send a to another thread, and use it there
        let t = std::thread::spawn(move || {
            assert_eq!(a.0, "hello");
        });

        t.join().unwrap();
        // a is dropped, but since there is another ref (b)
        // b should still be able to access the data
        assert_eq!(b.0, "hello");
        assert_eq!(NUM_DROPS.load(Ordering::Relaxed), 0);

        // There are no more references so the data should be dropped
        drop(b);
        assert_eq!(NUM_DROPS.load(Ordering::Relaxed), 1);
    }
}
