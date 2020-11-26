---
title: C Data Types
mathjax: true
layout: default
toc: true
---


# C Data Types

* [The C Programming Language](Introduction.html)




Data type sizes can vary by archituecture.
  *  All data types are measured in units of unsigned char.
  *  sizeof(char) is always exactly one on any system.
  *  The C standard does not specify a number of bits for a type, but a required range.
C has the following basic built-in datatypes.
  *  int
    *  As large as 32,767, and as small as -32,767
  *  float
  *  double
  *  char
    *  0 to 255
The data also have the following modifiers. 
  *  short
  *  long
  *  signed
  *  unsigned

“Rule 10.6 (required): A “U” suffix shall be applied to all constants of unsigned type.”

====  C99  ====

  *  The C99 standard standardized the naming conventions for specific integer types (int8_t, uint8_t, int16_t etc).They also defined data types which are minimum width and also fastest width

To see if your compiler is C99 compliant, open up stdint.h. If it is compliant, as well as the uint8_t etc data types, you’ll also see at least two other sections – minimum width types and fastest minimum width types. An example will help clarify the situation:

  *  Fixed width unsigned 8 bit integer: uint8_t
  *  Minimum width unsigned 8 bit integer: uint_least8_t
  *  Fastest minimum width unsigned 8 bit integer: uint_fast8_t

Thus a uint8_t is guaranteed to be exactly 8 bits wide. A uint_least8_t is the smallest integer guaranteed to be at least 8 bits wide. An uint_fast8_t is the fastest integer guaranteed to be at least 8 bits wide

====  Storage-class Specifiers  ====

Storage-class specifiers tell the compiler where or how a given object is stored, they include
  *  auto
    *  cannot be used outside a function
    *  requests storage that is local to a function's invocation. Iinstantiated when the function is called and deleted when it returns, and duplicated as necessary.
    *  Storage is allocated and deallocated on the call stack. 
    *  Are initialized during the run-time
    *  auto keyword is the default storage class, so never actually needed.
  *  extern
    *   indicates that an object is being declared, but not defined. the object itself will come from some other module
    *  gives the complier enough information to generate code which refers to that object.
    *  if used within a function, it is a reference to a global variable.
  *  register
    *  a suggestion to the compiler that the object in question might best be stored in a processor register
  *  static
    *  Defines an object to have permanent storage, but not be visible outside the scope of its declaration
    *  Declared in a file: it would be hidden outside that particular file. Make functions static if they are to be used within the c file only. h files are interface files for function and variables that will be used else where
    *  Used within a function:  Will invisible outside its scope, so the only effect is to reserve permanent storage. It allows the last value of the variable to be preserved between successive calls to that function
    *  Lifetime extends across the entire run of the program. 
    *   Static (and global) variables are initialized during the compile-time, so the initial values will simply be embeded in the executable file itself
    * Static variables can be initialized(.data) or unitialized(.bss)

====  Type qualifiers  ====

Type qualifiers tell the compiler something about how that object will be used. There are three type qualifiers:
  *  const
    *  a promise that the programmer won't try to modify something through a given value
  *  volatile.
    *  instructs the compiler to ensure that all accesses to the qualified object actually occur
    *  primarily used for objects which represent hardware, and essentially prohibits optimizations. 


  *  [[ C Data Type Examples ]]



===== Type Aliases =====

<code c>
#include <stdint.h>
</code>


^ signed type ^ unsigned type ^ 
| intmax_t	 | uintmax_t	 | 
| int8_t | uint8_t | 
| int16_t | uint16_t | 
| int32_t | uint32_t | 
| int64_t | uint64_t | 

Integer type with the maximum width supported.
Integer type with a width of exactly 8, 16, 32, or 64 bits. For signed types, negative values are represented using 2's complement. No padding bits. Optional: These typedefs are not defined if no types with such characteristics exist.*


http://www.cplusplus.com/reference/cstdint/

===== Reading Complex Type =====
When you see a complex declaration, first recognize the basic type and the variable name. In:

<code c>
int (*x)[10][20];
</code>


The basic type is int and the variable name is x. So the declaration means x is **…** int for some yet unknown value of **…**


To read the modifiers, go to the right from the variable name until you can – that is, until you run into a semicolon or a closing right parenthesis. When you reach one of these stops, start going left until you reach an opening left parenthesis (or the basic type, in which case you’re done). Each time you see a new modifier (either going right or left), attach it to the end of the current declaration sentence.
<code c>
/* x is int (but that was easy...) */
int x;

/* go right from 'x' - we hit the array
   and then get stuck on the ';', so 
   we start going left, where there's
   nothing.
   
   so:
   
   x is an array[5] of int 
*/
int x[5];

/* there's nothing to the right, but a '*'
   to the left, so:
   
   x is a pointer to int
*/
int *x;

/* now, combining these cases:
   
   x is an array[5] of pointer to int
*/
int *x[5];

/* how about this ?
  
   x is an array[5] of array[2] of int
*/
int x[5][2];

/* hey, this is becoming easy...

   x is an array[5] of array[2] of pointer
     to pointer to int
*/
int **x[5][2];

/* grouping parantheses complicate things,
   but not too much.
   trying to go right from 'x', we hit the
   closing paren, so we go left. After
   we attach the pointer we see an opening
   paren, so we can go right again:
   
   x is a pointer to array[5] of int
*/
int (*x)[5];

/* function declarations are just like arrays:
   we go right from 'x', and attach 'array[4] of'
   then we hit the paren, and go left, attaching
   'pointer to'. Then, we hit the left paren, so
   we go right again, attaching 
   'function(char, int) returning'
   
   And eventually:
   
   x is an array[4] of pointer to 
     function(char, int) returning int
*/
int (*x[4])(char, int);
</code>



=====  References  =====

[[ C ]]

http://www.ibm.com/developerworks/power/library/pa-ctypes1/index.html

http://eli.thegreenplace.net/2008/07/18/reading-c-type-declarations/

http://stackoverflow.com/questions/6418807/how-to-work-with-complex-numbers-in-c

http://en.wikibooks.org/wiki/C_Programming/Complex_types