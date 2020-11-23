---
title: Exercises 1.5
mathjax: true
layout: default
toc: true
---



# Exercises 1.5

----
## Exercise 1.5.1

1. For each of the following, find the free variables, if any, and decide if the
given formula is a sentence. The language includes a binary function
symbol +, a binary relation symbol <, and constant symbols 0 and 2.

(a) (∀x)(∀y)(x + y = 2)
(b) (x + y < x) ∨ (∀z)(z < 0)
(c) ((∀y)(y < x)) ∨ ((∀x)(x < y))

**SOLUTION:**


(a) It is a sentence, no free variables

(b) x and y are not free, therefore not a sentence

(c) x is not free on the left or, y is not free on right of or. Not a sentence


----
## Exercise 1.5.2

2. Explain precisely, using the definition of a free variable, how you know
that the variable v 2 is free in the formula
$(∀v_1 )(¬(∀v_5 )(v_2 = v_1 + v_5 ))$.

**SOLUTION:**

Definition states that v id free if $\phi$ if $\phi$ is $(\forall u)(\phi)$ and v is not u and v is free in $\phi$.  Here $v^2$ is not $v_1$ or $v_3$ and it is free in $\phi$


----
## Exercise 1.5.3

3. In mathematics, we often see statements such as sin 2 x + cos 2 x = 1.
Notice that this is not a sentence, as the variable x is free. But we all
agree that this statement is true, given the usual interpretations of the
symbols. How can we square this with the claim that sentences are the
formulas that can be either true or false?

**SOLUTION:**

That statement implies that we mean for all x

$$(\forall x)(sin^2x + cos^2 x = 1)$$

----
## Exercise 1.5.4

 If we look at the first of our example formulas in this section,
¬(∀x)[(y < x) ∨ (y = x)],
and we interpret the variables as ranging over the natural numbers, you
will probably agree that the formula is false if y represents the natural
number 0 and true if y represents any other number. (If you aren’t
happy with 0 being a natural number, then use 1.) On the other hand,
if we interpret the variables as ranging over the integers, what can we
say about the truth or falsehood of this formula? Can you think of an
interpretation for the symbols that would make sense if we try to apply
this formula to the collection of complex numbers?

**SOLUTION:**

The formula can be true if we limit what x and y can be. For exxample if $y,x \in \mathbb{N}$
formula is true.


----
## Exercise 1.5.5

5. A variable may occur several times in a given formula. For example,
the variable v 1 occurs four times in the formula


(∀v 1 ) (v 1 = v 3 ) ∨ (v 1 = Sv 2 ) ∨ (0 + v 17 < v 1 − S0) .
What should it mean for an occurrence of a variable to be free? Write a
definition that begins: The nth occurrence of a variable v in a formula
φ is said to be free if . . . . An occurrence of v in φ that is not free is
said to be bound. Give an example of a formula in a suitable language
that contains both free and bound occurrences of a variable v.

**SOLUTION:**

The nth occurence of a variable v in formula $\phi$ is said to be free if it is not within the scope of 

for all quantifers

$$(\forall v) (v > 0) \lor (v + x > 0)$$




----
## Exercise 1.5.6

6. Look at the formula

 

(∀y)(x = y) ∨ (∀x)(x < 0) .

If we denote this formula by φ(x) and t is the term S0, find φ(t).
[Suggestion: The trick here is to see that there is a bit of a lie in the
discussion of φ(t) in the text. Having completed Exercise 5, we can now
say that we only replace the free occurrences of the variable x when we
move from φ(x) to φ(t).]



**SOLUTION:**

$\phi(x) = [ (\forall y) (x = y) \lor (\forall x) (x < 0)]$

$\phi(x) = [ (\forall y) (s0 = y) \lor (\forall x) (x < 0)]$

We only replace the free variables