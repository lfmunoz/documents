

#________________________________________________________________________________
#  FLINK
#  PUBLIC
#   http://localhost:8081
#
#  PRIVATE
#   JobManager RPC port 6123
#   TaskManagers RPC port 6122
#   TaskManagers Data port 6121
#________________________________________________________________________________
FLINK_OFFICIAL_IMAGE=flink:1.8.2-scala_2.12
FLINK_JOB_JAR=flink-job.jar
FLINK_HOSTNAME=localhost:8081

flink-start:
         docker run --rm -d --name jobmanager-${RND} --network=${NETWORK} --network-alias=jobNet ${FLINK_PORTS} -p 9249:9249 \
                -e JOB_MANAGER_RPC_ADDRESS=jobNet \
                -v /home/centos/flink/flink-conf.yaml:/opt/flink/conf/flink-conf.yaml \
                -v /home/centos/flink/log4j-console.properties:/opt/flink/conf/log4j-console.properties \
                -v /home/centos/flink/flink-metrics-prometheus-1.8.2.jar:/opt/flink/lib/flink-metrics-prometheus-1.8.2.jar \
                ${FLINK_OFFICIAL_IMAGE} jobmanager
         docker run --rm -d --name taskmanager_0-${RND} --network=${NETWORK}  --network-alias=task0Net -p 9250:9249 \
                -e JOB_MANAGER_RPC_ADDRESS=jobNet \
                -v /home/centos/flink/log4j-console.properties:/opt/flink/conf/log4j-console.properties \
                -v /home/centos/flink/flink-conf.yaml:/opt/flink/conf/flink-conf.yaml \
                -v /home/centos/flink/flink-metrics-prometheus-1.8.2.jar:/opt/flink/lib/flink-metrics-prometheus-1.8.2.jar \
                ${FLINK_OFFICIAL_IMAGE} taskmanager
         docker run --rm -d --name taskmanager_1-${RND} --network=${NETWORK}  --network-alias=task1Net -p 9251:9249 \
                -e JOB_MANAGER_RPC_ADDRESS=jobNet \
                -v /home/centos/flink/log4j-console.properties:/opt/flink/conf/log4j-console.properties \
                -v /home/centos/flink/flink-conf.yaml:/opt/flink/conf/flink-conf.yaml \
                -v /home/centos/flink/flink-metrics-prometheus-1.8.2.jar:/opt/flink/lib/flink-metrics-prometheus-1.8.2.jar \
                ${FLINK_OFFICIAL_IMAGE} taskmanager


flink-stop:
         docker stop jobmanager-${RND}
         docker stop taskmanager_0-${RND}
         docker stop taskmanager_1-${RND}

flink-attach:
         docker exec -it jobmanager bash

# https://github.com/apache/flink/pull/3722/files
flink-upload:
         curl -X POST -H "Expect:" -F "jarfile=${FLINK_JOB_JAR}" http://${FLINK_HOSTNAME}/jars/upload






# ____________________________________________________________________________
#  DEPLOY
#________________________________________________________________________________
upload:
        # FLINK / RABBIT
        # bvt = rabbit / flink (10.37.120.52)
        scp /home/luis/bitbucket/eco-data-pipeline/rabbit-kafka-bridge/Makefile bvt:~/flink/
        # KAFKA
        # elastic = kafka (10.37.120.197)
        scp /home/luis/bitbucket/eco-data-pipeline/rabbit-kafka-bridge/Makefile elastic:~/flink/
















 cat log4j-console.properties 
