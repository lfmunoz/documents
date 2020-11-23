---
title: Processes
mathjax: true
layout: default
toc: true
---


# Processes

A **process** is an instance of an executing program. It is an abstract entity, defined by the kernel, to which system resources are allocated in order to execute a program. 

A **program** is a file containing a range of information that describes how to construct a process at run time.


**Segments** are logical divisions of a process’s virtual memory. 
Sometimes, the term **section** is used instead since section is
more consistent with the terminology used in the ELF specification.



## Layout


<details>
<summary> <strong> cat program_layout.cpp </strong> </summary>

<p markdown="block">
```cpp
{% include_relative src/program_layout.c %}
````
</p></details>


```bash
# dump a process's memory contents onto disk.
sudo gcore 1255
```

```bash
getconf PAGESIZE 
4096
```



```bash
size program_layout
  text    data     bss        dec        hex        filename
  1918     636   10305568   10308122   9d4a1a   program_layout
```


<details>
<summary> <strong> cat /proc/3570/maps </strong> </summary>

<p markdown="block">
```bash
# describes a region of contiguous virtual memory in a process
cat /proc/3570/maps
5652868c2000-5652868c3000 r-xp 00000000 103:03 4612851                   /home/luis/github/documents/books/Linux/src/a.out
565286ac2000-565286ac3000 r--p 00000000 103:03 4612851                   /home/luis/github/documents/books/Linux/src/a.out
565286ac3000-565286ac4000 rw-p 00001000 103:03 4612851                   /home/luis/github/documents/books/Linux/src/a.out
565286ac4000-565287498000 rw-p 00000000 00:00 0 
565287d2d000-565287d4e000 rw-p 00000000 00:00 0                          [heap]
7f5014619000-7f5014800000 r-xp 00000000 103:03 3943189                   /lib/x86_64-linux-gnu/libc-2.27.so
7f5014800000-7f5014a00000 ---p 001e7000 103:03 3943189                   /lib/x86_64-linux-gnu/libc-2.27.so
7f5014a00000-7f5014a04000 r--p 001e7000 103:03 3943189                   /lib/x86_64-linux-gnu/libc-2.27.so
7f5014a04000-7f5014a06000 rw-p 001eb000 103:03 3943189                   /lib/x86_64-linux-gnu/libc-2.27.so
7f5014a06000-7f5014a0a000 rw-p 00000000 00:00 0 
7f5014a0a000-7f5014a31000 r-xp 00000000 103:03 3943182                   /lib/x86_64-linux-gnu/ld-2.27.so
7f5014c0e000-7f5014c10000 rw-p 00000000 00:00 0 
7f5014c31000-7f5014c32000 r--p 00027000 103:03 3943182                   /lib/x86_64-linux-gnu/ld-2.27.so
7f5014c32000-7f5014c33000 rw-p 00028000 103:03 3943182                   /lib/x86_64-linux-gnu/ld-2.27.so
7f5014c33000-7f5014c34000 rw-p 00000000 00:00 0 
7ffdde410000-7ffdde432000 rw-p 00000000 00:00 0                          [stack]
7ffdde518000-7ffdde51b000 r--p 00000000 00:00 0                          [vvar]
7ffdde51b000-7ffdde51c000 r-xp 00000000 00:00 0                          [vdso]
ffffffffff600000-ffffffffff601000 --xp 00000000 00:00 0                  [vsyscall]
```
</p></details>


<details>
<summary> <strong> readelf --file-header ./program_layou</strong> </summary>

<p markdown="block">
```bash
readelf --file-header ./program_layout
ELF Header:
  Magic:   7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00 
  Class:                             ELF64
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI Version:                       0
  Type:                              DYN (Shared object file)
  Machine:                           Advanced Micro Devices X86-64
  Version:                           0x1
  Entry point address:               0x5d0
  Start of program headers:          64 (bytes into file)
  Start of section headers:          11816 (bytes into file)
  Flags:                             0x0
  Size of this header:               64 (bytes)
  Size of program headers:           56 (bytes)
  Number of program headers:         9
  Size of section headers:           64 (bytes)
  Number of section headers:         34
  Section header string table index: 33
