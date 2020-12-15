package main

import (
	"fmt"
)

type user struct {
	name  string
	email string
}

// pointer receiver
// When you call a method declared with a pointer receiver, the value used to
// make the call is shared with the method.
func (u *user) notifyp() {
	fmt.Printf("Sending user email to %s<%s>\n",
		u.name,
		u.email)
}

// value receiver
// method will be operating against a copy of the value
// used to make the method call.
func (u user) notify() {
	fmt.Printf("Sending user email to %s<%s>\n",
		u.name,
		u.email)
}

type admin struct {
	user  // Embedded Type
	level string
}

// main is the entry point for the application.
func main() {
	// Create an admin user.
	ad := admin{
		user: user{
			name:  "john smith",
			email: "john@yahoo.com",
		},
		level: "super",
	}

	// We can access the inner type's method directly.
	ad.user.notify()

	// The inner type's method is promoted.
	ad.notify()

	lisa := &user{"Lisa", "lisa@email.com"}
	// Go adjusts the pointer value to comply with the
	// 	method’s receiver.
	//  (*lisa).notify()
	lisa.notify()

	// calling a pointer receiver, go adjusts the value
	//(&bill).notify()
}
