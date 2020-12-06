---
title: Linux
mathjax: true
layout: default
toc: true
---



# Linux


* [Universal File I/O](UniversalFileIO.html)
* [Processes](Processes.html)
    * Conversions
* [System Calls](SystemCall.html)
* [Inter-process communication](IPC.html)



* 1   Executable programs or shell commands
* 2   System calls (functions provided by the kernel)
* 3   Library calls (functions within program libraries)
* 4   Special files (usually found in /dev)
* 5   File formats and conventions eg /etc/passwd
* 6   Games
* 7   Miscellaneous  (including  macro  packages  and  conventions), e.g. man(7), groff(7)
* 8   System administration commands (usually only for root)
* 9   Kernel routines [Non standard]

```
# See man page
man 2 open

# Show the corresponding source groff file
man -w 2 open   
/usr/share/man/man2/open.2.gz

# Show which package this file belongs to
dpkg -S /usr/share/man/man2/open.2.gz
manpages-dev: /usr/share/man/man2/open.2.gz

```

48decimal/30hex = 0
64decimal/41hex = A
97decimal/61hex = a



* od
  * od -c input.txt  # the contents of input in character format (meaning show \n)
  * od -c -          # - accepts input from stdin
  * od -x input.txt  # output as 2-byte hex
* hd
* hexdump 
* xxd 
  * xxd text.tmp     # show hex and ascii



# Linux Permissions


```bash
d rwx rwx rwx
   +   +   +
   |   |   |
   |   |   |
   |   |   +-----+ All Users
   |   |
   |   +---------+ Group
   |
   +-------------+ Owner
```


```bash
drwxr-xr-x   7 luis luis 4.0K Feb 21  2016 VirtualBox VMs/
-rw-r--r--   1 luis luis  317 Apr 18 18:24 index.html
-rw-r--r--   1 luis luis  304 Feb 14 23:51 missfont.log
```
The first character can be any of these:
* d = directory
* - = regular file
* l = symbolic link
* s = Unix domain socket
* p = named pipe
* c = character device file
* b = block device file

Read permission.
* regular file - it can be opened and read.
* directory - you can list the contents.

Write permission.
* regular file - you can modify the file, aka write new data to the file.
* directory - you can add, remove, and rename files in the directory.

Execute permission.
* regular file - you can execute the file as a program or a shell script.
* directory, the execute permission (also called the “search bit”) allows you to access files in the directory and enter it, with the cd command, for example. However, note that although the execute bit lets you enter the directory, you're not allowed to list its contents, unless you also have the read permissions to that directory

chmod - change file mode bits


```bash
drwxr-xr-x
```
Think of this in terms of binary 7 7 7 = rwx rwx rwx
-R - change files and directories recursively

```bash
# Wipe out all the permissions but add read permission for everybody
$ chmod a=r testfile 
# Add execute permissions for group:
$ chmod g+x testfile 
# Remove the execute permission from both the file's owner and group
$ chmod ug-x testfile 
$ chmod 755 testfile
```

```
644 = rw-r--r--   Usual permissions for reading an HTML web page or Read-only text files.
664 = rw-rw-r--   Used in most plain text hit-counter logs (writable = on)
666 = rw-rw-rw-   Used in scripts that require World writable permission.
711 = rwx--x--x   Used by Perl scripts to make them executable only upon access.
751 = rwxr-x--x   Used by Perl scripts that must be written to and executed (hit counters).
755 = rwxr-xr-x   Used by some Perl-scripts and binary database files.
775 = rwxrwxr-x   Normal permission for your website's Root directory
777 = rwxrwxrwx   The whole ball of wax. You better have tight security on any file marked with these permissions. 777 is usually only assigned to a CGI Directory, rather than to an individual file.
```



* Understanding glibc malloc
  * https://sploitfun.wordpress.com/2015/02/10/understanding-glibc-malloc/


# Learning


## Resources

* Linux Source Code
  * [https://elixir.bootlin.com/linux/v5.9.9/source/](https://elixir.bootlin.com/linux/v5.9.9/source/)
* Collection of lectures and labs  on the Linux kernel
  * [https://linux-kernel-labs.github.io/refs/heads/master/lectures/intro.html](https://linux-kernel-labs.github.io/refs/heads/master/lectures/intro.html)

* https://0xax.gitbooks.io/linux-insides/content/

* https://www.gnu.org/software/libc/

* https://tldp.org/LDP/tlk/mm/memory.html


## Books

**The Linux Programming Interface** \
Michael Kerrisk \
No Starch Press 2010 \
ISBN 978-1-59327-220-3

https://man7.org/tlpi/index.html

**Advanced Programming in the UNIX Environment, 3rd Edition**  \
W. Richard Stevens and Stephen A. Rago \
Addison-Wesley 2013 \
ISBN 978-0-321-63773-4 



