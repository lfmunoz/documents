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
* Simplicity and minimalism - No Generics
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
* [Strings](Strings.html)
* [Structures](Structures.html)
   * type keyword
   * methods (extension functions)
   * enums
* [Packaging](Packaging.html)
   * Modules
* [Concurrency](Concurrency.html)
* [Testing](Testing.html)

* [JSON](JSON.html)
* [gRPC](gRPC.html)
* [HTTP](HTTP.html)



# Installation


<details>
<summary> cat src/install_go.bash </summary>

<p markdown="block">
```c
{% include_relative src/install_go.bash %}
````
</p></details> <br>


```bash

# Statically build binary
env CGO_ENABLED=0 GOOS=linux GOARCH=amd64 go build cmd/main/main.go
# CGO_ENABLED=0 This tells compiler to disable CGO and statically link C bindings as well.
# GOOS=linux This tells compiler for which OS it needs to compile.
# GOARCH=amd64 This tells compiler to compile for an amd64 compatible system architecture (64 bit processor).

#  see current latest OS/ARCH combination that you can target
go tool dist list
```
* Cgo lets Go packages call C code.
   * https://blog.golang.org/cgo


# Project Layout

```
.
├── cmd               Main applications 
│   ├── app
│   └── skeleton
│       └── main.go
├── Makefile
├── api             OpenAPI/Swagger specs, JSON schema files, protocol definition files
├── pkg             Library code that's ok to use by external applications
├── internal        Private application and library code.
├── web             Web application specific components: static web assets
├── test            Additional external test apps and test data.
```

* https://github.com/golang-standards/project-layout

By default, the logger is set to write to the stderr device.




JSON



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


* Good source of Go examples 
   * Mark McGranaghan 
   * https://gobyexample.com/closures
   * https://github.com/mmcgrana/gobyexample
* Introduction
   * https://tour.golang.org/welcome/1
   * https://golang.org/doc/effective_go.html


* https://golang.org/doc/code.html




