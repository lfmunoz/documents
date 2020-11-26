---
title: Error Handling
mathjax: true
layout: default
toc: true
---


# Error Handling

* [The Rust Programming Language](Introduction.html)





Rust
doesn’t have exceptions. Instead, it has the type Result<T, E> for recoverable
errors and the panic! macro that stops execution when the program encoun-
ters an unrecoverable error.

```rust
fn main() {
panic!("crash and burn");
}


enum Result<T, E> {
Ok(T),
Err(E),
}


use std::fs::File;
fn main() {
  let f = File::open("hello.txt");
  let f = match f {
    Ok(file) => file,
    Err(error) => {
      panic!("Problem opening the file: {:?}", error)
    },
  };
}


fn main() {
let f = File::open("hello.txt");
let f = match f {
  Ok(file) => file,
  Err(error) => match error.kind() {
    ErrorKind::NotFound => match File::create("hello.txt") {
      Ok(fc) => fc,
      Err(e) => panic!("Problem creating the file: {:?}", e),
    },
    other_error => panic!("Problem opening the file: {:?}", other_error),
  },
  };
}


let f = File::open("hello.txt").unwrap()
```

unwrap will return the value
inside the Ok . If the Result is the Err variant, unwrap will call the panic! macro
for us.

Another method, expect , which is similar to unwrap , lets us also choose
the panic! error message.


```rust
let f = File::open("hello.txt").expect("Failed to open hello.txt");

let mut f = File::open("hello.txt")?;
let mut s = String::new();
f.read_to_string(&mut s)?;
Ok(s)


```