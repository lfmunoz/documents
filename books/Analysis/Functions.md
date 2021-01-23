---
title: Functions
mathjax: true
layout: default
toc: true
---


# Functions

* [Analysis](Introduction.html)


Loosely speaking, a function is rule that, for each element in some set D of possible inputs, assigns a possible output.


<div class="definition" markdown="block">
**Definition**: Function

A function f from a set X to a set Y, denoted $f: X \to Y$, associates to each $x \in X$ an element $f(x) \in Y$.

The set X is called the **domain** of f, and the elements $f(x)$ are called the **values** of f. The set of all values of f is called the **range** of f.  The set Y is called the **co-domain** of f. 

</div>


It never has one "A" pointing to more than one "B",

If it passes the vertical line test it is a function


* Dom(f) denotes the domain of f.
* Cod(f) denote the co-domain of f.

We can think of f as matching subsets of X with subsets of Y and vice-versa. X, the domain, is the set of possible inputs to the function. Y the co-domain, is the set from which the function's output values are chosen. The co-domain is the set of values that could possibly be output, while the range is the set of values that actually do come out.

The notation $f: X \to Y$ is read "f is a function from X to Y" or "f is a function that maps X to Y".

the set of elements that get pointed to in Y (the actual values produced by the function) is called the Range.


A function can then be defined as a set of ordered pairs



<div class="definition" markdown="block">
**Definition**:  Image

Let A and B be two sets and let f be a mapping of A into B. 

If $E \subset A$, $f(E)$ is defined to be the set of all elements $f(x)$, for $x \in E$. We call $f(E)$ the **image** of E under f. In this notation, $f(A)$ is the range of f. It is clear that $f(A) \subset B$. If $f(A) = B$ then we say that f maps A **onto** B (onto is more specific than into).
</div>


<div class="definition" markdown="block">
**Definition**:  onto (or surjective)

A function is said to be **onto** if for each $y \in Y$ there is an $x \in X$ with $f(x)=y$.

or

A function is **onto** or **surjective** if every element of B is the image under f of some element of A.

or

If $f\colon X \rightarrow Y$, then $f$ is said to be **onto** or **surjective** if $\forall y \in Y, \, \exists x \in X, \;\; f(x)=y$
</div>

A not-surjective function has a "hole" in its range. 
This means the function lacks a “right inverse” $f∘g=1$. 
There’s no complete way, given a desired  f(x) , to find the desired x .

The function  $f: \mathbb{N} \to \mathbb{N}$  given by $f(x)=x^2$ is not surjective, because not all numbers are perfect integer squares. For example, there is no x such that $f(x)=3$ because $\sqrt{3} \not \in \mathbb{N}$. 


<div class="definition" markdown="block">
**Definition**:  Inverse image

Let A and B be two sets and let f be a mapping of A into B. 

If $E \subset B$ then $f^{-1}(E)$ denotes the set of all $x \in A$ such that $f(x) \in E$. We call $f^{-1}(E)$ the **inverse image** of E under f. If $y \in B$ then $f^{-1}(y)$ is the set of all $x \in A$ such that $f(x) = y$.  If, for each $y \in B$, $f^{-1}(y)$ consists of at most one element of A, then f is said to be a 1-1 (**one-to-one**) mapping of A into B.

This may be also expressed as follows: f is a 1-1 mapping of A into B provided that $f(x_1) \neq f(x_2)$ whenever $x_1 \neq x_2$, $x \in A, x_2 in A$.



</div>

<div class="definition" markdown="block">
**Definition**:  one-to-one (or injective)

The function f is said to be **one-to-one** if for all $x, x' \in X$, if f(x) = f(x') then x = x' (or, equivalently, if $x \neq x'$ then $f(x) \neq f(x')$).

or 

f is called one-to-one, or injective, iff different elements of X always have different elements of Y.

or

$ \forall a,b \in X, \;\; f(a)=f(b) \Rightarrow a=b$
</div>

A not-injective function has a "collision" in its range. 
This means the function lacks a “left inverse”  $g∘f=1$.
There’s not a complete way to recover the original value of x, given only f(x).

To be Injective, a Horizontal Line should never intersect the curve at 2 or more points.


$f(x)=x^2$ is not injective, because  $f(−x)=f(x)$







A bijection is one-to-one and onto. 

<div class="definition" markdown="block">
**Definition** : Cartesian Product

For two nonempty sets A and B, the Cartesian product, denoted $A \times B$ is the set of all ordered paris (a,b) of elements $a \in A$ and $b \in B$. That is,

$$ A \times B = \{  (a,b) ~ | ~ a \in A ~~~ \text{and} ~~~ b \in B \}$$

The Cartesian product of two sets A and B is the set of all pairs (a,b) where $a \in A$ and $b \in B$.
</div>

<div class="definition" markdown="block">
**Definition** : Continous Function

The function f is continuous at some point a of its domain if the limit of f(x) as x approaches a through the domain of f exists and is equal to f(a).

$$\lim_{x \to a} f(x) = f(a) $$

</div>














# References

* https://www.mathsisfun.com/sets/injective-surjective-bijective.html
