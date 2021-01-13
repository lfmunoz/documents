---
title: Predicate Logic
mathjax: true
layout: default
toc: true
---



# Predicate Logic

[Logic](Introduction.html)


<div class="definition" markdown="block">
**Definition:** Predicate

A **predicate** is a propositional value function of some variable or variables.


</div>

i.e, You have P(x) and the truth value depends on what x is, where x can be anything. Propositional Logic isn't about the nature of the variables.


Construct new predicate from given ones.

a) $Q(,x,y, z) \iff P(x)  \land R(y,z)$

b) convert predicate of 1 variable into a proposition

a propositon $\forall x: P(x)$

a proposition that has been constructed from a predicate of 1 variable

"for all x P(x) is true"

defiend to be true if P(x) \iff is true independent of x. the proposition is true indepedent of x.

it isn't the task of predicate logic to construct these propsotion but as a feel good example:

P(x) \iff "x is a human being" \implies "x has been created"
then \forall x : P(x) is true




<div class="definition" markdown="block">
Definition: Existence Qualification

$\exists x: P(x) \iff \neg \forall x : \neg P(x)$

"there exists an x such that P(x)"

**Corollary:**  $\forall  x : \neg P(x) \iff \neg (\exists x: P(x) )$

</div>


if something isn't true for any x, then certainly it is not true that there exists one where it's true

remark 1: quantification for predicates of more than 1 variable
Q(y) \iff \forall x: P(x, y) 
x is a bound variable
y is a free variable


remark 2: order of quantification matters




## Predicate Interpretations



$\neg \exists x \forall y (y \in x)$

* There is no set x such that all sets y are elements of x
* There is no set to which all sets belong

$\forall x \exists y \neg( x  \in y)$

* For every set x, there is a set y of which x is not an element
* For any set there is a set to which it doesn't belong


$∃x∀y(x+y=y)$
* valid. we require that x be a fixed value that satisfies the equation regardless of the value of y; clearly x=0 will do
$∀y∃x(x+y=0).$
* valid. x  depends on y; if y=3, x=−3, if y=0, x=0.


$∀x∃y(x<y)$
* valid. given any number there is a strictly larger number,
$∃y∀x(x<y)$
* not valid.  there is a single number that is strictly larger than all real numbers.


$\forall x \forall y ( x \in y \land y \in z) \to x \in z)$
* all elements of any element of z are themselves elements of z

$\exists y ( y \in x \land \forall y' (y' \in x \to y' = y))$
* The set x contains exactly one element

$\exists x \forall y (y \in x \iff \phi(y))$
* There is a set x and all its members have property $\phi(y)$