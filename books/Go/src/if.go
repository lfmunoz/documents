package main

import (
	"fmt"
	"math"
)

func ifScore() {
	score := 85
	if score >= 90 {
		fmt.Printf("You get an A. \n")
	} else if score >= 80 {
		fmt.Printf("You get a B. \n")
	} else {
		fmt.Printf("You failed. \n")
	}
}

func pow(x, n, lim float64) float64 {
	// the if statement can start with a statement to execute before the condition.
	// Variables declared by the statement are only in scope until the end of the if.
	if v := math.Pow(x, n); v < lim {
		return v
	}
	return lim
}

func switchAge() {
	yourAge := 16
	// string also work
	switch yourAge {
	case 16:
		fmt.Println("16")
		// break statement is provided automatically
	case 18:
		fmt.Println("18")
	default:
		fmt.Println("Invalid")
	}

	// Switch without a condition is the same as switch true.
	//  This construct can be a clean way to write long if-then-else chains.
}

func mainZ() {
	ifScore()
	switchAge()
	fmt.Println(pow(2, 2, 10))
}
