---
title: Databases
mathjax: true
layout: default
toc: true
---




# Performance


**Latency** is defined as the elapsed time between issuing a request or a command to a particular subsystem and receiving a response or reply. It is measured in units of time (seconds, microseconds, etc) or cycles. Latency provides a measure of responsiveness and it is a critical metric for any subsystem that satisfies time-critical requests.


**Bandwidth** is defined as the throughput of system; that is, the rate at which it can satisfy requests. Bandwidth measured in quantity per unit time, where the quantity measured measured varies based on the type of request.

Bandwidth is generally driven by product-cost constraints rather than fundamental liminations of a given technology. A bus can always be made wider to increase the number of bytes transmitted per cycle.

Latency is fundamentally more difficult to improve since it is often dominated by liminations of a particular technology, or possible the law of physics.

| Event |  Latency |  Scaled |
| --- | --- | --- |
| 1 CPU Cycle | 0.3 ns | 1 s|
| Main memory access | 120 ns | 6 min |
| Solid-stae disk I/O | 50-150 us | 2-6 days |
| Rotational disk I/O | 1-10 ms | 1-12 months |
| Internet: San Francisco to new York | 40 ms | 4 years |
| TCP packet re-transmit | 1-3 s | 105-317 years |


# Databases Internals

* Query Planning
* Operator Execution
* Access Methods
* Buffer Pool Manager
* Disk Manager


## Disk Manager

file storage, page layout, tuple layout


DBMS stores a database as one or more files. It uses more than one because you don't want to hit system limits of single files if its terabytes for example. The format is usually proprietary and specific to the application.

The **storage manager** is responsible for maintaining a database's files on disk. It is a software layer. It represents the files as a collection of pages. 
* Keeps track of what data has been read and written to pages
* Keeps track of how much free space there is in the pages

A **page** is a fixed-size block of data. 
* Each page is given a unique identifier
* It can contain tuples, meta-data, indexes, log records
* Most systems do not mix page types
* some systems require page to be self-contained

There are different notions of pages
* Hardware Page - from the storage device itself (usually 4k)
  * hardware can only guarantee a "failsafe write" of 4k (atomic write)
* OS Page - (usually 4k)
* Database Page  (512B-16KB)


Why not make your own file system? The engineering effort to make your own file system is not worth it, you get maybe 10 percent improvement, and now you are less portable.

Why not allow the OS to manage the storage? The DBMS can do a better job. (flushing dirty pages, prefetching, buffer replacement, thread scheduling)


To manage pages in files on the disk we have different ways
* Heap file organization - unordered collection of pages where tuples are stored in random order.
    * create / get / write / delete page  and iterate
    * need meta-data to keep track what pages exist and which have free space
    * can be represented as a Linked List (not good idea) or Page Directory
* Sequential / Sorted File Organization
* Hashing File Organization

Note: At this level we don't know anything about what is on the pages


Linked List

Maintain a **header page** at the beginning of the file that stores pointers to
free page list, and data page list. 


```
              free  page    -->   free page
   | --->
   |
   |
  --------
  | header |
   --------
    |
    | ------->
                data page  -->     data page 

```

page directory

You have a file with special pages in the beginning that is going to maintain the mapping to page IDs to their offset.


DBMS maintains special pages that track the location of data pages in the database files.

```
               Page  
               Page
Directroy      page 

```

Like a hash table, you want page 123 and the hash table tells you where to get it.


What is inside the page?

```
 | Header | Data |
```
ever page contains a header of metadata about the page's content
page size, checksum, DBMS version, transaction visibility, compression information

the page layout can be
* tuple-oriented - store tuples one after another

The most common layout scheme is slotted pages
header keeps track of the number of used slots and the offset of the starting location of the last slot used.

header then a slot array and starting from the end  the tuples

```
 | Header | Slots | Data |
```

* log-structured




The way we identify tuples is with a unique record identifier
most common is page_id + offset/slot

```sql
create table r (id INT PRIMARY KEY, val VARCHAR(6));
insert into r values (101, 'aaa'), (102, 'bbb'), (103, 'ccc');
-- postgres  has CTID ( a virtual column with (page_id, offset) )
select r.ctid, r.* from r;
DELETE from r WHERE id = 102;
-- which slot will it go in? 4
insert into r values (104, 'xxx');
-- this will compact the pages, write them out sequentially
VACUUM FULL;
```

A **tuple** is essentially a sequence of bytes. The DMBS interprets those bytes into attribute types and values.

```
header | attribute data
```
header has visibility info (concurrency control) and a bit map for null values
We generally do not store the meta-data about the schema.

normalization is how we split our databse across different tables, this happens with foreign keys.   somtimes you want to embedd one table inside another to avoid teh overhead of the join, that is called **denormalization**.

### Buffer Manager

Programs in a database system make requests (i.e., calls) on the buffer manager when
they need a block from disk.

# Learning

Database System Concepts, 7ed \
Silberschatz, Korth, Sudarshan


* Andy Pavlo - Fall 2019 
    * https://www.youtube.com/playlist?list=PLSE8ODhjZXjbohkNBWQs_otTrBTrjyohi
    * https://15445.courses.cs.cmu.edu/fall2019/project1/
    * https://github.com/cmu-db/bustub

