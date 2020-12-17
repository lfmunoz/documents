---
title: Docker
mathjax: true
layout: default
toc: true
---

Docker




https://docs.docker.com/config/daemon/

```bash
dockerd --debug \
  --tls=true \
  --tlscert=/var/docker/server.pem \
  --tlskey=/var/docker/serverkey.pem \
  --host tcp://192.168.59.3:2376

nohup dockerd -s vfs &

```


```
docker run -d --name bmweb \
    # <host file or dir>:<container file or dir>
    -v ~/projects/docker/example-docs:/usr/share/nginx/html:ro \
    # <hostPort>:<containerPort>
    -p 80:80 \
    nginx:latest
``






