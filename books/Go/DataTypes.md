---
title: Data Types
mathjax: true
layout: default
toc: true
---


# Data Types

* [The Go Programming Language](Introduction.html)

In Go, types are composed of smaller types, which is in contrast to traditional inheritance-based models.


## Identifiers

 An **identifier** starts with a letter A to Z or a to z or an underscore _ followed by zero or more letters, underscores, and digits (0 to 9).

 Go does not allow punctuation characters such as @, $, and % within identifiers.




## Primitive daa types

architecture-independent:

```go
uint8,uint16,uint32,uint64
int8,int16,int32,int64

float32, float64, complex64, complex128

byte // same as uint8
uintptr // an unsigned integer to store the uninterpreted bits of a pointer value
 ```



## Variables

In general use **=** to initialize to the default value and use **:=** when you want to initialize to a specific value.


```go
// Declaration and initialization
//  Either the type or the = expression can be omitted, but not both.
//   var name type = expression
var u2 uint32 = 32 

// Declare a variable and initialize with 0
var  i, j, k int
var  c, ch byte;
var  f, salary float32;

// Auto specify the type, the type of variable is automatically 
//  computed by the compiler
d = 3, f = 5;

// := is called short variable declaration (type is inferred)
y := 42 

// Variables of different types can be declared in one go using type inference.
var a, b, c = 3, 4, "foo"  
fmt.Println(a) // 3  int
fmt.Println(b) // 4  int
fmt.Println(c) // "foo" string

// const prefix to declare constants 
// define constants in CAPITALS.
const LENGTH int = 10

```

## Literals 


* Variables are lvalues 
* Numeric literals are rvalues

```go
// Integer Literals
85         /* decimal */
0213       /* octal */
0x4b       /* hexadecimal */
30         /* int */
30u        /* unsigned int */
30l        /* long */
30ul       /* unsigned long */

// Floating-point Literals
3.14159      
314159E-5L   

```

## Operators

similar to [C Programming Language](../C/Introduction.html)

```go
& // This operator returns the address of the variable.
* // This operator provides pointer to a variable.
<- // The name of this operator is receive. 
   // It is used to receive a value from the channel.

```


Go doesn't have a ternary operator, using if/else syntax is the idiomatic way
