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


