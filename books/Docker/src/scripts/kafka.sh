

#________________________________________________________________________________
# Kafka
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


# VERIFIED

# ________________________________________________________________________________
# VARIABLES
# ________________________________________________________________________________
source ./infrastructure.bash

KAFKA_ADDR=$kafka_0
ZOOKEEPER_ADDR=$zookeeper_0

# ________________________________________________________________________________
# KAFKA BROKER
# ________________________________________________________________________________
docker run -d --rm --name kafka \
--network=host \
-e "KAFKA_BROKER_ID=1" \
-e "ADVERTISED_HOST_NAME=${KAFKA_ADDR}" \
-e "KAFKA_ADVERTISED_LISTENERS=PLAINTEXT://${KAFKA_ADDR}:9092" \
-e "KAFKA_ZOOKEEPER_CONNECT=${ZOOKEEPER_ADDR}:2181" \
-e "KAFKA_LISTENER_SECURITY_PROTOCOL_MAP=PLAINTEXT:PLAINTEXT,PLAINTEXT_HOST:PLAINTEXT" \
-e "KAFKA_INTER_BROKER_LISTENER_NAME=PLAINTEXT" \
confluentinc/cp-kafka:5.4.0

# ________________________________________________________________________________
# KAFKA UI
# ________________________________________________________________________________
docker run -d --rm -p 80:9000 \
-e KAFKA_BROKERCONNECT=${KAFKA_ADDR}:9092 \
-e JVM_OPTS="-Xms32M -Xmx64M" \
-e SERVER_SERVLET_CONTEXTPATH="/" \
obsidiandynamics/kafdrop
