---
title: The Universal I/O Model
mathjax: true
layout: default
toc: true
---


# Universal I/O Model

To perform file I/O, C programs typically employ I/O functions contained in the standard C library. This set of functions, referred to as the stdio library, includes fopen(), fclose(), scanf(), printf(), fgets(), fputs(), and so on. The stdio functions are layered on top of the I/O system calls (open(), close(), read(), write(), and so on).


One of the distinguishing features of the UNIX I/O model is the concept of universality of I/O. This means that the same four system calls—open(), read(), write(), and close()—are used to perform I/O on all types of files, including terminals, pipes, sockets, devices, and regular files.



```c

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
int open(const char * pathname , int flags , ... /* mode_t mode */);
// Returns file descriptor on success, or –1 on error

ssize_t read(int fd , void * buffer , size_t count );
// Returns number of bytes read, 0 on EOF, or –1 on error

ssize_t write(int fd, void * buffer , size_t count );
// Returns number of bytes written, or –1 on error

int close(int fd );
//Returns 0 on success, or –1 on error

off_t lseek(int fd , off_t offset , int whence );
// Returns new file offset if successful, or –1 on error

```


All system calls for performing I/O refer to open files using a file descriptor, a 
nonnegative integer. By default the a process will have the following file descriptors:

| File descriptor | Purpose | POSIX name | stdio stream |
| 0  | standard input | STDIN_FILENO | stdin |  
| 1 | standard output |  STDOUT_FILENO | stdout |
| 2 | standard error | STDERR_FILENO | stderr |

**Note:** A file descriptor is an integer which is passed to system calls
as a parameter used to identify a file that was opened by that process.

The kernels holds the following three data structures
* the per-process file descriptor table;
* the system-wide table of open file descriptions;  (open file table)
* the file system i-node table

If two processes each open the same file independently, there will be two entries in the kernel file table



## open


* O_RDWR
* O_WRONLY
* O_RDONLY


* O_APPEND
* O_CREAT
* O_TRUNC


## lseek

For each open file, the kernel records a file offset, sometimes also called the read-write offset or pointer.

* SEEK_SET - The file offset is set to offset bytes from the beginning of the file. Points to first byte.
* SEEK_CUR - The file offset is adjusted by offset bytes relative to the current file offset. Points to current byte.
* SEEK_END - The file offset is set to the size of the file plus offset. Points next byte after end of file.




----
**Atomic Operations**

All system calls are executed atomically.


when we have multiple processes appending data to the same file (e.g., a global log file)
This requires that the seek to the next byte past the end of
the file and the write operation happen atomically. This is what opening a file
with the O_APPEND flag guarantees


----
**File holes**

What happens if a program seeks past the end of a file, and then performs I/O? A call to read() will return 0, indicating end-of-file. It is possible to write bytes at an arbitrary point past the end of the file.

The space in between the previous end of the file and the newly written bytes is
referred to as a file hole.

Note: If the edge of a hole falls within a block, rather than on a block boundary, then a complete block is allocated to store the data in the other part of the block, and the part corresponding to the hole is filled with null bytes.

```
# Block size of the filesystem mounted in current directory
stat -fc %s .
4096
```




