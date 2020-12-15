---
title: Too many options slows production
layout: page
---


In Marketing and Psychology there is a well known principle called **"The Paradox of Choice"**. I've noticed a similar principle in programming languages and frameworks as well.

If you work with Gradle for example, it uses Groovy scripts which I feel has too many options. I often see scripts with different variations all doing the same thing, for example declaring a dependency. 

```groovy
// GOOD
testCompile("org.junit.jupiter:junit-jupiter:5.4.0") 
// NOT GOOD
testCompile "org.junit.jupiter:junit-jupiter:5.4.0"
testCompile 'org.junit.jupiter:junit-jupiter:5.4.0'
testCompile('org.junit.jupiter:junit-jupiter:5.4.0')
// https://mvnrepository.com/artifact/org.junit.jupiter/junit-jupiter
testCompile group: 'org.junit.jupiter', name: 'junit-jupiter', version: '5.4.0'
```

As a programmer I don't want all those options. 

(1) It's difficult to remember if there are any subtle differences or they are just doing the exact thing.  

* In C/C++ and Java " is for multiple characters and ' is a single character
* In Bash, Groovy, Kotlin " allows variable replacement while ' doesn't allow variable replacement
* In Python there is no difference between and " and '

(2) When I copy code from other project there are inconsistencies, someone in the team likes single quotes another likes double quotes, now I need coordinate to have code consistency.

Go is language that I enjoy because it is minimal and opinionated, giving it a sort of straight-forwardness feel. In most other languages good programmers intuitively follow the principle:

<div class="definition" markdown="block">
**Programming Principle:** Limit the language features you use.
</div>

Just because there is a language feature doesn't mean you should use it. Many features are actually anti-patterns, but they are there nevertheless.  For example goto in C. The with-statement in JavaScript (deprecated). In VHDL there is also a with-statement and if you know what you're doing you simply don't use it. These statements have better alternatives.

With frameworks you see the same situation, i.e, in Spring Boot, you can do **GetMapping** or **RequestMapping** to annotate an HTTP endpoint. Generally when I figure the options I pick one and stick to it, i.e, limit the features I use.



