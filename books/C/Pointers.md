---
title: Pointers And Arrays
mathjax: true
layout: default
toc: true
---


# Pointers And Arrays

* [The C Programming Language](Introduction.html)


# Pointers

A **pointer** is simply a variable that stores the address where a piece of data resides in memory rather than storing the data itself. A pointer is a location that has an address to some type. Allocates space for 1 address. We must associate a pointer to a particular type: You can't assign the address of a short int to a long int, for instance.  The reason we associate a pointer to a data type is so that it knows how many bytes the data is stored in. When we increment a pointer we increase the pointer by one "block" memory.  So for a character pointer ++ch_ptr adds 1 byte to the address. For an integer ++int_ptr adds 4 bytes to the address. 

  * The **unary** or monadic operator & gives the "address of a variable".
  * The **indirection** or **dereference** operator * gives the "contents of an object pointed to by a pointer".  

```c
// declare a pointer to int
int *pointer;
// declare a variable of type int
int x = 1;
// assign the pointer the address of x
pointer= &x;
// access the variable using the pointer
printf("%x\n", *pointer);
```



# Arrays 
An array holds a number of objects of a given type next to each other in memory. To create an array with N element the syntax is

```c
 int my_array[N];
// Wrong, out of range
 my_array[N] = 10; 
// Correct, assign last element the value 10
 my_array[N-1] 10; 
// Assign 0 to first element
 my_array[0] = 0;  
```

  *  The first element is at 0 and the last at N-1
  *  An array name is the address where a block of data starts. 
  *  the syntax a[i] means the same thing as *(a+i)


## Ways to Initalize an array

```c
// Equivalent
int a[8] = {2, 4, 6, 8, 10, 12, 14, 16};
int b[] = {2, 4, 6, 8, 10, 12, 14, 16};

//       0   1   2   3   4    5    6    7
//  a: | 2 | 4 | 6 | 8 | 10 | 12 | 14 | 16 |
//

```

```c
// In evaluating a[i], C converts it to *(a+i) immediately; the two forms are equivalent. 
// &a[i] and a+i are also identical: a+i is the address of the i-th element beyond a
matrix[i] = *(matrix + i )
```


```c
int x[4] = {10, 9, 8, 7};

x;  //address where 10 is located
&x;  //  address where 10 is located
x[0] // 10 itself

int *y = (int *) malloc(sizeof(int)*4);
y[0] = 10; y[1]=9; y[2]=8;, y[3]=7;

y;  //  address where 10 is located;
&y; //  address where y is locate
*y;  //  10 itself

```


# Arrays verses Pointers 

Arrays are not pointers.  The array declaration "char a[6];" requests that space for six characters be set aside, to be known by the name "a."  That is, there is a location named "a" at which six characters can sit. The pointer declaration "char *p;" on the other hand, requests a place which holds a pointer.  The pointer is to be known by the name "p," and can point to any char (or contiguous array of chars) anywhere.

As usual, a picture is worth a thousand words.  The statements

```c
char a[] = "hello";
char *p = "world";
```

would result in data structures which could be represented like this:
```c
	   +---+---+---+---+---+---+
	a: | h | e | l | l | o |\0 |
	   +---+---+---+---+---+---+

	   +-----+     +---+---+---+---+---+---+
	p: |  *======> | w | o | r | l | d |\0 |
	   +-----+     +---+---+---+---+---+---+
```


*  Pointers and arrays are different
*  The array is the location of where the data is actually at
*  A pointer holds the location of where the data is at, but it is just a plain varible able to hold an address location.


```c
int* xptr;
int xarray[10];

xptr  // address of where the data is held
&xtpr // address of the pointer variable 
*xptr // the value of the data 

xarray  // address of first location where data is held
&xarray // same as above


```



# Null Pointer

There is no portable way to check whether a pointer is valid, howeve, when an object is freed, pointers to it become invalid. What C provides is a special kind of pointer guaranteed to be invalid, but which can be compared with it, called a null pointer. A null pointer does not point to any object, but it is safe to compare other pointers to a null pointer, and any valid pointer is guaranteed to compare unequal to a null pointer. Syntactically, you can create a null pointer by using a 0 in place of a pointer, or by casting 0 to pointer type. 



# Pointers to Pointers 
Since we can have pointers to int, and pointers to char, and pointers to any structures we've defined, and in fact pointers to any type in C, it shouldn't come as too much of a surprise that we can have pointers to other pointers. If we're used to thinking about simple pointers, and to keeping clear in our minds the distinction between the pointer itself and what it points to, we should be able to think about pointers to pointers, too, although we'll now have to distinguish between the pointer, what it points to, and what the pointer that it points to points to.
	 
