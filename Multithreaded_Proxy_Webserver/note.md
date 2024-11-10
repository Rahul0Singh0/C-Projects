## Semaphore
A semaphore in an operating system (OS) is a synchronization tool used to manage and control access to shared resources in a multi-threaded or multi-process environment. Semaphores help prevent issues like race conditions and ensure that resources are used in an orderly way.

#### working 
A semaphore maintains a counter that represents the number of resources available. It provides two main atomic operations:

1. Wait (P operation):
   Decreases the semaphore’s value by 1.
   If the semaphore's value is positive, the process proceeds.
   If the semaphore’s value is zero or negative, the process is blocked until the semaphore's value becomes positive again (when a resource is released).

2. Signal (V operation):
   Increases the semaphore’s value by 1.
   If any processes are waiting, one of them will be allowed to proceed

## mutex_lock
A mutex lock (short for mutual exclusion lock) is a synchronization mechanism used to prevent multiple threads or processes from accessing a shared resource (like memory, files, or data structures) simultaneously. 
 
#### working
A mutex is essentially a lock that allows threads to "lock" a resource when they start using it and "unlock" it when they're done, so other threads can access it.

1. Locking: 
   When a thread wants to access the critical  section, it "locks" the mutex. If another thread tries to lock it while it's already locked, that thread will be blocked (or put in a waiting state) until the mutex is unlocked.
   
2. Unlocking: 
   Once the thread finishes its task in the critical section, it releases or "unlocks" the mutex, allowing other waiting threads to acquire the lock and access the critical section.

### int socket(int domain, int type, int protocol);
   example: proxy_socket_id = socket(AF_INET, SOCK_STREAM, 0);
   The SOCK_STREAM style is like a pipe (see Pipes and FIFOs). It operates over a connection with a particular remote socket and transmits data reliably as a stream of bytes. 

   AF_INET is used to represent the IPv4 address of the client to which a connection should be made. These sockets are called internet domain sockets.

### inet_ntop()
   The inet_ntop function in C is used to convert an IP address from its binary form (used in struct in_addr or struct in6_addr) to a human-readable string. 

### buffer:
   A buffer in programming is a temporary storage area, usually in memory, used to hold data while it is being transferred from one place to another. Buffers are essential in various scenarios, such as managing I/O operations, network communication, data processing, and more.

## Note : Makefile same as gradle in java, package.json to build npm in node/javascript