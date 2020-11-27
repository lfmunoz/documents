---
title: Functions
mathjax: true
layout: default
toc: true
---


# Functions 

* [The Go Programming Language](Introduction.html)


 
## Functions



Go doesn't support default function arguments 
Go doesn't support function overloading


built-in functions:
 len()


```go
func function_name( [parameter list] ) [return_types]
{
   body of the function
}
```

```go
// Returning multiple values
func swap(x, y string) (string, string) {
   return y, x
}

```


## Strings


```go

// A string literal holds a valid UTF-8 sequences called runes.
// A String holds arbitrary bytes.
var greeting = "Hello world!"
fmt.Printf("String Length is: ")
fmt.Println(len(greeting))

// concatenate
strings.Join(sample, " ")

```