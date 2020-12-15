---
title: Go
mathjax: true
layout: default
toc: true
---



# The Go Programming Language

Go is a general-purpose language designed with systems programming in mind.  

* Syntax similar to [C Programming Language](../C/Introduction.html)
* Traditional compile and link model to generate executable binaries
* Statically typed
* Strongly typed
* Inbuilt support for Garbage Collection
* Inbuilt support for Concurrent Programming
* Concise syntax with few keywords to memorize
* Fast compiler
* No semicolon
* Case-sensitive

This language sits between Java and C++ as far as performance, rapid development and abstractions. Libraries tend to be less clean, mature and lacking features that equivalent Java libraries have. The code is less verbose and more straightforward compared to C++, which is in part because of Garbage Collection and built-in concurrency.

Notable projects using Go: CockroachDB, Kubernetes, Terraform


```go
{% include_relative src/cmd/skeleton/main.go %}
```



## Table of Contents

* [Data Types](DataTypes.html)
   * identifiers, literals, primitives
   * variables 
   * operators
* [Control Statements](ControlStatements.html)
    * if, switch
    * for, range, break, continue
* [Functions](Functions.html)
* [Collections](Collections.html)
* [Structures](Structures.html)
   * type keyword
   * methods (extension functions)
   * enums
* [Packaging](Packaging.html)
   * Modules
* [Concurrency](Concurrency.html)
* [Testing](Testing.html)



# Installation


<details>
<summary> cat src/install_go.bash </summary>

<p markdown="block">
```c
{% include_relative src/install_go.bash %}
````
</p></details> <br>


# Project Layout

```
.
├── cmd               Main applications 
│   ├── app
│   └── skeleton
│       └── main.go
├── Makefile
├── pkg             Library code that's ok to use by external applications
├── internal        Private application and library code.
```

* https://github.com/golang-standards/project-layout

By default, the logger is set to write to the stderr device.




JSON

```go
type Feed struct {
   URI string `json:"link"`
   Type string `json:"type"`
}

var feeds []*Feed
err = json.NewDecoder(file).Decode(&feeds)
```



Error Handling in Go
https://blog.golang.org/errors-are-values



When you try to build a program with this import path, the go build command will
search the GOPATH for this package location on disk.



# Resources 

* http://play.golang.org
* https://golang.org/pkg/fmt/

# Learning






Go In Action \
William Kennedy, Brian Ketelsen and Erik St. Martin \
Manning Publications Co. 2016 \
ISBN 9781617291784

* https://github.com/goinaction/code/blob/master/chapter5/listing50/listing50.go

* https://www.golang-book.com/books/intro



Introduction
https://tour.golang.org/welcome/1


https://golang.org/doc/code.html

https://golang.org/doc/effective_go.html





https://medium.com/@trevor4e/learning-gos-concurrency-through-illustrations-8c4aff603b3

https://yourbasic.org/golang/concurrent-programming/