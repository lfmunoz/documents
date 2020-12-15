---
title: String
mathjax: true
layout: default
toc: true
---

# String Algorithms 

[Algorithms](Introduction.html)

## String Matching 

Also known as: String Searching 

**Problem:** Find the starting index (or indices) of a substring called a pattern in a longer string called the text.

* pattern of size m is the string we are searching for
* text of size n is the string where we are searching for pattern

**Solution:**

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




## String Edit Distance

Also known as: String Alignment 




**Problem:** Given two strings A and B and the operations, replace, delete, or insert,  
what is the minimum number operations to convert A into B?


Spell checking, Comparing DNA Sequences, Longest Common Subsequence.

**Solution:**

This is solved using [Dynamic Programming](DP.html) because it is an optimization problem.

```
      a b c d e f
    --------------
  | 0 1 2 3 4 5 6
a | 1 0 1 2 3 4 5
z | 2 1 1 2 3 4 5
c | 3 2 2 1 2 3 4
e | 4 3 3 2 2 2 3
d | 5 4 4 3 2 3 3 

```

Looking at the first row, the 0 means that given the empty string, it takes 0 operations to convert it into an empty string. The 1 means, given the string "a" and the empty string it takes 1 operations to convert the empty string to "a". 

Looking at the second row, the 1 means given the string "a" and the empty string it takes 0 operations to convert one to the other.  The next column is a 0, it means to convert "a" to "a" is zero operations.

If they are the same you get the diagonal value, if they are different you get the minimum of three.

Recurrence 

```
DP(i,j) = min( 
    cost of replace x[i] -> y[y] + DP(i+1, j + 1) ,  
    cost of insert y[j] into x + DP(i, j+1),
    cost of delete of x[i] + DP(i+1, j)
  )

```








### Longest Common Subsequence (LCS)


**Problem:** The characters are not together but they are coming in the same order.

**Solution:**

The naive implementation is exponential time $O(2^n)$

With [memozation](DP.html) you create a table so the time is $O(m*n)$

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

