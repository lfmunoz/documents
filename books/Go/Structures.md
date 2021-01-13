---
title: Structures 
mathjax: true
layout: default
toc: true
---


# Structures

* [The Go Programming Language](Introduction.html)


## User-defined types

<details>
<summary> cat src/struct.go </summary>

<p markdown="block">
```c
{% include_relative src/struct.go %}
````
</p></details> <br>



But the cool thing about Go is that, when we use an anonymous nested struct, all the nested struct fields are automatically available on parent struct. This is called field promotion.

## Methods

Methods provide a way to add behavior to user-defined types.

Methods are extension functions that contain an extra parameter that’s declared between the keyword func and the function name.

There are two types of receivers in Go: value receivers and pointer receivers.


<details>
<summary> cat src/method.go </summary>

<p markdown="block">
```c
{% include_relative src/method.go %}
````
</p></details> <br>



## Interfaces

Interfaces in Go provide a way to specify the behavior of an object: if something can do this, then it can be used here.

<details>
<summary> cat src/interfaces.go </summary>

<p markdown="block">
```c
{% include_relative src/interfaces.go %}
````
</p></details> <br>



## Embedding

Go does not provide the typical, type-driven notion of subclassing, but it does have the ability to “borrow” pieces of an implementation by embedding types within a struct or interface.

https://golang.org/doc/effective_go.html#embedding

```go
// Only interfaces can be embedded within interfaces.
// ReadWriter is the interface that combines the Reader and Writer interfaces.
type ReadWriter interface {
    Reader
    Writer
}

```

 When we embed a type, the methods of that type become methods of the outer type, but when they are invoked the receiver of the method is the inner type, not the outer one. 


## Enums


https://www.ribice.ba/golang-enums/

enums in Go aren’t as useful due to Go’s implementation. The biggest drawback is that they aren’t strictly typed, thus you have to manually validate them.

```go
type LeaveType string

const(
    AnnualLeave LeaveType = "AnnualLeave"
    Sick = "Sick"
    BankHoliday = "BankHoliday"
    Other = "Other"
)
```




## Reference


https://medium.com/rungo/structures-in-go-76377cc106a2