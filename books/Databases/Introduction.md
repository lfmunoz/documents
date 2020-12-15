---
title: Databases
mathjax: true
layout: default
toc: true
---







# Databases Internals

How the DBMS represents the database in files on disk

DBMS stores a database as one or more files. It uses more than one because you don't want to hit system limits of single files if its terabytes for example. The format is usually proprietary and specific to the application.

The engineering effort to make your own file system is not worth it, you get maybe 10 percent improvement, and now you are less portable.

The storage manager is responsible for maintaining a database's files.

A page is a fixed-size block of data.


# How the DBMS represents the database in files on disk

DBMS stores a database as one or more files. It uses more than one because you don't want to hit system limits of single files if its terabytes for example. The format is usually proprietary and specific to the application.

* Why not create your own file system? 
    * The engineering effort to make your own file system is not worth it, you get maybe 10 percent improvement, and now you are less portable.


### Storage Manager

The **storage manager** is responsible for maintaining a database's files. It represents the files as a
collection of pages. It also keeps track of what data has been read and written to pages, as well how much
free space there is in the pages.

The DBMS organizes the database across one or more files in fixed-size blocks of data called pages




A database is mapped into a number of different files that are maintained by the operating system.

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

