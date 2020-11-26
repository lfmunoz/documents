---
title: Generics
mathjax: true
layout: default
toc: true
---


# Generics

* [The Rust Programming Language](Introduction.html)

 Generic Types, Traits, and Lifetimes

 
Rust implements generics in
such a way that your code doesn’t run any slower using generic types than it
would with concrete types.

Rust accomplishes this by performing monomorphization of the code
that is using generics at compile time. Monomorphization is the process of
turning generic code into specific code by filling in the concrete types that
are used when compiled.

```rust
fn largest<T>(list: &[T]) -> T {
}

struct Point<T> {
  x: T,
  y: T,
}

impl<T> Point<T> {
  fn x(&self) -> &T {
    &self.x
  }
}
```

A trait tells the Rust compiler about functionality a particular type has and
can share with other types.

Traits are similar to a feature often called interfaces in other languages, although
with some differences.


```rust
pub trait Summary {
  fn summarize(&self) -> String;
}

impl Summary for NewsArticle {
  fn summarize(&self) -> String {
    format!("{}, by {} ({})", self.headline, self.author, self.location)
  }
}

// Default Implementation
pub trait Summary {
  fn summarize(&self) -> String {
    String::from("(Read more...)")
  }
}
```

This parameter accepts any type that implements the specified trait.

```rust
pub fn notify(item: impl Summary) {
  println!("Breaking news! {}", item.summarize());
}
```
same as longer form 

```rust
pub fn notify<T: Summary>(item: T) {
 println!("Breaking news! {}", item.summarize());
}

fn some_function<T: Display + Clone, U: Clone + Debug>(t: T, u: U) -> i32 {

fn some_function<T, U>(t: T, u: U) -> i32
  where T: Display + Clone,  U: Clone + Debug
{


```

every reference in Rust has a lifetime, which is the scope for which that
reference is valid.


Lifetime annotations have a slightly unusual syntax: the names of
lifetime parameters must start with a single quote ( ' ) and are usually all
lowercase and very short, like generic types.

```rust
&i32 // a reference
&'a i32 // a reference with an explicit lifetime
&'a mut i32 // a mutable reference with an explicit lifetime

fn longest<'a>(x: &'a str, y: &'a str) -> &'a str {
  if x.len() > y.len() {
    x
  } else {
    y
  }
}
```

This annotation means an instance of ImportantExcerpt can’t outlive the reference
it holds in its part field.

```rust
struct ImportantExcerpt<'a> {
   part: &'a str,
}
```

lifetime elision rules.

One special lifetime we need to discuss is 'static , which denotes the entire
duration of the program. All string literals have the 'static lifetime, which
we can annotate as follows:

```rust
let s: &'static str = "I have a static lifetime.";
```

The text of this string is stored directly in the binary of your program,
which is always available.
