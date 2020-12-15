---
title: Inter-process communication
mathjax: true
layout: default
toc: true
---


# Inter-process communication

Communication: These facilities are concerned with exchanging data between processes.

Synchronization: These facilities are concerned with synchronizing the actions of processes or threads.


Shared memory: Shared memory allows processes to exchange information by
placing it in a region of memory that is shared between the processes. (The kernel
accomplishes this by making page-table entries in each process point to the
same pages of RAM


Both have the same basic tools -- semaphores, shared memory and message queues. 
 They offer a slightly different interface to those tools, but the basic concepts are the same. 

* IPC Examples
* http://hildstrom.com/projects/ipc_sysv_posix/index.html





## POSIX shared memory

* POSIX shared memory objects allow us to avoid the overhead of using a disk file when a backing store is not required.
* POSIX shared memory objects have at least kernel persistence; that is, they continue to exist until they are explicitly removed or the system is rebooted.



Linux uses a dedicated tmpfs file system

mounted under the directory /dev/shm . This file system has kernel persistence—the shared memory
objects that it contains will persist even if no process currently has them open, but they will be lost if the system is shut down.

To use a POSIX shared memory object, we perform two steps:
* Use the shm_open() function to open an object with a specified name.
* Pass the file descriptor obtained in the previous step in a call to mmap() that specifies MAP_SHARED in the flags argument. This maps the shared memory object into the process’s virtual address space.



```c
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
/* Defines O_* constants */
/* Defines mode constants */
int shm_open(const char * name , int oflag , mode_t mode );
// Returns file descriptor on success, or –1 on error

#include <sys/mman.h>
int shm_unlink(const char * name );
// Returns 0 on success, or –1 on error

```



