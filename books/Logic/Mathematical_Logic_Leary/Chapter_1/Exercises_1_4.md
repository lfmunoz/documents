---
title: Exercises 1.4 
mathjax: true
layout: default
toc: true
---

# Exercises 1.4


----
## Exercises 1.4.1

**PROBLEM:** Prove, by ordinary induction on the natural numbers, that $1 + 2 + 3 + \dots + n^2 = \frac{n(n + 1)(2n + 1)}{6}$

**PROOF BY INDUCTION:**  $[P(0) \land \forall n (P(n) \to P(n+1))] \to \forall n P(n) $

Let $P(n) = 1 + 2 + 3 + \dots + n^2 = \frac{n(n + 1)(2n + 1)}{6}$

We will prove P(n) holds for all n ∈ ℕ where $n \geq 0$

**Basis:** P(0)

We simply substitute n = 0 and we get that P(0) = 1

**Induction**: $\forall n (P(n) \to P(n+1))$

We are given that 

$P(n) = 1 + 2 + 3 + \dots + n^2$

To get to P(n+1) from P(n) add $(n+1)^2$ to both sides. Simplifying the right side you get:

$\frac{n(n + 1)(2n + 1) + 6(n+1)^2}{6}$

$\frac{(n+1)[n(n+1)+6(n+1)]}{6}$

$\frac{(n+1)[2n^2+7n+6]}{6}$

$\frac{(n+1)(2n+3)(n+2)}{6}$



----
## Exercises 1.4.2 


**Problem:** Prove, by induction, that the sum of the interior angles in a convex n-gon is (n − 2)*180◦. 


{% include theorems/ConvexPolygon.md %}


----
## Exercises 1.4.3


**Problem:** Prove by induction that if A is a set consisting of n elements, then A has $2^n$ subsets.

{% include theorems/PowerSetCardinality.md %}



----
## Exercises 1.4.4


**PROBLEM:** Suppose that L is {0, f, g}, where 0 is a constant symbol, f is a binary function symbol, and g is a 4-ary function symbol. Use induction on complexity to show that every L-term has an odd number of symbols.

**PROOF:** Let t be an L-term. We will prove that "t has an odd number of symbols" by induction on the complexity of t.

**Case 1:** t is the 0 constant symbol. 

Then t has 1 symbol, and 1 is an odd number.

**Case 2:** t is a variable. 

Then t has 1 symbol, and 1 is an odd number.

**Case 3:** t is $f t_1 t_2$.  

Let $n_1$ be the number of symbols in $t_1$ , and let $n_2$ be the number of symbols in $t_2$. The induction hypothesis states that $n_1$ and $n_2$ are odd numbers. Let $n = n_1 + n_2 + 1$. Now, n is the
number of symbols in t, and moreover, n is an odd number since $n_1$ and $n_2$ are odd numbers.

**Case 4:** t is  $g t_1 t_2 t_3 t_4$ . 

This case is similar to the preceding case. Let $n_1$ , $n_2$ , $n_3$ , and $n_4$ be the number of symbols in respectively $t_1$ , $t_2$ , $t_3$ , and $t_4$ . We know by our induction hypothesis that $n_1$ , $n_2$ , $n_3$ , and $n_4$ are odd numbers, and then, the number of symbols in t, that is, the number $n_1 + n_2 + n_3 + n_4 + 1$ is also odd.

----
## Exercises 1.4.5


**PROBLEM:** If L is {0, <}, where 0 is a constant symbol and < is a binary relation symbol, show that the number of symbols in any formula is divisible by 3.

**PROOF:** Let φ be an L-formula. We will prove that "the number of symbols in φ is divisible by 3" by induction on the complexity of φ.

**Case 1:** φ is $=t_1t_2$ where $t_1$ and $t_2$ are L-terms. Any L-term has exactly one symbol (as L does not contain any function symbols). Thus, there are 3 symbols in the term $= t_1 t_2$ , and 3 is divisible by 3.

**Case 2** φ is $<t_1 t_2$ where $t_1$ and $t_1$ are L-terms. This case is similar to the preceding case.

**Case 3:** φ is (¬α). Let n be the number of symbols in the formula α. Our induction hypothesis asserts that n is divisible by 3. The number of symbols in (¬α) is n + 3, and n + 3 is divisible by 3 when n is divisible by 3. 

**Case 4:** φ is (α ∨ β). Let $n_1$ be the number of symbols in the formula α, and let $n_2$ be the number of symbols in the formula β. By the induction hypothesis, $n_1$ and $n_2$ are divisible by 3. The number of
symbols in (α ∨ β) is $n_1 + n_2 + 3$, and this number is divisible by 3 as $n_1$ and $n_2$ are divisible by 3. 

**Case 5:** φ is  (∀x)(α). Let n be the number of symbols in the formula α. By the induction hypothesis, n is divisible by 3. The number of symbols in (∀x)(α) is n + 6, and n + 6 is divisible by 3 when n is divisible by 3. 



----
## Exercises 1.4.6


**PROBLEM:** If s and t are strings, we say that s is an **initial segment** of t if there is a
nonempty string u such that $t = su$, where $su$ is the string s followed by the string u. For example, KUMQ is an initial segment of KUMQUAT and +24 is an initial segment of +24u − v. Prove, by induction on the complexity of s, that if s and t are terms, then s is not an initial segment of t. [Suggestion: The base case, when s is either a variable or a constant symbol, should be easy. Then suppose that s is an initial segment of t and $s = f t_1 t_2 \dots t_n$, where you know that each $t_i$ is not an initial segment of any other term. Look for a contradiction.] 


