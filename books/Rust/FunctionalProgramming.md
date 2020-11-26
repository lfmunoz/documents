---
title: Functional Programming
mathjax: true
layout: default
toc: true
---



# Functional Programming

* [The Rust Programming Language](Introduction.html)




```rust
let expensive_closure = |num| {
  println!("calculating slowly...");
  thread::sleep(Duration::from_secs(2));
  num
};

fn add_one_v1 (x: u32) -> u32 { x + 1 }
let add_one_v4 = | x |  x + 1;
```

All closures implement at least one of the traits: Fn , FnMut , or FnOnce .

```rust
struct Cacher<T>
where T: Fn(u32) -> u32
{
  calculation: T,
  value: Option<u32>,
}

let equal_to_x = move |z| z == x;

pub trait Iterator {
  type Item;
  fn next(&mut self) -> Option<Self::Item>;
  // methods with default implementations elided
}
```

The iter method produces an iterator over immutable references. 
If we want to create an iterator that takes ownership of v1 and returns owned values, we can call into_iter instead of iter .
Similarly, if we want to iterate over mutable references, we can call iter_mut instead of iter

```rust
let v2: Vec<_> = v1.iter().map(|x| x + 1).collect();
```

If the closure returns true , the value will
be included in the iterator produced by filter . If the closure returns false ,
the value won’t be included in the resulting iterator.


