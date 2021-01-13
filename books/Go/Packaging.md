---
title: Packaging 
mathjax: true
layout: default
toc: true
---


# Packaging

* [The Go Programming Language](Introduction.html)

All code files in a folder must use the same package name, and it’s common practice to name the package after the folder.

All init functions in any code file that are part of the program will get called before the main function.


This variable is located outside the scope of any function and so is considered a package-level variable. 


In Go, identifiers are either exported or unexported from a package. An exported identifier can be directly accessed by code in other packages when the respective package is imported. These identifiers start with a capital letter. Unexported identifiers start with a lowercase letter and can’t be directly accessed by code in other packages



## Modules

A Module is a way to group together a set of packages and give it a version number to mark it’s existence (state) at a specific point in time. 

Go Modules use Semantic Versioning for their numbering scheme. (https://semver.org/)

Modules allow for the deprecation of the GOPATH


```bash
# Initialize a new module:
go mod init github.com/lfmunoz/documents/tree/master/books/Go/src
go: creating new go.mod: module github.com/lfmunoz/documents/tree/master/books/Go/src

# View final versions that will be used in a build for all direct and indirect dependencies 
go list -m all 
github.com/lfmunoz/documents/tree/master/books/Go/src


# Allows you to store your dependencies in the vendor directory inside of the project directory
# Allow projects more control over their dependencies than having to use go get every time and hope the dependent library still existed as a project, that it hadn’t been deleted from github, and that no breaking changes had been pushed to master
go mod vendor
```


<details>
<summary> cat src/go.mod </summary>

<p markdown="block">
```go
{% include_relative src/go.mod %}
````
</p></details> <br>


There are four directives: module, require, replace, exclude