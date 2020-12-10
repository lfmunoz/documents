---
title: Complete Search
mathjax: true
layout: default
toc: true
---


# Dynamic Programming


Dynamic programming is a method by which a solution is determined based on solving successively similar but smaller problems. This technique is used in algorithmic tasks in which the solution of a bigger problem is relatively easy to find, if we have solutions for its sub-problems.

* DP is primarily used to solve optimization problems (min or max result) and counting problems.
* A type of exhaustive search done in a clever way so you can get polynomial time.
* The name doesn't mean anything it just sounded cool to the guy who invented it, Richard Bellman
* Take a problem make sub-problems and reuse the sub-problem.

The key skills that you have to develop in order to master DP are the abilities to determine the problem states and to determine the relationships or transitions between current problems and their sub-problems.



```python
def fin(n, memo):
  if memo[n] != null:
    return memo[n]
  if n == 1 or n == 2:
    result = 1
  else 
    result = fib(n-1) + fib(n-2)
  memo[n] = result
  return result
```



## Reference


* 4 Principle of Optimality - Dynamic Programming introduction
* https://www.youtube.com/watch?v=5dRGRueKU3M