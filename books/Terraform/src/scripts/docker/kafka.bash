#!/usr/bin/env bash


KAFKA_ADDR=localhost
ZOOKEEPER_ADDR=zookeeper

docker run -d --rm --name kafka \
--network=host \
-e "KAFKA_BROKER_ID=1" \
-e "ADVERTISED_HOST_NAME=localhost" \
-e "KAFKA_ADVERTISED_LISTENERS=PLAINTEXT://localhost:9092" \
-e "KAFKA_ZOOKEEPER_CONNECT=zookeeper:2181" \
-e "KAFKA_LISTENER_SECURITY_PROTOCOL_MAP=PLAINTEXT:PLAINTEXT,PLAINTEXT_HOST:PLAINTEXT" \
-e "KAFKA_INTER_BROKER_LISTENER_NAME=PLAINTEXT" \
confluentinc/cp-kafka:5.4.0

