---
title: Proof Theory
mathjax: true
layout: default
---



# Proof Theory


* [Induction](Induction.html)


Law of the Ecluded Middle: Either a statement is true or its negation is true (there is no "middle" possibility).

Law of Contradiction: A statement and its negation cannot both be true


Proof by contradiction (proof by reductio ad absurdum)



### Contrapositive

$$P \rightarrow Q \iff \neg Q \rightarrow \neg P$$

^ P ^ Q ^ $P \rightarrow Q$ ^  
| 0 | 0   | 1 | 
| 0 | 1   | 1 |
| 1 | 0   | 0 |
| 1 | 1   | 1 |

^ $\neg Q$ ^ $\neg P$ ^ $ \neg Q \rightarrow \neg P$ ^  
| 1 | 1   | 1 | 
| 0 | 1   | 1 |
| 1 | 0   | 0 |
| 0 | 0   | 1 |


“If something is a bat, then it is a mammal.”
“If something is not a mammal, then it is not a bat.”