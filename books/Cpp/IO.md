---
title: C++ - Input/Output
mathjax: true
layout: default
toc: true
---

# Input/Output

This disables the synchronization between the C and C++ standard streams.
ios_base::sync_with_stdio(false);

This unties cin from cout. Tied streams ensure that one stream is flushed automatically before each I/O operation on the other stream.
cin.tie(NULL);


## Input 

```cpp




Extracts and discards up to nCount characters. Extraction stops if the delimiter delim is extracted or the end of file is reached. If delim = EOF (the default), then only the end of file condition causes termination. The delimiter character is extracted.

cin.ignore( int nCount = 1, int delim = EOF );

nCount - The maximum number of characters to extract.
delim - The delimiter character (defaults to EOF).



 //std::ws (a manipulator which discards leading whitespaces from an input stream) :

   // cin >> N >> std::ws;



  // std::endl is actually slower because it forces a flush


    // used to ignore or clear one or more characters from the input buffer.
    // (streamsize n = 1, int delim = EOF);
    cin.ignore(); // eat new lin

   // getline is an unformatted function.
    // delim = ('\n') for the first form, when found in the input sequence, 
    // it is extracted from the input sequence, but discarded and not written to s.
    istream& getline (char* s, streamsize n ); 
    istream& getline (char* s, streamsize n, char delim );
```


## Output

```cpp

void main() {
  cout << fixed << setprecision(2) << num1 << " " << num2;
}

```


## Common input patterns


```cpp

//  include the standard template library (STL)
#include <bits/stdc++.h>
using namespace std;


/*
  first line
  second line
  ___________
*/
void read_line_by_line_until_x() {
    const string END_OF_IO = "___________";
    string line;
    getline(cin, line);
    while(true) {
        getline(cin, line);
        if(line.compare(END_OF_IO) == 0) break;
        cout << line << "\n";
    }
}

/*
  first line
  second line
  last line
*/
void read_line_by_line_until_eof() {
    string line;
    // Since an if statement is a boolean context, it will invoke std::istream member function operator for that conversion.
    // Returns true if the stream has no errors occurred and is ready of I/O operations. Specifically, returns !fail().
    // cin.getline() stops at the character designated by third argument . default \n
    while(getline(cin, line)) {
      cout << line << "\n";
    }
}


/*
  3
  line 1
  line 2
  line 3
*/
void number_then_lines() {
    int N;
    string line;
    cin >> N >> ws; 

    for(int n = 0; n < N; n++) {
        getline(cin, line); 
        cout << line << "\n"; 
    }

    // ALTERNATIVE
    while(N--) {
        getline(cin, line); 
        cout << line << "\n"; 
    }


}


/*
  3    
  1 2 3 4
  5 6 7 8
  9 10 11
*/
void read_vector_of_numbers() {
  int length; 
  cin >> length;
  vector<int> sequence; 
  // Requests that the vector capacity be at least enough to contain n elements.
  sequence.reserve(length);
  // single-pass input iterator that reads successive objects of type T from the std::basic_istream object 
  // for which it was constructed, by calling the appropriate operator>>.
  copy_n(istream_iterator<int>(cin), length, back_inserter(sequence));
}



```


# References

* https://en.cppreference.com/w/cpp/named_req/FormattedInputFunction
* https://abitofcs.blogspot.com/search/label/UVa
* https://marcoarena.wordpress.com/2016/03/13/cpp-competitive-programming-io/
