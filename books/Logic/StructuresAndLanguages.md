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


---
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

---



In general to specify a language we need to list the constant symbols, the function symbols, and the relation symbols.


Strings in our language refer to mathematical objects. Those strings are called terms.

---
**Definition:**  term of  $\mathcal{L}$

If  $\mathcal{L}$ is a language, a **term** of  $\mathcal{L}$ is a nonempty finite string t of symbols from  $\mathcal{L}$  such that either:

1. t is a variable, or
2. t is a constant symbol, or
3. t is $ft_1t_2 \dots t_n$, where f is an n-ary function symbol of $\mathcal{L}$ and each of the $t_i$ is a term of $\mathcal{L}$.

---

We need to make sure that strings that we write down can be interpreted in only one way. This property is called _unique readability_.


---
**Definition:** formula of $\mathcal{L}$

If $\mathcal{L}$ is a first-order language, a **formula of $\mathcal{L}$** is a nonempty finite string $\phi$ of symbols from $\mathcal{L}$ such that either:

1. $\phi$ is $=t_1t_2$, where $t_1$ and $t_2$ are terms of $\mathcal{L}$ or
2. $\phi$ is $Rt_1t_2 \dots t_n$, where R is an n-ary relation symbol of $\mathcal{L}$ and $t_1, t_2, \dots, t_n$ are all terms of $\mathcal{L}$ or
3. $\phi$ is $(\lnot \alpha)$, where $\alpha$ is a formlya of $\mathcal{L}$, or
4. $\phi$ is $(\alpha \lor \beta)$, where $\alpha$ and $\beta$ are formulas of $\mathcal{L}$, or
5. $\phi$ is $(\forall v)(\alpha)$, where v is a variable and $\alpha$ is a formula of $\mathcal{L}$

---


The **terms** of $\mathcal{L}$ play the role of the nouns of the language. 

The **formulas** will be the statements. Statements can be either true or false


