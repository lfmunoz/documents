#!/usr/bin/env bash



#  -p 8500:8500 -p 8300:8300 -p 8600:8600

docker run -d --rm --name rabbitmq \
--network=host \
rabbitmq:3.8.9-management

