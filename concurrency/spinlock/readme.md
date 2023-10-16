# Spinlock

A spinlock is a synchronization primitive used in multithreaded environments. Unlike other locking mechanisms that put a thread to sleep if a lock is unavailable, a spinlock causes the thread to actively wait ("spin") in a loop
until the lock can be obtained. This busy-wait approach can be efficient for very short waiting durations, but most of the time it should not be used in production environments as it wastes CPU cycles.

## Remarks implementation

### Traits

The method `Spinlock::lock()` yields a `Guard`. This `Guard` abstracts away the manual unlocking process, ensuring that the lock is automatically released when the `Guard` falls out of scope.
To provide seamless access to the underlying data without an additional dereference step, the `Deref` and `DerefMut` traits are implemented on the `Guard`. This allows users to interact directly with the protected data
as if they were working with the original type.

### UnsafeCell

The spinlock implementation uses an `unsafeCell`. In Rust, a `&T` is typically seen as a shared, immutable reference, meaning the underlying data cannot be mutated through this reference due to the strict ownership model. However, in multithreaded environments,
there are scenarios where one might want multiple threads to potentially mutate a value simultaneously, something the default ownership model prohibits.

`UnsafeCell` provides a way around this. It allows us to bypass the default immutability guarantees for shared references. By wrapping a value inside an `unsafeCell<T>`, you can mutate the inner `T` even through a shared reference `&UnsafeCell<T>`.
This mechanism is known as `interior mutability`. `UnsafeCell` is unsafe, it is your responsibility to ensure that accesses are synchronized, and no data races occur.

### Processor hint

`Lock()` repeatedly attempts to acquire a lock in a loop. During this loop, it uses a spin loop hint (`std::hint::spin`), which tells the processor that we're spinning while waiting for something to change. On most major platforms, this hint results in a special instruction that causes the processor core to optimize its behavior for such a situation. For example, it might temporarily slow down or prioritize other useful things it can do.
