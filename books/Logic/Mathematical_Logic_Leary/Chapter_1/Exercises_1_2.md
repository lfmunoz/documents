---
title: Exercises 1.2
mathjax: true
layout: default
toc: true
---



# Exercise 1.2.1
1. Carefully write out the symbols that you would want to have in a language L that you intend to use to write statements of elementary algebra. Indicate which of the symbols are constant symbols, and the arity of the function and relation symbols that you choose. Now write
out another language, M (i.e., another list of symbols) with the same
number of constant symbols, function symbols, and relation symbols
that you would not want to use for elementary algebra. Think about
the value of good notation.



+, =, *, (,), / 
-> ? $ # @




2. What are good examples of unary (1-ary) functions? Binary functions?
Can you find natural examples of relations with arity 1, 2, 3, and 4? As

you think about this problem, stay mindful of the difference between
the function and the function symbol, between the relation and the
relation symbol.

++, abs arity 1
+ arity 2
?: arity 3 
 






3. In the town of Sneezblatt there are three eating establishments: McBurgers, Chez Fancy, and Sven’s Tandoori Palace. Think for a minute about
statements that you might want to make about these restaurants, and
then write out L, the formal language for your theory of restaurants.
Have fun with this, but try to include both function and relation symbols in L. What interpretations are you planning for your symbols?

L is   { ↑ , ||, >, < }

McBugers
Chez gacy
Sirens Tandori Palance




4. You have been put in charge of drawing up the schedule for a basketball
league. This league involves eight teams, each of which must play each
of the other seven teams exactly two times: once at home and once
on the road. Think of a reasonable language for this situation. What
constants would you need? Do you need any relation symbols? Function
symbols? It would be nice if your finished schedule did not have any
team playing two games on the same day. Can you think of a way
to state this using the formal symbols that you have chosen? Can you
express the sentence which states that each team plays every other team
exactly two times?
5. Let’s work out a language for elementary trigonometry. To get you
started, let us suggest that you start off with lots of constant symbols—
one for each real number. It is tempting to use the symbol 7 to stand
for the number seven, but this runs into problems. (Do you see why
this is illegal? 7, 77, 7/3, . . . .) Now, what functions would you like
to discuss? Think of symbols for them. What are the arities of your
function symbols? Do not forget that you need symbols for addition
and multiplication! What relation symbols would you like to use?


6. A computer language is another example of a language. For example,
the symbol := might be a binary function symbol, where the interpretation of the instruction
x := 7
would be to alter the internal state of the computer by placing the value


relational function a constant
+ two
x,y variable



7 into the position in memory referenced by the variable x. Think about
the function associated with the binary function symbol
if , then .
What are the inputs into this function? What sort of thing does the
function do? Look at the statement
If x + y > 3, then z := 7.
Identify the function symbols, constant symbols, and relation symbols.
What are the arities of each function and relation symbol?



7. What would be a good language for the theory of vector spaces? This
problem is slightly more difficult, as there are two different varieties of
objects, scalars and vectors, and you have to be able to tell them apart.
Write out the axioms of vector spaces in your language. Or, better
yet, use a language that includes a unary function symbol for each real
number so that scalars don’t exist as objects at all!


8. It is not actually necessary to include function symbols in the language,
since a function is just a special kind of relation. Just to see an example,
think about the function f : N → N defined by $f(x) = x^2$
. Remembering that a relation on N × N is just a set of ordered pairs of natural
numbers, find a relation R on N × N such that (x, y) is an element of R
if and only if y = f(x). Convince yourself that you could do the same
for any function defined on any domain. What condition must be true
if a relation R on A × B is to be a function mapping A to B?


