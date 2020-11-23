




// ________________________________________________________________________________
//  INCLUDE
// ________________________________________________________________________________
#include <bits/stdc++.h>

using namespace std;



int main() {


    while(true) {}
    do {} while(true);

    for(int i = 0; i < 10; i++) {}


    // Looping through each character is a string
    // A.  using a range-based for loop 
    std::string str = ???;
    for(char& c : str) {
        do_things_with(c);
    }
    // B. using iterators
    for(std::string::iterator it = str.begin(); it != str.end(); ++it) {
        do_things_with(*it);
    }
    // C. using old fashion for-loop
    std::string str = ???;
    for(std::string::size_type i = 0; i < str.size(); ++i) {
        do_things_with(str[i]);
    }
}

