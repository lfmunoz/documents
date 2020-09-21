


> **Induction Principle:** Suppose that the first number, 0, has a certain property; and suppose also that if any number has that property, then so does the next; then it follows that all numbers have the property.

Is this obvious? Many authors jump straight into examples because they consider it obvious that the principle of induction is a correct principle for reasoning. I disagree that it is obvious, there is something subtle and magical going on.

Consider the following two theorems:

1. The number 1 is a natural number.
2. If k is a natural number, then k+1 is a natural number.

then the natural umbers are infinite


1.  P(0) is true
2.  If P(0), P(1), P(2), ..., P(n) are true, then P(n+1) is true as well.

Then P(n) is true for all n ∈ ℕ

These two seems completely different. The first I would consider obvious the second brings up doubts.

It looks like I can find a counter example, 

Consider $P(n)=n^{2}+n+41$ (Euler 1772) is prime for the first 40 integers

the magic is that premise 2, that n must not be specified. The key phrase is **if any number**.  It must work for all n.


 premise 2 is actually saying there is a recursion. this is is substle.

 You have to prove that you can start from any k and and when you go to k+1 the formulate still holds. 

 You showing something generic. proof by recursion. You are showing the theorem follows induction. that is to say it has a property that says it is true for k and it is true for k+1, then it is alwasy true. because i didn't say what k was, I instead showed induction applies. induction means it is true for all numbers k. that seems like circular reasoning. what is undereant this is recursion.

 teh fact there is a way to get from k to k+1, with a definite process. algorithmatically.

 
 
 Clearly then it holds of all k. 






There is no proof for induction because it is an axiomatic property of the natural numbers. Understanding induction requires understanding how the natural numbers are formed. Therefore although induction must be accepted as axiom it is equivalent to the Well-Ordering Property.

---
**The Well-Ordering Property :** ([[well-ordering principle]]) Every nonempty set of non-negative integers has a least element.

That is, there is some integer $a \in S$ such that $a \leq b$ for all b's belonging to S. 

The well ordering priciple requires two things:
- A non empty set
- Non-negative integers

---
**Principle of Induction** Let S be a subset of $\mathbb N$ such that:

1. $1 \in S$,
2. if $k \in S$ then $k+1 \in S$,

then $S = \mathbb N$


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






The difficult part for me was premise 2. Which says

> If the formula holds for k, then the formula holds for k + 1

That is because these this property can be defined recursively. That is the condition. That is the difficult step in any induction prove. You need to show that the property will work recusively. Meaning you pick some k, then you pick k+1 and you get the same outcome.

By recursively I mean that from a particular case k, I can get to the next case k+1

This will not always work. That is why proof by induction actualyl takes a few steps.






  For all n > 0, n^3 <= n^2
We know perfectly well that this statement just isn't so: cubes of whole numbers are bigger than squares (except for the cube and square of 1, where they're equal). But let's try to prove this false statement, and see what happens.

Let n = 1. Then n3 = 13 = 1 and n2 = 12 = 1, and 1 < 1.

Then (*) holds for n = 1.

Hmm...that's weird; the first part worked. Well, let's continue, and see what happens:

















We prove this implication by assuming the antecedent, that the theorem holds for a (fixed, but unknown) number k, and from that assumption proving the consequent, that the theorem holds for the next number, k + 1.



This is not the same as assuming the theorem that we are trying to prove. The theorem is a universal statement -- it claims that a certain formula holds for every natural number.










Suppose that, for every number, if all the numbers less than it have a certain property, then so does it; then it follows that every number has the property.

> 




 first you show that that the pattern is indeed true in some particular place. Then we know that it works in a few places, but we need to prove that the pattern works everywhere, and we'll never do that by proving one case at a time. Next let us assume that the pattern works, somewhere, out there in space, I'm not saying where, I don't maybe even know where; just somewhere.If we can prove, assuming pattern works at n = k, that pattern then works at n = k + 1 (that is, if it works some place, then it must also work at the next place), then, since we know of a certain place (n = 1) where pattern works, we will have proved that pattern works everywhere.

 
The inductive step shows how each step influences the next.



Note: Induction can be used only to prove results obtained in some other way, it is not a tool for discovering formula or theorems.






● Suppose that you want to prove that some
property P(n) holds of all natural numbers.
To do so:
● Prove that P(0) is true.
– This is called the basis or the base case.
● Prove that for all n ∈ ℕ, that if P(n) is true, then
P(n + 1) is true as well.
– This is called the inductive step.
– P(n) is called the inductive hypothesis.
● Conclude by induction that P(n) holds for all n.


State that your proof works by induction.
● State your choice of P(n).
● Prove the base case:
● State what P(0) is, then prove it using any technique you'd
like.
● Prove the inductive step:
● State that for some arbitrary n ∈ ℕ that you're assuming
P(n) and mention what P(n) is.
● State that you are trying to prove P(n + 1) and what
P(n + 1) means.
● Prove P(n + 1) using any technique you'd like

We assume the thing we are trying to prove and use it in the prove that we can recursively get to the next element

what do you mean by recursively being able to go to the next element?

TODO: T is random, better if it was called A for all

S is random better if it is called K for up to K



## Example: Detect Counterfeit Coin

Theorem: Given n weighings, we can detect which of 3n
 coins is counterfeit.

Proof: By induction. Let P(n) be “Given n weighings, we can detect which
of 3n
 coins is counterfeit.” We prove that P(n) is true for all n ∈ ℕ.

For the base case, we show P(0), that we can detect which of 30
 = 1
coins is counterfeit in no weighings. Exactly one coin is counterfeit, so
the sole coin must be counterfeit and we can find it with no weighings.

For the inductive step, suppose P(n) holds for some n ∈ ℕ, so we can
detect which of 3n
 coins is counterfeit using n weighings. We will show