```
</p></details>





<details>
<summary> <strong> hexdump -C -s 0x0  ./a.out   </strong> </summary>

<p markdown="block">
```bash
hexdump -C -s 0x0  ./a.out  
```
</p></details>



```


High Addresses ---> .----------------------.
0xFFFFFFFFF (4GB)   |        Kernel        |   mapped into process virtual memory
                    |        Space         |   but not accessible to program
                    |                      |
                    |                      |   Anything not in Kernel Space is
                    |                      |    User Space
0xC0000000          |----------------------|
                    |                      |   argv, environ
                    |     Environment      |    command line arguments
                    |                      |    process environment list
                    |                      |
                    |                      |
Top of stack --->   |----------------------|
                    |                      |   Dynamically growing and shrinking.
                    |                      |   Contains stack frames.
                    |         STACK        |   Local variables, parameter passing
                    |           v          |
                    |           v          |   
                    |           v          |
base pointer ->     | - - - - - - - - - - -|
                    |           |          |
                    |           v          |
                    :                      :
                    .                      .   The stack grows down into unused space
                    .         Empty        .   while the heap grows up. 
                    .                      .
                    .                      .   (other memory maps do occur here, such 
                    .                      .    as dynamic libraries, and different memory
                    :           ^          :    allocate)
                    |           ^          |
                    |           |          |
 brk point ->       | - - - - - - - - - - -|   Top of heap is called the program break.
                    |                      |   brk() system call is used to adjust
                    |          HEAP        |
                    |                      | Dynamically allocated memory is declared on the heap
                    |                      |
extern end          |----------------------|
                    |         BSS          |   Uninitialized Data (BSS)
                    |                      |    Holds global and static variables that are not initialized.
                    |                      |    The size that the bss will require at runtime is 
                    |                      |    recorded into the object file but bss doesn't take
                    |                      |    up any actual space in the object file.  
                    |                      |    Initialized to 0. BSS = block started by symbol
                    |                      |     
                    |                      |    char globBuf[65536];   
                    |                      |    static char localBuf[10240000];  
                    |                      |     
extern edata        |----------------------|   
                    |        Data          |   Initialized Data (DS)
                    |                      |     Global and static variables with their assigned values.
                    |                      |     Values read from the executable file.
                    |                      |     
                    |                      |    int primes[] = { 2, 3, 5, 7 }; 
                    |                      |    static int key = 9973; 
                    |                      |     
                    |                      |     
extern etext        |----------------------|
                    |        Text          |   Text Segment (machine-language instructions of program)
                    |                      |    Program instructions, copied directly from file into memory.
                    |                      |    Read-only. Shareable.
                    |                      |     
                    |                      |     
                    |                      |     
0x08048000 (32-bit) |----------------------|
0x00400000 (64-bit) |                      |     
                    |                      |     
Low Addresses ----> '----------------------'
0x00000000


```

The entry point of a non-PIE executable should be 0x400000, whereas for 32 bit ELF executables, the entry point is 0x08048000.




```c
// C program environment provides three global symbols
extern char etext;  // end of the program text
extern char edata;   // end of the initialized data segment
extern char end;  // end of the uninitialized data segment
```

## Commands

```bash
# The Linux kernel limits process IDs to being less than 
# or equal to 32,767. This limit is adjustable.
cat /proc/sys/kernel/pid_max        
32768

# The parent of any process can be found by looking at the Ppid field in
cat /proc/PID/status
```



```c
#include <unistd.h>
pid_t getpid(void);
// Always successfully returns process ID of caller
```










# References


https://gist.github.com/neraliu/dc7c9a9f1980075c9c9f649da71cf37c
https://gist.github.com/CMCDragonkai/10ab53654b2aa6ce55c11cfc5b2432a4
