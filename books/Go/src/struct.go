package main

import "fmt"

// ________________________________________________________________________________
// Types
// ________________________________________________________________________________
type user struct {
	name       string
	email      string
	ext        int
	privileged bool
}

type admin struct {
	person user
	level  string
}

// taking an existing type and using
// it as the type specification for the new type.
type Duration int64

// ________________________________________________________________________________
// ________________________________________________________________________________
func basicUsage() {
	// initialized with default value
	// idiomatic to use the keyword var
	var bill user
	fmt.Println(bill) // {0   false}

	// If the variable will be initialized to something other than
	// its zero value, then use the short variable declaration operator
	// with a struct literal.
	lisa := user{
		name:       "Lisa",
		email:      "lisa@email.com",
		ext:        123,
		privileged: true, // it requires a trailing comma.
	}
	fmt.Println(lisa)

	// Order is important
	lisaAlt := user{"Lisa", "lisa@email.com", 123, true}
	fmt.Println(lisaAlt)
}

func nested() {
	fred := admin{
		person: user{
			name:       "Lisa",
			email:      "lisa@email.com",
			ext:        123,
			privileged: true,
		},
		level: "super",
	}
	fmt.Println(fred)
}

// ________________________________________________________________________________
// Main
// ________________________________________________________________________________
func main() {
	basicUsage()
	nested()
	var dur Duration
	// dur = int64(1000)
	// cannot use int64(1000) (type int64) as type Duration in assignment
	fmt.Println(dur)
}
