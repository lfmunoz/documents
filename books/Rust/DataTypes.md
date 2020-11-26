---
title: Data Types
mathjax: true
layout: default
toc: true
---





# Data Types 

* [The Rust Programming Language](Introduction.html)

const are immutable and you must specify the data type. 

constants must be known at compile time



Rust has four primary scalar types: integers, floating-point numbers, Booleans, and characters. 

i8, u8, u16, u32, u64, u128


# Literals

```rust
Decimal 98_222
Hex 0xff
Octal 0o77
Binary 0b1111_0000
Byte (u8 only) b'A'
```

## Variables

Rust is statically typed meaning all variable types at compile time

```rust

let y: f32 = 3.0; // f32
let f: bool = false; // bool is 1 byte in size
let c = 'z'; // 4 bytes long Unicode Scalar

let w = 2; // variables are immutable by default
let mut x = 5;  
const MAX_POINTS: u32 = 100_000;


//f32 and f64
let y: f32 = 3.0; // f32

let f: bool = false; // bool is 1 byte in size

let c = 'z'; // 4 bytes long Unicode Scalar


```

You can declare a new variable with the same name as a previous variable (shadowing it)

