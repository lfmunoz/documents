






// ________________________________________________________________________________
// SPLIT
// ________________________________________________________________________________

/*
http://www.boost.org/doc/libs/1_46_1/doc/html/string_algo/usage.html#id2728530

std::vector<std::string> words;
std::string s;
boost::split(words, s, boost::is_any_of(", "), boost::token_compress_on);

*/

std::vector<std::string> split(const std::string& str, char delim) {
    std::vector<std::string> strings;
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != std::string::npos) {
        end = str.find(delim, start);
        strings.push_back(str.substr(start, end - start));
    }
    return strings;
}






#include <bits/stdc++.h>

using namespace std ;
int main()
{
    string str, token ;
    getline(cin, str) ; // get the string as input
    istringstream ss(str); // insert the string into tokenizer

    vector<string> tokens; // vector tokens holds the tokens


// char delimiter = ',' ;
// while(getline(ss, token, delimiter)) tokens.push_back(token) ;
    while (ss >> token) tokens.push_back(token); // splits the tokens
    for(auto x : tokens) cout << x << endl ; // prints the tokens

    return 0;
}



/**
    std::vector<std::string> x = split("one:two::three", ':');
*/
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

template <typename Out>
void split(const std::string &s, char delim, Out result) {
    std::istringstream iss(s);
    std::string item;
    while (std::getline(iss, item, delim)) {
        *result++ = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

// ________________________________________________________________________________
// FIND
// ________________________________________________________________________________
int main() {
  std::string str ("There are two needles in this haystack with needles.");
  std::string str2 ("needle");

  // different member versions of find in the same order as above:
  std::size_t found = str.find(str2);
  if (found!=std::string::npos)
    std::cout << "first 'needle' found at: " << found << '\n';
}



// ________________________________________________________________________________
// TO LOWER CASE WITH COPY
// ________________________________________________________________________________
string toLower(string data) {
    std::transform(data.begin(), data.end(), data.begin(),
    [](unsigned char c){ return std::tolower(c); });
    return data;
}

string toUpper(string data) {
    std::transform(data.begin(), data.end(), data.begin(),
    [](unsigned char c){ return std::toupper(c); });
    return data;
}



//// find and erase operations

int maint () {
         marker = line.find(":"); line.erase(marker, 1);
            marker = line.find("min"); line.erase(marker, 3);
            marker = line.find("sec"); line.erase(marker, 3);
            marker = line.find("ms"); line.erase(marker, 2);
            marker = line.find(" "); 
            name = line.substr(0, marker); line.erase(0, marker);
            stringstream stream(line);
            stream >> min >> ws;
            stream >> sec >> ws;
            stream >> ms >> ws;
}




If you just want to pass a std::string to a function that needs const char* you can use
std::string str;
const char * c = str.c_str();

If you want to get a writable copy, like char *, you can do that with this:

std::string str;
char * writable = new char[str.size() + 1];
std::copy(str.begin(), str.end(), writable);
writable[str.size()] = '\0'; // don't forget the terminating 0
// don't forget to free the string after finished using it
delete[] writable;
Notice that the above is not exception safe.
If anything between the new call and the delete call throws, 
you will leak memory, as nothing will call delete for you automatically. 