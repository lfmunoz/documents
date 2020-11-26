---
title: Functions
mathjax: true
layout: default
toc: true
---


# Functions 

* [The C Programming Language](Introduction.html)

Functions are the at the heart of structural programming paradigm

```c
#include <stdio.h>
int main(void) {
   hello_world();
   return 0;
}

void hello_world(void) {
   printf("Simplest Function \n");
}

```


## Pass by Value  

```c
#include <stdio.h>
int main(void) {
   int five = 5;
   hello_world(five);
   return 0;
}

void hello_world(int age) {
   printf("Simplest Function with argument %d \n", age);
}
```

Pass by value creates a copy of the variable

## Pass by Reference 

When an array name is passed to a function, what is passed is the location of the initial element. Within the called function, this argument is a local variable and so an array name parameter is a pointer, that is, a variable containing an address
 

### Passing an address

```c
#include <stdio.h>
int main(void) {
   int five = 5;
   hello_world(&five);
   return 0;
}

void hello_world(int* age) {
   printf("Simplest Function with argument %d \n", age);
}
```


### Passing a 2D Array


Notice that the first brackets [] (the row) are left empty while the following ones specify sizes for their respective dimensions. This is necessary in order for the compiler to be able to determine the depth of each additional dimension.


```c
int func(int a[][7]) {

}
```

```c
void zeroit(int **array, int nrows, int ncolumns) {
   int i, j;
	for(i = 0; i < nrows; i++) {
		for(j = 0; j < ncolumns; j++) {
			array[i][j] = 0;
		}
	}
}
```


```c
// Best Advice, forget 2D 
void func_2d(int *p, size_t M, size_t N)
{
  size_t i, j;
  ...
  p[i*N+j] = ...;
}

```

## What if a function needs to change one of the pointer parameters passed to it? 

For example, the insert() function may want to change the root pointer. In C and C++, one solution uses pointers-to-pointers (aka "reference parameters"). That's a fine technique, but there is a simpler technique that a function that wishes to change a pointer passed to it will return the new value of the pointer to the caller.The caller is responsible for using the new value.

```c
// suppose the variable "root" points to the tree
root = change(root); 
```


