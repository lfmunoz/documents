


Suppose that a property holds for 0, and suppose you can prove that if this property holds for another natural number, then it also holds for the successor of that number. Then the property holds for all natural numbers.

Induction can be thought as an axiomatic property of the natural numbers. Although induction must be accepted as axiom it is equivalent to the Well-Ordering Property.


---
**The Well-Ordering Property :** ([[well-ordering principle]]) Every nonempty set of nonnegative integers has a least element.

That is, there is some integer $a \in S$ such that $a \leq b$ for all b's belonging to S. 

The well ordering priciple requires two thigns:
- A non empty set
- Nongenative integers

---
**Principle of Induction** Let S be a subset of $\mathbb N$ such that:

1. $1 \in S$,
2. if $k \in S$ then $k+1 \in S$,

then $S = \mathbb N$


The Well-Ordering Property and Principle of Induction are equivalent. 

$$WOP \iff POI$$


**Proof:** (by contradiction)

$WOP \implies POI$

Suppose S has the POI but $S \neq \mathbb N$. \
Then $A = \mathbb N - S$ has a least element (by WOP), call it n. \
Notice n > 1, because $1 \in S$ so  $1 \notin A$. \
Consider n - 1, it is not in A because n was the least element, so it is in S. \
But $(k-1) + 1 \in S$. \
This is a contradiction because n was in A.

---



 first you show that that the pattern is indeed true in some particular place. Then we know that it works in a few places, but we need to prove that the pattern works everywhere, and we'll never do that by proving one case at a time. Next let us assume that the pattern works, somewhere, out there in space, I'm not saying where, I don't maybe even know where; just somewhere.If we can prove, assuming pattern works at n = k, that pattern then works at n = k + 1 (that is, if it works some place, then it must also work at the next place), then, since we know of a certain place (n = 1) where pattern works, we will have proved that pattern works everywhere.

 




Note: Induction can be used only to prove results obtained in some other way, it is not a tool for discovering formula or theorems.