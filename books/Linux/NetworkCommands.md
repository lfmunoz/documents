---
title: Network Commands
mathjax: true
layout: default
toc: true
---

# Network Commands

* [Linux](Introduction.html)
* [Commands](Commands.html)


## CURL

```bash
# Download with retries
curl ftp://server/dir/file[01-30].ext --user user:pass -O --retry 999 --retry-max-time 0 -C -
[01-30] will make it download 30 files named file01.ext, file02.ext and so on
--user user:pass should be obvious
-O to output to files with original name
--retry 999 to retry 999 times
--retry-max-time 0 to prevent it from timing out the retrys. The default behavior if you don't specify a fixed --retry-delay is to sleep first one second between retries, then doubling that, until it reaches 10 min. between retries
-C - to make it continue where it dropped of (if you run the command again). The dash afterwards tells it to figure out where to resume from

# POST JSON file 
curl -vX POST http://server/api/v1/places.json -d @testplace.json --header "Content-Type: application/json"

```



## netcat

```bash
# listen on port 2010
nc -l 2010

# connect to IP and port
nc 10.0.0.10 2010
```







## ufw

**UFW** - Uncomplicated Firewall is an interface to iptables that is geared towards simplifying the process of configuring a firewall.

```bash
# typical location of binary
which ufw
/usr/sbin/ufw

# check the version you are using
ufw version
ufw 0.35
Copyright 2008-2015 Canonical Ltd. 

# what is the status of the service
ufw status  
Status: inactive

# get more information
ufw status verbose

ufw show added
```



```bash
# To set the defaults used by UFW
ufw default deny incoming
ufw default allow outgoing
ufw allow 22
ufw enable 
```

**Note:** UFW knows what "ssh" is because it is listed in /etc/services

```bash
# Allow SSH, both commands do the same thing
ufw allow ssh
ufw allow 22
ufw allow http
sudo ufw allow 80
ufw allow https
ufw allow 443

# Allow Specific Port Ranges (must specify protocol)
ufw allow 6000:6007/tcp
ufw allow 6000:6007/udp

ufw allow from 15.15.15.0/24
ufw allow from 15.15.15.51
ufw allow from 15.15.15.0/24 to any port 873

# Deny connections
ufw deny from 15.15.15.51
# Specify a subnet instead
ufw deny from 15.15.15.0/24
```

Delete Rules 
```
ufw status numbered
ufw delete 2
ufw delete allow http
ufw reset
```