**PROOF:** Let s and t be different L-terms. We will prove that "s cannot be an initial segment of t" by induction on the complexity of s.

**Case 1**: s is a variable.  \\
If t is a variable, it must be a different variable than s. \\
If t is a constant then the first string doesn't match because s is a variable. \\
If t is a function then the first string doesn't match because s is a variable.

**Case 2**: s is a constant.  This case is similar to the preceding case.

**Case 3**: $s = f t_1 t_2 \dots t_n$ \\
If t is a variable, then the first string doesn't match because s is a function. \\
If t is a constant then the first string doesn't match because s is a function. \\
If t is a function, suppose that s is an initial segment of t, then the first string matches as they are both f, but the second string does not by the induction hypothesis, therefore s cannot be an initial segment of t.




----
## Exercises 1.4.7


**Problem:**  A language is said to satisfy unique readability for terms if, for each term t, t is in exactly one of the following categories:
* (a) Variable
* (b) Constant symbol
* (c) Complex term

and furthermore, if t is a complex term, then there is a unique function symbol f and a unique sequence of terms t1, t2, . . . , tn such that t :≡
f t1t2 . . . tn. Prove that our languages satisfy unique readability for terms. [Suggestion: You mostly have to worry about uniqueness—for
example, suppose that t is c, a constant symbol. How do you know that t is not also a complex term? Suppose that t is f t1t2 . . . tn. How do
you show that the f and the ti ’s are unique? You may find Exercise 6 useful.]

----
## Exercises 1.4.8



**Problem:**  To say that a language satisfies unique readability for formulas is to say that every formula φ is in exactly one of the following categories:

* (a) Equality (if φ :≡ = t1t2)
* (b) Other atomic (if φ :≡ Rt1t2 . . . tn for an n-ary relation symbol R)
* (c) Negation
* (d) Disjunction
* (e) Quantified

Also, it must be that if φ is both = t1t2 and = t3t4, then t1 is identical
to t3 and t2 is identical to t4, and similarly for other atomic formulas.
Furthermore, if (for example) φ is a negation (¬α), then it must be
the case that there is not another formula β such that φ is also (¬β),
and similarly for disjunctions and quantified formulas. Prove that our
languages satisfy unique readability for formulas. You will want to look
at, and use, Exercise 7. You may have to prove an analog of Exercise 6,
in which it may be helpful to think about the parentheses in an initial
segment of a formula, in order to prove that no formula is an initial
segment of another formula.




Lemma 2.1.5 (Unique Readability).
Each admissible word equals f t1 . . . tm for a unique tuple (f, t1, . . . , tm) where
f ∈ F has arity m and t1, . . . , tm are admissible words.


Proof. Suppose f t1 . . . tm = gu1 . . . un where f, g ∈ F have arity m and n
respectively, and t1, . . . , tm, u1, . . . , un are admissible words on F. We have to
show that then f = g, m = n and ti = ui for i = 1, . . . , m. Observe first that
f = g since f and g are the first symbols of two equal words. After cancelling
the first symbol of both words, the first consequence of the previous lemma leads
to the desired conclusion.
Given words v, w ∈ F
∗ and i ∈ {1, . . . , length(w)}, we say that v occurs in
w at starting position i if w = w1vw2 where w1, w2 ∈ F
∗ and w1 has length
i − 1. (For example, if f, g ∈ F are distinct, then the word fgf has exactly
two occurrences in the word fgfgf, one at starting position 1, and the other
at starting position 3; these two occurrences overlap, but such overlapping is
impossible with admissible words, see exercise 5 at the end of this section.)
Given w = w1vw2 as above, and given v
0 ∈ F
∗
, the result of replacing v in w at
starting position i by v
0
is by definition the word w1v
0w2.


Definition. Let F be a set of symbols with a function a : F → N (called the
arity function). A symbol f ∈ F is said to have arity n if a(f) = n. A word on
F is said to be admissible if it can be obtained by applying the following rules:
(i) If f ∈ F has arity 0, then f viewed as a word of length 1 is admissible.
(ii) If f ∈ F has arity m > 0 and t1, . . . , tm are admissible words on F, then
the concatenation f t1 . . . tm is admissible







----
## Exercises 1.4.9 


**Problem:** Take the proof of Theorem 1.4.2 and write it out in the way that you
would present it as part of a homework assignment. Thus, you should
cut out all of the inessential motivation and present only what is needed
to make the proof work


**Theorem 1.4.2:** Suppose that $\phi$ is a formula in the language L. Then the number of 
left parentheses occurring in $\phi$ is equal to the number of right parentheses occuring in $\phi$.


**PROOF:** Let $\phi$ be a formula in the language L. 
We will prove that "the number of left parentheses is equal to the number of right parentheses" by induction on the complexity of $\phi$.


**Case 1**: $\phi$ is an atomic formula that begins with equal sign followed by 2 terms \\
$\phi$ has no parentheses.

**Case 2**: $\phi$ is an atomic formula that begins with a relational symbol followed by several terms \\
$\phi$ has no parentheses.

We assume $\alpha$ and $\beta$ are formulas that contain equal number of left and right parentheses, given by the induction hypotheses.

**Case 3**: $\phi$ is $(\not \alpha)$

**Case 4**: $\phi$ is $(\alpha \lor \beta)$

**Case 5**: $\phi$ is $(\forall v)(\alpha)$


# References 

* https://web.stanford.edu/class/archive/cs/cs103/cs103.1142/lectures/03/Small03.pdf
* https://web.stanford.edu/class/archive/cs/cs103/cs103.1142/lectures/04/Small04.pdf