```c
char ch;     /* a character */ 
char *pch; 	 /* a pointer to a character */
char **ppch; /* a pointer to a pointer to a character  
				identical to declaring char *ppch[[]] */
```



When you pass a pointer-pointer to a function it allows you to modify where the pointer points to

```c
int pop(struct Stack **head) {
   ...
}

```

* *head is the address of where the pointer points
* **head is the location the pointer points to
* head is location where the pointer address is stored.

What are pointers to pointers good for, in practice? One use is returning pointers from functions, via pointer arguments rather than as the formal return value. To explain this, let's first step back and consider the case of returning a simple type, such as int, from a function via a pointer argument. If we write the function
```c
	f(int *ip)
	{
		*ip = 5;
	}
```

and then call it like this:
```c
	int i;
	f(&i);
```

then f will **return** the value 5 by writing it to the location specified by the pointer passed by the caller; in this case, to the caller's variable i. A function might **return** values in this way if it had multiple things to return, since a function can only have one formal return value (that is, it can only return one value via the return statement.) The important thing to notice is that for the function to return a value of type int, it used a parameter of type pointer-to-int.


Now, suppose that a function wants to return a pointer in this way.  The corresponding parameter will then have to be a pointer to a pointer. 

# How to determine size of Array? 

```c
int a[17];
n = sizeof(a)/sizeof(a[0]);
```
It is worth noting that sizeof doesn't help if you are dealing with a pointer to an array:

```c
int a[10];
int* p = a;

assert(sizeof(a) / sizeof(a[0]) == 10);
assert(sizeof(p) == sizeof(void*));
```

# Multidimensional Arrays 
In computing, **row-major order** and** column-major order** describe methods for storing multidimensional arrays in linear memory.

Following standard matrix notation, rows are numbered by the first index and columns by the second index.

```c
int Matrix[row][column];
```

C uses row-major storage, a multidimensional array in linear memory is organized such that rows are stored one after the other. 

For example, consider this 2×3 array:

$$ \begin{pmatrix} 1 & 2 & 3 \\  4 & 5 & 6  \end{pmatrix} $$

```c
int A[2][3] = { {1, 2, 3}, {4, 5, 6} };
```

would be laid out contiguously in linear memory as:
```c
 1  2  3  4  5  6
```

To traverse this array in the order in which it is laid out in memory, one would use the following nested loop:

```c
for (i = 0; i < 2; i++) 
    for (j = 0; j < 3; j++) 
        printf("%d\n", A[i][j]);
```
The difference in offset from one column to the next is 1 and from one row to the next is 3. The linear offset from the beginning of the array to any given element A[row][column] can then be computed as:
```c
offset = row*NUMCOLS + column
```

where NUMCOLS is the number of columns in the array.



There is no such thing as a multi-dimensional array.  All arrays are 1-dimensional, but some of them contain arrays, or arrays of arrays. What this means is that when you see


In reality, the computer cannot store a “grid”, because memory is one long line of addresses. multiarray[0] is an array of 2 elements, multiarray[1] is an array of 2 elements, etc. That also means that multiarray[0] is a pointer! 


```c
int zippo[4][2]
// Is really the same as:
int zippo[8]
```



```c
matrix[i][j] = *( *(matrix + i ) + j)
```


# Initializing 

Multidimensional arrays can be described as "arrays of arrays".

Multidimensional arrays are just an abstraction for programmers, since we can obtain the same results with a simple array just by putting a factor between its indices:

```c
int jimmy [3][5];   // is equivalent to
int jimmy [15];     // (3 * 5 = 15) 
```


With the only difference that with multidimensional arrays the compiler remembers the depth of each imaginary dimension for us. 

Ways to initialize a two dimensional array:

```c

int c[2][3] = { {1,3,0}, {-1,5,9} };

int c[][3] = { {1,3,0}, {-1,5,9} };

int c[2][3] = {1,3,0,-1,5,9};

```



```c
 func(int a[][7])
 {
   ...
 }
```
The second dimension is still required. (For a three- or more dimensional array, all but the first dimension are required; again, only the first dimension may be omitted.) 

# Dynamically Allocating Multidimensional Arrays 

