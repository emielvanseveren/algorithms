# Arc (Atomic Reference Counter)

### Basic idea

`Arc` is a thread-safe reference counting smart pointer. When you create a new `Arc`, it has a reference count of 1. When you clone the `Arc`, you get a new `Arc` that
points to the same data, and the reference count is incremented. When an `Arc` is dropped, the reference count is decremented. When the reference count drops to zero, the data is deallocated.

## Remarks implementations

I have a hard time understanding memory ordering. Below are a few of the memory ordering concepts used in the Arc:

- Fences are a way to ensure a certain order of operations across atomic variables. When you see `fence(Ordering::Acquire)`, it ensures that all previous reads on the current thread happened before the fence and all subsequent reads happen after.
  Conversely, `fence(Ordering::Release)` ensures that all previous writes happen before the fence and all subsequent writes happen after.

- `Ordering::Release` in `fetch_sub`: ensures that all previous operations on the current thread happen before decrementing the reference count.
  This is crucial as it prevents any operations on the Arc from being reordered after this decrement.

- `fence(Ordering::Acquire)`: when the reference count drops to 1 (after the `fetch_sub`), this fence ensures a "happens-before" relationship. It ensures that any operations from other threads that saw the incremented count
  happen before this point.
