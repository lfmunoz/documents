#!/usr/bin/env bash




############################################################################
# Zookepper
#################################################################
zoo-start:
        docker run -d --rm --name zookeeper -p 2181:2181 -p 2888:2888 -p 3888:3888 -p 8091:8080 --network=kafka_net -e "ZOO_4LW_COMMANDS_WHITELIST=*" zookeeper:3.5.5
        #docker run -d --rm --name zookeeper -p 2181:2181 -p 2888:2888 -p 3888:3888 -e "ZOO_4LW_COMMANDS_WHITELIST=*" zookeeper:3.5.5






   docker run -d --rm --name zkui -p 1090:9090 --network=kafka_net -e ZK_SERVER=zookeeper:2181 qnib/plain-zkui




#________________________________________________________________________________
# Zookepper
#  Public port 2181 2888 3888 8091  (2181 is cconnection port)
# IP: 172.18.0.6
#________________________________________________________________________________
zookeeper-start:
        -docker run -d --rm --name zookeeper-${RND} --network=${NETWORK} --network-alias=zooKeeperNet ${ZOOKEEPER_PORT} \
            -e "ZOO_4LW_COMMANDS_WHITELIST=*" \
            zookeeper:3.5.5

zookeeper-stop:
        -docker stop zookeeper-${RND}




