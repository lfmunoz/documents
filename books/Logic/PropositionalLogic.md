---
title: Propositional Logic
mathjax: true
layout: default
toc: true
---



# Propositional Logic

[Logic](Introduction.html)

**Propositional logic** (also called sentential calculus or sentential logic or Zeroth-order logic) is a formal system in which formulas of a formal language may be interpreted to represent propositions.

> The theorems of mathematics all say the same, namely nothing - Wittgenstein 

Wht does he mean? If we have theorems of the type $A \iff B$, A and B being propositions then obviously A says nothing else than B does. It is a tautologically, but psychologically it may be useful to have a reformulation.




<div class="definition" markdown="block">
**Definition:** Proposition

A **proposition** $p$ is a variable that can take the value "true" or "false". No others.

</div>

The term **proposition** is sometimes used synonymously with **statement**. However, it is sometimes used to name something abstract that two different statements with the same meaning are both said to “express”. In this usage, the English sentence, “It is raining”, and the French sentence “Il pleut”, would be considered to express the same proposition.

It is not the task of propositional logic to decide whether
* a statement is a proposition or not
* a statement is true or false.

A proposition deals with the entire proposition and just assumes that it is either true or false.

It is possible to build new propositions from given ones using **logical operators**. There are 4 **unary operator** which take a proposition and makes a new proposition. These exhaust all possibilities for unary $4=2^2$.

| $p$ | $\neg p$ | $id(p)$ | $\top_p$ | $\bot_p$ |
|  |  inverse | identity | tautology | contradiction / absurdity |
| ----------- | ----------- | ----------- | ----------- | ----------- |
| T | F | T | T | F |
| F | T | F | T | F |


**Binary operators** take two propositions and makes a new proposition. There are four combinations of the truth values of two propositions and, since a binary operator assigns one of the two possible truth values to each of those, we have $16 = 2^4$  binary operators in total.

| P | Q | $\neg P$ | $ P \land Q$ | $ P \lor Q$ | $ P \to Q$ | $P \leftrightarrow Q$ | $P \oplus Q$ | $P \uparrow Q$ |
|  |  | inverse | and / conjunction | or / disjunction | implication / conditional | iff / biconditional |  xor | nand |
| ----------- | ----------- | | ----------- | ----------- | ----------- | ----------- | ----------- |
| T | T | false | true | true  | true | true | F | T |
| T | F | false | false | true | false | false | T | T | 
| F | T | true | false | true |  true | false | T | T |
| F | F | true | false | false | true | true | F | F |



ex falso quodlibet, from the false everything follows

<div class="definition" markdown="block">
**Theorem:** Let p,q be propositions. $ (p \implies q)  \iff  (\neg q \implies \neg p)$

**Proof:**  Construct truth table

</div>

Note: All higher order operators $\phi (p_1, \dots , p_N)$ can be constructed from a single binary operator **nand**.


Corollary: we can prove asserts by way of contradiction

assume we know p is true, we want to prove that then q is true
what we can do instead is
assume that what we want to prove is false and to prove that
means that the assumption isn't true.



All highe rorder operations can be constructed from a single binary operator. The NAND operator 


<div class="definition" markdown="block">
**Theorem:**  Propositional logic is consistent

**Proof:** Suffices to show that there exists a proposition
that cannot be proved within propositional logic.
Propositional Logic has an empty sequence of axioms.

Only T and M must carry any proof
only things you can prove are tautologies

i.e, $q \land \neg q$ cannot be proven because that isn't a tautology.
We constructed a proposition that cannot be proven, so Propositional Logic is consistent.

</div>



R, Q, P - formulae, Schematic Letters, propositions

Standing in for sentences which are or express propositions.

Interpret a setence letter just by assigning to it a truth-value (T or F)


$\vDash$  entails (sign is pronounced turnstile)

$\Gamma \vDash \phi$

There is no interpretation in which every formula $\gamma$ is true and the formula 
$\phi$ is false.


Any sentence that exemplifies schema $$ \gamma \entails \phi $$
with actual formulae will be called a sequent

**Modus Ponens**
if P then Q; P; therefore Q 

An **argument-schema** counts as a valid schema if there is no interpretation in wich
each of the premise-formulae comes out true and the conclusion-formula comes out false


$\phi$ is any formula

$\gamma$ is any set of formula


$$\entails \phi$$  claim that $\phi$ is valid
There is no interpretation in which $\phi$ is false

$$\gamma \entails$$ there is no interpretation in which every formulate in $\gamma$ is true
can be read as "is inconsistent"

There is a proof whose conclusion is $\phi$ and whose undischarged assumptions
are all in the set $\gamma$

When is true the sequent is correct

$\gamma$ can be empty $\entails \phi$ this sequence is correct iff there is a proof of $\phi$ with no
discharged assumptions


A **sequent** makes a definite claim that certain formulae are related in a particular way and it is either true or false


$\phi$ is a statement the conclusion of the sequent and $\gamma$ is a set of statements the assumptions of the sequent




⊢ \vdash

⊨ \vDash