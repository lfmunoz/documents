---
title: Concurrency
mathjax: true
layout: default
toc: true
---



# Concurrency


Does a computer execute the program you wrote? No, that would be too slow, you didn't mean to do that, so the compiler or processor or cache system will re-write it for you. 

**Important:** Re-ordering can happen for many reasons (compiler, caching system, CPU pre-fetch) but it doesn't matter, the end effect is re-ordering. 


**Sequential consistency** : Executing the program you wrote. Defined in 1979 by Leslie Lamport as 

> The result of any execution is the same as if the operations of all the processors were executed in some sequential order and the operations of each individual processor appear in this sequence in the order specified by its program

This means the execution order of a program in the same processor (or thread) is the same as the program order. The execution order of a program between processors (or threads) is undefined.




Let's explore the classic example of trying to modify a global variable from two different threads.

```
 thread 1:     [incr global variable]  [incr global variable]  [incr global variable]
 thread 2:       [incr global variable]  [incr global variable]  [incr global variable]
 Time   t: -------------------------------------------------------------------------------->
```


<details>
<summary> <strong> cat concurrency.c </strong> </summary>

<p markdown="block">
```c
{% include_absolute '/books/Linux/src/concurrency.c'  %}
````
</p></details>



As the programmer you talk to the compiler through source code. 

What the compiler knows is all memory operations in this thread and exactly what they do including data dependencies.

What the compiler doesn't know is which memory locations are mutable shared variables which could change asynchronously due memory operations in another thread

Solution: Tell it. Somehow identify the operations on mutable shared locations. This is why we use mutual exclusion and atomics.




## Mutual Exclusion (mutex)

Wouldn’t it be nice if you could mark all pieces of code that access data structures concurrency as mutually exclusive. 

Then if any thread was accessing a data structure and any other thread tried to access the same data structure it would have to wait until the first thread was finished. 

That would make it impossible for a thread to see a broken invariant except when it was the thread doing the modification.


Before accessing a shared data structure, you lock the mutex associated with that data, and when you’ve finished accessing the data structure, you unlock the mutex.

```c
std::mutex
lock() 
unlock()
```

The common advice for avoiding deadlock is to always lock the two mutexes in the
same order: if you always lock mutex A before mutex B, then you’ll never deadlock.





# Understanding re-ordering




In our current chip designs: the memory doesn’t get out of sync. That is, despite what you think about how memory is working, each core actually has a correct and accurate view of the memory at all times. If two cores happen to be accessing the same memory the CPU takes care of ensuring they are both working with the correct memory. This is something known as **cache coherence**.


But we all know if we don’t use mutexes our program memory will become horribly corrupt. Something doesn’t seem right. So I should clarify. As far as the CPU is concerned it has a consistent view of the memory.

When one core writes an integer to the cache, any other core which then reads from that location will get that new value.
To be clear, a core will not read an outdated value from the memory cache.



The moment you have larger data structures however things aren’t so simple.

A sequence of atomic operations is not atomic itself.


This is the first role which locks play. If the code in both threads uses a lock around these 4 bytes, the second core won’t read any of the data until you have finished copying all of it.



 To truly maximize the use of even the fastest cache, the CPU changes the order in which data is written and read from that cache.
 
 So while you may have written values 1,2,3 in sequence, the CPU could easily chose to write in the order 1,3,2 instead. If this happens the other thread might get the 3, but not the 2!
 
 This is why it’s actually not enough to just lock access to parts of memory, since the CPU could just reorder memory writes outside of that block.
 
 When a CPU encounters a fence it knows that all its reordering of loads and stores has to be complete before it passes the fence. 
  This ensures that if two threads both use a fence, the second thread will see the complete set of written data and not just a part of it.
  
  They key to understanding the need for a mutex lies in the reordering of memory access and that lack atomicity in large data structures. 
  
  
  
   Without CPU support there is no way to implement a mutex in user space: this operation must be atomic with respect to the other threads.
 
  If a system call does provide a full mutex, why would we bother with any test-and-set in userspace? The answer is that system calls have quite a bit of overhead and should be avoided when possible.
  
   Under Linux, there is a system call futex which provides mutex like semantics.


# Learning

* Great Overview of Concurrency
* [https://www.youtube.com/watch?v=A8eCGOqgvH4](https://www.youtube.com/watch?v=A8eCGOqgvH4)

* [https://en.wikipedia.org/wiki/Consistency_model#Processor_consistency](https://en.wikipedia.org/wiki/Consistency_model#Processor_consistency)

* Leslie Lamport, "How to Make a Multiprocessor Computer That Correctly Executes Multiprocess Programs", IEEE Trans. Comput. C-28,9 (Sept. 1979), 690-691.




* Notes on structured concurrency, or: Go statement considered harmful
[https://vorpus.org/blog/notes-on-structured-concurrency-or-go-statement-considered-harmful/](https://vorpus.org/blog/notes-on-structured-concurrency-or-go-statement-considered-harmful/)




https://stackoverflow.com/questions/39393850/can-num-be-atomic-for-int-num