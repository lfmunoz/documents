#!/usr/bin/env bash

# VERIFIED

mkdir -p $PWD/tank-redis/

cat << EOF > $PWD/tank-redis/tank-redis.conf
port 6379
cluster-enabled yes
#cluster-config-file nodes.conf
cluster-node-timeout 5000
#dir /opt/pace/tankdata
hash-max-ziplist-value 10240
daemonize no
#pidfile /opt/pace/tankRedis/redis.pid
#logfile /opt/pace/tankRedis/logs/redis.log
#Optional socket connection
#unixsocket "/tmp/redis.sock"
#unixsocketperm 777

#save 900 1
#save 300 10
#save 60 10000

# maxmemory <bytes>

appendonly no
#To serve data if slots are down. Not tested
# cluster-require-full-coverage yes

EOF

#  -p 6379:6379 

docker run --name redis --rm -d \
--network=host \
-v $PWD/tank-redis:/usr/local/etc/redis/ \
redis:5.0.5 redis-server /usr/local/etc/redis/tank-redis.conf

sleep 5

docker exec -it redis /bin/sh -c "seq 0 16383 | xargs -n 500 redis-cli cluster addslots"

