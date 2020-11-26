---
title: Structures 
mathjax: true
layout: default
toc: true
---


# Structures

* [The C Programming Language](Introduction.html)


* A structure, introduced with the struct keyword, is an aggregate object containing other objects.
* C lets you group related information into a structure. 
* A structure alone does not create a usable variable, the definition serves as a template for future variable declarations.
* Structures have many similarities to classes


## Structure Creation

C provides two ways to define a variables of a specific structure template.


### Method 1: Define structure then create variables;
```c
/* Define the Structure */
struct employee {
 char name[65];
 int pay_grade; 
}; // NOTE: This last semicolon is VERY important!
```

Declare the structure after it has been defined:

```c
/* Declare the structure */ 
struct employee employtee_info;
struct employee new_emp, terminated_emp; 
```

### Method 2: You can also declare the structure when defining the structure

```c
 /* Define and declare the structure */
struct employee { 
char name[65]; 
int pay_grade; 
} employtee_info, new_emp,  terminated_emp; 
 
```

## Accesing structure members 

```c
/* Access a member using the dot operator */
new_emp.paygrade = 50000;
```

 To change a member within a function, the program must pass a pointer to the structure. 

```c

void change_structure(struct Shape *shape) {
   // These statements are equivalent
   shape->type = 0; // cleaner
   (*shape).type = 0;
}

int main(){
   struct Shape circle;
   change_structure(&circle);
}
```

Always remember the following two statements are equivalent.

```c
 (*pointer).member = value;
 pointer->member = value;
```

This is used when using pointers to structures.  C starts within the parentheses, first obtaining the location of the structure, next c adds to the address the offset of the specified member.  If you omit the parentheses, c assumes that the member itself is a pointer and uses the asterisk indirection operator to resolve it, as shown here:
 
```c
struct Planet { 
  char name[40]; 
  int *some_pointer
} planet;
 
planet.some_pointer = (int *) malloc(sizeof(int));
*planet.some_pointer = 5;

```

This is correct for assigning to some_pointer a value. The member is a pointer. Another method to access the members is as following:


```c
struct student {
int roll;
int class;
char name[50];
};


struct student st3={
.name = "Mark",  //Notice the equal to and the comma
.class = 10,
.roll = 1038
};
```

To access a structure that is part of an array you simply do:
```c

struct Employee {
    float salary;
} staff[1000];

staff[emp].salary = 50000;

```


## Unions

Structure allocates storage space for all its members separately. Whereas, Union allocates one common storage space for all its members

```c
union data {
	uint16_t data0;
	uint8_t  data1[2];
};

union data num;
num.data1[0] = 0xAA; // LSB
num.data1[1] = 0x55; // MSB

``` 

```c
union Data {
   int i;
   float f;
   char  str[20];
} data_a;  



union Data data_b;
```