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

**Solution:** In the naive implementation you get a O(n*m) algorithm by searching for the pattern 
starting from each index in the text. You can get worse case with the following inputs: 

* text    = aaaaaaaaaaaaaab
* pattern = aaaaaaaaaaaaab

<details>
<summary> string_matching.cpp </summary>

<p markdown="block">
```cpp
{% include_relative src/string_matching.cpp %}
````
</p></details> <br> 



### Reference 

* Knuth-Morris-Pratt KMP String Matching Algorithm - Abdul Bari
* https://www.youtube.com/watch?v=V5-7GzOfADQ




## String Edit Distance

Also known as: **String Alignment Problem**

The **edit distance** or Levenshtein distance is the minimum number of editing operations needed to transform a string into another string.

```
distance(LOVE,MOVIE) = 2
LOVE -> MOVE  (Replace L with M)
MOVE -> MOVIE (INSERT I)
```

**Applications:** Spell checking, Comparing DNA Sequences, Longest Common Subsequence.

**Problem Statement:** Given two strings A and B and the operations, replace, delete, or insert, what is the minimum number operations to convert A into B?


**Solution:** This is solved using [Dynamic Programming](DP.html) because it is an optimization problem.

```
    M O V I E
  0 1 2 3 4 5
L 1 1 2 3 4 5
O 2 2 1 2 3 4
V 3 3 2 1 2 3
E 4 4 3 2 2 2
```

Suppose string x has length n and string y has length m. We want to calculate the distance between x and y. We define a function distance(a,b) which gives the distance between prefixes x[0...a] and y[0...b]. The distance is then distance(n-1, m-1).

```
distance(a,b) = min (
  distance(a, b-1) + 1,   // insert char at end of x
  distance(a-1, b) + 1,   // remove last char from x
  distance(a-1, b-1) + cost(a,b) // match or modify last char of x
)

cost(a,b) = 0  if x[a] = x[b]
            1  otherwise
```

<details>
<summary> string_alignment.cpp </summary>

<p markdown="block">
```cpp
{% include_relative src/string_alignment.cpp %}
````
</p></details><br>




## Longest Common Subsequence (LCS)


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
</p></details><br>



### Reference 


* 4.9 Longest Common Subsequence (LCS) - Recursion and Dynamic Programming- Abdul Bari
* https://www.youtube.com/watch?v=sSno9rV8Rhg

