---
title: Linux
mathjax: true
layout: default
toc: true
---



# man pages

[Linux](Introduction.html)

* man pages are split into:
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



