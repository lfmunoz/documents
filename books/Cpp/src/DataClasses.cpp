
// ________________________________________________________________________________
//  INCLUDE
// ________________________________________________________________________________
#include <bits/stdc++.h>

using namespace std;


//________________________________________________________________________________ 
// Generic.hpp
//________________________________________________________________________________ 
#ifndef GVSU_CAR_H
#define GVSU_CAR_H

// Interface goes into a .h file
class Generic {
    public:
    Generic();
    ~Generic();
    int myMethod(int a, int b);

};  // note the semicolon after the class declaration! 

#endif

//________________________________________________________________________________ 
// Filename: Generic.cpp
//________________________________________________________________________________ 
class Generic {
    // Three levels of protection for class members in C++: public, private, and protected.
    //  protection level defaults to private
    private:
        const double MPG = 22.3;
      // Instance variables can not be assigned a value when declared in the header file;
      // they are initialized in the constructor instead.
        int value;
        int m_a;
        int m_b;

    public:
        Generic(int a, int b) {

        }
    // member function
    // You can give default values for parameters of functions
    // parameters without default values must precede all the parameters with defaults
    void setValues(int a, int b=5) { 
        m_a = a; m_b = b; 
    }


    // non-mutable member functions 
    // member function that do no alter their instance variables
    bool isEven() const {
        return (value % 2) == 0;
    }

}; // NOTE: Ending semicolon is important to remember

// Filename: main.cpp

// non-member or global function
// argc - argument count
// argv - argument of values
void main(int argc, char* argv[]) {

    Generic aGeneric = new Generic(0, 0); // NOT VALID 

    // The new operator returns a pointer to whatever follows it.
    Generic* aGeneric = new Generic(0, 0);
    aGeneric->bar(); // dereference the pointer and call the method

    // We can request a block of memory in global storage for certain data 
    // types by using new, and we return the memory by using delete. Only 
    // objects created using new should be deleted with delete
    Foo* fooPointer = new Foo(0, 0); // create a pointer to Foo and give it a
                                     // value
    Foo myFooInstance = *fooPointer; // dereference the pointer and assign it
                                     // to myFooInstance; copy is made (!)

    Generic aGeneric(0, 0);

    // These are equivalent
    Generic aGeneric;
    Generic aGeneric()

}


// Heap objects: created explicitly by the programmer by invoking new.
 // Detroy explicitly by the programmer
Car *his;
his = new Car ("1HTSF30Y68E387874");

// Atomatic object
Car hers("1F6DP5ED7B0858285"); /* she owns a Ford */

// C++ Reference
// A C++ reference is not a pointer, but it is an alias to an existing data;
Car hers("1F6DP5ED7B0858285"); /* she owns a Ford */
Car blue_ford& = hers;

int& feb = days_of_months[1];


// Copy constructor
// pass by reference as a read-only object
MyClass (const MyClass& source) {
}

// Move Constructor
MyClass (MyClass&& source) {
}


// NAMESAPCE 

namespace gvsu {
    class Car {
        private:

    }
}


// move assignment
void operator= (Coin&& src) {
value = src.value;
serial = std::move(src.serial);
}

// copy assignment
void operator= (const Coin& src) {
value = src.value;
serial = src.serial;
}


cout << sawyer;
cout . operator<< (sawyer); // equivalent expanded expression
operator<< (cout, sawyer); // alternate syntax of invocation

// correct, but the void return type will prevent chaining of <<
void operator<< (ostream& os, const Book& b)
{
os << b.getTitle() << " by " << b.getAuthor();
}

// To allow chaining, we must change the return type
// from void to ostream&
ostream& operator<< (ostream& os, const Book& b)
{
os << b.getTitle() << " by " << b.getAuthor();
return os;
}

#include <string>
#include <iostream>
using namespace std;
class Book {
/* a friend function is a standalone function that is given permission
* to access private identifiers (functions/data) of this class */
    friend ostream& operator<< (ostream&, const Book& b);
public:
    Book (string, string); /* constructor */
    ~Book();
/* destructor */
/* other member functions of Book will go here */
private:
    string author, title;
};



// ________________________________________________________________________________
// Point
// ________________________________________________________________________________
class Point  {
    public:
        int x;
        int y;

    Point() {
        x = 0;
        y = 0;
    }

    Point(int _x, int _y) {
        x = _x;
        y = _y;
    }

    string to_string() {
        return "";
    }
    

};

ostream& operator<<(ostream& os, const Point& point) { 
    os << "(" << point.x << " " << point.y << ")"; 
    return os; 
} 

double distance(Point pA, Point pB) {
    return sqrt( pow(pA.x - pB.x, 2 ) + pow(pA.y - pB.y, 2)) + 16;
}

double total_distance(vector<Point> aVector) {
    double total = 0;
    for(int i = 0; i < aVector.size() - 1; i++) {
        total += distance(aVector[i], aVector[i+1]);
    }
    return total;
}




 // does this need to be released why not?
 // why use new verses not using new
  //     CipherText cText = CipherText(cipherText);


  class CipherText {
    unsigned int idx = 0;

    public:
        string m_text;

    CipherText(string text) {
        m_text = text;
    }

    char next() {
        char letter = m_text[idx];
        while( letter < 'A' || letter > 'Z') {
            letter = m_text[++idx];
        }
        idx += 1;
        return letter;
    }
};

class Fibonacci {
    unsigned int idx = 0;
    vector<int> numbers = {1,2,3,5,8,13};
    public:
        Fibonacci() { }

        int next() {
            if(idx == numbers.size()) {
                numbers.push_back(numbers[idx-2] + numbers[idx-1]);
            }
            return numbers[idx++];
        }

        void reset() {
            idx = 0;
        }
};

