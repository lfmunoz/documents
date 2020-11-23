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



