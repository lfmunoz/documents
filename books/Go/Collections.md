---
title: Collections
mathjax: true
layout: default
toc: true
---


# Collections

* [The Go Programming Language](Introduction.html)

Go has three different data structures that are baked into the language arrays, slices, and maps.



## Arrays
An array in Go is a fixed-length data type that contains a contiguous block of elements of the same type.
The memory is allocated sequentially.

Once an array is declared, neither the type of data being stored nor its length can be changed.

```go
// Declare an integer array of five elements.
var array [5]int

// initialized to their zero value (use var)
var favNums2[5] float64

// Initialize each element with a specific value.
favNums3 := [5]float64 {1,2,3,4,5}

// Capacity is determined based on the number of values initialized.
array := [...]int{10, 20, 30, 40, 50}

// Initialize index 1 and 2 with specific values.
// The rest of the elements contain their zero value.
array := [5]int{1: 10, 2: 20}

// Change the value at index 2.
array[2] = 35

array := [5]*int{0: new(int), 1: new(int)}
*array[0] = 10
// note array[2] = nil


// Copy the values from array2 into array1.
array1 = array2

// Copying an array of pointers copies the pointer 
// values and not the values that the
array1 = array2

```

An array is a value in Go. The type of an array variable includes both the length and the type of data that can be
stored in each element. This means you cannot assign an array of length 4 to an array of length 5.

```go
// Declare a two dimensional integer array
var array [4][2]int

// Declare and initialize a two dimensional array.
array := [4][2]int{
   {10, 11}, {20, 21}, {30, 31}, {40, 41}
}


```




```go

// Declare an array of 8 megabytes.
var array [1e6]int
// Pass the array to the function foo.
foo(array)

// Function foo accepts an array of one million integers.
func foo(array [1e6]int) {
    // ...
}

// Allocate an array of 8 megabytes.
var array [1e6]int
// Pass the address of the array to the function foo.
foo(&array)

// Function foo accepts a pointer to an array of one million integers.
func foo(array *[1e6]int) {
   //...
}
```



```go


for i, value := range favNums3 {
   fmt.Println(i, value)
}



```


##  Slices

Slices are built around the concept of dynamic arrays that can grow and
shrink as you see fit.

if you specify a value inside the [ ] operator, you’re creating an array. If
you don’t specify a value, you’re creating a slice.

A slice is a pointer a length and a capacity

```go
// Create a slice of integers.
// Contains a length of 3 and has a capacity of 5 elements.
slice := make([]int, 3, 5)

// Create a slice of integers.
slice := []int{10, 20, 30}

// Create a nil slice of integers.
var slice []int

// Get 3 and 4 ignore 5
numSlice2 :=numSlice[3:5]


   var s []int
   // Go provides a built-in append function. 
   //  func append(s []T, vs ...T) []T
   // If the backing array of s is too small to fit all the given values 
   //  a bigger array will be allocated. The returned slice will point to 
   //  the newly allocated array.

	// We can add more than one element at a time.
   s = append(s, 2, 3, 4)
   

   // The length and capacity of a slice s can be obtained 
   // using the expressions len(s) and cap(s).
   // The length of a slice is the number of elements it contains.
   len(s)
   // The capacity of a slice is the number of elements in the 
   // underlying array, counting from the first element in the slice.
   cap(s)

```

Removing an item from the middle of a slice

```go
func remove(slice []int, i int) []int {
  copy(slice[i:], slice[i+1:])
  return slice[:len(slice)-1]
}

// Removing an element from the first or last position is slightly easier:
slice = slice[1:len(slice)]
slice = slice[:len(slice)-1]
```

# Map

A map is an unordered collection of key-value pairs. If you need a stable iteration order, you must maintain a separate data structure.

```go

presAge := make(map[string] int)
// Create a map with a key of type string and a value of type int.
dict := make(map[string]int)
// Create a map with a key and value of type string.
// Initialize the map with 2 key/value pairs.
dict := map[string]string{"Red": "#da1337", "Orange": "#e95a22"}


```

```go
m := map[string]int{"Alice": 2, "Cecil": 1, "Bob": 3}

keys := make([]string, 0, len(m))
for k := range m {
    keys = append(keys, k)
}
sort.Strings(keys)

for _, k := range keys {
    fmt.Println(k, m[k])
}
// Output:
// Alice 2
// Bob 3
// Cecil 1


m = make(map[string]Vertex)
	m["Bell Labs"] = Vertex{
		40.68433, -74.39967,
   }
   
```


## Reference

* Treeset
   * https://godoc.org/github.com/emirpasic/gods/sets/treeset#Iterator.Value