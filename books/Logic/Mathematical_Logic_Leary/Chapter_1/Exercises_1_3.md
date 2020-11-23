---
title: Exercises 1.3 
mathjax: true
layout: default
toc: true
---

## Exercises 1.3

----
1. Suppose that the language L consists of two constant symbols, ♦ and
♥, a unary relation symbol U, a binary function symbol [, and a 3-
ary function symbol ]. Write down at least three distinct terms of the
language L. Write down a couple of nonterms that look like they might
be terms and explain why they are not terms. Write a couple of formulas
and a couple of nonformulas that look like they ought to be formulas.

L♦ ♥  constant

b binary

\# 3-anary function

♦♦
Y♦
♦b♦


----
2. The fact that we write all of our operations on the left is important
for unique readability. Suppose, for example, that we wrote our binary
operations in the middle (and did not allow the use of parentheses). If
our language included the binary function symbol #, then the term
u#v#w
could be interpreted two ways. This can make a difference: Suppose
that the operation associated with the function symbol # is “subtract.”
Find three real numbers u, v, and w such that the two different interpretations of u#v#w lead to different answers. Any nonassociative binary
function will yield another counterexample to unique readability. Can
you think of three such functions?

u # v # w



----
3. The language of number theory is
LNT is {0, S, +, ·, E, <},
where the intended meanings of the symbols are as follows: 0 stands for
the number zero, S is the successor function S(x) = x + 1, the symbols
+, ·, and < mean what you expect, and E stands for exponentiation,
so E(3, 2) = 9. Assume that LNT -formulas will be interpreted with
respect to the nonnegative integers and write an LNT -formula to express
the claim that p is a prime number. Can you write the statement of
Lagrange’s Theorem, which states that every natural number is the sum
of four squares?
Write a formula stating that there is no largest prime number. How
would we express the Goldbach Conjecture, that every even number
greater than two can be expressed as the sum of two primes?
What is the formal statement of the Twin Primes Conjecture, which
says that there are infinitely many pairs (x, y) such that x and y are
both prime and y = x + 2? The Bounded Gap Theorem, proven in
2013, says that there are infinitely many pairs of prime numbers that
differ by 70,000,000 or less. Write a formal statement of that theorem.
Use shorthand in your answers to this problem. For example, after you
have found the formula which says that p is prime, call the formula
Prime(p), and use Prime(p) in your later answers.


LNt is 
{0, s, t, *, E, <}

----
4. Suppose that our language has infinitely many constant symbols of the
form 0
,
00
,
000
, . . . and no function or relation symbols other than =. Explain why this situation leads to problems by looking at the formula
=000000. Where in our definitions do we outlaw this sort of problem?