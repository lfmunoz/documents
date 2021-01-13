---
title: Testing 
mathjax: true
layout: default
toc: true
---


# Testing

* [The Go Programming Language](Introduction.html)

Note: Go doesn't provide assertions. They are undeniably convenient, but our experience has been that programmers use them as a crutch to avoid thinking about proper error handling and reporting.


You write a test by creating a file with a name ending in _test.go that contains functions named TestXXX with signature func (t *testing.T). The test framework runs each such function; if the function calls a failure function such as t.Error or t.Fail, the test is considered to have failed.

```bash
go test

# run the tests recursively
go test -v ./...
```

If t.Fatal or t.Error are not called the test is considered passing


If the amount of extra code required to write good errors seems repetitive and overwhelming, the test might work better if table-driven, iterating over a list of inputs and outputs defined in a data structure

Put all the source files for the package in a directory by themselves. Source files can refer to items from different files at will; there is no need for forward declarations or a header file.

Other than being split into multiple files, the package will compile and test just like a single-file package.

## Basic Unit Test


<details>
<summary> cat src/test/basic_test.go </summary>

<p markdown="block">
```c
{% include_relative src/test/basic_test.go  %}
````
</p></details> <br>


## Table tests

<details>
<summary> cat src/test/table_test.go </summary>

<p markdown="block">
```c
{% include_relative src/test/table_test.go  %}
````
</p></details> <br>
