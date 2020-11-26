---
title: C++ - Control Structures
mathjax: true
layout: default
toc: true
---

# Control Structures



The C language (as well as C++) is historically a mix of two completely different programming styles,
**statement programming** and **expression programming**.

```cpp 

void main() {
    // is equivalent to (x = 1),2,3,4,5;
    int x = 1,2,3,4,5;   //  x = 1
    // seq is evaluated and gives 5
    int y = (1,2,3,4,5); // y = 5
}

```



Branching in expression programming is done through ?: operator and, alternatively,
 through short-circuit evaluation properties of && and || operators. 


 (Expression programming has no cycles though. And to replace them with recursion you'd 
 have to apply statement programming.)




Operator , in nothing else than a separator of sequential expressions in C, i.e. operator ,
 in expression programming serves the same role as ; does in statement programming.


The difference is that two expressions separated by a semicolon form two separate statements, 
while comma-separation keeps all as a single expression. 

int a, b; --- variable declaration list is comma separated, but these are not comma operators
int a=5, b=3; --- this is also a comma separated variable declaration list



if (something) dothis(), dothat(), x++;
this is equivalent to
if (something) { dothis(); dothat(); x++; }







```cpp
int foo = (bar > bash) ? bar : bash;
```





```cpp
{% include_relative src/LoopingExample.cpp %}
```



# References

*  [https://stackoverflow.com/questions/1613230/uses-of-c-comma-operator](https://stackoverflow.com/questions/1613230/uses-of-c-comma-operator)