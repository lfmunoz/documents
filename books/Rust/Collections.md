---
title: Collections
mathjax: true
layout: default
toc: true
---


# Collections

* [The Rust Programming Language](Introduction.html)


https://doc.rust-lang.org/stable/std/collections/

A vector allows you to store a variable number of values next to each other.

A string is a collection of characters. We’ve mentioned the String type previously, but in this chapter we’ll talk about it in depth.
A hash map allows you to associate a value with a particular key. It’s a particular implementation of the more general data structure called a map.

```rust
let v: Vec<i32> = Vec::new();
let v = vec![1, 2, 3];
puts all the values next to each other in memory.

let mut v = Vec::new();
v.push(5);

let third: &i32 = &v[2];
match v.get(2) {
Some(third) => println!("The third element is {}", third),
None => println!("There is no third element."),
}

let v = vec![100, 32, 57];
for i in &v {
println!("{}", i);
}
```


It’s useful to discuss strings in the context of collections because strings
are implemented as a collection of bytes

```rust

let mut s = String::new();
let data = "initial contents";
let s = data.to_string();
let s = String::from("initial contents");

A String can grow in size and its contents can change,

let mut s = String::from("foo");
s.push_str("bar");

let s = format!("{}-{}-{}", s1, s2, s3);

for c in "नमस्त " े .chars() {
println!("{}", c);
}

for b in "नमस्त " े .bytes() {
println!("{}", b);
}



use std::collections::HashMap;
let mut scores = HashMap::new();
scores.insert(String::from("Blue"), 10);
scores.insert(String::from("Yellow"), 50);

use std::collections::HashMap;
let teams = vec![String::from("Blue"), String::from("Yellow")];
let initial_scores = vec![10, 50];
let scores: HashMap<_, _> = teams.iter().zip(initial_scores.iter()).collect();
```

For types that implement the Copy trait, such as i32 , the values are copied
into the hash map. For owned values such as String , the values will be
moved and the hash map will be the owner of those values


```rust
for (key, value) in &scores {
println!("{}: {}", key, value);
}

```

