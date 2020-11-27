---
title: Control Statements
mathjax: true
layout: default
toc: true
---




# Control Statements

* [The Go Programming Language](Introduction.html)


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
