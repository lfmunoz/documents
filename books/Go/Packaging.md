---
title: Packaging 
mathjax: true
layout: default
toc: true
---


# Packaging

* [The Go Programming Language](Introduction.html)



All code files in a folder must use the same package name, and it’s common practice to name the package after the folder.

All init functions in any code file that are part of the program will get called before
the main function.



This variable is located outside the scope of any function and so is considered a
package-level variable.

In Go, identifiers are either exported or unexported from a package. An exported
identifier can be directly accessed by code in other packages when the respective
package is imported. These identifiers start with a capital letter. Unexported identifi-
ers start with a lowercase letter and can’t be directly accessed by code in other pack-
ages
