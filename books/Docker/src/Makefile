
#________________________________________________________________________________
# DEFAULT
#________________________________________________________________________________
.PHONY: default

USER = $(shell whoami)
USER_ID = $(shell id -u ${USER})
GROUP_ID = $(shell id -g ${USER})
DIR = ${CURDIR}
RND ?= 123
NETWORK=berthaNet
GIT_HASH=$(shell git rev-parse --short HEAD)

CONSUL_PORT ?= -p 8500:8500
FB_PORT ?= -p 4500:4500

default:
	@echo "[DEFAULT]"
	@echo ${GIT_HASH}
	java -version
	./gradlew -version



#________________________________________________________________________________
# CONSUL
# PUBLIC 8500
#________________________________________________________________________________
consul-start:
	-docker run -d --rm --name consul ${CONSUL_PORT} --network-alias=consulNet \
	    consul:1.7.3 agent -dev -client=0.0.0.0
consul-stop:
	-docker stop consul


#________________________________________________________________________________
# RabbitMQ
# #  Public port 5672  15672
#________________________________________________________________________________
rabbit-start:
	docker run --name rabbitmq --rm -p 5672:5672 -p 15672:15672 -d rabbitmq:3.7.2-management

rabbit-stop:
	docker stop rabbitmq


#________________________________________________________________________________
# Zookepper
#  Public port 2181 2888 3888 8091  (2181 is cconnection port)
#  Public port
# IP: 172.18.0.6
#________________________________________________________________________________
zookeeper-start:
	-docker run -d --rm --name zookeeper-${RND} --network=${NETWORK} --network-alias=zooKeeperNet ${ZOOKEEPER_PORT} \
	    -e "ZOO_4LW_COMMANDS_WHITELIST=*" \
	    zookeeper:3.5.5

zookeeper-stop:
	-docker stop zookeeper-${RND}


#________________________________________________________________________________
# Kafka (version = 2.12-2.4.0)
#  Public port 9092 (bootstrapServer)
# IP: 172.18.0.8
#________________________________________________________________________________
kafka-start:
	-docker run -d --rm --name kafka-${RND} --network=${NETWORK} ${KAFKA_PORT} --network-alias=kafkaNet \
	    -e "ADVERTISED_HOST_NAME=${KAFKA_IP}" \
	    -e "ZOOKEEPER_CONNECT=zookeeper-${RND}:2181" \
	    debezium/kafka:1.0

kafka-stop:
	-docker stop kafka-${RND}

