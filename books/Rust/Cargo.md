---
title: Cargo
mathjax: true
layout: default
toc: true
---


# Cargo

* [The Rust Programming Language](Introduction.html)



# Cargo

Cargo is similar to make

Installed **cargo** with a **curl** command to downloads into **~/.cargo/bin/rustc**

**rustup** is used for updating the compiler and looking at docs (**rustup docs**)

```bash
rustc --version
cargo --version
rustup docs
cargo new  
cargo run #knows if needs to build
cargo build --release #builds a release which is faster
cargo build #without the release builds faster but executable is not optimized
cargo check #makes sure the program can build but doesn't generate executable used for dev
```





# CHAPTER 14:  More about Cargo

In Rust, release profiles are predefined and customizable profiles with different
configurations that allow a programmer to have more control over various
options for compiling code


Cargo has two main profiles: the dev profile Cargo uses when you run
cargo build and the release profile Cargo uses when you run cargo build
--release .

```
Cargo.toml
[profile.dev]
opt-level = 0
[profile.release]
opt-level = 3
```

Documentation comments use three slashes, /// , instead of two and
support Markdown notation for formatting the text.


For convenience, running cargo doc --open will build the HTML for your
current crate’s documentation

Adding example code blocks to your documentation comments can help
demonstrate how to use your library, and doing so has an additional bonus:
running cargo test will run the code examples in your documentation as
tests!

Another style of doc comment, //! , adds documentation to the item that
contains the comments rather than adding documentation to the items fol-
lowing the comments.  

```rust
pub use self::kinds::PrimaryColor;
pub use self::kinds::SecondaryColor;
pub use self::utils::mix;

pub mod kinds {
// --snip--
}
pub mod utils {
// --snip--
}


use art::PrimaryColor;
use art::mix;
```


Before you can publish any crates, you need to create an account on https://crates.io/ and get an API token.


cargo login abcdefghijklmnopqrstuvwxyz012345

This command will inform Cargo of your API token and store it locally

in ~/.cargo/credentials.

```
[package]
name = "guessing_game"
version = "0.1.0"
authors = ["Your Name <you@example.com>"]
description = "A fun game where you guess what number the computer has
chosen."
license = "MIT OR Apache-2.0"
```


are allocated on a first-come, first-served basis.

A workspace is a set of packages that share the same Cargo.lock and output
directory.

```
[workspace]
members = [
"adder",
]

[dependencies]
add-one = { path = "../add-one" }

```
