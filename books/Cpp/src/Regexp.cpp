
#include <iostream>
#include <string>
#include <regex>
using namespace std;


int main() {
    // Regular expression for an opening bracket and a digit in the range 0 to 9 as a regex:
    //  [\[0-9]
    // We need to use the C++ specific escape sequence
    string expression = "[\\[0-9]";


    // regex_match()
    // This function returns true if the given expression matches the string. Otherwise, 
    // the function returns false.
    if (regex_match ("softwareTesting", regex("(soft)(.*)") )) {
        cout << "string:literal => matched\n";
    }
    regex str_expr ("(soft)(.*)");
    string str ("software");
    cout << regex_match (str,str_expr) << endl;
    cout << regex_match ( str.begin(), str.end(), str_expr ) << endl;

    // regex_search() 
    // Used to search for a pattern in the string that matches the regular expression.
    string mystr = "She sells_sea shells in the sea shore"; 
    regex regexp("s[a-z_]+");
    // flag type for determining the matching behavior
    smatch m;
    // The function searches for the first occurrence of pattern in the input 
    // string and returns the matched string.
    regex_search(mystr, m, regexp); 
    for (auto x : m) {
        cout << x << " " << endl; 
    }


    return 0;
}




// https://en.cppreference.com/w/cpp/regex/regex_iterator