P(n + 1) holds, meaning we can detect a counterfeit in 3n+1 coins using
n + 1 weighings.

Given 3n+1 coins, split them into three groups of size 3n
; call them A, B,
and C. Put the coins in A on one side of the scale and the coins in B on
the other. We consider three cases based on how the scale tips:

 Case 1: Side A is heavier. Then the counterfeit must be in group A.
 Case 2: Side B is heavier. Then the counterfeit must be in group B.
 Case 3: The scale is balanced. Then the counterfeit must be in
 group C, since it isn't in groups A or B.

In all cases, we use one weighing to find a set of 3n
 coins containing the
counterfeit coin. By the inductive hypothesis, with n more weighings, we
can find which of these 3n
 coins is counterfeit. This means that we can
find the counterfeit of 3n+1 coins in n + 1 weighings. Thus P(n + 1) holds,
completing the induction. 





## Example: Sum Of Powers of 2


**Theorem:** The sum of the first n powers of two is $2^n – 1$.

Proof: 

By induction. Let P(n) be “the sum of the first n powers of two is 2n – 1.” 

We will show P(n) is true for all n ∈ ℕ.


For our base case, we need to show P(0) is true, meaning the sum of the first zero powers of two is 20 – 1. Since the sum of the first zero powers of two is 0 = 20 – 1, we see P(0) is true.

For the inductive step, assume that for some n ∈ ℕ that

P(n) holds, meaning that 20
 + 21
 + … + 2n-1 = 2n
 – 1. We

need to show that P(n + 1) holds, meaning that the sum of the first n + 1 powers of two is 2n+1 – 1.

Consider the sum of the first n + 1 powers of two. This is the sum of the first n powers of two, plus 2n . 

Using the inductive hypothesis, we see that
2 0 + 21
 + … + 2n-1 + 2n = (20
 + 21
 + … + 2n-1) + 2n
= 2n
 – 1 + 2n
= 2(2n
) – 1
= 2n+1 – 1

Thus P(n + 1) is true, completing the induction. 




## Example: Power Set 

**Theorem:**	For	any	finite set S, if |S|= n, then	S	has	$2^n$	subsets.

Proof	is by induction.

Let	P(n) be	the	predicate "A set	with	cardinality	n	has	$2^n$	subsets."

Basis	step:

P(0) is	true,	because	the	set	with cardinality 0 (the	empty	set) has 1	subset (itself)	and	$2^0 = 1$.

Inductive	step:

Show that	if a set with	k	elements has $2^k$ subsets,	then a set	with k+1 elements	has	$2^{k+1}$	subsets.

Assume that	for	an arbitrary k, any	set	with cardinality k has $2^k$ subsets.

Let T	be a set such	that |T| =	k+1.

Enumerate	the	elements of T

$T = \{e_1, e_2, \dots, e_k, e_{k+1} \}$.

Let $S = \{ e_1, e_2, \dots , e_k \}$

Then |S| = k,	so S has $2^k$	subsets, according to	the	inductive	hypothesis.

Note	that $T = S ∪ e_{k+1}$,	so	every	subset of	S	is also	a	subset of	T.

Any	subset	of T	either	contains	the	element $e_{k+1}$, or	it	doesn’t	contain	$e_{k+1}$.

If a subset of T	doesn’t	contain $e_{k+1}$, then	it is	also a	subset of	S, and	there	are	$2^k$	of
those	subsets. 

On	the	other	hand,	if a subset	of T does	contain	the	element	$e_{k+1}$, then that subset	is formed	by	including	${e_k+1}$ in one of	the	$2^k$	subsets	of S,	so T has $2^k$ subsets containing $e_{k+1}$. (**KEY SETENCE**)





We have	shown	that T has $2^k$ subsets	containing $e_{k+1}$, and	another	$2^k$	subsets	not	containing	
$e_{k+1}$, so	the	total	number of	subsets	of T	is $2^k	+	2^k	=	(2)2^k = 2^{k+1}$.



Key Sentence:  if you have a set of 2 elements it has 4 subsets, a set with 3 elments has 8 elements, which is the original 4 subsets with an included elment in each one. it is almost circular because this is just by definition of what a subset is. )



## Example: Convex Polygon

**Theorem:** For any convex polygon with n vertices, the sum of the angles in that polygon is (n – 2) · 180°

 By induction. 
 
 Let P(n) be "all convex polygons with n vertices have angles that sum to (n – 2) · 180°." 

  We will prove P(n) holds for all n ∈ ℕ where n ≥ 3.

Basis

As a base case, we prove P(3): the sum of the angles in any convex polygon with three vertices is 180°. Any such polygon is a triangle, so its angles sum to 180°. 

For the inductive step, assume for some n ≥ 3 that 

P(n) holds and all convex polygons with n vertices have angles that sum to (n–2) · 180°.

We prove P(n+1), that the sum of the angles in any convex polygon with n+1 vertices is (n–1) · 180°. 
Let A be an arbitrary convex polygon with n+1 vertices. Take any three consecutive vertices in A


The sum of the angles in A is equal to the sum of the angles in triangle B (180°) 
and the sum of the angles in convex polygon C (which, by the IH, is (n – 2) · 180°). Therefore, the sum of the angles in A is (n–1) · 180°. Thus P(n + 1) holds, completing the induction




$[ P(1) \land \forall n P(n) \implies P(n+1) ] \implies \forall n P(n)$


If you can get to the first step of the ladder and you can always take one more step, then you can go as high as you want.

To this the quantified statement  $\forall n P(n) \implies P(n+1)$ it suffices to prove the unquantified implication. This will usually be proved by condtional proof, which means the induction step starts with assuming P(n).

You assume P(n)  and that leads to a proof of \forall n P(n)