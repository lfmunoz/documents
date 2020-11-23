---
title: Testing
mathjax: true
layout: default
toc: true
---


# Testing

* [The Kotlin Programming Language](Introduction.html)



## Gradle KTS Configuration

```kotlin
val guavaVersion = 29.0-jre
val jacksonVersion = 2.11.2
val slf4jVersion = 1.7.30
val slf4jFluentVersion = 0.13.3
val kotlinVersion = 1.4.0
val kotlinCoroutinesVersion = 1.4.0-M1


val awaitilityVersion = 4.0.3
testImplementation("org.awaitility:awaitility:2.0.0")
testImplementation("org.awaitility:awaitility-kotlin:4.0.1")

val assertJVersion = "3.18.1"
testImplementation("org.assertj:assertj-core:$assertJVersion")


val junitVersion = 5.6.2
testImplementation("org.junit.jupiter:junit-jupiter-api:$junitVersion")
testRuntimeOnly("org.junit.jupiter:junit-jupiter-engine:$junitVersion")
```


## Skeleton


```kotlin
import org.assertj.core.api.Assertions.assertThat
import org.assertj.core.api.Assertions.assertThatThrownBy
import org.junit.jupiter.api.Test
import java.lang.NullPointerException

internal class MappingTraversalKtTest {

    @Test
    fun `should traverse the mapping tree and collect non-empty mappings in a list`() {
        val mapping = load("traversal").modelMapping()
        val result = collectMappings(mapping)

        assertThat(result).hasSize(3)
    }
}
```

