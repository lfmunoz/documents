---
title: Structures and Language
mathjax: true
layout: default
toc: true
---

# Languages

> We must know we shall know - Hilbert's tombstone


We want to construct very restricted formal languages to be able to form certain precise statements about certain kinds of mathematical structures.

We are discussing the syntax of a language, the marks on the paper or pixels on the screen.

These are formal rules about what constitutes a language, and allows us to identify the terms, formulas, and sentences of a language.


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
**Definition:** The language $\mathcal{L}_{NT}$ 

The language $\mathcal{L}_{NT}$ is $\\{ 0, S, +, ·, E, < \\}$, where
* 0 is a constant symbol, 
* S is a unary function symbol, 
* +, ·, and E are binary function symbols, and 
* < is a binary relation symbol. 

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




# Structures


Here we tie together the syntax and the semantics. 




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
**Definition:** Variable assignment function 

If  $\mathbb{A}$  is an $\mathcal{L}$-structure, a **variable assignment function into  $\mathbb{A}$**  is a function **s** that assigns to each variable an element of the universe A. So a variable assignment function into  $\mathbb{A}$  is any function with domain Vars and codomain A.

$$s: Vars \to A$$

</div>

<div class="definition" markdown="block">
**Definition:**  x-modification of the assignment function s.

If **s** is a variable assignment function into  $\mathbb{A}$  and x is a
variable and $a \in A$ , then $s[x\|a]$ is the variable assignment function into  $\mathbb{A}$ 
defined as follows:

$$
s[x|a](v) =
\begin{cases}
s(v) ~~   \text{if } v \neq x \\
a ~~~~~~~ \text{if } v = x
\end{cases}
$$

We call the function $s[x\|a]$ an **x-modification of the assignment function** s.

</div>

The variable x is assigned to a particular element of the universe.


<div class="definition" markdown="block">
**Definition:** term assignment function generated by s

Suppose that $\mathbb{A}$ is an $\mathcal{L}$-structure and s is a variable
assignment function into $\mathbb{A}$. The function $\bar{s}$, called the **term assignment
function generated by s**, is the function with domain consisting of the
set of $\mathcal{L}$-terms and codomain A defined recursively as follows:

1. If t is a variable, $\bar{s}(t) = s(t)$.
2. If t is a constant symbol c, then $\bar{s}(t) = c^{\mathbb{A}}$ .
3. If t is $f t_1 t_2 \dots t_n$, then $\bar{s}(t) = f^{\mathbb{A}}(\bar{s}(t_1 ), \bar{s}(t_2), \dots , \bar{s}(t_n))$.

</div>

Here we extend a variable assignment function s to a term assignment function $\bar{s}$.

<div class="definition" markdown="block">
**Definition:** $\mathbb{A}$ satisfies $\phi$ 


Suppose that $\mathbb{A}$ is an $\mathcal{L}$-structure, $\phi$ is an L-formula,
and $s : Vars \to A$ is an assignment function. We will say that **$\mathcal{L}$ satisfies
$\phi$ with assignment s**, and write $\mathbb{A} \vDash \phi[s]$, in the following circumstances:

1. If $\phi$ is $= t_1 t_2$ and $\hat{s}(t_1)$ is the same element of the universe A as $\hat{s}(t_2)$, or
2. If $\phi$ is $R t_1 t_2 \dots t_n$ and $\\{ s(t_1 ), s(t_2 ), \dots , s(t_n ) \\} \in R^{\mathbb{A}}$ , or
3. If $\phi$ is $(\lnot \alpha)$ and $\mathbb{A} \nvDash α[s]$, (where $\nvDash$ means “does not satisfy”) or
4. If $\phi$ is $(\alpha \lor \beta)$ and $\mathbb{A} \vDash \alpha[s]$, or $\mathbb{A} \vDash \beta[s]$ (or both), or
5. If $\phi$ is $(\forall x)(\alpha)$ and, for each element a of $\mathbb{A}$, $\mathbb{A} \vDash \alpha[s(x\|a)]$.

If $\Gamma$ is a set of $\mathcal{L}$-formulas, we say that $\mathbb{A}$ satisfies $\Gamma$ with assignment s,
and write $\mathbb{A} \vDash \Gamma[s]$ if for each $\gamma \in \Gamma$ , $\mathbb{A} \vDash \gamma[s]$.
</div>

The symbol $\vDash$ is not part of the language $\mathcal{L}$, it is a metalinguistic symbol that we use to talk about the formulas in the language and structures for the language.


<div class="definition" markdown="block">
**Definition:** Model

If $\phi$ is a formula in the language $\mathcal{L}$ and $\mathbb{A}$ is an $\mathcal{L}$-structure, we say that $\mathbb{A}$ is a **model** of $\phi$, and write $\mathbb{A} \vDash \phi$, if and only if $\mathbb{A} \vDash \phi[s]$ for every assignment function s. 

If $\Phi$ is a set of $\mathcal{L}$-formulas, we will say that $\mathbb{A}$ models $\Phi$, and write $\mathbb{A} \vDash \Phi$, if and only if $\mathbb{A} \vDash \phi$ for each $\phi \in \Phi$.

</div>

If $\phi$ is a sentence, then $\mathbb{A} \vDash \phi$ if and only if $\mathbb{A} \vDash \phi[s]$ for any assignment function s. In this case we will say that the sentence $\phi$ is true in $\mathbb{A}$.



<div class="definition" markdown="block">
**Definition:** Substitute

Suppose that u is a term, x is a variable, and t is a term. We dine the term $u^x_t$ (read "u x replaced by t") as follows:

1. If u is a variable not equal to x, then $u^x_t$ is u
2. If u is x, then $u^x_t$ is t
3. If u is a constant symbol, then $u^x_t$ is u
4. If u is $fu_1u_2 \dots u_n$, where f is an n-ary function symbol and the $u_i$ are terms, then $u^x_t$ is $f(u_1)^x_t(u_2)^x_t \dots (u_n)^x_t$

</div>