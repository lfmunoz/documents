---
title: Set Theory
mathjax: true
layout: default
toc: true
---




# Set Theory

Set theory is that branch of mathematics whose task is to investigate mathematically the fundamental notions “number”, “order”, and “function”, taking them in their pristine, simple form, and to develop thereby the logical foundations of all of arithmetic and analysis; thus it constitutes an indispensable component of the science of mathematics.



Intuitively speaking, a set is any collection of objects

These objects are referred
to as the elements of the set.




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
**Definition**: Difference

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
