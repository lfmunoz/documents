---
title: Exercises 1.6
mathjax: true
layout: default
toc: true
---



# Exercises 1.6


----
## Exercise 1.5.1

1. Consider the structure constructed in Example 1.6.2. Find the value of
each of the following: 0 + 0, 0E0, S0 · SS0. Do you think 0 < 0 in this
structure?


Bottom + Botton = Oberon

OEO = Pink

SO = Titania



----
## Exercise 1.5.2


2. Suppose that L is the language {0, +, <}. Let’s work together to de-
scribe an L-structure A. Let the universe A be the set consisting of all
of the natural numbers together with Ingrid Bergman and Humphrey
Bogart. You decide on the interpretations of the symbols. What is the
value of 5 + Ingrid? Is Bogie < 0? (Suggested solution on page 286.)




----
## Exercise 1.5.3

3. Here is a language consisting of one constant symbol, one 3-ary function
symbol, and one binary relation symbol: L is {[, ], \}. Describe an L-
model that has as its universe R, the set of real numbers. Describe
another L-model that has a finite universe.

----
## Exercise 1.5.4

4. Write a short paragraph explaining the difference between a language
and a structure for a language.

----
## Exercise 1.5.5


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
## Exercise 1.5.6

6. Take the language of Example 1.6.4 and let C be the set of all L-terms.
Create an L-structure C by using this universe in such a way that the
interpretation of a term t is not equal to t.

----
## Exercise 1.5.7

7. If we take the language L N T , we can create a Henkin structure for that
language in the same way as in Example 1.6.4. Do so. Consider the
L N T -formula S0 + S0 = SS0. Is this formula “true” (whatever that
means) in your structure? Justify your answer.