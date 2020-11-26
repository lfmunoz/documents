---
title: Modules
mathjax: true
layout: default
toc: true
---


# Modules

* [The Rust Programming Language](Introduction.html)




A crate is a binary or library.

A package is one or more crates that provide a set of functionality.

A package must contain zero or one library crates, and no more. It can contain as many
binary crates as you’d like, but it must contain at least one crate (either
library or binary).

If a package contains src/main.rs

and src/lib.rs, it has two crates: a library and a binary, both with the same

name as the package.

```rust
mod front_of_house {
mod hosting {
fn add_to_waitlist() {}
fn seat_at_table() {}
}
mod serving {
fn take_order() {}
fn serve_order() {}
fn take_payment() {}
}
}
```

A path can take two forms:

An absolute path starts from a crate root by using a crate name or a literal crate .
A relative path starts from the current module and uses self , super , or an identifier in the current module.

```rust
use self::front_of_house::hosting;
use crate::front_of_house::hosting;
pub fn eat_at_restaurant() {
hosting::add_to_waitlist();
hosting::add_to_waitlist();
hosting::add_to_waitlist();
}
```

Bringing the function’s parent module into scope with use so we have to
specify the parent module when calling the function makes it clear that
the function isn’t locally defined while still minimizing repetition of the
full path.

On the other hand, when bringing in structs, enums, and other items
with use , it’s idiomatic to specify the full path.

```rust
use std::collections::HashMap;

use std::io::Result as IoResult;
```

https://crates.io/


```rust

use std::io;
use std::cmp::Ordering;


use std::{io, cmp::Ordering};
```

If we want to bring all public items defined in a path into scope, we can
specify that path followed by * , the glob operator:

```rust
use std::collections::*;

mod front_of_house;
```

Using a semicolon after mod front_of_house rather than using a block
tells Rust to load the contents of the module from another file with the
same name as the module
