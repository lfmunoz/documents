#!/usr/bin/env bash


#  -p 8500:8500 -p 8300:8300 -p 8600:8600

docker run -d --rm --name consul \
--network=host \
consul:1.8.4 agent -dev -client=0.0.0.0

#	-docker run -d --rm --name consul-loader \
#        --network=${NETWORK} \
#        -v ${PWD}/central-server-config:/config \
#        -e "INIT_SLEEP_SECONDS=5" \
#        -e "CONSUL_URL=consul" \
#        -e "CONSUL_PORT=8500" \
#	    jhipster/consul-config-loader:v0.3.0 
