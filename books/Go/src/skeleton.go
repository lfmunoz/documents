// Mandatory statement, as Go programs run in packages.
// Note: If your main function doesn’t exist in package main,
//  the build tools won’t produce an executable.
package main

import "fmt"

// Main
//  go run skeleton.go
func main() {
	// Single line comment
	/* Multi-line comment */
	// A name is exported if it starts with capital letter.
	fmt.Println("Hello, World!")
}
