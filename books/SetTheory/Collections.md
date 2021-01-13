---
title: Collections
mathjax: true
layout: default
toc: true
---



# Collections

* [Introduction](Introduction.html)

Note: a, b, c denote collections


## Foundations 

An **aggregate** is a single entity which is in some manner composed of, or formed from, some other entities.
Aggregate is an umbrella term for all notions: set, class, extension, collection.

Understanding a **fusion** can help with collections, both are formed by bundling objects together. A fusion is nothing more than the sum of its parts, where a collection is something more, what more is difficult to say. A collection does not merely lump several objects together into one, it keeps the things distinct and is a further entity over and above them.

Collections can always be characterized determinately by their **membership**. The relation of membership is primitive. It has a non-logical primitive the binary relation symbol "$\in"$. The formula "$x \in y$" is read "x belongs to y"

We start with a theory T about objects and the objects in the domain of interpretation of T are called **individuals**. To not confuse claims about T as applying to collections we defined the predicate U(x) to mean that x is an individual and relativize all the axioms of T to U.

An urelement or individual is an object that is not a set, but that may be an element of a set.


<div class="definition" markdown="block">
**Definition:** Collection

If $\Phi(x)$ is a formula, then the term $i!y(\text{not} ~ U(y) ~ \text{and} ~ (\forall x )(x \in y  \iff \Phi(x)))$ is abbreviated $\\{x : \Phi(x) \\}$ and read "the collection of all x such that $\Phi(x)$".

</div>


In words: If $\\{x : \Phi(x) \\}$ exists, it is the unique non-individual whose elements are precisely the objects satisfying $\Phi$.

<div class="definition" markdown="block">
**Lemma**: Membership

If $\Phi(x)$ is a formula such that $a = \\{x : \Phi(x) \\}$ exists, then $(\forall x)( x \in a \iff \Phi(x))$.

</div>

<div class="definition" markdown="block">
**Lemma**: Unique-non-individual

If $\Phi(x)$ and $\Psi(x)$ are formulae, then 
$(\forall x)( \Phi(x)  \iff \Psi(x)) \implies \\{ x : \Phi(x) \\} = \\{x : \Psi(x) \\}$

</div>


Let us call a property **collectivizing** if there is a collection whose members are just the objects which have it.

<div class="definition" markdown="block">
**Theorem:** Russell's paradox

$ \\{x: x \not\in x \\}$ does not exist.

**Proof**. By Contradiction

Suppose that a = $\\{x : x \not\in x \\}$ exists. \\
Then $(\forall x)(x \in a \iff x \not\in x)$ [Lemma: Membership]. \\
Therefore in particular $a \in a \iff a \not\in a$. \\
Contradiction.
</div>

A **paradox** is a fact that is contrary to expectation.  The property of non-self-membership is not collectivizing.

A property is **self-reproductive** or **indefinitely extensible** if, "given any class of terms all having [the] property, we can always define a new term also having the property". A property F is indefinitely extensible if there is a process which, when applied to some Fs, gives rise to another object which is not among them but is nevertheless an F.



<div class="definition" markdown="block">
**Definition**: 

We say that b is a **collection** if $b = \\{x : x \in b \\}$.

**Lemma**: No collection is an individual.

</div>

Nothing is both a collection and an individual.




<div class="definition" markdown="block">
**Theorem**: Extensionality principle.

$(\forall x) (x \in a \iff a \in b) \implies a  = b$.

**Proof:**

Suppose a and b are collections. \\
Then $a = \\{x: x \in a \\}$ and $b = \\{x : x \in b \\}$. \\
But if $(\forall x)(x \in a \iff x \in b)$, then \\
$\\{x : x \in a \\} = \\{x: x \in b \\}$, \\
and so a = b.

</div>

In words: a collection is determined by its elements.

Zermelo calls this the axiom of definiteness. 


<div class="definition" markdown="block">
**Definition:** Empty Set

$\varnothing = \\{x : x \neq x \\}$

</div>

We say a collection b is **empty** if $(\forall x)(x \not\in b)$




<div class="definition" markdown="block">
**Definition**: Intersection (or product)

$$A \cap B = \{ x | x \in A \text{ and } x \in B \}$$


The intersection of two sets A and B is the set of all elements that belong to both A and B , and is denoted by $A \cap B$.
</div>


The set consisting of the elements that A and B have in common.

<div class="definition" markdown="block">
**Definition**: Union (or sum)

$$A \cup B = \{ x | x \in A \text{ or } x \in B \}$$

The union or sum of two sets A and B is the set of all elements that belong to A or B (or both), and is denoted by $A \cup B$.

</div>

The set resulting from throwing all the elements of A and B together into one set


<div class="definition" markdown="block">
**Definition**: Difference (or complement)

$$A \backslash B = A - B = \{x ~|~ x \in A \text{ and } x \notin B \}.$$

</div>

The set you would get if you started with the set A and removed from it any elements that were also in B


<div class="definition" markdown="block">
**Definition**: Symmetric Difference

$$ A \Delta B = (A \backslash B) \cup (B \backslash A) = (A \cup B) \backslash (A \cap B) $$

</div>

The set of objects that are elements of either A or B but not both


<div class="definition" markdown="block">
**Definition**: Subset

If $x \in A$ then $x \in B$

A set **A** is called a subset of a set **B** if every element of **A** is also an element of **B**. We write $A \subseteq B$


</div>
Notice that by definition every set is a subset of itself. 

We think of A as a smaller set that is made up of some of the elements of B. We also say that B is a **superset** of A.


<div class="definition" markdown="block">
**Definition**: Proper Subset 

A **proper subset** is a subset but not equal to the larger set. $A \subset B$ denotes that A is a proper subset of B.
</div>



<div class="definition" markdown="block">
**Definition**: Disjoint

Two sets are said to be **disjoint** if their intersection is empty $A \cap B = \emptyset$

</div>

A and B are said to be disjoint if they have no elements in common


<div class="definition" markdown="block">
**Definition**: Power Set

For any set A, the power set of A, denoted by $\mathcal{P(A)}$, is the set of all subsets of A and is written

$$ \mathcal{P}(A) = \{ x | x \subseteq A \} $$

</div>






<div class="definition" markdown="block">
**Definition**: Cartesian product

We write $X \times Y$ for the **Cartesian product** of X and Y which is the set of all ordered pairs (x,y) with $x \in X$ and $y \in Y$. We use $X^2$ as a shorthand for $X \times X$.

</div>



$$\bigcup_{i \in I} A_i$$

$$\bigcap_{i \in I} A_i$$









Strategies that have guided realists in formulating axiomatizations

The object of a good axiomatization is to retain as many possible naive set-theory argumnets but stop short of permitting those arguments that lead to paradoxes.

The security of a theory depend on no more than its failure so far to lead to contradiction



Motivation for a conception of collection that gives us reason to believe that the axioms we shall be stating are true independent of their consequences.



It is only recent that the idea of deriving our conception of collections from a relation of dependence between them.

