---
title: Proof Theory
mathjax: true
layout: default
---



# Proof Theory


* [Induction](Induction.html)



* A **lemma** is a result of no intrinsic interest proved as a step towards the proof of a theorem
* A **proposition** is a result of less independent importance than a theorem
* A **corollary** is an easy consequence of a theorem

These distinctions are of no formal significance, we use them only as a way of providing signposts to the reader as the relative importance of the result.


**Definitions** explain our use of various words and symbols. It is a requirement of a definition that it should be formally eliminable, so that every occurrence of the word defined could in principle be replaced by the phrase that defines it, but this process of elimination must stop eventually, therefore some words or symbols we do not define byt merely take as given: they are called **primitives.**

 If we are to avoid an infinite regress, there must be some propositions that are not proved, we call these **axioms**.


An alternative to axioms is empiricist such as Lakatos(1976).




Realism is thus committed to the notion that words mathematicians use already have a meaning independent of the system of axioms in which the words occur. If the axioms make existential claims they by taking them to be true we commit ourselves to the existence of the requisite objects.






Often variables that occur in mathematical texts are intended to range over only a restricted class of objects, and in order to aid readability we use letters to mark these restrictions: m,n,k for natural numbers, z,w for complex numbers, G,H for groups.

Greek letters are to be thought as part of the specification language (metalanguage), not as part of the formal language itself. $\Phi$ used to comment on the features that certain formula have in common, or to introduce abbreviations for formulae with a certain pattern.

Propositional Logic - has no quantifiers

first-order - the variables we use as placeholders in quantified sentences have objects as their intended range (comon practice to use lower-case letters x,y,z,t)

second-order permits in addition the use of quantified variables ranging over properties of objects (common practice ot use upper case letters X,Y,Z for such variables) (quantifies over sets, relations, functions)




We cannot in the language itself assert an infinite list of object language sentences, but we can in the metalanguage make a commitment to assert any member of such a list by means of finite description of its syntactic form. This is known as an **axiom scheme**.

It will be a mechanical matter to check whether any given finite string of symbols is an instance of the schema.


first-order logic has a complete formalization but second-order logic does not. The result of this was that it had become standard to state mathematical theories in  first-order form using axiom schemes.



$!x\Phi(x)$  read "the x such that $\Phi(x)$. refer to the unique object which is $\Phi$ if there is one, and ot nothing otherwise


expressions of the sort that denote objects are called terms.


Proper names are also terms but they do not depend on variables. We shall use lower-case Greek letters such as $\rho \tau$, to stand for arbitary terms.

















Law of the Ecluded Middle: Either a statement is true or its negation is true (there is no "middle" possibility).

Law of Contradiction: A statement and its negation cannot both be true


Proof by contradiction (proof by reductio ad absurdum)



Individuals are objects that can't be predicated of or had by other objects.

Properties are way that something can be

Relations are ways that things can be related to each other.



### Contrapositive

$$P \rightarrow Q \iff \neg Q \rightarrow \neg P$$

^ P ^ Q ^ $P \rightarrow Q$ ^  
| 0 | 0   | 1 | 
| 0 | 1   | 1 |
| 1 | 0   | 0 |
| 1 | 1   | 1 |

^ $\neg Q$ ^ $\neg P$ ^ $ \neg Q \rightarrow \neg P$ ^  
| 1 | 1   | 1 | 
| 0 | 1   | 1 |
| 1 | 0   | 0 |
| 0 | 0   | 1 |


“If something is a bat, then it is a mammal.”
“If something is not a mammal, then it is not a bat.”