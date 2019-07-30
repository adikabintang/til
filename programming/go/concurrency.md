Question in my head: how does the Golang's concurrency work?

The answer is here: https://codeburst.io/why-goroutines-are-not-lightweight-threads-7c460c1f155f

## Intro: process vs thread

Some basic stuffs:
1. Threads share memory space, PID, and file descriptors. Processes share none of the three. 
2. Communication between threads is simpler because they have a shared memory. In process, we need Inter-Process Communications (IPC) modes such as piper, semaphores, etc.

Thread is a lightweight process. But, it does not always mean that thread is always lighter than process. Why? because synchronizing data in shared memory takes effort.

Thread are slow because:
1. Thread consumes a lot of memory: one thread has its own stack size and the size is >= 1 MB each thread.
2. Thread stores a lot of registers
3. Thread setup and teardown requires call to OS for resources

## Goroutines

Some basic stuffs:
1. Go has "go runtime". It implements garbage collections, concurrency, stack management, etc ([ref](https://golang.org/doc/faq#runtime)). Go is analogous to `libc` in C. However, Go does not have virtual machine like JVM.
2. Goroutines is a lightweight thread managed by the Go runtime, not the OS. It sounds funny now: *Thread is lightweight process, Goroutine is lightweight thread*.
3. Thread scheduler is managed by the OS. Goroutine scheduler is managed by Go runtime.
4. **OS threads are created to handle goroutines**. The number of OS thread created is no more than GOMAXPROCS, which is equal to the number of cores available.