```c
	int **array;
	array = malloc(nrows * sizeof(int *));
	for(i = 0; i < nrows; i++){
          array[i] = malloc(ncolumns * sizeof(int));
        }

	void zeroit(int **array, int nrows, int ncolumns)
	{
	int i, j;
	for(i = 0; i < nrows; i++)
		{
		for(j = 0; j < ncolumns; j++)
			array[i][j] = 0;
		}
	}


	for(i = 0; i < nrows; i++)
		free(array[i]);
	free(array);
```

array is a pointer-to-pointer-to-int: at the first level, it points to a block of pointers, one for each row. That first-level pointer is the first one we allocate; it has nrows elements, with each element big enough to hold a pointer-to-int, or int *. If we successfully allocate it, we then fill in the pointers (all nrows of them) with a pointer (also obtained from malloc) to ncolumns number of ints, the storage for that row of the array.


![ptr_to_ptr](/assets/ptrptr.gif)




If a program uses simulated, dynamically allocated multidimensional arrays, it becomes possible to write "heterogeneous" functions which don't have to know (at compile time) how big the "arrays" are. In other words, one function can operate on "arrays" of various sizes and shapes. The function will look something like
```c
func2(int **array, int nrows, int ncolumns) {

}
```

# Best Advice, forget 2D 

```c
void func_2d(int *p, size_t M, size_t N)
{
  size_t i, j;
  ...
  p[i*N+j] = ...;
}

```


Take as example these two pieces of code, with both exactly the same result. One uses a bidimensional array and the other one uses a simple array: 

# multidimensional array 

```c
#define WIDTH 5
#define HEIGHT 3

int jimmy [HEIGHT][WIDTH];
int n,m;

int main ()
{
  for (n=0;n<HEIGHT;n++)
    for (m=0;m<WIDTH;m++)
    {
      jimmy[n][m]=(n+1)*(m+1);
    }
  return 0;
}
```

# pseudo-multidimensional array

```c
#define WIDTH 5
#define HEIGHT 3

int jimmy [HEIGHT * WIDTH];
int n,m;

int main ()
{
  for (n=0;n<HEIGHT;n++)
    for (m=0;m<WIDTH;m++)
    {
      jimmy[n*WIDTH+m]=(n+1)*(m+1);
    }
  return 0;
}
```

http://www.eskimo.com/~scs/cclass/int/sx9b.html

http://en.wikipedia.org/wiki/Row-major_order


 Why a double pointer can't be used as a 2D array?

 When a double pointer that points to the first element of an array, 
 is used with subscript notation "ptr[0][0]", it is fully dereferenced 
 two times


After two full dereferencings the resulting 
 object will have an address equal to whatever value was found INSIDE 
 the first element of the array. Since the first element contains 
 our data, we would have wild memory accesses. 

# Get the values in a two-dimensional array through array pointer 

```c

#include <stdio.h>

int main(void)
{
  char board[3][3] = {
                       {'1','2','3'},
                       {'4','5','6'},
                       {'7','8','9'}
                     };


  int i;
  for(i = 0; i < 9; i++)
    printf(" board: %c\n", *(*board + i));
  return 0;
}
```


```c
      board: 1
      board: 2
      board: 3
      board: 4
      board: 5
      board: 6
      board: 7
      board: 8
      board: 9
```
# When using a function 

Multi-dimensional arrays must be fully dimensioned in the "calling" module, and partially dimensioned in the source function.

As always, the name of the array may be different in each module, but it must be in the same position in the list and agree in type 

```c
void sub(double x[][100]){

}

main() {
  double a[100][100]
  sub(a)
}
```


Notice that the first brackets [] (the row) are left empty while the following ones specify sizes for their respective dimensions. This is necessary in order for the compiler to be able to determine the depth of each additional dimension.


http://www.taranets.net/cgi/ts/1.37/ts.ws.pl?w=329;b=284

http://www.cplusplus.com/doc/tutorial/arrays/

http://www.eskimo.com/~scs/cclass/int/sx9.html

http://www.programiz.com/c-programming/c-multi-dimensional-arrays


http://stackoverflow.com/questions/274865/what-is-int-usermask34-pointing-to/274943#274943



# Pointers to functions


A function pointer is, in its simplest form, the address at which some code is stored. To declare a pointer to a function do:

```c

 int (*pf) ();  
```

This simply declares a pointer *pf to function that returns and int. No actual function is pointed to yet. If we have a function int f() then we can point to it by simply writing:

```c

 /* the ampersand is actually optional */
 pf = &f;
 pf();
 (*pf)(); // same as above
```

it is not safe to call a function with the wrong type. 

# References 


* http://www.cprogramming.com/tutorial/function-pointers.html
* http://www.lysator.liu.se/c/c-faq/c-2.html