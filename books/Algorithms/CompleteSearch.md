---
title: Complete Search
mathjax: true
layout: default
toc: true
---




# Complete Search

The **Complete Search** technique, also known as **brute force** or **recursive backtracking**, is a method for solving a problem by traversing the entire (or part of the) search space to obtain the required solution. During the search, we are allowed to prune (that is, choose not to explore) parts of the search space if we have determined that these parts have no possibility of containing the required solution.

* Generally, the earlier you can prune the search space, the better.
* Considering symmetries can actually complicate the code. We want shorter code to minimize bugs.


Iterative approaches are used when one can derive the different states easily with some formula relative to a certain counter and (almost) all states have to be checked, e.g. scanning all the indices of an array, enumerating (almost) all possible subsets of a small set, generating (almost) all permutations, etc.

Recursive Backtracking is used when it is hard to derive the different states with a simple index and/or one also wants to (heavily) prune the search space, e.g. the 8-queens chess problem.

Complete Search

A complete Search solution is used when there is clearly no other algorithm available (e.g. the task of enumerating all permutations of {0, 1, 2, . . . , N − 1} clearly requires O(N!) operations)

Recursive Complete Search

The main idea is to construct solutions one component at a time and evaluate such partially constructed candidates as follows: If a partially constructed solution can be developed further without violating the problem’s constraints, it is done by taking the first remaining legitimate option for the next component. If there is no legitimate option for the next component, no alternatives for any remaining component need to be considered. In this case, the algorithm backtracks to replace the last component of the partially constructed solution with the next option for that component.

Typically, backtracking involves undoing a number of wrong choices—the smaller this number, the faster the algorithm finds a solution. Although in the worst-case scenario a backtracking algorithm may end up generating all the same candidate solutions as an exhaustive search, this rarely happens.


###  n-Queens Problem

**Problem:** Place n queens on an n × n chessboard so that no two queens attack each other by being in the same column, row, or diagonal.



