---
title: String
mathjax: true
layout: default
toc: true
---

# String Algorithms 

## String Matching 

[Algorithms](Introduction.html)

String Matching or String Searching is the problem of finding the starting index (or indices) of a substring called a pattern in a longer string called the text.

* pattern of size m is the string we are searching for
* text of size n is the string where we are searching for pattern

In the naive implementation you get a O(n*m) algorithm by searching for the pattern 
starting from each index in the text. You can get worse case with the following inputs: 

* text    = aaaaaaaaaaaaaab
* pattern = aaaaaaaaaaaaab

<details>
<summary> string_matching.cpp </summary>

<p markdown="block">
```cpp
{% include_relative src/string_matching.cpp %}
````
</p></details>  



### Reference 

* Knuth-Morris-Pratt KMP String Matching Algorithm - Abdul Bari
* https://www.youtube.com/watch?v=V5-7GzOfADQ



## String Alignment 



## Longest Common Subsequence

The characters are not together but they are comming in the same order.


The naive implementation is exponential time $O(2^n)$

With memozation you create a table so the time is $O(m*n)$



<details>
<summary> lcs.cpp </summary>

<p markdown="block">
```cpp
{% include_relative src/lcs.cpp %}
````
</p></details>  



### Reference 


* 4.9 Longest Common Subsequence (LCS) - Recursion and Dynamic Programming- Abdul Bari
* https://www.youtube.com/watch?v=sSno9rV8Rhg

