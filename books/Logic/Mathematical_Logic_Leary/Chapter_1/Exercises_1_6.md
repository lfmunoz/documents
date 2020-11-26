---
title: Exercises 1.6
mathjax: true
layout: default
toc: true
---



# Exercises 1.6


----
## Exercise 1.6.1

**Problem:** Consider the structure constructed in Example 1.6.2. Find the value of each of the following: 0 + 0, 0E0, S0 · SS0. Do you think 0 < 0 in this structure?


**Solution:**

$A = \\{ Oberon, Titania, Puck, Bottom \\}$

$0^{\mathbb{A}} = Bottom $


**(a)** 0 + 0

$Bottom +^{\mathbb{A}} Bottom = Oberon$

**(b)** 0E0 

$Bottom E^{\mathbb{A}} Bottom = Punk$

**(c)** S0*SS0 

$S^{\mathbb{A}}(Bottom) \cdot^{\mathbb{A}} S^{\mathbb{A}}(S^{\mathbb{A}}(Bottom))$

$ = Titania \cdot^{\mathbb{A}} Bottom$
 
$ = Titania $


**(d)** Do you think 0 < 0 is in this structure?

Yes it is in the structure, you can look it up in the table. 

0 < 0 is false.



----
## Exercise 1.6.2


**Problem:** Suppose that L is the language {0, +, <}. Let’s work together to describe an L-structure A. Let the universe A be the set consisting of all of the natural numbers together with Ingrid Bergman and Humphrey
Bogart. You decide on the interpretations of the symbols. What is the
value of 5 + Ingrid? Is Bogie < 0? 


**Solution:**

We define the structure $\mathbb{A}$ by

$A = \mathbb{N} \cup \\{  Ingrid,, Bogie \\}$ and


$0^\mathbb{A}  = Bogie$

$<^\mathbb{A}$ is the equality relation, that is, 
$<^\mathbb{A} = \\{ (x, x) | x \in A \\}$

$a +^\mathbb{A}  b = 0$ for any $a, b \in A$

**(a)**  What is the value of 5 + Ingrid? 

0. The sum of any two elements of the universe is 0.

**(b)** Is Bogie < 0? 

The answer is Yes if the pair is in the set $<^\mathbb{A}$ \
The answer is No if the pair is not in set. 

In this case the answer is no,
the pair (Bogie, 0) is not in the set.





----
## Exercise 1.6.3

**Problem** Here is a language consisting of one constant symbol, one 3-ary function
symbol, and one binary relation symbol: L is {[, ], \}. Describe an L-model that has as its universe R, the set of real numbers. Describe
another L-model that has a finite universe.




----
## Exercise 1.6.4

**Problem:** Write a short paragraph explaining the difference between a language
and a structure for a language.

A language is a collection of distinct symbols which are categorized into parenthesis, quantifier, function symbols, constant symbols etc.  The structure of a language gives an interpretation of what the symbols mean, 1 is a constant symbol but what it represents is a quantity or length.




----
## Exercise 1.6.5


5. Suppose that A and B are two L-structures. We will say that A
and B are isomorphic and write A ∼
= B if there is a bijection
i : A → B such that for each constant symbol c of L, i(c A ) =
c B , for each n-ary function symbol f and for each a 1 , . . . , a n ∈ A,
i(f A (a 1 , . . . , a n )) = f B (i(a 1 ), . . . , i(a n )), and for each n-ary relation
symbol R in L, (a 1 , . . . , a n ) ∈ R A if and only if (i(a 1 ), . . . , i(a n )) ∈ R B .
The function i is called an isomorphism.


(a) Show that ∼
= is an equivalence relation. [Suggestion: This means
that you must show that the relation ∼
= is reflexive, symmetric, and
transitive. To show that ∼
= is reflexive, you must show that for any
structure A, A ∼
= A, which means that you must find an isomor-
phism, a function, mapping A to A that satisfies the conditions
above. So the first line of your proof should be, “Consider this
function, with domain A and codomain A: i(x) = something bril-
liant.” Then show that your function i is an isomorphism. Then
show, if A ∼
= B, then B ∼
= A. Then tackle transitivity. In each
case, you must define a particular function and show that your
function is an isomorphism.]
(b) Find a new structure that is isomorphic to the structure given in
Example 1.6.2. Prove that the structures are isomorphic.
(c) Find two different structures for a particular language and prove
that they are not isomorphic.
(d) Find two different structures for a particular language such that
the structures have the same number of elements in their universes
but they are still not isomorphic. Prove they are not isomorphic.

----
## Exercise 1.6.6

6. Take the language of Example 1.6.4 and let C be the set of all L-terms.
Create an L-structure C by using this universe in such a way that the
interpretation of a term t is not equal to t.

----
## Exercise 1.6.7

7. If we take the language L N T , we can create a Henkin structure for that
language in the same way as in Example 1.6.4. Do so. Consider the
L N T -formula S0 + S0 = SS0. Is this formula “true” (whatever that
means) in your structure? Justify your answer.