log4j.rootLogger=INFO, console, file
# Uncomment this if you want to _only_ change Flink's logging
#log4j.logger.org.apache.flink=INFO
# The following lines keep the log level of common libraries/connectors on
# log level INFO. The root logger does not override this. You have to manually
# change the log levels here.
log4j.logger.akka=INFO
log4j.logger.org.apache.kafka=INFO
log4j.logger.org.apache.hadoop=INFO
log4j.logger.org.apache.zookeeper=INFO
# Log all infos to the console
log4j.appender.console=org.apache.log4j.ConsoleAppender
log4j.appender.console.layout=org.apache.log4j.PatternLayout
log4j.appender.console.layout.ConversionPattern=%d{yyyy-MM-dd HH:mm:ss,SSS} %-5p %-60c %x - %m%n
# Log all INFOs to the given rolling file
log4j.appender.file=org.apache.log4j.RollingFileAppender
log4j.appender.file.file=/opt/flink/log/output.log
log4j.appender.file.MaxFileSize=5MB
log4j.appender.file.MaxBackupIndex=5
log4j.appender.file.append=true
log4j.appender.file.layout=org.apache.log4j.PatternLayout
log4j.appender.file.layout.ConversionPattern=%d{yyyy-MM-dd HH:mm:ss,SSS} %-5p %-60c %x - %m%n
# Suppress the irrelevant (wrong) warnings from the Netty channel handler
log4j.logger.org.apache.flink.shaded.akka.org.jboss.netty.channel.DefaultChannelPipeline=ERROR, console, file





                                                                                                                                                                                 
#CUSTOM PROPERTIES                                                                                                                                                               
web.log.path: /opt/flink/log/output.log                                                                                                                                          
taskmanager.log.path: /opt/flink/log/output.log                                                                                                                                  
                                                                                                                                                                                 
metrics.reporter.prom.class: org.apache.flink.metrics.prometheus.PrometheusReporter                                                                                              
        
#==============================================================================                                                                                                  
# Common                                                                                                                                                                         
#==============================================================================

# The external address of the host on which the JobManager runs and can be
# reached by the TaskManagers and any clients which want to connect. This setting
# is only used in Standalone mode and may be overwritten on the JobManager side
# by specifying the --host <hostname> parameter of the bin/jobmanager.sh executable.
# In high availability mode, if you use the bin/start-cluster.sh script and setup
# the conf/masters file, this will be taken care of automatically. Yarn/Mesos
# automatically configure the host name based on the hostname of the node where the
# JobManager runs.

jobmanager.rpc.address: jobNet

# The RPC port where the JobManager is reachable.

jobmanager.rpc.port: 6123


# The heap size for the JobManager JVM

jobmanager.heap.size: 2048m


# The heap size for the TaskManager JVM

taskmanager.heap.size: 4096m


# The number of task slots that each TaskManager offers. Each slot runs one parallel pipeline.

taskmanager.numberOfTaskSlots: 24

# The parallelism used for programs that did not specify and other parallelism.

parallelism.default: 1

# The default file system scheme and authority.
#
# By default file paths without scheme are interpreted relative to the local
# root file system 'file:///'. Use this to override the default and interpret
# relative paths relative to a different file system,
# for example 'hdfs://mynamenode:12345'
#
# fs.default-scheme



#==============================================================================
# High Availability
#==============================================================================

# The high-availability mode. Possible options are 'NONE' or 'zookeeper'.
#
# high-availability: zookeeper

# The path where metadata for master recovery is persisted. While ZooKeeper stores
# the small ground truth for checkpoint and leader election, this location stores
# the larger objects, like persisted dataflow graphs.
#
# Must be a durable file system that is accessible from all nodes
# (like HDFS, S3, Ceph, nfs, ...)
#
# high-availability.storageDir: hdfs:///flink/ha/

# The list of ZooKeeper quorum peers that coordinate the high-availability
# setup. This must be a list of the form:
# "host1:clientPort,host2:clientPort,..." (default clientPort: 2181)
#
# high-availability.zookeeper.quorum: localhost:2181


# ACL options are based on https://zookeeper.apache.org/doc/r3.1.2/zookeeperProgrammers.html#sc_BuiltinACLSchemes
# It can be either "creator" (ZOO_CREATE_ALL_ACL) or "open" (ZOO_OPEN_ACL_UNSAFE)
# The default value is "open" and it can be changed to "creator" if ZK security is enabled
#
# high-availability.zookeeper.client.acl: open
#==============================================================================
# Fault tolerance and checkpointing
#==============================================================================

# The backend that will be used to store operator state checkpoints if
# checkpointing is enabled.
#
# Supported backends are 'jobmanager', 'filesystem', 'rocksdb', or the
# <class-name-of-factory>.
#
# state.backend: filesystem

# Directory for checkpoints filesystem, when using any of the default bundled
# state backends.
#
# state.checkpoints.dir: hdfs://namenode-host:port/flink-checkpoints

# Default target directory for savepoints, optional.
#
# state.savepoints.dir: hdfs://namenode-host:port/flink-checkpoints

# Flag to enable/disable incremental checkpoints for backends that
# support incremental checkpoints (like the RocksDB state backend).
#
# state.backend.incremental: false
#==============================================================================
# Rest & web frontend
#==============================================================================

