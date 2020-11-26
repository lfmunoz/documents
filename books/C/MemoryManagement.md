---
title: Memory Management
mathjax: true
layout: default
toc: true
---


# Memory Management

* [The C Programming Language](Introduction.html)

C provides several functions for memory allocation and management also known as dynamic memory allocation.

  *  malloc and calloc, to reserve space, on the heap
  *  realloc, to move a reserved block of memory to another allocation of different dimensions
  *  free, to release space back to C

tip: When you allocate memory immediately write the code to free the memory.

These functions can be found in the stdlib library

```c
#include <stdlib.h>
void *calloc(size_t nmemb, size_t size);
void free(void *ptr);
void *malloc(size_t size);
void *realloc(void *ptr, size_t size);
 
```

Examples 

```c

 int *int_values; 
 int_values = (int *) malloc(100 * sizeof(int));
 if (!int_values) {
  perror("Failed to allocate space because");
  exit(1);
 }
  free(values);
 
```


Malloc (and calloc) will return a non-NULL value if the request for space has been successful, and NULL if it fails

# Memory Allocation 

A memory allocator's responsibility is to manage free blocks of memory. If you've never read a **malloc** implementation, you may have assumed that calling **free** simply causes memory to be released to the operating system. But acquiring memory from the OS has a cost, so allocators tend to keep free chunks around for a while for possible re-use before deciding to release them.


A very basic malloc implementation might use the linux system call **sbrk**(2) to acquire memory from the operating system and a [[linked list]] to store free chunks. That would make calls to free constant time, but **malloc** would be O(n).


the allocator needs to store metadata about each chunk it manages, such as its size, free/in-use status, free-list pointer(s), etc. 


```
 header                pointer address  
    V                     V
    -----------------------------------------------------
    |                     |                             | 
    | struct malloc_chuck |                             | 
    |                     |                             | 
    -----------------------------------------------------

```


```c
struct malloc_chunk {
  struct malloc_chunk *next; // next pointer on free list
  size_t size; // the size of this chunk
  unsigned free; // > 0 if this pointer is free - useful for runtime assertions
}
 
struct malloc_chunk *
header(void *ptr) //prts to memory subtract header to get start of header
{
  return (struct malloc_chunk *)ptr - sizeof(malloc_chunk); 
}
```

#  Leaked Memory
Once you have allocated memory, the problem is that the compiler can't tell when you're done with it, so you lose the automatic releasing. Your code is now responsible to decide when the variable is not needed anymore, and release it so the memory can be taken for other purposes. Forgetting to release a variable when you don't need it will cause your program to consume more memory that it needs to. This situation is called a "leak". The "leaked" memory cannot be used for anything until your program ends and the OS recovers all of its resources. Even nastier problems are possible if you release a heap variable by mistake before you are actually done with it.

# What to free? 
How does free know what to free? Malloc stores additional information about the size of the buffer in a few bytes before the actual data. Free reads that.
  *  When you call malloc(), you specify the amount of memory to allocate. The amount of memory actually used is slightly more than this, and includes extra information that records (at least) how big the block is. When you call free(), it simply looks at the extra information to find out how big the block is
  *  The only thing that matters to free is getting the exact same address as what malloc returned.

```c
void load_file() 
{   

 char *data = "This is so data";   
 printf("function: %s\n", data); 
 free(data);
} 
```

Will the above code leak memory? Should I have call free(data)? Why or why not?
  *  You only need to free memory you allocate, memory on the heap.
  *  It cannot leak because you did not dynamically allocate it. data is a string literal and not a dynamically allocated array of characters.
  *  You can only leak memory on the heap
  *  Data itself, a pointer, is allocated on the stack


# memcpy()

Copy block of memory
Copies the values of num bytes from the location pointed by source directly to the memory block pointed by destination.

The underlying type of the objects pointed by both the source and destination pointers are irrelevant for this function; The result is a binary copy of the data.
```c
#include <string.h>
void * memcpy ( void * destination, const void * source, size_t num );
// destination is returned.
```

## Example

```c
/* memcpy example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str1[]="Sample string";
  char str2[40];
  char str3[40];
  memcpy (str2,str1,strlen(str1)+1);
  memcpy (str3,"copy successful",16);
  printf ("str1: %s\nstr2: %s\nstr3: %s\n",str1,str2,str3);
  return 0;
}
```


# Examples

```c
pOutDMA = (unsigned char*)_aligned_malloc(burst_size, 4096);

unsigned char *pInDMA = (unsigned char*)_aligned_malloc(MAX_BURST, 4096);

unsigned char *pInDMA = (unsigned char *)_aligned_malloc(burst_size, 4096);

unsigned char *pOutDMASaved = (unsigned char*)_aligned_malloc(burst_size, 4096);
// cast our DMA pointer to char *
unsigned char *pOutDMA_8 = (unsigned char *)pOutDMA;
//	unsigned char *pInDMA_8 = (unsigned char *)pInDMA;

printf("Running Memtest\n");
uint16_t* pOutDMABuffer16 = (uint16_t*)pOutDMA_8;

uint32_t *pOutDmaBuffer32 = (uint32_t*)pOutDMA_8;
uint32_t *pOutDmaSavedBuffer32 = (uint32_t *)pOutDMASaved;
```

# References  

  *  http://c-faq.com/malloc/freesize.html
  *  http://en.wikibooks.org/wiki/C_Programming/Memory_management
