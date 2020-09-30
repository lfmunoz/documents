---
title: C++
mathjax: true
layout: default
toc: true
---

C language (as well as C++) is historically a mix of two completely different programming styles,
 which one can refer to as "statement programming" and "expression programming"

Branching in expression programming is done through ?: operator and, alternatively,
 through short-circuit evaluation properties of && and || operators. 
 (Expression programming has no cycles though. And to replace them with recursion you'd 
 have to apply statement programming.)

void blah() {
    i = 1,2,3,4,5;  // is equivalent to (i = 1),2,3,4,5; //  i = 1
    i = (1,2,3,4,5); // seq is evaluated and gives 5 therefore // i = 5

}



Operator , in nothing else than a separator of sequential expressions in C, i.e. operator ,
 in expression programming serves the same role as ; does in statement programming.


The difference is that two expressions separated by a semicolon form two separate statements, 
while comma-separation keeps all as a single expression. 

int a, b; --- variable declaration list is comma separated, but these are not comma operators
int a=5, b=3; --- this is also a comma separated variable declaration list



if (something) dothis(), dothat(), x++;
this is equivalent to
if (something) { dothis(); dothat(); x++; }



## Conditionals

```cpp
{% include_relative src/Conditionals.cpp %}
```

## Data Classes

```cpp
{% include_relative src/DataClasses.cpp %}
```

## Data Types
```cpp
{% include_relative src/DataTypes.cpp %}
```


```cpp
{% include_relative src/IO.cpp %}
```

```cpp
{% include_relative src/LoopingMain.cpp %}
```

```cpp
{% include_relative src/Macros.cpp %}
```

```cpp
{% include_relative src/Map.cpp %}
```

```cpp
{% include_relative src/PairApp.cpp %}
```

```cpp
{% include_relative src/Pointers.cpp %}
```

```cpp
{% include_relative src/Vector.cpp %}
```
