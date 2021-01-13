---
title: Mathematics Foundations
mathjax: true
layout: default
toc: true
---

#  Foundations






Mathematics is just a language.

> What we cannot speak about clearly, that we must passover in silence - Wittgenstein

If we have concepts about the real world and it's not possible 
to cast them into precise mathematical form that usually is an indicator that some aspects of these concepts have not been well understood .





* Classical Mechanics
* Electromagnatis
* quantum mechanis
* stastistical physics
* general relativity

To understand any of that at a professional level, you first need to understand:

* Geometry - Metric 
* Bundles 
* Differential Manifolds 
* Topological Manifolds - Interesting topologies, locally look like some $R^d$
* [Topology](Topology.html) - A notion of continuity 
* [Set Theory](/documents/books/SetTheory/Introduction) - From the language of Logic we write Axioms
* [Logic](/documents/books/Logic/Introduction.html)- Propositional / Predicate Logic




A recurrent theme in mathematics is the study/classification of spaces by means of structure preserving maps between those spaces.

A space is meant to be some set equipped with some structure.


Definition: A map $\phi A \to B$ is a relation such that for every $a \in A$ there exists exactly one $\a \in B$ such that $\phi(a,b)$

Notation: $a \to \phi(a)$ is an abuse of notation

$phi(a,b)$ is a relation that takes two variables a produces a truth value. 




Euclid's work consists of a single deductive chain of 465 theorems.

Applied Mathematics - Developed with an eye on practical applications.

Pure Mathematics - Basis for applied mathematics. The real mathematics. Pure mathematics is a box of games.

Pure mathematics is the world's best game. It is dramatic, challenging, endless and full of surprises.


# Logic

according to the orthodox view of logic,
logic has no special content, not even objects so ethereal as those apparently
needed for mathematics.

# Set Theory

On the neo-Fregean conception, all mathematics is embedded in set
theory and all the entities of mathematics are sets. In particular, numbers
are sets. But, it appears, if numbers are sets then they must be particular
sets, and the philosopher should be able to identify which ones they are.
However, mathematicians have long recognized that arithmetic can be
reduced to set theory in many different ways: the natural numbers can
be identified with the von Neumann numbers, the Zermelo numbers, or
with any of an infinite number of other sequences of sets.


# Analysis

In the orignal formulation by Leibniz and Newton there were deficiencies which centred
around the use of the infinite. The use of the infinitely large, for instance the use of $\dots$
and the infinitely small, i.e, the infinitesimals.

Through the work of Cauch, Bolzano and Weierstrass, calculus acquired the rigorous foundation which
is used today.


Libeiz an Netwoton freely used infinitesimals

an infinitely small number

Berkeley called infinitesimals "ghosts of departed quantities"
The use of limits, with formal definitions in terms of $\epislons$
and $\deltas$ came to replace the informal use of infinitesimals in mathematical proofs

infinitesimals were intuitive and they worked.


In early 1960s, Abraham Robinson developed a system of hyperral numbers,
extending the system of real numbers by adjoining infinitely
small and infinitely large numbers.

With hyperreals, it's possible to legitimately use infinitesimals for calculus.
This is called Nonstandard analysis. It simplified classical definitions, theorems,
and proofs and also led to new discoveries.






<div class="definition" markdown="block">
**Definition:** A sequence (of real numbers)

A **sequence** of real numbers is a function from the natural numbers to the real numbers. 

$f : N \to R$

Thus a sequence can be denoted by any of: 

$f(m), f(m + 1), f(m + 2), \dots$ 

$\\{a_i \\}_{i=m}^{\infty}$  where $a_i = f(i)$

$\\{a_n \\}_{n \in N}$ 

</div>

A sequence is a "list" of numbers that may or may not exhibit a certain pattern.




http://www.ms.uky.edu/~droyster/courses/fall06/PDFs/Chapter06.pdf

https://mathcs.org/analysis/reals/numseq/sequence.html

<div class="definition" markdown="block">
**Definition:** Convergence

A sequence  of real (or complex) numbers is said to converge to a real (or complex) number L if for every  $\epsilon > 0$ there is an integer $N > 0$ 
such that if $j > N$ then $\| a_j - L \| < \epsilon$

If {ak} converges to L we will write lim k→∞ ak = L or simply ak → L. If a sequence does not converge, then we say that it **diverges**.
</div>



# Abstract Algebra

Also known as Modern Algebra


A group is an ordered pair (G, *) where G is a set and * is binary operation on G satisfying the following axioms:

