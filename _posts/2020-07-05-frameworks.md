---
title: Frameworks and Libraries
layout: page
---

<span class="intro">Should Frameworks and Libraries be avoided or embraced? </span> Obviously I can't give you an absolute answer, but there are guidelines, rules and code smells that will separate a well structured system from a kludge.

Once upon a time I thought, “Wow, everything has already been written. There is a library for that, let me just download it and use it. All I have to do is just stitch it together. Most programming is just about finding the right framework or library.”

Unfortunately it's more complicated than that. That sort of thinking will lead to overly embracing frameworks which leads to having overly complicated code,  performance problems and extra refactorings. Professional programmers always use frameworks and libraries with caution. Here are some guidelines:

>  If a framework has a feature that doesn't mean you should be using it. More likely you should be avoiding it.

For example, with _Spring Boot_ you get dependency injection. Often in such projects I see dependency injection abused, meaning used everywhere even when it would be just as easy to pass in arguments that aren't _@Autowired_. Proper use of dependecy injection means using it at strategic boundaries where you end up with isolated subsystems that can be easily swapped.

The intermediate programmers thinks she understands that coupling is bad but often she hasn't taken the concept far enough. Coupling also means using a feature from a third party library and therefore using it only when necessary will keep coupling low. Keeping coupling low creates boundaries of seperation and allows the code to be more malleable.  Malleability is important becomes it means adding a feature or making a modification will be feasible with minimum effort.

>   If you think you can do it in one day do it . Even after you figure out it will take you three days.

 For example, if you need to communicate with _RabbitMQ_, _Kafka_ or _ElasticSearch_  most programmers would reach for _Spring Boot_ (i.e., _"org.springframework.kafka:spring-kafka"_) or some other  library which is just wrapper code around the already good libraries provided by the implementation developers (i.e., _"org.apache.kafka:kafka-clients"_). This rule says that if you think you can get the same required functionality by using a lower-level library absoutely do it. The lower-level libraries have better code quality, performance and stability.  The lower-libraries are written by domain experts the framework wrappers are written by competent programmers who read through the documnetation of the lower-libraries.
 
To understand this fully look through this issue: [FLINK-10195](https://issues.apache.org/jira/browse/FLINK-10195).  Note one of the _Apache Flink_ developers  says, "Although this has been very much a crash course in _RabbitMQ_ for me.  Looking at forums it looks like the prefetch.count is the way that this is handled normally." Most of these framework wrappers are written for the intermediate programmer. Instead of dealing with simliar issues to _FLINK-10195_ consider how long it will take you to rollout your own _RabbitMQ_ connector and do it:  [RabbitConsumerBare.kt](https://gist.github.com/lfmunoz/c7922382a13e2c576ff77b3b9f3f99ae). 
  
Intermediate programmers go for the wrapper libraries  and violate this rule because they don't trust their own abilities. Often they will  justify it by  telling themselves that they are  saving time which  is due to the false sense of productivity that you will get  in the beginning stages. If the application is going to live through a few years and multiple versions that initial productivity will become irrelevant. It will quickly be over shadowed by the tentacles and complexity the framework coupling has created. 


>  Separate your code from the library, replacing the library should be not be a re-write.


Here is a common scenario:  You  have a _Spring Boot_ Application and you start using _Spring Boot AMQP_. You just added the _Gradle_ dependency and start putting annotations. You go read the documentation to understand the configuration settings and for the most part is just works.  You feel productive. Later you realize the way they are using channels and connections to _RabbitMQ_ isn't as efficient as it can be. It also is blocking and you want something asynchronous. It is also not efficiently managing threads. This is the price to pay for productivity you say. Your application becomes popular and you find yourself having to remove _RabbitMQ_ completely because you realize that _RSocket_ would give you more bandwidth and lower latency. Now you come face-to-face with a months worth re-writing code. Even then how poorly seperated the business logic from the framework is overlooked. 

When an application is correctly structured changing from _RabbitMQ_ to _RSocket_ is straightfoward, satisfiying, everything falls into place and there is a feeling that it is writing itself.  Professional programmers learn this by doing a couple major refactors and they reflect back and realize that the lastest and greatest framework a year later is obselete and must be replaced with a newer framework. When using a framework or library write code asking what if I use a different library or framework how much of my code must be re-written, what files must be changed? This will guide you in making better choices.





 












