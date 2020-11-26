---
title: Structures and Language
mathjax: true
layout: default
toc: true
---

# Structures and Languages

> We must know we shall know - Hilbert's tombstone



We want to construct very restricted formal languages to be able to form certain precise statements about certain kinds of mathematical structures.

We are discussing the syntax of a language, the marks on the paper or pixels on the screen.


<div class="definition" markdown="block">
**Definition:** first-order language $\mathcal{L}$

A **first-order language $\mathcal{L}$** is an infinite collection of distinct symbols, no one of which is properly contained in another, separated into the following categories:

* _Parantheses_: (, ).
* _Connectives_: $\lor$ $\lnot$.
* _Quantifier_: $\forall$.
* _Variables_, one for each positive integer $n: v_1, v_2, \dots, v_n$. The set of variable symbols will be denoted Vars.
* _Equality symbol_ =.
* _Constant symbols_: Some set of zero or more symbols.
* _Function symbols_: For each positive integer n, some set of zero or more n-ary function symbols.
* _Relation symbols_: For each positive interger n, some set of zero or more n-ary relation symbols.
</div>




In general to specify a language we need to list the constant symbols, the function symbols, and the relation symbols.


Strings in our language refer to mathematical objects. Those strings are called terms.

<div class="definition" markdown="block">
**Definition:**  term of  $\mathcal{L}$

If  $\mathcal{L}$ is a language, a **term** of  $\mathcal{L}$ is a nonempty finite string t of symbols from  $\mathcal{L}$  such that either:

1. t is a variable, or
2. t is a constant symbol, or
3. t is $ft_1t_2 \dots t_n$, where f is an n-ary function symbol of $\mathcal{L}$ and each of the $t_i$ is a term of $\mathcal{L}$.
</div>


We need to make sure that strings that we write down can be interpreted in only one way. This property is called _unique readability_.


<div class="definition" markdown="block">
**Definition:** formula of $\mathcal{L}$

If $\mathcal{L}$ is a first-order language, a **formula of $\mathcal{L}$** is a nonempty finite string $\phi$ of symbols from $\mathcal{L}$ such that either:

1. $\phi$ is $=t_1t_2$, where $t_1$ and $t_2$ are terms of $\mathcal{L}$ or
2. $\phi$ is $Rt_1t_2 \dots t_n$, where R is an n-ary relation symbol of $\mathcal{L}$ and $t_1, t_2, \dots, t_n$ are all terms of $\mathcal{L}$ or
3. $\phi$ is $(\lnot \alpha)$, where $\alpha$ is a formlya of $\mathcal{L}$, or
4. $\phi$ is $(\alpha \lor \beta)$, where $\alpha$ and $\beta$ are formulas of $\mathcal{L}$, or
5. $\phi$ is $(\forall v)(\alpha)$, where v is a variable and $\alpha$ is a formula of $\mathcal{L}$
</div>



The **terms** of $\mathcal{L}$ play the role of the nouns of the language. 

The **formulas** will be the statements. Statements can be either true or false






<div class="definition" markdown="block">
**Definition:** The language $\mathcal{L}_{NT}$ is $\{ 0, S, +, ·, E, < \}$, 
where 0 is a constant symbol, 
S is a unary function symbol, 
+, ·, and E are binary function symbols, and 
< is a binary relation symbol. 
This will be referred to as the language of number theory.
</div>


<div class="definition" markdown="block">
**Definition:**  Free Variables

Suppose that v is a variable and φ is a formula. We will say that v is free in φ if

1. φ is atomic and v occurs in (is a symbol in) φ, or
2. φ is (¬α) and v is free in α, or
3. φ is (α ∨ β) and v is free in at least one of α or β, or
4. φ is (∀u)(α) and v is not u and v is free in α.
</div>



<div class="definition" markdown="block">
**Definition:**  Sentence

A sentence in a language $\mathcal{L}$  is a formula of $\mathcal{L}$  that contains no free variables.
</div>



<div class="definition" markdown="block">
**Definition:** Structure

