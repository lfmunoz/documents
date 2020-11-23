# Clever Design - It's a problem

In all my years as an engineer I've always noticed a disinclination to design that is ordinary, tried and true, obvious, and straight-forward.

The source of this disinclination is difficult to pinpoint and has many variants. It could be that it's human nature to seek creativity, perhaps Lead Engineers tend to get bored and try to experiment or maybe there is just a misunderstanding of what makes a successful Software Project.


It isn't common to hear that Software Engineering is an already solved problem. Your particular engineering problem or something similar has already been thought about and solved by someone smarter than you. Engineering is ordinary, proven, well-known, straight-forward and simple. Beautiful code is where you can't make it any more clear and simple. The creativity and originality should be happening at a higher level. Despite this I've been in many situations working with someone more senior than me where it has been obvious that this person was being clever. It's just a matter of time. The question is how to handle Clever Design?

Being clever in small dosages isn't detrimental, we have methodologies to protect against code and design that will be difficult to maintain and understand: modularization and encapsulation. Second, you could be wrong, maybe someone does know something that you don't. Software Engineering is a team effort, you must be able to communicate and be ready to compromise often. Understand now that there is going to be a time when you will be the person being clever and it will be near impossible for you to see the situation for what it is. Documenting the design is important for this reason. You spell out the decisions and people sign their name creating accountability and scrutiny.

Things to look for in Clever Designs:
* The decision is stated in terms of performance, with no actual numerical evidence. Peoples intuition about performance has been proven to be incredibly inaccurate, specially experienced engineers. 
* The decision is stated in absolute terms, "there is no other way to do this". There are always alternatives, there is no perfect decisions.
* The decision is made without considering alternatives. It has been shown that people who consider one alternative rarely choice the best one. 
* The decision is made without consider others opinions. I.e,. If two talented engineers disagree with me I will immediately move from being to right to compromising.
*  The decision is based on an argument from authority. "This is correct because I know it is based on my extensive authority and experience."

Another question to consider is, as a developer should you construct an application if you disagreed with the design? If you thought the design was overly complicated, inefficient, use inferior technologies, is going to be difficult to maintain or some other reason.

This could be a form selling your soul. Life is short, you should do what you feel good about. Do you really want to build something you don't feel good about and then have to maintain and debug it? Absolutely not, but there is also a sense of being a good team member and helping out and compromising, especially when it isn't that big of an issue. One week worth of work, 1 month? Worth it to build good relationships with team members. So like all things it depends.

Generally if I create a design and someone doesn't like it, I wouldn't expect them to work on it and maintain it. I need buy-in from engineers working on my designs. I would explain my thinking and try to help them see my point of view, compromise and let them modify parts of it, or just build it myself and let them work the parts they do agree with.
