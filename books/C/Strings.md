---
title: Strings
mathjax: true
layout: default
toc: true
---


# Strings

* [The C Programming Language](Introduction.html)

A string in C is merely an array of characters. The length of a string is determined by a terminating null character: '\0'. 
So, a string with the contents,  "abc" has four characters: 'a', 'b', 'c', and the terminating null character. 


## Instantiation

```c
char stringA[3] = "Om";

char stringB[]  = "Om";

char stringC[] = {'O', 'm', '\0'};

char stringD[3];
stringD[0] = 'O';
stringD[1] = 'm';
stringD[2] = '\0';

char * string = "Om";

// To create an extra long string
char string[] = 
"This is a very, very long "
 "string that requires two lines.";

// Allocate in the heap dynamically
char* string = (char *)malloc(sizeof(char)*size);
```



## Conversions

You must often convert an ASCII representation of a value, such as 1234 to the corresponding int, float, long, etc value. For example when reading from the command line.

```c
// Function             Purpose 
//  atof           Converts a string represenstation of a float value
//  atoi           Converts a string represenstationof an integer value
//  atol           Converts a string represenstation of long integer value
//  strtod         Converts a string represenstation of double value
//  strtol         Converts a string represenstation of long value  int 

// Example:				
int int_value = atoi("1234");  					
float float_value = atof("123.34");
```

## Commonly-used string functions and there implementations
The nine most commonly used functions in the string library are:

*     strcat - concatenate two strings
*     strchr - string scanning operation
*     strcmp - compare two strings
*     strcpy - copy a string
*     strlen - get string length
*     strncat - concatenate one string with part of another
*     strncmp - compare parts of two strings
*     strncpy - copy part of a string
*     strrchr - string scanning operation

<details>
<summary> string.cpp </summary>

<p markdown="block">
```c
{% include_relative src/string.c %}
````
</p></details> 


## sprintf 

Write formatted data to string

```c
#include <stdio.h>
int sprintf ( char * str, const char * format, ... );

// On success, the total number of characters written is returned. 
// This count does not include the additional null-character automatically appended at the end of the string.

// On failure, a negative number is returned.
```

Composes a string with the same text that would be printed if format was used on printf, but instead of being printed, the content is stored as a C string in the buffer pointed by s.
The size of the buffer should be large enough to contain the entire resulting string (see snprintf for a safer version).
A terminating null character is automatically appended after the content.

### Examples 

```c
/* sprintf example */
#include <stdio.h>

int main ()
{
  char buffer [50];
  int n, a=5, b=3;
  n=sprintf (buffer, "%d plus %d is %d", a, b, a+b);
  printf ("[%s] is a string %d chars long\n",buffer,n);
  return 0;
}
```


# References 

* [http://www.cplusplus.com/reference/cstdio/sprintf/](http://www.cplusplus.com/reference/cstdio/sprintf/)
* [http://en.wikibooks.org/wiki/C_Programming/Strings](http://en.wikibooks.org/wiki/C_Programming/Strings)
* [http://www.cplusplus.com/reference/clibrary/cstring/](http://en.wikibooks.org/wiki/C_Programming/Strings)
* [http://www.koders.com/zeitgeist/c/](http://en.wikibooks.org/wiki/C_Programming/Strings)

