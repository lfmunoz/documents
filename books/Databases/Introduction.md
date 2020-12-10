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




# Learning

* Fall 2019
* https://www.youtube.com/playlist?list=PLSE8ODhjZXjbohkNBWQs_otTrBTrjyohi