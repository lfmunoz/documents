---
title: RESTful HTTP creates coupling
layout: page
---


Imagine your requirements for a design wasn't to support some RPC technology but instead it was support all RPC technologies. This may seem like a lot of unnecessary work to some, but I would say it takes similar effort to at least support the possibility and it follows the principle of **Design For Change**. I will pick a technology but at the same time I am also designing it like I'm going to change to another ( HTTP, gRPC, WebSocket, Kafka, AMPQ, STOMP, etc). When there is no coupling it doesn't make a difference how the data is arriving.

The problem is that technologies will tilt you into coupling your code. For example HTTP REST wants you to split your data into a header and body payload:

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

Data objects will often need the Id embedded into the object and other RPC technologies will not have this split. It is fine to make the decision that the application is going to use HTTP and that changing it will be a complete re-write but my point is this is often poor design. A better approach is to layer it like this:

```
HTTP Generic Packet -> MyAppDTO -> Application Code
GRPC Generic Packet -> MyAppDTO -> Application Code
Kafka Generic Packet -> MyAppDTO -> Application Code
```

Often, people see code layered like this and it doesn't look clean because:

* A) They have no experience in having gone through a re-write. For example I've had to refactor applications from RabbitMQ to KAFKA and from HTTP to WebSockets.
* B) They're used to seeing example code from all these projects doing what I am suggesting not to do. These programmers often don't write many applications using competing technologies. 

Looking at a typical gRPC designs you see:

```protobuf
// Naive implementation (beginner design)
service Greeter {
    // Sends a greeting
    rpc SayHello (HelloRequest) returns (HelloReply) {}
}

// Intermediate implementation decouples what objects you send
service GRPC {
    rpc grpc(RpcRequest) returns (RpcResponse) {}
}

// Advanced implementation additionally decouples serialization
service GRPC {
    rpc grpc(bytes) returns (bytes) {}
}
```

Many libraries will want you to register your serializer with their implementations or worse
specify a serializer for each object type. Avoid this feature, don't allow the frameworks to wrap their tentacles around your code. If you do it generically it will work with any library.

Let's look at Kafka, you will often see:


```java
// Naive implementation
props.setProperty("key.deserializer", "MyObjectSerializer"); // not generic  (coupled)
props.setProperty("value.deserializer", "MyKeySerializer"); // not generic (cohesion)
KafkaConsumer<MyAppObjectKey, MyAppObjectValue> consumer = new KafkaConsumer<>(props);

// Design for change implementation
props.setProperty("key.deserializer", "ByteArraySerializer"); // generic
props.setProperty("value.deserializer", "ByteArraySerializer");  // generic
KafkaConsumer<ByteArray, ByteArray>(props)
```

The naive implementations don't clearly separate out the applications objects from the input and output implementations. This means you cannot easily switch between them. If you simply create a intermediate object, there is hard separation. In Kafka this would look like this:

```kotlin
// Kafka specific intermediate container object
data class KafkaMessage (
    val key: ByteArray,
    val value: ByteArray,
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
    // domain object going to... it doesn't matter code will write itself
    fun toAnything() { } 
}
```

There is clear decoupling in the application. I use domain objects but when doing input/output/rpc I simply convert to a specific messages container that is technology specific. When testing I verify the consumer and producers work but only care that I can send and receive KafkaMessages, what is inside of those messages doesn't make a difference that is a different layer and a separate test. If I verify I can create a generic KafkaMessages out of my domain objects and I separately verify I can send KafkaMessage objects across the network then that is a verification for the full path, that is how managing complexity is done. 

Would you have Kafka tests for each topic? Why is that you see HTTP tests hitting every endpoint? With HTTP the container object looks something like this:

```kotlin
data class HttRequest(
    val method: String = "POST"
    val body: String = "some payload",
    val headers: String = "cookies, and tokens"
    val path: String = "/home/url/string"
)
```

This is implicit and hidden in many frameworks which causes coupling. If you were to use explicit container objects with clear separations then you get malleable, verifiable, and readable code. 

