
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

kafka-ui:
	docker run -d --rm -p 9000:9000 \
    	-e KAFKA_BROKERCONNECT=localhost:9092 \
    	-e JVM_OPTS="-Xms32M -Xmx64M" \
    	-e SERVER_SERVLET_CONTEXTPATH="/" \
    	obsidiandynamics/kafdrop





#________________________________________________________________________________
# Grafana / Prometheus
#  Prometheus exposes 9090
#  Grafana exposes 3000
#________________________________________________________________________________
grafana-start:
	docker run -d --rm --name grafana --network=${NETWORK} -p 3000:3000 grafana/grafana



prometheus-start:
	docker run -d --rm --name prometheus --network=${NETWORK} -p 9090:9090 -v ~/prometheus.yml:/etc/prometheus/prometheus.yml prom/prometheus



	docker run -d --rm --name prometheus --network=host -v ~/prometheus.yml:/etc/prometheus/prometheus.yml prom/prometheus




# Sample global config for monitoring JHipster applications
global:
  scrape_interval: 15s # By default, scrape targets every 15 seconds.
  evaluation_interval: 15s # By default, scrape targets every 15 seconds.
  # scrape_timeout is set to the global default (10s).

  # Attach these labels to any time series or alerts when communicating with
  # external systems (federation, remote storage, Alertmanager).
  external_labels:
    monitor: 'jhipster'

# A scrape configuration containing exactly one endpoint to scrape:
# Here it's Prometheus itself.
scrape_configs:
  # The job name is added as a label `job=<job_name>` to any timeseries scraped from this config.
  - job_name: 'prometheus'

    # Override the global default and scrape targets from this job every 5 seconds.
    scrape_interval: 5s

    # scheme defaults to 'http'.
    metrics_path: /management/prometheus
    static_configs:
      - targets:
          # On MacOS, replace localhost by host.docker.internal
          - localhost:8080





global:
  scrape_interval:     15s # Set the scrape interval to every 15 seconds. Default is every 1 minute.
  evaluation_interval: 15s # Evaluate rules every 15 seconds. The default is every 1 minute.

# A scrape configuration containing exactly one endpoint to scrape:
# # Here it's Prometheus itself.
scrape_configs:
  # The job name is added as a label `job=<job_name>` to any timeseries scraped from this config.
  - job_name: 'cwmp-simulators'
    consul_sd_configs:
      - server: 'oc112-16.maas.auslab.2wire.com:8500'
        services: ['cwmp-simulator']
    metrics_path: '/actuator/prometheus'
    params:
      format: ['prometheus']
      honor_labels: [true]





https://github.com/prometheus-community/windows_exporter/blob/master/docs/collector.textfile.md


The directory containing the files to be ingested. Only files with the extension .prom are read. The .prom file must end with an empty line feed to work properly.


--collector.textfile.directory



https://github.com/prometheus/node_exporter


https://github.com/prometheus/node_exporter


textfile	Exposes statistics read from local disk. The --collector.textfile.directory flag must be set.	any





To use it, set the --collector.textfile.directory flag on the node_exporter commandline. The collector will parse all files in that directory matching the glob *.prom


docker run -d \
  --net="host" \
  --pid="host" \
  -v "/:/host:ro,rslave" \
  quay.io/prometheus/node-exporter:latest \
  --path.rootfs=/host

The node_exporter will use path.rootfs as prefix to access host filesystem.
