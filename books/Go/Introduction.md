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
* Strongly and statically typed
* Inbuilt support for Garbage Collection
* Inbuilt support for Concurrent Programming
* concise syntax with few keywords to memorize
* fast compiler
* No semicolon
* Case-sensitive

This language sits between Java and C++ as far as performance, rapid development and abstractions. Libraries tend to be less clean, mature and lacking features that equivalent Java libraries have. The code is less verbose and more straightforward compared to C++. That is in part because of Garbage Collection and built-in concurrency.

Notable projects using Go: CockroachDB, Kubernetes, Terraform

<details>
<summary> skeleton.go </summary>

<p markdown="block">
```c
{% include_relative src/skeleton.go %}
````
</p></details> <br>



## Table of Contents

* [Data Types](DataTypes.html)
   * identifiers, literals, primitives
   * variables
* [Control Statements](ControlStatements.html)
    * if, switch, ?:
    * do, do-while, for, goto
* [Functions](Functions.html)
* [Collections](Collections.html)
* [Structures](Structures.html)
* [Concurrency](Concurrency.html)



# Installation


* https://golang.org/dl/


```bash
tar -C /usr/local -xzf go1.15.5.linux-amd64.tar.gz
export PATH=$PATH:/usr/local/go/bin
 go version
 ```



All code files in a folder must use the same package name, and it’s common practice to name the package after the folder.

All init functions in any code file that are part of the program will get called before
the main function.

By default, the logger is set to write to the stderr device.

```go
var matchers = make(map[string]Matcher)
```
This variable is located outside the scope of any function and so is considered a
package-level variable.

In Go, identifiers are either exported or unexported from a package. An exported
identifier can be directly accessed by code in other packages when the respective
package is imported. These identifiers start with a capital letter. Unexported identifi-
ers start with a lowercase letter and can’t be directly accessed by code in other pack-
ages


Go is a statically typed programming language. What that means is the compiler
always wants to know what the type is for every value in the program. When the
compiler knows the type information ahead of time, it can help to make sure that
the program is working with values in a safe way. This helps to reduce potential
memory corruption and bugs, and provides the compiler the opportunity to pro-
duce more performant code.


User-defined types

```go
type user struct {
   name string
   email string
   ext int
   privileged bool
}
// Once you have a type declared, you can create values from the type.
var bill user
```

When you declare variables, the value that the variable represents is always initialized.

Any time a variable is created and initialized to its zero value, it’s idiomatic to use
the keyword var .

If the variable will be initialized to something other than
its zero value, then use the short variable declaration operator with a struct literal.

```go
// Declare a variable of type user and initialize all the fields.
lisa := user{
   name: "Lisa",
   email: "lisa@email.com", 
   ext: 123,
   privileged: true, // it requires a trailing comma.
}
// Order is important
lisa := user{"Lisa", "lisa@email.com", 123, true}
```

short variable declaration operator. ( := )
it both declares and initializes a variable. Based on the type information on the
right side of the operator, the short variable declaration operator can determine the
type for the variable.

taking an existing type and using
it as the type specification for the new type.
```
type Duration int64
```

Methods

Methods provide a way to add behavior to user-defined types. Methods are really func-
tions that contain an extra parameter that’s declared between the keyword func and
the function name.


```go

func (user u) notify() {

}

```


The parameter between
the keyword func and the function name is called a receiver and binds the function to
the specified type.

The reason ?: is absent from Go is that the language's designers had seen the operation used too often to create impenetrably complex expressions.



If the amount of extra code required to write good errors seems repetitive and overwhelming, the test might work better if table-driven, iterating over a list of inputs and outputs defined in a data structure

Put all the source files for the package in a directory by themselves. Source files can refer to items from different files at will; there is no need for forward declarations or a header file.

Other than being split into multiple files, the package will compile and test just like a single-file package.


There are two types of receivers in Go: value receivers and pointer receivers

```go

lisa := &user{"Lisa", "lisa@email.com"}
lisa.notify()

```

a variable named lisa of pointer type user is declared and initialized with a name
and email address. Then on line 37, the notify method is called using the pointer
variable.


JSON

```go
type Feed struct {
   URI string `json:"link"`
   Type string `json:"type"`
}

var feeds []*Feed
err = json.NewDecoder(file).Decode(&feeds)
```

https://www.ribice.ba/golang-enums/

enums in Go aren’t as useful due to Go’s implementation. The biggest drawback is that they aren’t strictly typed, thus you have to manually validate them.

type LeaveType string

const(
    AnnualLeave LeaveType = "AnnualLeave"
    Sick = "Sick"
    BankHoliday = "BankHoliday"
    Other = "Other"
)


Error Handling in Go
https://blog.golang.org/errors-are-values



When you try to build a program with this import path, the go build command will
search the GOPATH for this package location on disk.



# Resources 

* http://play.golang.org

# Learning


Introduction
https://tour.golang.org/welcome/1


https://golang.org/doc/code.html

https://golang.org/doc/effective_go.html







Concurrency in Go: Tools and Techniques

Go In Action
William Kennedy, Brian Ketelsen and Erik St. Martin
Manning Publications Co. 2016
ISBN 9781617291784


Concurrency


https://medium.com/@trevor4e/learning-gos-concurrency-through-illustrations-8c4aff603b3

https://yourbasic.org/golang/concurrent-programming/