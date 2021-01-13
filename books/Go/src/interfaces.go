package main

import "math"

type Shape interface {
	// A method set is a list of methods that a type must have
	//  in order to “implement” the interface.
	area() float64
}

type Rectangle struct {
	// Cannot be accessed outside of this package because
	// they the field names start with lowercase
	x1, y1, x2, y2 float64
}

func distance(x1, y1, x2, y2 float64) float64 {
	a := x2 - x1
	b := y2 - y1
	return math.Sqrt(a*a + b*b)
}

// Rectangle has area methods which return float64s
// so implement the Shape interface.
func (r *Rectangle) area() float64 {
	l := distance(r.x1, r.y1, r.x1, r.y2)
	w := distance(r.x1, r.y1, r.x2, r.y1)
	return l * w
}
