#!/usr/bin/env bash


docker run -d --rm --name zookeeper \
--network=host \
-e ZOOKEEPER_CLIENT_PORT=2181 \
-e ZOOKEEPER_TICK_TIME=2000 \
confluentinc/cp-zookeeper:5.4.0

