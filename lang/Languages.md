---
title: Languages
mathjax: true
layout: default
toc: true
---

# Languages


```
# expression 
b + 1

# statement
a = b + 1; 
```

A **statement** forms a complete unit of execution. A statement consists of expressions.

An **expression** is a construct made up of variables, operators, and method invocations, which are constructed according to the syntax of the language, that evaluates to a single value.


---

A **parameter** is the variable which is part of the method’s signature (method declaration). The receiving variable used within the function.

 An **argument** is an expression used when calling the method.

```c
// i and f are the parameters
void Foo(int i, float f) {
    // Do things
}

void Bar() {
    int anInt = 1;
    // anInt and 2.0 are the arguments
    Foo(anInt, 2.0);
}
```

# Programming

Computer programs are the most complicated thing humans make. Humans must make programs that are perfect, we cannot reach perfection but we should do the best possible. One way is to have a discipline and program in a form that is less like to cause problems, this is unique to a programming language. We don't use all the language features we use a subset that has empirically shown to cause less problems.

Arrange the important parts of the code so it fits on one page. Make that code understandable to a person reading it from top to bottom. Do not require the code to be repeatedly scanned in order to understand how data is used and how control moves about.




modularization: code is factored into "modules" of some sort where each module has a clear responsibility. The action of the code can be documented and understood without a user having to understand its implementation details.


encapsulation: modules make a distinction between their "public" surface area and their "private" implementation details so that the latter can be improved without affecting the correctness of the program as a whole.

re-use: when a problem is solved correctly once, it is solved for all time; the solution can be re-used in the creation of new solutions. Techniques such as making a library of utility functions, or making functionality in a base class that can be extended by a derived class, or architectures that encourage composition, are all techniques for code re-use. Again, the point is to lower costs.

annotation: code is annotated to describe the valid values that might go into a variable, for instance.
automatic detection of errors: a team working on a large program is wise to build a device which determines early when a programming error has been made and tells you about it so that it can be fixed quickly, before the error is compounded with more errors. Techniques such as writing a test suite, or running a static analyzer fall into this category.