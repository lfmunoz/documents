---
title: Rust
mathjax: true
layout: default
toc: true
---


# The Rust Programming Language

* Rust Home
    * https://kotlinlang.org/docs/tutorials/command-line.html


<details>
<summary> <strong> [ skeleton.rs ] </strong> </summary>

<p markdown="block">
```cpp
{% include_relative src/skeleton.rs %}
````
</p></details>  



* Rust code uses snake case as the conventional style for function and variable names. 
* Rust doesn’t care where you define your functions (the order)
* Rust is an expression-based language. Statements are instructions that perform some action and do not return a value. Expressions evaluate to a resulting value.



# TOC

  
* [Cargo](Cargo.html)
  * Installing Rust
* [Data Types](DataTypes.html)
    * literals: hex, decimal, binary, byte
    * variables: bool, f32, u8, i8, u128
    * modifiers: mut, const
    * shadowing
* [IO](IO.html)
    * fs::read_to_string
    * env::args()
* [Generics](Generics.html)
    * pub
    * trait - similar to interface
* [Collections](Collections.html)
    * Vec, HashMap
    * String - collection of bytes
* [Functional Programing](FunctionalProgramming.html)
    * closures
* [Error Handling](ErrorHandling.html)
* [Testing](Testing.html)
* [Modules](Modules.html)
    * crates, packages
* [Concurrency](Concurrency.html)



# Data Structures 

Tuples
```rust
let tup: (i32, f64, u8) = (500, 6.4, 1);
let (x, y, z) = tup; // destructuring,
let five_hundred = x.0;
```

Arrays
```rust
let a: [i32; 5] = [1, 2, 3, 4, 5];
let a = [1, 2, 3, 4, 5]; // must have the same type (fixed length)
```


# Loops 


Expressions do not include ending semicolons. If you add a semicolon
to the end of an expression, you turn it into a statement, which will then not
return a value.

```rust
if number < 5 { // must be bool
    println!("condition was true");
} else if number % 3 == 0 {
    println!("x")
} else {
    println!("condition was false");
}
```




Rust has three kinds of loops: **loop** , **while** , and **for**.

The loop keyword tells Rust to execute a block of code over and over again
forever or until you explicitly tell it to stop.

```rust
loop {
  println!("again!");
}

break counter * 2;

let a = [10, 20, 30, 40, 50];
for element in a.iter() {
}

for number in (1..4).rev() {
println!("{}!", number);  //  ! means it is a macro not function

}
```








# CHAPTER 4: UNDERSTANDING OWNERSHIP

Each value in Rust has a variable that’s called its owner.
There can be only one owner at a time.
When the owner goes out of scope, the value will be dropped.

```rust
let mut s = String::from("hello");
s.push_str(", world!"); // push_str() appends a literal to a String
let r1 = &mut s;
let bytes = s.as_bytes();

fn change(some_string: &mut String) {
some_string.push_str(", world");
}

let s = String::from("hello world");
let hello = &s[0..5];
let world = &s[6..11];
```

# Chapter 5: Using Structs to Structure Related Data

```rust
struct User {
  username: String,
  email: String,
  sign_in_count: u64,
  active: bool,
}
``

the entire instance must be mutable; Rust doesn’t allow us to mark only certain fields as mutable

```rust
let user2 = User {
email: String::from("another@example.com"),
username: String::from("anotherusername567"),
..user1
};

//Tuple Struct
struct Color(i32, i32, i32);

println!("rect1 is{:?}", rect1)

#[derive(Debug)]
struct Rectangle {
width: u32,
height: u32,
}

impl Rectangle {
  fn area(&self) -> u32 {
    self.width * self.height
  }
}

// associated fucntions don't take a &self
impl Rectangle {
  fn square(size: u32) -> Rectangle {
    Rectangle { width: size, height: size }
  }
}

let sq = Rectangle::square(3);
```


# CHAPTER 6: Enums and Pattern Matching

```rust
let four = IpAddrKind::V4;
let six = IpAddrKind::V6;
enum IpAddrKind {
  V4,
  V6,
}

enum IpAddr {
  V4(String),
  V6(String),
}

let home = IpAddr::V4(String::from("127.0.0.1"));
```

Rust
doesn’t have the null feature that many other languages have. Null is a value
that means there is no value there.

Rust does not have nulls, but it does have an enum that
can encode the concept of a value being present or absent.

```rust
enum Option<T> {
Some(T),
None,
}

let absent_number: Option<i32> = None;

fn value_in_cents(coin: Coin) -> u8 {
  match coin {
    Coin::Penny => 1,
    Coin::Nickel => 5,
    Coin::Dime => 10,
    Coin::Quarter => 25,
  }
}
```

Matches in Rust are exhaustive: we must exhaust
every last possibility in order for the code to be valid.


```rust
let some_u8_value = 0u8;
match some_u8_value {
1 => println!("one"),
3 => println!("three"),
5 => println!("five"),
7 => println!("seven"),
_ => (),
}

if let Some(3) = some_u8_value {
println!("three");
}
```

In other words, you can think of if let as syntax sugar for a match that
runs code when the value matches one pattern and then ignores all other
values.





# CHAPTER 15:  Smart Pointers

A pointer is a general concept for a variable that contains an address in memory.

References are indicated by the & symbol and borrow the value they point to.
They don’t have any special capabilities other than referring to data. Also, they
don’t have any overhead and are the kind of pointer we use most often.

Smart pointers are usually implemented using structs. The charac-
teristic that distinguishes a smart pointer from an ordinary struct is that
smart pointers implement the Deref and Drop traits.

```rust
enum List {
  Cons(i32, Box<List>),
  Nil,
}

fn main() {
let list = Cons(1, Box::new(Cons(2, 
  Box::new(Cons(3,
  Box::new(Nil)))))); } 

let x = 5;
let y = &x;
assert_eq!(5, x);
assert_eq!(5, *y);
```

if we want to make an
assertion about the value in y , we have to use *y to follow the reference to the
value it’s pointing to (hence dereference)

To enable multiple ownership, Rust has a type called Rc<T> , which is an
abbreviation for reference counting.

Unlike Rc<T> , the RefCell<T> type represents single ownership over the data it
holds.


