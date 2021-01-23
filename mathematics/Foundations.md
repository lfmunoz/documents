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


<div class="definition" markdown="block">

**Definition:** 

Let x be a set. 

For each formula $\phi(x)$ we write $\\{ z \in x : \phi(z) \\}$ for the set y in ZF4 such that

$\forall z (z \in y \iff (z \in x \land \phi(z)))$.

We write $\mathscr{P}(x)$, called the power set of x, for the y in ZF5 such that

$\forall z ( z \in y \iff z \subseteq x).$

We write $\cup x$, called the union of x, for the y in ZF6 such that

$\forall z (z \in y \iff \exists w ( z \in w \land w \in x))$.

</div>


<div class="definition" markdown="block">

**Definition:** Function

Let F be a set of ordered pairs. F is said to be a function if

$\forall a \forall b \forall b' (( \langle a, b \rangle \in F \land \langle a, b' \rangle  \in F ) \to b = b' )$

The **domain** of a function F, written as Dom(F), is the set defined by

$Dom(F) = \\{a \in \cup (\cup F) : \exists b \langle a, b \rangle \in F \\}$


 **Alternative:**

 Let A, B and F be sets with $F \subseteq A \times B$. We say that F is a **function** with **domain** A
 and **codomain** B if

 $\forall a (a \in A \to \exists b( b \in B \land \langle a,b \rangle \in F \land \forall b' ( \langle a,b' \rangle \in F \to b' = b) ))$

 In words: A function with domain A and codomain B is a subset f of $A \times B$ such that, for each $a \in A$, there is one and only one $b \in B$ such that  $(a,b) \in f$
</div>


<div class="definition" markdown="block">

**Definition:** 

For sets X and Y the **Cartesian product**, written as $X \times Y$, is the set

$\\{x \in \mathscr{P}(\mathscr{P}(X \cup Y)): \exists x \exists y ((x \in X \land y \in Y) \land z = \langle x,y \rangle)\\}$

</div>

<div class="definition" markdown="block">

**Definition:** 


Suppose that the set F is a function

The range of a function F, written as Range(F), is the set defined by

$Range(F) = \\{b \in \cup(\cup(F)) : \exists a \langle a,b \rangle \in F \\}$.

Suppose that X is a subset of Dom(F). Then the restriction of the function F to X, written as $F\|_x$ is the set

$\\{\langle x, y \rangle \in F : a \in X \\}$.

In general, if G is a function with $G \subseteq F$, then G is said to be a restriction of F and F is said to be an 
extension of G.

</div>



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

<div class="definition" markdown="block">
**Definition:** Group  

A **group** is an ordered pair (G, *) where G is a set and * is binary operation on G satisfying the following axioms:

(i) Associative: (a * b) * c = a * (b * c), for all $a,b,c \in G$.

(ii) Identity: There exists an element e in G, called an **identify** of G, such that for all $a \in G$ we have 
a * e  = e * a = a.

(iii) Inverse: For each $a \in G$ there is an element $a^{-1}$ of G, called an **inverse** of a, such that 
$a * a^{-1} = a^{-1} * a = e$.

**Definition:** Abelian Group (commutative)

The group (G, *) is called **abelian** (or commutative) if a * b = b * a for all $a, b \in G$

</div>

Mnemonic: AII A

If G is finite we say G is a **finite group**. Note that axiom (ii) ensures that a group is always nonempty.






# Latex



$\mathfrak{A}$

$\mathcal{A}$


$\mathbb{A}$

$\mathbf{A}$

$\mathscr{A}$