Fix a language $\mathcal{L}$ . An $\mathcal{L}$-structure $\mathbb{A}$ is a nonempty set A, called the universe of $\mathbb{A}$, together with:

1. For each constant symbol c of $\mathcal{L}$ , an element $c^\mathbb{A}$ of A,
2. For each n-ary function symbol f of $\mathcal{L}$ , a function $f^\mathbb{A} : A^n \to A$, and
3. For each n-ary relation symbol R of $\mathcal{L}$ , an n-ary relation $R^\mathbb{A}$ on A (i.e., a subset of $A^n$ ).

Notice that the domain of the function $f^\mathbb{A}$ is the set $A^n$ , so $f^\mathbb{A}$ is defined
for all elements of $A^n$
</div>


**What is the difference between a Model and a Structure?**

A structure is a set with some interpretable symbols(constants, relations and functions) within a fixed language. You do not ask for more from a structure. A model (of a theory) is a structure which satisfies the axioms of the theory.

When you say $\mathcal{L}$-structure, it is implying that it doesn't matter what sort of theory I am assuming on the structure. If you say "a model of ZFC" that implies a model which satisfies all the axioms of ZFC.

In other words when we say "model" we mean that there is a particular theory which holds in the structure, and when we say "structure" we are mainly interested in an arbitrary interpretation of the language.

**Historical Note:** The term 'structure' is a replacement for the earlier term 'system' which was used by various authors (Weber, Hilbert, Dedekind) and meant something along the lines of "a set with added features".


<div class="definition" markdown="block">
**Definition:** If A is an L-structure, a variable assignment func-
tion into A is a function s that assigns to each variable an element of the
universe A. So a variable assignment function into A is any function with
domain Vars and codomain A.
</div>

<div class="definition" markdown="block">
**Definition:**  If s is a variable assignment function into A and x is a
variable and a ∈ A, then s[x|a] is the variable assignment function into A
defined as follows:
(
s(v) if v is a variable other than x
s[x|a](v) =
a
if v is the variable x.
We call the function s[x|a] an x-modification of the assignment
function s.
</div>

<div class="definition" markdown="block">
**Definition:** Suppose that A is an L-structure and s is a variable
assignment function into A. The function s, called the term assignment
function generated by s, is the function with domain consisting of the
set of L-terms and codomain A defined recursively as follows:
1. If t is a variable, s(t) = s(t).
2. If t is a constant symbol c, then s(t) = c A .
3. If t : ≡ f t 1 t 2 . . . t n , then s(t) = f A (s(t 1 ), s(t 2 ), . . . , s(t n )).
</div>

<div class="definition" markdown="block">
**Definition:** Suppose that A is an L-structure, φ is an L-formula,
and s : Vars → A is an assignment function. We will say that A satisfies
φ with assignment s, and write A |= φ[s], in the following circumstances:
1. If φ : ≡ = t 1 t 2 and s(t 1 ) is the same element of the universe A as s(t 2 ),
or
2. If φ : ≡ Rt 1 t 2 . . . t n and (s(t 1 ), s(t 2 ), . . . , s(t n )) ∈ R A , or
3. If φ : ≡ (¬α) and A 6| = α[s], (where 6| = means “does not satisfy”) or
4. If φ : ≡ (α ∨ β) and A |= α[s], or A |= β[s] (or both), or
5. If φ : ≡ (∀x)(α) and, for each element a of A, A |= α[s(x|a)].
If Γ is a set of L-formulas, we say that A satisfies Γ with assignment s,
and write A |= Γ[s] if for each γ ∈ Γ, A |= γ[s].
</div>


<div class="definition" markdown="block">
**Definition:** . If φ is a formula in the language L and A is an L-
structure, we say that A is a model of φ, and write A |= φ, if and only if
A |= φ[s] for every assignment function s. If Φ is a set of L-formulas, we
will say that A models Φ, and write A |= Φ, if and only if A |= φ for each
φ ∈ Φ.
Notice that if σ is a sentence, then A |= σ if and only if A |= σ[s] for
any assignment function s. In this case we will say that the sentence σ is
true in A.
</div>
