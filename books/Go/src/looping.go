package main

import "fmt"

func infinite() {
	for { // same as for true {}
		fmt.Printf("This loop will run forever.\n")
	}
}

func rangeLoop() {
	strings := []string{"hello", "world"}
	// The range expression, strings, is evaluated once
	//  before beginning the loop.
	for i, s := range strings {
		fmt.Println(i, s)
	}
}

func stdForLoop() {
	sum := 0
	for i := 1; i < 10; i++ {
		sum += i
		if i == 8 {
			break
		}
	}
	fmt.Println(sum)
}

func aWhileLoop() {
	i := 0
	for i <= 10 {
		i = i + 1
		fmt.Println(i)
	}
}

func mainY() {
	stdForLoop()
	aWhileLoop()
	rangeLoop()
	// infinite()
}
