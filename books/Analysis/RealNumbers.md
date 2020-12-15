---
title: Analysis
mathjax: true
layout: default
toc: true
---

# Real Numbers

* [Analysis](Introduction.html)





## Order 



<div class="definition" markdown="block">
**Definition:** Order

Let S be a set. An **order** on S is a relation, denoted by <, with the following two properties:

**i. Trichotomy** If $x,y \in S$ then exactly one of these is true (x < y) or (x > y) or (x = y)

**ii. Transitivity** If $x,y,z \in S$ and if (x < y) and (y < z) then (x < z).

</div>

If you have an **order** on S then you have an **ordered set**.


## Upper Bound 



<div class="definition" markdown="block">
**Definition:** Say $E \subset S$ ordered. If there exists $\beta \in S$ (beta for bound) s.t. for all $x \in E$ we have $x \leq \beta$ we call $\beta$ an upper bound for E, and we say E is **bounded above**.

</div>

i.e., S can be $\mathbb{Q}$, E can be the interval [0,1], then $\beta$ is a number like 10, or 2. What we are asking: Is there a number that is bigger than everything? Yes, then we call that an upper bound. It is saying that the subset E of S, has a largest number, the sequence ends.

Idea of lower bound, just replace $\leq$ by $\geq$.


An **uppper bound** is a number that is bigger than everything in the set. The bigger number doesn't have to be in the set but notice the less than or equal to, so it can be equal to the largest number in the set.

## Least Upper Bound 



<div class="definition" markdown="block">
**Definition:**  Suppose S is an ordered set, $E \subset S$, and E is bounded above. If there exists $\alpha \in S$ s.t. 

**i.** $\alpha$ is an upper bound of E,

**ii.** if $\gamma < \alpha $ then $\gamma$ is not an upper bound for E. 

Then $\alpha$ is called the **least upper bound** of E or **supremum** of E. we write 

$$\alpha = \sup E.$$

</div>

The supremum is the least biggest thing. I think for this definition to make sense gamma must be in E?

**Example:** If $ E = \\{ \frac{1}{2}, 1, 2 \\}$ then sup E = 2.

We justify this by noticing that 2 is an upper bound of E, because it is the largest number in the set. It is the least upper bound because suppose there was an upper bound less than 2, call it $\gamma$ well then $\gamma$ wouldn't be bigger than 2 and therefore it isn't an upper bound for that set.

## Least-Upper-Bound Property 



<div class="definition" markdown="block">
**Theorem:** Suppose S is an ordered set with the **least-upper-bound property**, $B \subset S$, B is not empty, and B is bounded below. Let L be the set of all lower bounds of B. Then

$$\alpha = \sup L$$

exists in S, and $\alpha = \inf B$. In particular $\inf B$ exists in S.
</div>



<div class="definition" markdown="block">
**Theorem:** A set S has the **least-upper-bound property** (satisfies the compleness axiom) if every nonempty subset of S that has an **upper bound** also has a **least-upper-bound** in S.
</div>

# Construction of Real Numbers  


How do we fill the holes in the number line? For example we have a length which we call $\sqrt{2}$, that doesn't exists in the rationals, it leaves a hole. I want to fill all the wholes but I don't even know where all the holes are at. What can do I?

Consider:

$$ A = \{ x \in \mathbb{Q} | x^2 < 2 \} $$

The problem is that there is nothign at the edge but I wish there were because that is were one of our holes is at. This points to an idea that is called a least upper bound.




<div class="definition" markdown="block">
**_Theorem_:** $\mathbb{R}$ is an ordered field, with the least upper-bound-property and $\mathbb{R}$ contains $\mathbb{Q}$ as a subfield.

</div>

<div class="definition" markdown="block">
**Dedekind:** A cut $\alpha$ is a subset of $\mathbb{Q}$, s.t.

**i.** $\alpha \neq \emptyset, \mathbb{Q} $ (not empty and also not the entire thing, cut is not trivial)

**ii.** If $p \in \alpha$, $q \in \mathbb{Q}$ and q < p, then $q \in \alpha$ (closed downward, or closed to the left)

**iii.** If $p \in \alpha$ then p < r for some $r \in \alpha$ (there is no largest number, there is something to the right of p that is also in $\alpha$)

</div>


ii. implies two facts which we will use freely: \\
If $p \in \alpha$ and $q \notin \alpha$ then p < q. \\
If $r \notin \alpha$ and r < s the $s \notin \alpha.$ \\


Let $\mathbb{R} \equiv \\{ \alpha \| \alpha \text{ is a cut} \\}$

what is the cut of 1? All the rationals to the left of 1. What is the cut for square of 2, all the rationals to the left of 2.


Define: order  $\alpha < \beta$, means $\alpha \subset \beta$ and $\alpha \neq \beta$. Properly contained. (where $\alpha$ and $\beta$ are two cuts.)

Check order, Trichotomy and Transitivity


Addition define $\alpha + \beta \equiv \{ r + s \| r \in \alpha \text{ and } s \in \beta \}$

check that it is a cut. nontrivial, closed to the left, no largest number

show axioms A1-A5. field.



Also $\mathbb{R}$ contains $\mathbb{Q}$ as a subfield. Associates to $q \in \mathbb{Q}$ the cut $\q* = \{ r \in Q: r < q \}$




# Summary

$\mathbb{Q}$ has gaps, not every bounded set has a supremum. Think of the $\sqrt{2}$, there is no rational that is at that gap, but many rationals approach that number. Doesn't have the least-upperbound-property.

This leads to the idea of dedekind cut. The real numbers is just the set of all cuts.

Defiend order by inclusion, if one cut was inside another then it was smaller.

Defiend arithmetic which includes operations + and $\times$.


Also R contains Q as a subfield.

Associate to $q \in Q$ the cut $q* = \{ r \in Q : r < q \}$.


Note the length "$\sqrt{2}$" sits in R as $\{ q : q^2 < 2 ~~\text{or}~~ q < 0 \}$.


=== Consequences of Least-Upper-Bound Property ===

Archimedian property of the real numbers.

If $x,y \in R$, x > 0, then  $\exists$ positive integer n s.t nx > y.



## Dedekind cuts criticism

In mathematics often there is something that works. It may not be understood deeply enough why it works. Someone offers an explanation
but some people find it flawed but at least it is some explanation. 

Some people disagree that Dedekind cuts are valid it doesn't matter because maybe there isn't some other better formulation
which is more accurate or makes more sense, but that doesn't mean what Dedekind cuts are trying to do isn't valid.



