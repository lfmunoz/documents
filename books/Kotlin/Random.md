---
title: Random
mathjax: true
layout: default
toc: true
---


# Random


* [The Kotlin Programming Language](Introduction.html)





```kotlin

fun getRandomString(length: Int) : String {
    val allowedChars = ('A'..'Z') + ('a'..'z') + ('1'..'9')
    return (1..length)
        .map { allowedChars.random() }
        .joinToString("")
}

fun randomId(): Int = (1..99999).random()


fun getRandomPortNumber() : Int {
    return (41413..61612).random()
}

```
