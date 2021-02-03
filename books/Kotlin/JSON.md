





```kotlin
val jacksonVersion =  "2.10.3"

//JSON
implementation( "com.fasterxml.jackson.module:jackson-module-kotlin:$jacksonVersion")

implementation( "com.fasterxml.jackson.core:jackson-core:2.12.0")

Let's first add the following dependencies to the pom.xml:

<dependency>
    <groupId>com.fasterxml.jackson.core</groupId>
    <artifactId>jackson-databind</artifactId>
    <version>2.11.1</version>
</dependency>
This dependency will also transitively add the following libraries to the classpath:

jackson-annotations
jackson-core

```