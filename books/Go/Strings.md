---
title: Strings
mathjax: true
layout: default
toc: true
---


# Strings

* [The Go Programming Language](Introduction.html)





```go

// A string literal holds a valid UTF-8 sequences called runes.
// A String holds arbitrary bytes.
var greeting = "Hello world!"
fmt.Printf("String Length is: ")
fmt.Println(len(greeting))

// concatenate
strings.Join(sample, " ")

```


## String Comparison

```go

    // Creating and initializing strings
    // using shorthand declaration
    str1 := "Geeks"
    str2 := "Geek"

 
    // Checking the string are equal
    // or not using == operator
    result1 := str1 == str2
 fmt.Println("Result 1: ", result1)

result5 := str1 != str2

   fmt.Println("\nResult 5: ", result5)
```


```go

 myslice := []string{"Geeks", "Geeks",
                    "gfg", "GFG", "for"}

    // Using comparison operator
    result1 := "GFG" > "Geeks"
    fmt.Println("Result 1: ", result1)

    // Using Compare() method:
// func Compare(str1, str2 string) int
    // Return 0, if str1 == str2.
// Return 1, if str1 > str2.
// Return -1, if str1 < str2.
  fmt.Println(strings.Compare("gfg", "Geeks"))
```



# Format Strings


```go

fmt.Sprintf("foo: %s", bar)

	const name, age = "Kim", 22
	s := fmt.Sprintf("%s is %d years old.\n", name, age)
```

```
%v	the value in a default format
	when printing structs, the plus flag (%+v) adds field names
```

* Reference
  * https://golang.org/pkg/fmt/#Sprintf