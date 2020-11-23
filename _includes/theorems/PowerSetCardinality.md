
**Theorem:** For any finite set S, if \|S\|= n, then S has $2^n$ subsets.

**Proof:** by induction.

Let	P(n) be	the	predicate "A set	with	cardinality	n	has	$2^n$	subsets."

We prove that P(n) is true for all n ∈ ℕ

**Basis	step:**

P(0) is	true,	because	the	set	with cardinality 0 (the	empty	set) has 1	subset (itself)	and	$2^0 = 1$.

**Inductive	step:**

We show that if a set with k elements has $2^k$ subsets, then a set	with k+1 elements	has	$2^{k+1}$	subsets.

Assume that	for	an arbitrary k, any	set	with cardinality k has $2^k$ subsets.

Let T be a set such	that \|T\| = k+1.

Enumerate	the	elements of T

$T = \{e_1, e_2, \dots, e_k, e_{k+1} \}$.

Let $S = \{ e_1, e_2, \dots , e_k \}$

Then \|S\| = k,	so S has $2^k$	subsets, according to	the	inductive	hypothesis.

Note that $T = S ∪ e_{k+1}$,	so	every	subset of	S	is also	a	subset of	T.

Any	subset of T	either	contains the element $e_{k+1}$, or	it	doesn’t	contain	$e_{k+1}$.

If a subset of T doesn’t	contain $e_{k+1}$, then	it is	also a	subset of	S, and	there	are	$2^k$	of
those	subsets. 

On	the	other	hand,	if a subset	of T does	contain	the	element	$e_{k+1}$, then that subset	is formed	by	including	${e_k+1}$ in one of	the	$2^k$	subsets	of S,	so T has $2^k$ subsets containing $e_{k+1}$. 

We have	shown	that T has $2^k$ subsets	containing $e_{k+1}$, and	another	$2^k$	subsets	not	containing	
$e_{k+1}$, so	the	total	number of	subsets	of T	is $2^k	+	2^k	=	(2)2^k = 2^{k+1}$.


**Key Sentence:**  If you have a set of 2 elements it has 4 subsets, a set with 3 elements has 8 subsets, which are the original 4 subsets + those same subsets with an included element in each one. 

