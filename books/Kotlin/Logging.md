---
title: Logging
mathjax: true
layout: default
toc: true
---


# Logging


* [The Java Programming Language](Introduction.html)


```
#File: log4j.properties

# Root logger option
log4j.rootLogger=INFO, stdout

# Direct log messages to stdout
log4j.appender.stdout=org.apache.log4j.ConsoleAppender
log4j.appender.stdout.Target=System.out
log4j.appender.stdout.layout=org.apache.log4j.PatternLayout
log4j.appender.stdout.layout.ConversionPattern=%d{HH:mm:ss.SSS}[%-5p][%thread][%c{36}:%L] - %m%n

log4j.logger.akka=INFO
log4j.logger.org.apache.kafka=INFO
```

```
<configuration>

  <appender name="STDOUT" class="ch.qos.logback.core.ConsoleAppender">
    <!-- encoders are assigned the type
         ch.qos.logback.classic.encoder.PatternLayoutEncoder by default -->
    <encoder>
      <pattern>%d{HH:mm:ss.SSS} [%thread] %-5level %logger{36} - %msg%n</pattern>
    </encoder>
  </appender>

  <logger name="org.apache.flink.runtime.jobgraph.JobGraph" level="DEBUG"/>

  <root level="debug">
    <appender-ref ref="STDOUT" />
  </root>
</configuration>
```

```
slf4jVersion=1.7.30
slf4jFluentVersion=0.13.3

val slf4jFluentVersion: String by project
val logbackClassicVersion: String by project

// LOGGING
implementation("org.fissore:slf4j-fluent:$slf4jFluentVersion")

```


```



val log = FluentLoggerFactory.getLogger(KafkaPublisherImpl::class.java)
log.info().log("Starting GenericKafkaFlinkJob...")
log.info().log("[Configuration] - $config")
```

```java

import org.fissore.slf4j.FluentLogger;
import org.fissore.slf4j.FluentLoggerFactory;

private static FluentLogger log = FluentLoggerFactory.getLogger("ConvertService");

  log.debug().log("parse_keyword " + it.current());
```