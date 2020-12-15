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

<details>
<summary> cat src/interfaces.go </summary>

<p markdown="block">
```c
{% include_relative src/interfaces.go %}
````
</p></details> <br>



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