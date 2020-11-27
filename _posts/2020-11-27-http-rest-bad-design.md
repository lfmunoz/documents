---
title: RESTful HTTP creates coupling
layout: default
---


Imagine your requirements for a design wasn't to support some RPC technology but instead it was support all RPC technologies. This may seem like a lot of unnecessary work to some, but I would say it takes similar effort to at least support the possibility and it follows the principle of **Design For Change**. I will pick a technology but at the same time I am also designing it like I'm going to change to another ( HTTP, gRPC, WebSocket, Kafka, AMPQ, STOMP, etc). When there is no coupling it doesn't make a difference how the data is arriving.

The problem is that technologies will tilt you into coupling your code. For example HTTP REST wants you to split your data into a header and body payload.

```
DELETE /api/appSpecific/{id}
   +                      +
   |                      |
   |                      +-----+ http specific header causes 
   +----------------------------+  coupling and redundancy
{
  object payload...    
}
```

Data objects will often need the ID embedded into the object also other RPC technologies will not have this split. It is fine to make the decision that the application is going to use HTTP and changing it will be a complete re-write but point is that often this is poor design. A better approach is to layer it like this:

```
HTTP Generic Packet -> MyAppDTO -> Application Code
GRPC Generic Packet -> MyAppDTO -> Application Code
Kafka Generic Packet -> MyAppDTO -> Application Code
```

Often when people see code layed like this and it doesn't seem clean because:

* A) They have no experience in having gone through a re-write. For example I've had to refactor applications from RabbitMQ to KAFKA and from HTTP to WebSockets.
* B) They're used to seeing example code from all these projects doing what I am suggesting not to do. These programmers often don't write actual applications using competing technologies. 

Looking at typical gRPC designs you see:

```protobuf
// Naive implementation
service Greeter {
    // Sends a greeting
    rpc SayHello (HelloRequest) returns (HelloReply) {}
}

// Design for change implementation A
service GRPC {
    rpc grpc(RpcRequest) returns (RpcResponse) {}
}

// Design for change implementation B
service GRPC {
    rpc grpc(bytes) returns (bytes) {}
}
```

In Kafka designs you will often see 


```java
// Naive implementation
props.setProperty("key.deserializer", "MyObjectSerializer"); // not generic
props.setProperty("value.deserializer", "MyKeySerializer"); // not generic
KafkaConsumer<MyAppObjectKey, MyAppObjectValue> consumer = new KafkaConsumer<>(props);

// Design for change implementation
props.setProperty("key.deserializer", "ByteArraySerializer"); // generic
props.setProperty("value.deserializer", "ByteArraySerializer");  // generic
KafkaConsumer<ByteArray, ByteArray>(consumerProps(aKafkaConfig)
```

The naive implementations don't clearly separate out the applications objects from the input and output implementations. This means you cannot easily switch between them. If you simply create a intermediate object, there is hard separation. In Kafka this would look like this:

```kotlin
// Kafka specific intermediate container object
data class KafkaMessage (
    val key: ByteArray
    val value: ByteArray
    val headers: MutableMap<String, ByteArray>
)
```

```kotlin
data class SomeAppSpecificDomainObject(
    val id: String = "",
    val meataData: String = "",
    val created: Instant = Instant.now()
) {
    // domain object going to kafka
    fun toKafkaMessage() : KafkaMessage {
        val value = mapper.writeAsByteArray(this) 
        val key = this.id.toByteArray()
        return KafkaMessage(value, key)
    }
    // domain object going to gRpc
    fun toGrpcMessage() {}
    // domain object going to it doesn't matter code is all the same
    fun toAnything() { } }
```

When testing I only care that I can send and receive KafkaMessages, what is inside of those messages doesn't make a difference. There is clear decoupling, In my application I use domain objects when sending out I simply convert to a specific messages container depending out what technology I am going to use.






