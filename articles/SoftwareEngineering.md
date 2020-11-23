---
title: Software Engineering
mathjax: true
layout: default
toc: true
---


# Software Engineering

> An engineer can do for a nickel what any fool can do for a dollar - Henry Ford


A successful project

1. Is delivered on the agreed time
2. At the agreed cost
3. With the agreed functionality
4. At an acceptable quality level
5. And leaves the team energized for future projects


## Why Do Software Projects Get into Trouble?

1. Bad requirements Vague, ambiguous, and/or incomplete requirements. (This issue is usually beyond the control of the development team.)
2. Poor project management Poor planning, estimation, and tracking. (The developers are not the project managers.)
3. Complexity. Number three overall but number one for the technical team. So, our number one goal should be to manage complexity. The Primary Technical Imperative: Manage Complexity


1/4 of all projects fail to the point that they are cancelled



### Net Negative Producing Programmer

Schulmeyer’s study implies that about 20% of developers are NNPPs. What to do about this is unclear, just make sure you aren't one of them.

"We've known since the early ‘60s but have never come to grips with the implications that there are net negative producing programmers (NNPPs) on almost all projects, who insert enough spoilage to exceed the value of their production. This negative production does not merely apply to extreme cases. In a team of ten, expect as many as three people to have a defect rate high enough to make them NNPPs. With a normal distribution of skills, the probability that there is not even one NNPP out of ten is virtually nil."


# Software Development 

> Requirements => Design => Construction  => Test

These aren’t phases in a software development life cycle (i.e., not implying waterfall). These are activities in the decision-making process that is at the root of software development. 



## Requirements 

**The Product Backlog** - The single ordered list of everything that might be needed in the product. The items are known as **PBIs** (Product Backlog items).

A good backlog is ordered, has estimates, and  has good descriptions



**Epic** - User story that is too large to be implemented in a single Sprint

**Acceptance Criteria** - Objective criteria by which we can evaluate whether we have implemented enough of user story in this sprint.  The basis for functional testing of completed user stories.


**Stakeholders** - Anyone whose problem you need to solve

Requirement Roles
* Originator - End users who is using product
* Source - Who you hear the requirement from, often someone who represents the end user like a marketing person
* Steward - Captures and writes the requirements
* Verifier - Person who packages the requirements
* Implementer - Person who provides the solution


## Design

While requirements are decisions that are made by somebody else (e.g., stakeholders). Design is made up of decisions that developers make.

* You must understand requirements to create a good design; design must be consistent with the requirements. - Implication Requirements must be good, complete, and unambiguous.
* Real-world designs are constrained and influenced by technology.  - Prototyping is very useful for exploring and testing various design ideas.
* Design involves tradeoffs. -  No single “right” design exists, only better or worse mixes of tradeoffs. Your professional judgement is required. 
* Design is almost always an evolutionary process. - You’re never going to get it right the first time. Some iteration will always be required.
* Some design is better than no design, but the best is the enemy of the good. - Sometimes you just need to go into production.


Identify the significant elements of that internal structure
Explain the important relationships between those elements
Provide sufficient detail to construct those elements



As a communication tool, design enables vital communication between technical peers, with the project manager, and with Quality Assurance.


Different designs vary in the code volume required to implement them by a factor of 10, but the average programmer considers only one design that will actually work before beginning coding.




### There’s no such thing as “self-documenting code.”

Code does not answer these questions:
1. What is this code intended to do? Code will tell you only what it does, not what it was intended to do.
2. Why does this code look the way it does? Code will not tell you why it looks the way it does. (“Has to be” versus “happens to be.”)



## Construction 


In a typical software budget, 80% of the budget is spent on maintaining existing code! Decreasing maintenance costs is much more powerful than decreasing development costs.


Uncle Bob talks about how when you first start a project it is easy to add features.

You start a project and a week later you have something running and someone comes to you and says, can you add this, and a week later you add the feature and it is working.

Then you add another feature. A year later, someone comes to you and says can you add this feature, and you think about it and realize it won't be easy. it will take 6 months.

how can you be so productive at first and so unproductive later. the issue is not understanding the primary imperative.

> The Primary Technical Imperative: Manage Complexity

**modularization:** code is factored into "modules" of some sort where each module has a clear responsibility. The action of the code can be documented and understood without a user having to understand its implementation details.

**encapsulation:** modules make a distinction between their "public" surface area and their "private" implementation details so that the latter can be improved without affecting the correctness of the program as a whole.

**re-use:** when a problem is solved correctly once, it is solved for all time; the solution can be re-used in the creation of new solutions. Techniques such as making a library of utility functions, or making functionality in a base class that can be extended by a derived class, or architectures that encourage composition, are all techniques for code re-use. Again, the point is to lower costs.

**automatic detection of errors:** a team working on a large program is wise to build a device which determines early when a programming error has been made and tells you about it so that it can be fixed quickly, before the error is compounded with more errors. Techniques such as writing a test suite, or running a static analyzer fall into this category.




Complexity has essential and accidental properties:

Essential properties The properties a thing has by virtue of being that thing.

Accidental properties The properties a thing happens to have.



### Lowering quality lengthens development time.

Quality software takes the least amount of time to develop. If you have code that is simple as possible, tests that are complete and a design that fits just right, additions and changes happen in the fastest possible way because the impact is lowest. Consequently, if you hack something out, the more you hack the slower you go because the cost of addition or change grows with each line of code.






## Test

Test Driven Development is not about writing test cases for testability and quaility assurance . It is a requirement pratice or discovery practice not a test practice.



