#!/usr/bin/env bash



# -p 8081:80

docker run --name nginx --rm -d --network=host nginx

