---
title: Testing
mathjax: true
layout: default
toc: true
---


# Testing

* [The Rust Programming Language](Introduction.html)





cargo test compiles your code in test mode and runs the resulting test binary.

```bash
$ cargo test -- --test-threads=1

#Run only one test
cargo test one_hundred

#Run anything starting with add
cargo test add

#Run only ignored tests
cargo test -- --ignored   
```

At its simplest, a test in Rust is a function that’s annotated with the test
attribute.

To change a function into a test function, add #[test] on the line before fn .

When you run
your tests with the cargo test command, Rust builds a test runner binary
that runs the functions annotated with the test attribute and reports on
whether each test function passes or fails.

```rust
#[cfg(test)]
mod tests {
 #[test]
  fn it_works() {
    assert_eq!(2 + 2, 4);
  }
  #[test]
  fn another() {
    panic!("Make this test fail");
  }
}

assert!(larger.can_hold(&smaller));
assert_ne!
assert!(result.contains("Carol"), "Greeting did not contain name, value was `{}`", result);

#[test]
#[should_panic]
fn greater_than_100() {
Guess::new(200);
}

#[ignore]
fn expensive_test() {
// code that takes an hour to run
}
```


cfg stands for configuration and tells Rust that the following item should
only be included given a certain configuration option
In this case, the
configuration option is test , which is provided by Rust for compiling and
running tests. By using the cfg attribute, Cargo compiles our test code
only if we actively run the tests with cargo test



