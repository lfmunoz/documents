

//  include the standard template library (STL)
#include <bits/stdc++.h>

using namespace std;




// https://abitofcs.blogspot.com/search/label/UVa
/  http://www.cplusplus.com/reference/vector/vector/size/

// Common input patterns

/*

int n, k, t; 
int cnt = 0; 
cin >> n >> k; 
for (int i=0; i<n; i++) { 
  cin >> t; 
  if (t % k == 0) cnt++; 
} 



int length; cin >> length;
vector<int> sequence; sequence.reserve(length);
copy_n(istream_iterator<int>(cin), length, back_inserter(sequence));


int rows, cols; cin >> rows >> cols; 
vector<vector<int>> matrix; matrix.resize(rows); 
for (auto& row : matrix)
{    
   row.reserve(cols); 
   copy_n(istream_iterator<int>(cin), cols, back_inserter(row)); 
}



cin >> N >> std::ws;
getline(cin, line);



int N, T, t; cin >> N >> T;
vector<int> arr; arr.reserve(N);
copy_n(istream_iterator<int>(cin), N, back_inserter(arr));
// pre-process here
while (T--) 
{
  cin >> t;
  // solve here
}



**/


// Reference : https://marcoarena.wordpress.com/2016/03/13/cpp-competitive-programming-io/

void read_vector_of_numbers() {
  int length; 
  cin >> length;
  vector<int> sequence; 
  // Requests that the vector capacity be at least enough to contain n elements.
  sequence.reserve(length);
  // single-pass input iterator that reads successive objects of type T from the std::basic_istream object 
  // for which it was constructed, by calling the appropriate operator>>.
  copy_n(istream_iterator<int>(cin), length, back_inserter(sequence));


  // std::endl is actually slower because it forces a flush


    // used to ignore or clear one or more characters from the input buffer.
    // (streamsize n = 1, int delim = EOF);
    cin.ignore(); // eat new lin

    // delim = ('\n') for the first form, when found in the input sequence, 
    // it is extracted from the input sequence, but discarded and not written to s.
    istream& getline (char* s, streamsize n ); 
    istream& getline (char* s, streamsize n, char delim );


// getline is an unformatted function.

//int N; string line; 
// cin >> N; getline(cin, line);

// The problem here is that we want to ignore the separator between the int and the line. E.g.:

// 10'\n'
// a line representing some data

// This problem is easy to solve by passing std::ws (a manipulator which discards leading whitespaces from an input stream) :

   // cin >> N >> std::ws;

   //ranges can also be used

// vector<int> boundedIn = view::bounded(istream_iterator<int>(cin), length);

}

// ________________________________________________________________________________
// INPUT
// ________________________________________________________________________________
void read_line_by_line_until_x() {
    const string END_OF_IO = "___________";
    int N;
    string line;

    getline(cin, line);
    while(true) {
        getline(cin, line);
        if(line.compare(END_OF_IO) == 0) break;
        cout << line << "\n";
    }
}

void read_line_by_line_until_eof() {
    string line;

    // cin.getline() stops at the character designated by third argument . default \n
    while(getline(cin, line)) {
    }
     cout << n << ": " << s << endl;  // last line
}



void number_then_lines() {
    int N;
    string line;

    cin >> N; 
    // istream& ignore (streamsize n = 1, int delim = EOF);
    cin.ignore(); // eat new line

    for(int n = 0; n < N; n++) {
        getline(cin, line);  /// START ROW
    }
}

// ________________________________________________________________________________
// OUTPUT
// ________________________________________________________________________________


void common_output_patterns() {

  cout << ans1 << " " << ans2 << "\n";

  cout << fixed << setprecision(2) << num1 << " " << num2;
}
