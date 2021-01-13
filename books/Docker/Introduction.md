---
title: Docker
mathjax: true
layout: default
toc: true
---


# Docker

Docker takes a logistical approach to solving common software problems and simplifies your experience with installing, running, publishing, and removing software. It’s a command-line program, a background daemon, and a set of remote services.




# Containers

You can think of a **Docker container** as a physical shipping container. It’s a box where you store and run an application and all of its dependencies. The component that fills the shipping container role is called an image.


```bash

docker exec -it <mycontainer> bash

# Run an image and remove it after exiting
docker run -it --rm erlang /bin/bash
# –interactive or -i option tells Docker to keep the standard input 
#   stream (stdin) open for the container even if no terminal is attached.
# –tty or -t option tells Docker to allocate a virtual terminal for the 
#   container, which will allow you to pass signals to the container.
# --rm remove the container once it has finished running
# To detach from the terminal you can press Ctrl+P+Q

# Install and start a container running NGINX.
docker run --detach --name web nginx:latest
# Detached (–detach or -d) means that the container will run in the background, 
#  without being attached to any input or output stream.


```

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
```


# Docker Images




## Building Docker Images

```dockerfile
FROM openjdk:8u141-jdk-slim

ENV SPRING_OUTPUT_ANSI_ENABLED=ALWAYS \
    JHIPSTER_SLEEP=0 \
    JAVA_OPTS=""

# add directly the jar
ADD *.jar /app.jar

EXPOSE 8080
CMD echo "The application will start in ${JHIPSTER_SLEEP}s..." && \
    sleep ${JHIPSTER_SLEEP} && \
    java ${JAVA_OPTS} -Djava.security.egd=file:/dev/./urandom -jar /app.jar
    

```

```dockerfile

# There are no big difference between ADD and COPY
# https://jhooq.com/docker-copy-vs-docker-add/
#  copy multiples files
COPY hello* /destination-dir/

```


```bash
docker build -t jmenga/todobacked-base .

# Verify the images has been successfully published and tagged on docker host
docker images

```

