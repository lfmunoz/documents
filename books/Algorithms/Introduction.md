---
title: Algorithms
mathjax: true
layout: default
toc: true
---


# Algorithms 

An algorithm is a well defined set of rules for solving a problem.

**Note** If you need to write a program that will be used once on small amounts of data and then discarded, then you should select the easiest-to-implement algorithm you know, get the program written and debugged, and move on to something else


# String Matching 

String Matching or String Searching is the problem of finding the starting index (or indices) of a substring called a pattern in a longer string called the text.

<details>
<summary> string_matching.cpp </summary>

<p markdown="block">
```cpp
{% include_relative src/string_matching.cpp %}
````
</p></details>  


## Reference 

* Knuth-Morris-Pratt KMP String Matching Algorithm - Abdul Bari
* https://www.youtube.com/watch?v=V5-7GzOfADQ


# Sorting

**Problem Statement:**

**Input:** Sequence $a_1,a_2, \dots, a_n$ of numbers. \
**Output:** Permutation  of $a_1, a_2, \dots, a_n$  such that $a_1 < a_2 <  \dots < a_n$ 

**Note:** A **permutation** is a re-arrangement of numbers.


**Should I use built-in sorting?** Yes

* C++ STL algorithm::sort
* Java Collections.sort
* JavaScript [].sort()

**What is the quickest sorting method to use?**

No algorithm is best in all cases. Generally Quick Sort, Merge Sort, or Radix Sort.


| Algorithm | Data Structure | Time Complexity | Worst Case Auxiliary Space Complexity |||
| | | Best | Average | Worst | Worst | 
| --- | --- | --- | --- | --- | --- | 
| [Quick Sort](QuickSort.html) | Array | O(n log(n)) | O(n log(n))  | $O(n^2)$  | O(log(n))  | 
| [Merge sort]() | Array | O(n log(n))| O(n log(n))  | O(n log(n)) | O(n)  | 
| [Heapsort]() | Array | O(n log(n)) | O(n log(n))  | O(n log(n)) | O(1)  | 
| [Bubble Sort]() | Array | O(n) | $O(n^2)$ | $O(n^2)$  | O(1) | 
| [Insertion Sort]() | Array| $O(n^2)$ | $O(n^2)$ | $O(n^2)$  | O(1) | 
| [Selection Sort]() | Array| $O(n^2)$ | $O(n^2)$ | $O(n^2)$  | O(1) | 
| [Bucket Sort]() | Array| O(n+k) | O(n+k) | $O(n^2)$ | O(nk) | 
| [Radix Sort]() | Array | O(nk) | O(nk) | O(nk) | O(n+k) | 

----
**Theorem:** Complexity of sorting. 

Any comparison-based sorting program must use at least $$\lceil \lg{N!} \rceil > N \lg{N - N / ln2}$$ comparisons for some input.

**Proof**

Each comparison can cut down the number of possible arrangements of the elements to be considered by at most 2. Since there are N! possible arrangements before the sort and the goal is to have one possible arrangement (the sorted one), the number of comparisons must be at least the number of times N! can be divided by 2 before reaching a number less than unity, that is to say $\lceil lg N! \rceil$

----


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


