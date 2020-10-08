More formally stated,
a field is any set where addition and multiplication are well-defined operations
that are commutative, associative, and obey the familiar distributive property
a(b + c) = ab + ac.
 There must be an additive identity, and every element must
have an additive inverse.

Finally, there must be a multiplicative identity, and
multiplicative inverses must exist for all nonzero elements of the field.

Neither
Z nor N is a field.





# Functions



Loosely speaking, a function is rule that, for each element in some set D of possible inputs, assigns a possible output.

----
**Definition**: Function

A function f from a set X to a set Y, denoted $f: X \to Y$, associates to each $x \in X$ an element $f(x) \in Y$.


The notation $f: X \to Y$ is read “f is a function from X to Y” or “f is a function that maps X to Y”. We can think of f as matching each element of X with exactly one element of Y. We will see that f can also be thought of as matching subsets of A with subsets of B and vice-versa.

The set X is called the domain of f
We let Dom(f) denote the domain of f
X, the domain, is the set of possible inputs to the function
The set Y is called the co-domain of f
We let Cod(f) denote the co-domain of f.
Y, the co-domain, is the set from which the function's output values are chosen



A function, any function, has three features:

A domain set X,
A co-domain set Y, and
A rule of assignment that associates to each element x in the domain X a unique element, usually denoted f(x), in the co-domain Y.


----
Injective (One-to-One)
Let $f: X \to Y$. Then f is called one-to-one, or injective, iff different elements of X always have different elements of Y.

----
Surjective (Onto)
If $f : X \to Y$, then f is onto or surjective if every element of Y is the image under f of some element of A.

----
Bijection (Invertible)
A bijection is one-to-one and onto. A morphism means a mapping between sets. An automorphism, means a bijective map.


----
Inverse
Definition: Let f be a real-valued function. A rela-valued function g is called the inverse of f if f(g(x)) = x for all $x \in Dom(g)$ and g(f(x))=x for all $x \in Dom(f)$. We denote this by $g=f^{-1}$.

----
**Definition** : Cartesian Product

For two nonempty sets A and B, the Cartesian product, denoted $A \times B$ is the set of all ordered paris (a,b) of elements $a \in A$ and $b \in B$. That is,

$$ A \times B = \{  (a,b) ~ | ~ a \in A ~~~ \text{and} ~~~ b \in B \}$$

The Cartesian product of two sets A and B is the set of all pairs (a,b) where $a \in A$ and $b \in B$.


----
**Definition** : Continous Function

The function f is continuous at some point a of its domain if the limit of f(x) as x approaches a through the domain of f exists and is equal to f(a).

$$\lim_{x \to a} f(x) = f(a) $$

