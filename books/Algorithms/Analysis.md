---
title: Algorithms Analysis
mathjax: true
layout: default
toc: true
---


# Algorithms Analysis

**Algorithms Analysis** is the theoretical study of computer program performance and resource usage.

Think about running an algorithm over all possible instances of data that can be fed to it.

* **worst-case complexity** of the algorithm is the function defined by the maximum number of steps taken in any instance of size n.
* **best-case complexity** is the function defined by the minimum number of steps taken in any instance of size n.
* **average-case complexity** is the function defined by the average number of steps over all instances of size n

"Dropping all factors" and of "keeping the largest growing term" is what we call **asymptotic behavior**.


Runtime generally means the number of steps to execute a program.


# The Big Oh Notation

<div class="definition" markdown="block">
**Theorem:**  Big Oh

We write $T(n) = O(f(n))$ if and only if there exists constant**s** c, $n_0 > 0$ such that $T(n) \leq c \cdot f(n)$ for all $n \geq n_0$.

</div>


$ f(n) = O (g (n) ) $ means $c \cdot g(n)$ is an upper bound on f(n). Thus there exists some constant c such that $f(n) \leq c \cdot g(n)$, for large enough n (i.e., $n \leq n_o$ for some constant $n_o$).

The Big Oh simplifies our analysis by ignoring levels of detail that do not impact our comparison of algorithms. It ignores the difference between multiplicative constants, $2*n$ and $n$ are identical.


<div class="definition" markdown="block">
**Theorem:**  

If $T(n) = a_k n^k + \dots + a_1 n + a_0$ then $T(n) = O(n^k)$.



**Proof:** Choose $n_0 = 1$ 

Need to show that  $\forall n \geq 1$, $T(n) \leq c \cdot n^k$

We have, for every $n \geq 1$,

$T(n) \leq \|a_k\| n^k  + \|a_{k-1}\| n^{k-1} + \dots + \|a_1\|n + \|a_0\| $.

$T(n) \leq \|a_k\| n^k + \|a_{k-1}\| n^k + \dots + \|a_1\| n^k+ \|a_0\| n^k $.

$c = \|a_k\| + \|a_{k+1}\| + \dots + \|a_1\| + \|a_0\|,$

$T(n) \leq  c \cdot n^k $.

</div>






# Masters method



Applies to recurrences of the form

$T(n) = a T(n/b) + f(n) $

where $a \geq 1, b > 1$ and f(n) is asymptotically positive.



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


