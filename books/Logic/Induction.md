---
title: Induction
mathjax: true
layout: default
---


# Induction

> **Induction Principle:** Suppose that the first number, 0, has a certain property; and suppose also that if any number has that property, then so does the next; then it follows that all numbers have the property.

Is this obvious?  Consider the following two theorems:

----

**Theorem A:** 
1. The number 1 is a natural number.
2. If k is a natural number, then k+1 is a natural number.

Then the natural numbers are infinite

**Theorem B:**
1.  P(0) is true
2.  If P(0), P(1), P(2), ..., P(n) are true, then P(n+1) is true as well.

Then P(n) is true for all n ∈ ℕ

----

These two theorems seem completely different. The first I would consider obvious the second brings up doubts because how can it not depend on what P(n) is. The reason is that you aren't specifying what n is, so there is a recursive relationship that is established, a sort of domino effect.

There is no proof for induction because it is an axiomatic property of the natural numbers. Understanding induction requires understanding how the natural numbers are formed. Therefore although induction must be accepted as axiom it is equivalent to the Well-Ordering Property.

----
**The Well-Ordering Property :**  Every nonempty set of non-negative integers has a least element.

That is, there is some integer $a \in S$ such that $a \leq b$ for all b's belonging to S. 

The well ordering priciple requires two things:
- A non empty set
- Non-negative integers

---
**Principle of Induction** Let S be a subset of $\mathbb N$ such that:

1. $1 \in S$,
2. if $k \in S$ then $k+1 \in S$,

then $S = \mathbb N$

----

**Theorem:** The Well-Ordering Property and Principle of Induction are equivalent. 

$$WOP \iff POI$$


**Proof:** (By contradiction) Assume that the conclusion of POI is false, then if we get a contradiction it must be true.

Suppose S has the POI but $S \neq \mathbb N$. \
(Assumption for contradiction: There are elments in S that are not in N.)

Then $A = \mathbb N - S$ has a least element n \
(By WOP and A contains elements in S not in A)

Notice n > 1, because $1 \in S$ so  $1 \notin A$. \
(By POI that is premise 1. Important to note that n is not one, zero or negative)

Consider n - 1, it is not in A because n was the least element \
so $(n - 1) \in S$ but $(n-1) + 1 \in S$. \
(By POI premise 2)

This is a contradiction because n was thought to be the least element in A, therefore it can't be in S.

---



What makes a proof by induction work is the fact that the natural numbers can be defined recursively. There is a base case, consisting of the smallest natural number and there is a recursive case, showing how to construct bigger natural numbers from smaller ones.

We abstract away natural numbers for a different object, call it P(n) but this new object has this same induction property as the natural numbers.

----
**Definition:** The principle of mathematical induction(statement form) consists of all statements in the form 

$$[ P(1) \land \forall n  ( P(n) \implies P(n+1) ) ] \implies \forall n P(n)$$

where P(n) is any statement containing a free natural number variable n.

----

P(n) is the statement that it's possible to reach the nth step. P(1) says it's possible to reach the first step and $\forall n ( P(n) \implies P(n+1) )$ says that, for any n, if you can reach the nth step, you can also reach the (n+1)-th step. If you can get to the first step and you always take one more step, then you can go as high as you want. 

In a proof of induction, the goal is to prove a statement of the form 
$\forall n P(n)$. It suffices to prove P(1), the **base case**, and  $\forall n ( P(n) \implies P(n+1) )$, the **induction step**. To prove this quantified statement it suffices to prove the unquantified implication. This will usually be proved by conditional proof, which means the induction step starts with assuming P(n). P(n) is often called the **induction hypothesis**. It is then required to prove P(n+1) from this assumption.

People are often surprised by the fact that, in an induction proof, you get to assume P(n), which is very similar to what you are trying to prove. But note that the statement to be proved is $\forall n P(n)$, whereas the induction hypothesis is just P(n).

You assume P(n) and that leads to a proof of $\forall n P(n)$. This is not the same as assuming the theorem that we are trying to prove. The theorem is a universal statement -- it claims that a certain formula holds for every natural number.



## Template for Induction Proofs


Suppose that you want to prove that some property P(n) holds of all natural numbers.

To do so:
1. Prove that P(0) is true. 
  - This is called the basis or the base case.
2. Prove that for all n ∈ ℕ, that if P(n) is true, then P(n + 1) is true as well.
  - This is called the inductive step.
  - P(n) is called the inductive hypothesis.
3. Conclude by induction that P(n) holds for all n.

Follow the following steps

1. State that your proof works by induction.
2. State your choice of P(n).
3. Prove the bast case 
  - State what P(0) 
  - Prove it using any technique you'd like.
4. Prove the inductive step:
  - State that for some arbitrary n ∈ ℕ that you're assuming P(n) and mention what P(n) is.
5. State that you are trying to prove P(n + 1) and what P(n + 1) means.
  - Prove P(n + 1) using any technique you'd like


Note: Induction can be used only to prove results obtained in some other way, it is not a tool for discovering formula or theorems.



## Example: Detect Counterfeit Coin

**Problem:**  
If we have n weighings on a scale, what is the largest number of coins out of which we can find the counterfeit? 

**Theorem:** 
 If exactly one coin in a group of $3^n$ coins is heavier than the rest, that coin can be found using only n weighings on a balance.

**Proof:** By induction. 

Let P(n) be “Given n weightings, we can detect which one out of $3^n$ coins is counterfeit.” 

We prove that P(n) is true for all n ∈ ℕ.

For the **base case**, we show P(0), that we can detect which one of $3^0 = 1$ coins is counterfeit.
Exactly one coin is counterfeit, so the sole coin must be counterfeit and we can find it with n=0 weighings.


For the **inductive step**, suppose P(k) holds for some k ∈ ℕ, so we can detect which of $3^k$ coins is counterfeit using k weighings. 

We will show P(k + 1) holds, meaning we can detect a counterfeit in $3^{k+1}$ coins using k + 1 weighings.

Given $3^{k+1} = 3*3^k$ coins, split them into three groups of size $3^k$; call them A, B, and C. 
Put the coins in A on one side of the scale and the coins in B on the other. 
We consider three cases based on how the scale tips:

* Case 1: Side A is heavier. Then the counterfeit must be in group A.
* Case 2: Side B is heavier. Then the counterfeit must be in group B.
* Case 3: The scale is balanced. Then the counterfeit must be in group C, since it isn't in groups A or B.

In all cases, we use one weighing to find a set of $3^n$ coins containing the counterfeit coin. 

By the inductive hypothesis, with n more weighings, we can find which of these $3^n$ coins is counterfeit. This means that we can find the counterfeit of $3^{n+1}$ coins in (n + 1) weighings. Thus P(n + 1) holds,
completing the induction. 



## Example: Convex Polygon

{% include theorems/ConvexPolygon.md %}


## Example: Power Set 


{% include theorems/PowerSetCardinality.md %}


# References

http://web.stanford.edu/class/archive/cs/cs103/cs103.1152/lectures/03/Small03.pdf
https://web.stanford.edu/class/archive/cs/cs103/cs103.1142/lectures/03/Small03.pdf

http://web.stanford.edu/class/archive/cs/cs103/cs103.1126/lectures/04/Slides04.pdf