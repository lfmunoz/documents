---
title: C Decisions
mathjax: true
layout: default
toc: true
---




# C Control Statements

* [The C Programming Language](Introduction.html)

A statement is a complete line of code that performs some action.

An expression is any section of the code that evaluates to a value. 


## If Statement  

```c
if (testScore >= 90 )
  printf("Your grade is an A\n");
else if (testScore >= 80 )
  printf("Your grade is an B\n");
else if (testScore >=70 )
  printf("Your grade is an C\n");
else if (testScore >=60 ) 
  printf("Your grade is an D\n");
else 
  printf("Your grade is an F\n");
```

**Note:** Brackets are optional for single lines

## Case Statement  

```c

int i = 3, j = 2; 
switch(i) {
    printf("This will never get printed \n"); 
  case 1 : 
    printf("This is the first case \n");
    break; 
  case 2 : 
    printf("this is the second case \n");
    break; 
  case j : /* This gives an error cases must be constant xpressions */
    printf("this is the j case \n"); break;
  default: 
    printf("this is the default case \n"); 
}
```

Note break gets you out of the nearest enclosing interation or switch statement, it isn't limited to getting you out of if statements

## Conditional Operator 
  *  ternary operator
  *  (comparision) ? (true result) : (false result);

```c
printf("The result is: %s", (score < 0) ? "Failed" : "Passed");
(void) printf("%s", p->name  ? p->name : "(null)");

```

These two are equivalent
```c
y = (a > b) ? c : d; 

if (a > b) {
 y = c;
} else {
 y = d;
}
```

## Goto Statement 

  *  Cannot jump to another function

```c
int main(void) {
label:
  printf("%d \n", counter++);
  if (counter < 10)
   goto label;
} 
```


## For Loop 

Lets you repeat one or more statements a specific number of times.
```c
for(int i = 0; i < 10; i++) {
  ... statements ...
}
```

The for loop can be traced step-by-step:
  -  1) The initial value section is executed.
  -  2) The condition is tested.
  -  2) Code between braces is executed.
  -  3) Control is sent back to the for statement, where value is incremented.
  -  4) The condition is tested. (We are back at step 2)

## While Loop

Lets you repeat one ore more statements until a specific condition is met.

```c
while(i < 10) {
  ... statements...
  i++;
}
```

## Do While Loop 

Lets you execute one or more statements at least one time.
```c
do {
  ...statements...
  i++;
} while(i < 10);
```


