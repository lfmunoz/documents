---
title: Sorting
mathjax: true
layout: default
toc: true
---





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

