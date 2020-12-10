---
title: Algorithms
mathjax: true
layout: default
toc: true
---


# Algorithms 

An algorithm is a well defined set of rules for solving a problem.

**Note** If you need to write a program that will be used once on small amounts of data and then discarded, then you should select the easiest-to-implement algorithm you know, get the program written and debugged, and move on to something else


**Table of Contents**
* [Sorting](Sorting.html)
    * Quick Sort, Merge Sort, Radix Sort
* [String](String.html)
    * Longest Common Subsequence
    * String Matching
* [Complete Search](CompleteSearch.html)
    * bute force or recursive backtracking
* [Dynamic Programming](DP.html)



# 2D Algorithms

```
------> y-axis
| A B
| C D      
V
x-axis

A = (0,0), B = (0, 1), C = (1, 0) , D = (1,1)

```

<details>
<summary> matrix.cpp </summary>

<p markdown="block">
```cpp
{% include_relative src/matrix.cpp %}
````
</p></details>  


```
size_t index( int x, int y ) const { return x + m_width * y; }
array = new int[ width * height ];
array[ index( x, y )]
```


# Masters method


| --- | ----------- |
| $T(n) = T(n-1) + 1$ | $O(n)$ |
| $T(n) = T(n-1) + n$ | $O(n^2)$ |
| $T(n) = T(n-1) + \log{n}$ |  $O(n\log{n})$ |
| $T(n) = 2 T(n-1) + 1$ | $O(2^n)$ |
| $T(n) = 3 T(n-1) + 1$ | $O(3^n)$ |
| $T(n) = 2 T(n-1) + n$ | $O(n2^n)$ |


$T(n) = a T(n-a) + f(n)$

$a > 0, b > 0, and f(n) = O(n^k)$ where $k \geq 0$



## References 

* Masters Theorem Decreasing Function - Abdul Bari
* https://www.youtube.com/watch?v=OynWkEj0S-s




# Learning


Competitive Programming 3 by Steven Halim and Felix Halim

Solutions Manual: [https://github.com/lfmunoz/competitive_programming](https://github.com/lfmunoz/competitive_programming)


