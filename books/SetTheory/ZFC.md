---
title:  Zermelo–Fraenkel Set theory
mathjax: true
layout: default
toc: true
---


#  Zermelo–Fraenkel Set Theory

* [Set Theory](Introduction.html)

ZFC consists of 9 axioms mnemonic: **EE PURP IC F**

* EE - 2 basic existence axioms, one about the ∈ relation and the other about the existence
of the empty set;
* PURP - 4 construction axioms, which establish rules for building new sets from given ones.
They are the pair set axiom, the union set axiom, the replacement axiom and the
power set axiom;
* IC - 2 further existence/construction axioms, these are slightly more advanced and newer
compared to the others;
* F - 1 axiom of foundation, excluding some constructions as not being sets.

A relation is a predicate of two variables $\epsilon$ is a relation, it has no definition. There will be no definition of what ∈ is, or of what a set is. Instead, we have nine axioms concerning ∈ and sets, and it is only in terms of these nine axioms that ∈ and sets are defined at all.


<div class="definition" markdown="block">
**1. Axiom on Epsilon-Relation**

$x \in y$  is a proposition if and only if x and y are both sets


Axiom of extensionality 

Two sets are equal if and only if they contain the same elements.

$\forall x \forall y ( x = y \iff \forall z (z \in x \iff z in y))$

</div>

Remeber proposition mean it is either true or false. 


$\forall x : \forall y : (x \in y)  XOR \neg (x \in y)$

<div class="definition" markdown="block">
**2. Axiom on existence of an empty set**

There exists a set that contains no elements

$\exists x : \forall y : (y \not \in x)$
</div>


<div class="definition" markdown="block">
**Theorem:**  All empty sets are the same objects

There is only one empty set, call it $\emptyset$.

**Proof:**  

Assume x and x' are both empty sets, but then 

$\forall y (y \in x  \to y \in x')$

The first statement (antecedent) is false, then the conclusion (consequent) can be anything and the entire proposition is true.
This just mens $x \subset x'$ but then $x \subset x$. In summary x = x' so they must be the same object.
</div>



<div class="definition" markdown="block">
**3. Axiom on Pair Sets**

Let x and y be sets. Then there exists a set that contains
as its elements precisely the sets x and y

$\forall x :  \forall y : \exists m : \forall u ( u \in m \iff (u = x \lor u = y) )$

</div>

The set m is called the pair set of x and y and it is denoted by $\\{ x, y \\}$.

Gives an unexceptional way of constructing a new set from known sets.


<div class="definition" markdown="block">
**Problem:** Show that given sets x and y there is a unique set z whose elements are x and y.

**Solution:**

By axiom of pairs there is at least one set z whose elements are x and y. If z' is another
such set, then any element of z', namely x or y is also an element of z, and vice versa.
By the axiom of extensionality we have z=z.

</div>

<div class="definition" markdown="block">
**4. Axiom on Union Sets**

Let x be a set. Then there exists a set that whose elements are precisely the elements of the elements of x.

$∀ x : ∃ u : ∀ y : (y ∈ u ⇔ ∃ s : (y ∈ s ∧ s ∈ x))$
</div>

The set u is denoted by $\cup x$.


Example Let a,b be sets  x  = { {a}, {b}} 
U x = {a, b}

second example
x = { {a}, {a,b}} 
Ux is a set by union set axiom

<div class="definition" markdown="block">
**5. Axiom of replacement**

Let R be a functional relation let m be a set. Then
the image of m under R is again a set.
</div>

Relation R is called functional if $\forall x \exists ! y: R(x,y)$

\exist !  = exists precisely

THe image of a setm under a functinal relation R consists of all
those y for which there is an x \in m such that R(x,y)

the axiom of replacement implies, but is not implied by, the principle of 
restricted comprehension:  Let P be a predicate of one variable and let m
be a set. Then hose elments y \in m for which P(y) holds constitue a set

Notation this set is usually denooted $\\{ y \in m \| P(y) \\}$

restrictive becasue the elements come from something that is arleady known to be a set .


PUC - principle of universal comprehension (bad principle)

historically in naive set theory, PUC was thought to be needed to define
any set m P(m) (power set)  :=  { y | y \subset m }




<div class="definition" markdown="block">
**6. Axiom on existence power sets**

Let m be a set . then there exists a set  denoted
P(m) whose elements are precisely the subsets of m.

</div>

$m = \\{ a,b \\}$

$P(m) = \\{ \emptyset, \\{ a \\}, \\{ b \\}, \\{ a,b \\} \\}$

how do we know the set exist? 
from which set do these subsets come from?
we need an extra axiom for the existence of power set






<div class="definition" markdown="block">
**7. Axiom of infinity**

there exists a set that contains the empty set
and with every  of its elements y,
it also contains it also contains 
{y} as an element.
</div>

remark: one such set is the set with the elements
$\\{ \\}, \\{ \\{ \\} \\}, \\{ \\{ \\{ \\} \\} \\}$ 

corollay: N is a set

remark: as a set the real numbers can be understood  
P(N)







<div class="definition" markdown="block">
**8. Axiom of Choice**

let x be a set whose elements are 
non empty
mutually disjoint
then there exists a set y
which contains exactly one element
of each element of x
</div>

remark: set y is called "dark" set.
it isn't clear how you pick each element of x

inutition 


a)
x = { { lefft shoe1, right shoe1}, 
         {left shoe 2, right shoe 2}
         }
         
y = { left shoe1, left shoe2, ... }

you don't need the axiom of choice

b)
x = { { lefft sock, right sock}, 
         {left sock, right sock 2}
         }





you have two socks they look the same you need to invoke 
the axiom of choice to build the set y

y = {sock1, sock2, sock3,.. }

remark: axiom of choice is independent
of the other 8 axiomsl we could have set theory
with or without it

remark:
proof that every vector space has a basis needs the axiom of choice
proof that there exists a complete system of representatives of equivalence
relation

need aximo of choice



<div class="definition" markdown="block">
**9. Axiom of Foundation**

eveyr non-empty set x contains an element y that
has none of its elements in common with x.

</div>


immediate implication: there is no set
that contains itself as an element.
x \in x for no set x

every set needs to be built from the empty set

all of mathematics follows from these