# The port to which the REST client connects to. If rest.bind-port has
# not been specified, then the server will bind to this port as well.
#
#rest.port: 8081

# The address to which the REST client will connect to
#
#rest.address: 0.0.0.0

# Port range for the REST and web server to bind to.
#
#rest.bind-port: 8080-8090

# The address that the REST & web server binds to
#
#rest.bind-address: 0.0.0.0

# Flag to specify whether job submission is enabled from the web-based
# runtime monitor. Uncomment to disable.

#web.submit.enable: false

#==============================================================================
# Advanced
#==============================================================================

# Override the directories for temporary files. If not specified, the
# system-specific Java temporary directory (java.io.tmpdir property) is taken.
#
# For framework setups on Yarn or Mesos, Flink will automatically pick up the
# containers' temp directories without any need for configuration.
#
# Add a delimited list for multiple directories, using the system directory
# delimiter (colon ':' on unix) or a comma, e.g.:
#     /data1/tmp:/data2/tmp:/data3/tmp
#
# Note: Each directory entry is read from and written to by a different I/O
# thread. You can include the same directory multiple times in order to create
# multiple I/O threads against that directory. This is for example relevant for
# high-throughput RAIDs.
#
# io.tmp.dirs: /tmp

# Specify whether TaskManager's managed memory should be allocated when starting
# up (true) or when memory is requested.
#
# We recommend to set this value to 'true' only in setups for pure batch
# processing (DataSet API). Streaming setups currently do not use the TaskManager's
# managed memory: The 'rocksdb' state backend uses RocksDB's own memory management,
# while the 'memory' and 'filesystem' backends explicitly keep data as objects
# to save on serialization cost.
#
# taskmanager.memory.preallocate: false

# The classloading resolve order. Possible values are 'child-first' (Flink's default)
# and 'parent-first' (Java's default).
#
# Child first classloading allows users to use different dependency/library
# versions in their application than those in the classpath. Switching back
# to 'parent-first' may help with debugging dependency issues.
#
# classloader.resolve-order: child-first

# The amount of memory going to the network stack. These numbers usually need
# no tuning. Adjusting them may be necessary in case of an "Insufficient number
# of network buffers" error. The default min is 64MB, the default max is 1GB.
#
# taskmanager.network.memory.fraction: 0.1
# taskmanager.network.memory.min: 64mb
# taskmanager.network.memory.max: 1gb


#==============================================================================
# Flink Cluster Security Configuration
#==============================================================================

# Kerberos authentication for various components - Hadoop, ZooKeeper, and connectors -
# may be enabled in four steps:
# 1. configure the local krb5.conf file
# 2. provide Kerberos credentials (either a keytab or a ticket cache w/ kinit)
# 3. make the credentials available to various JAAS login contexts
# 4. configure the connector to use JAAS/SASL

# The below configure how Kerberos credentials are provided. A keytab will be used instead of
# a ticket cache if the keytab path and principal are set.

# security.kerberos.login.use-ticket-cache: true
# security.kerberos.login.keytab: /path/to/kerberos/keytab
# security.kerberos.login.principal: flink-user

# The configuration below defines which JAAS login contexts

# security.kerberos.login.contexts: Client,KafkaClient

#==============================================================================
# ZK Security Configuration
#==============================================================================

# Below configurations are applicable if ZK ensemble is configured for security

# Override below configuration to provide custom ZK service name if configured
# zookeeper.sasl.service-name: zookeeper

# The configuration below must match one of the values set in "security.kerberos.login.contexts"
# zookeeper.sasl.login-context-name: Client

#==============================================================================
# HistoryServer
#==============================================================================

# The HistoryServer is started and stopped via bin/historyserver.sh (start|stop)

# Directory to upload completed jobs to. Add this directory to the list of
# monitored directories of the HistoryServer as well (see below).
#jobmanager.archive.fs.dir: hdfs:///completed-jobs/

# The address under which the web-based HistoryServer listens.
#historyserver.web.address: 0.0.0.0

# The port under which the web-based HistoryServer listens.
#historyserver.web.port: 8082

# Comma separated list of directories to monitor for completed jobs.
#historyserver.archive.fs.dir: hdfs:///completed-jobs/

# Interval in milliseconds for refreshing the monitored directories.
#historyserver.archive.fs.refresh-interval: 10000

blob.server.port: 6124
query.server.port: 6125



