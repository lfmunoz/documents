---
title: Go
mathjax: true
layout: default
toc: true
---



# The Go Programming Language

Go is a general-purpose language designed with systems programming in mind.   It is strongly and statically typed, provides inbuilt support for garbage collection, and supports concurrent programming.

Go programming implementations use a traditional compile and link model to generate executable binaries.

* No semicolon.
* Case-sensitive

<details>
<summary> skeleton.go </summary>

<p markdown="block">
```c
{% include_relative src/skeleton.go %}
````
</p></details> <br>

# Installation


* https://golang.org/dl/


```bash
tar -C /usr/local -xzf go1.15.5.linux-amd64.tar.gz
export PATH=$PATH:/usr/local/go/bin
 go version
 ```


 

 An **identifier** starts with a letter A to Z or a to z or an underscore _ followed by zero or more letters, underscores, and digits (0 to 9).

 Go does not allow punctuation characters such as @, $, and % within identifiers.

architecture-independent:

 uint8,uint16,uint32,uint64
 int8,int16,int32,int64

 float32, float64, complex64, complex128

byte - same as uint8

uintptr - an unsigned integer to store the uninterpreted bits of a pointer value



Variables are lvalues 
Numeric literals are rvalues


### Variables

```go
var variable_list optional_data_type;
// declare a variable and initialize with 0
var  i, j, k int
var  c, ch byte;
var  f, salary float32;

// declare variable and assign value 
var u2 uint32 = 32 

// The type of variable is automatically judged by the compiler
d = 3, f = 5;

// Declaration and initialization
// Either the type or the = expression can be omitted, but not both.
var name type = expression

// := is called short variable declaration
name := expression
//  in case of type inference, we initialized the variable with :=
y := 42 

// Variables of different types can be declared in one go using type inference.
var a, b, c = 3, 4, "foo"  
fmt.Println(a) // 3  int
fmt.Println(b) // 4  int
fmt.Println(c) // "foo" string

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


// const prefix to declare constants 
// define constants in CAPITALS.
const LENGTH int = 10


```


## Operators




```go

// sizeof
// ?:

// & - returns thbe address of a variable

// * - Pointer to a variable.

```


## Control Statements

if, switch, select


```go

   score := 85
   if score >= 90 {
      fmt.Printf("You get an A. \n");
   } else if >= 80 {
      fmt.Printf("You get a B. \n");
   else {
      fmt.Printf("You failed. \n");
   }

   yourAge := 16
   switch yourAge {
      case 16: fmt.Println("16")
      case 18: fmt.Println("18")
      default: fmt.Println("Invalid")
   }

```


break, continue, goto


```go

for true  {
   fmt.Printf("This loop will run forever.\n");
}

for i := 0; i < 5; i++ {
   fmt.Printf("%d \n", i);
}

```

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

## Arrays


```go

var favNums2[5] float64

favNums3 := [5]float64 {1,2,3,4,5}

for i, value := range favNums3 {
   fmt.Println(i, value)
}

// Get 3 and 4 ignore 5
numSlice2 :=numSlice[3:5]



```

# Map

```go

presAge := make(map[string] int)



```


# Concurrency

A wait group is a synchronisation primitive that allows you to 'hang' your program until the counter goes down to 0. It is similar to CountDownLatch in JVM land. 

```go

 // parallel with mutex and waitgroup
    // create a wait group
    wg := &sync.WaitGroup{}
    // init a mutex
    mutex := & ync.Mutex{}
    startTime := time.Now()

     wg.Add(1)

      defer wg.Done()

       mutex.Lock()

        mutex.Unlock()

         wg.Wait()
    elapsedTime := time.Now().Sub(startTime)
    fmt.Println(elapsedTimeMt)


```

Roman Elizarov on goroutines verses kotlin coroutines
https://stackoverflow.com/questions/46864623/which-of-coroutines-goroutines-and-kotlin-coroutines-are-faster


http://journal.stuffwithstuff.com/2015/02/01/what-color-is-your-function/



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