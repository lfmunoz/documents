---
title: System Calls
mathjax: true
layout: default
toc: true
---




# System Calls


A system call is a controlled entry point into the kernel, allowing a process to request that the kernel perform some action on the process’s behalf. The kernel makes a range of services accessible to programs via the system call application programming interface (API). These services include, for example, creating a new process, performing I/O, and creating a pipe for interprocess communication. 


(The syscalls(2) manual page lists the Linux system calls.)


A system call changes the processor state from user mode to kernel mode, so that the CPU can access protected kernel memory.

The set of system calls is fixed. Each system call is identified by a unique number. (This numbering scheme is not normally visible to programs, which identify system calls by name.)

Each system call may have a set of arguments that specify information to be transferred from user space (i.e., the process’s virtual address space) to kernel space and vice versa.


* read()	read bytes
* write()	write bytes
* open()	open file
* close()	close file
* fork()	create new process
* exec()	execute a new program
* connect()	connect to network host
* accept()	accept a network connection
* stat()	fetch file statistics
* ioctl()	set I/O properties, or other miscellaneous functions
* nmap()	map a file to the memory address space
* brk()	extend the heap pointer


# References

* The Definitive Guide to Linux System Calls
* https://blog.packagecloud.io/eng/2016/04/05/the-definitive-guide-to-linux-system-calls/

