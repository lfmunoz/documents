---
title: HTTP
mathjax: true
layout: default
toc: true
---


# HTTP

* [The Go Programming Language](Introduction.html)


<details>
<summary> cat src/cmd/http/main.go </summary>

<p markdown="block">
```c
{% include_relative src/cmd/http/main.go  %}
````
</p></details> <br>


A Context carries deadlines, cancellation signals, and other request-scoped values across API boundaries and goroutines.


```go

rw.Header().Set("Content-Type", "application/json")
rw.WriteHeader(200)
```


# Reference


* https://www.alexedwards.net/blog/how-to-properly-parse-a-json-request-body
* https://github.com/go-chi/chi