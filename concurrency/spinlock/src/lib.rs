#![allow(dead_code)]

use std::cell::UnsafeCell;
use std::ops::{Deref, DerefMut, Drop};
use std::sync::atomic::{AtomicBool, Ordering};

const LOCKED: bool = true;
const UNLOCKED: bool = false;

struct Guard<'a, T> {
    lock: &'a SpinLock<T>,
}
unsafe impl<T> Send for Guard<'_, T> where T: Sync {}

impl<T> Deref for Guard<'_, T> {
    type Target = T;
    fn deref(&self) -> &Self::Target {
        // Safety: The Guard guarantees we have exclusive access.
        unsafe { &*self.lock.v.get() }
    }
}
impl<T> DerefMut for Guard<'_, T> {
    fn deref_mut(&mut self) -> &mut T {
        // Safety: The Guard guarantees we have exclusive access.
        unsafe { &mut *self.lock.v.get() }
    }
}
impl<T> Drop for Guard<'_, T> {
    fn drop(&mut self) {
        // remove the lock
        self.lock.state.store(UNLOCKED, Ordering::Release)
    }
}

struct SpinLock<T> {
    state: AtomicBool,
    pub v: UnsafeCell<T>,
}

unsafe impl<T> Sync for SpinLock<T> where T: Send {}

impl<T> SpinLock<T> {
    pub fn new(t: T) -> Self {
        Self {
            state: AtomicBool::new(UNLOCKED),
            v: UnsafeCell::new(t),
        }
    }

    pub fn lock(&self) -> Guard<T> {
        while self
            .state
            .compare_exchange_weak(UNLOCKED, LOCKED, Ordering::Acquire, Ordering::Relaxed)
            .is_err()
        {
            std::hint::spin_loop()
        }
        Guard { lock: self }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::thread::scope;

    #[test]
    fn test_lock() {
        let x = SpinLock::new(Vec::new());

        scope(|s| {
            s.spawn(|| x.lock().push(1));
            s.spawn(|| {
                let mut g = x.lock();
                g.push(2);
                g.push(2);
            });
        });

        let g = x.lock();
        assert!(g.as_slice() == [1, 2, 2] || g.as_slice() == [2, 2, 1])
    }
}
