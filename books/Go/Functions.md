---
title: Functions
mathjax: true
layout: default
toc: true
---


# Functions 

* [The Go Programming Language](Introduction.html)


 
## Functions

* Go doesn't support default function arguments 
* Go doesn't support function overloading


built-in functions:
 len()



```go
// Returning multiple values
func swap(x, y string) (string, string) {
   return y, x
}

```

## Variadic Functions

```go

func sum(nums ...int) {
    fmt.Print(nums, " ")
    total := 0
    for _, num := range nums {
        total += num
    }
    fmt.Println(total)
}

```

## Anonymous functions

```go
// This function intSeq returns another function
func intSeq() func() int {
    i := 0
    return func() int {
        i++
        return i
    }
}

```


```go

//  Go compiler is very Intelligent!. It will not allocate the memory on the stack to the local variable of the function. It will allocate this variable on the heap.

// defining function having integer pointer as return type 
func rpf() *int { 
  
    // taking a local variable inside the function 
    // using short declaration operator 
    lv := 100 
  
    // returning the address of lv 
    return &lv 
} 
```

## References

* Straightforward tutorial
   * https://gobyexample.com/closures

