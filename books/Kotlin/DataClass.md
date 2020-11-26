---
title: Data Classes
mathjax: true
layout: default
toc: true
---


#  Data Classes


* [The Kotlin Programming Language](Introduction.html)


# Data Class

```kotlin
data class OurDto(
   id: Long = 0L,
   metaData: String = "N/A"
    
)

data class WfDto(
  var type: WfType = WfType.RUN_BY_ID,
  var method: String = "main",
  var wfId: Long = 0L,
  var timeout: Long = 120_000L,
  var nodeId: Long? = null,
  var message: String? = null,
  var params: Map<String, String>? = null
) {
  // Serialize / Deserialize
  companion object {
    fun fromJson(json: String) = mapper.readValue<WfDto>(json)
  }

  fun toJson() : String =  mapper.writeValueAsString(this)
}
```


# Enum

```kotlin
enum class WfType(val value: String) {
  RUN_BY_ID("RUN_BY_ID"),
  REFRESH_WF("REFRESH_WF"),
  FORMAT_CODE("FORMAT_CODE"),
  LINT_CODE("LINT_CODE"),

  RSP_STDOUT("RSP_STDOUT"),
  RSP_STDERR("RSP_STDERR"),
  RSP_STDIELD("RSP_STDIELD"),
  RSP_SUCCESS("RSP_SUCCESS"),
  RSP_FAILURE("RSP_FAILURE")
}
```


# Sealed Classes

```kotlin

sealed class GenericResult<R> {
    data class Success<R>(val result: R): GenericResult<R>()
    data class Failure<R>(val message: String, val cause: Exception? = null) : GenericResult<R>()
}
```