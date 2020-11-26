---
title: IO
mathjax: true
layout: default
toc: true
---


# Input / Output

* [The Rust Programming Language](Introduction.html)



```rust
use std::env;
use std::fs;
let contents = fs::read_to_string(filename)
.expect("Something went wrong reading the file");
```


As a function gains
responsibilities, it becomes more difficult to reason about, harder to test,
and harder to change without breaking one of its parts

Split your program into a main.rs and a lib.rs and move your program’s logic to lib.rs.
As long as your command line parsing logic is small, it can remain in main.rs.

```rust
let args: Vec<String> = env::args().collect();
let (query, filename) = parse_config(&args);

fn parse_config(args: &[String]) -> (&str, &str) {
  let query = &args[1];
  let filename = &args[2];
  (query, filename)
}
```


Using primitive values when a complex type would be more appropriate is an anti-
pattern known as primitive obsession.
implies that the two values we return are related
and are both part of one configuration value. We’re not currently conveying
this meaning in the structure of the data other than by grouping the two
values into a tuple; we could put the two values into one struct and give each
of the struct fields a meaningful name.


```rust
if let Err(e) = run(config) {
  println!("Application error: {}", e);
  process::exit(1);
}
```
