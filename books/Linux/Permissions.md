---
title: Permissions
mathjax: true
layout: default
toc: true
---



# Permissions

[Linux](Introduction.html)


## Users and Groups

**/etc/passwd**  contains one line for each user account on the system. 

```bash
# Each line is composed of seven fields separated by colons ( : )
cat /etc/passwd 
root:x:0:0:root:/root:/bin/bash
daemon:x:1:1:daemon:/usr/sbin:/usr/sbin/nologin
bin:x:2:2:bin:/bin:/usr/sbin/nologin
sys:x:3:3:sys:/dev:/usr/sbin/nologin
sync:x:4:65534:sync:/bin:/bin/sync
games:x:5:60:games:/usr/games:/usr/sbin/nologin
man:x:6:12:man:/var/cache/man:/usr/sbin/nologin
lp:x:7:7:lp:/var/spool/lpd:/usr/sbin/nologin
mail:x:8:8:mail:/var/mail:/usr/sbin/nologin
news:x:9:9:news:/var/spool/news:/usr/sbin/nologin
uucp:x:10:10:uucp:/var/spool/uucp:/usr/sbin/nologin
proxy:x:13:13:proxy:/bin:/usr/sbin/nologin
www-data:x:33:33:www-data:/var/www:/usr/sbin/nologin
backup:x:34:34:backup:/var/backups:/usr/sbin/nologin
list:x:38:38:Mailing List Manager:/var/list:/usr/sbin/nologin
irc:x:39:39:ircd:/var/run/ircd:/usr/sbin/nologin
gnats:x:41:41:Gnats Bug-Reporting System (admin):/var/lib/gnats:/usr/sbin/nologin
nobody:x:65534:65534:nobody:/nonexistent:/usr/sbin/nologin
_apt:x:100:65534::/nonexistent:/usr/sbin/nologin
systemd-timesync:x:101:101:systemd Time Synchronization,,,:/run/systemd:/usr/sbin/nologin
systemd-network:x:102:103:systemd Network Management,,,:/run/systemd:/usr/sbin/nologin
systemd-resolve:x:103:104:systemd Resolver,,,:/run/systemd:/usr/sbin/nologin
messagebus:x:104:105::/nonexistent:/usr/sbin/nologin
sshd:x:105:65534::/run/sshd:/usr/sbin/nologin
```

```
cat /etc/shadow
root:$6$PCN10PSIYZH8ciji$vOZj3SEnB0dT8agKPrlKTT1WWXlpj5TvTSlQazyHIG/FVB3dAsh2GKV96rBEUEQnnRn8uUsWzZKJwQxP/mlbY0:18600:0:99999:7:::
daemon:*:18572:0:99999:7:::
bin:*:18572:0:99999:7:::
sys:*:18572:0:99999:7:::
sync:*:18572:0:99999:7:::
games:*:18572:0:99999:7:::
man:*:18572:0:99999:7:::
lp:*:18572:0:99999:7:::
mail:*:18572:0:99999:7:::
news:*:18572:0:99999:7:::
uucp:*:18572:0:99999:7:::
proxy:*:18572:0:99999:7:::
www-data:*:18572:0:99999:7:::
backup:*:18572:0:99999:7:::
list:*:18572:0:99999:7:::
irc:*:18572:0:99999:7:::
gnats:*:18572:0:99999:7:::
nobody:*:18572:0:99999:7:::
_apt:*:18572:0:99999:7:::
systemd-timesync:*:18600:0:99999:7:::
systemd-network:*:18600:0:99999:7:::
systemd-resolve:*:18600:0:99999:7:::
messagebus:*:18600:0:99999:7:::
sshd:*:18600:0:99999:7:::
```

```bash
cat /etc/group
root:x:0:
daemon:x:1:
bin:x:2:
sys:x:3:
adm:x:4:
tty:x:5:
disk:x:6:
lp:x:7:
mail:x:8:
news:x:9:
uucp:x:10:
man:x:12:
proxy:x:13:
kmem:x:15:
dialout:x:20:
fax:x:21:
voice:x:22:
cdrom:x:24:
floppy:x:25:
tape:x:26:
sudo:x:27:
audio:x:29:
dip:x:30:
www-data:x:33:
backup:x:34:
operator:x:37:
list:x:38:
irc:x:39:
src:x:40:
gnats:x:41:
shadow:x:42:
utmp:x:43:
video:x:44:
sasl:x:45:
plugdev:x:46:
staff:x:50:
games:x:60:
users:x:100:
nogroup:x:65534:
systemd-timesync:x:101:
systemd-journal:x:102:
systemd-network:x:103:
systemd-resolve:x:104:
messagebus:x:105:
ssh:x:106:
docker:x:999:
```


```c
#include <pwd.h>
struct passwd *getpwnam(const char * name );
struct passwd *getpwuid(uid_t uid );
// Both return a pointer on success, or NULL on error

#define _XOPEN_SOURCE
#include <unistd.h>
char *crypt(const char * key , const char * salt );
// Returns pointer to statically allocated string containing
//  encrypted password on success, or NULL on error
```


## File Permissions


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
