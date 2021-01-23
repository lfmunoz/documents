#include <bits/stdc++.h>
using namespace std;
// ________________________________________________________________________________
// Helper Methods
// ________________________________________________________________________________
template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
  if ( !v.empty() ) {
    out << '[';
    std::copy (v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
    out << "\b\b]";
  }
  return out;
}
// ________________________________________________________________________________
// Naive - Edit Distance by Recursion
//   We can define a recursive algorithm using the observation that the last character in
//    the string must either be matched, substituted, inserted, or deleted.
// ________________________________________________________________________________
#define MATCH 0 /* enumerated type symbol for match */
#define INSERT 1  /* enumerated type symbol for insert */
#define DELETE 2 /* enumerated type symbol for delete */

int string_compare(char *s, char *t, int i, int j) {
    int k; /* counter */
    int opt[3]; /* cost of the three options */
    int lowest_cost; /* lowest cost */
    if (i == 0) return(j * indel(’ ’));
    if (j == 0) return(i * indel(’ ’));
    opt[MATCH] = string_compare(s,t,i-1,j-1) + match(s[i],t[j]);
    opt[INSERT] = string_compare(s,t,i,j-1) + indel(t[j]);
    opt[DELETE] = string_compare(s,t,i-1,j) + indel(s[i]);
    lowest_cost = opt[MATCH];
    for (k=INSERT; k<=DELETE; k++) {
        if (opt[k] < lowest_cost) lowest_cost = opt[k];
    }
    return( lowest_cost );
}

// ________________________________________________________________________________
// Knuth-Morris-Pratt's (KPM) Algorithm
//  KPM algorithm never re-compares a character in the text that has matched a 
//   a character in the pattern
// ________________________________________________________________________________
vector<int> kmpPreprocess(const string &pattern) {
    vector<int> bTable(pattern.size());
    bTable[0] = -1;
    int i = 0, j = -1; 
    while(i < pattern.size()) {
        while(j >= 0 && pattern[i] != pattern[j]) {
            j = bTable[j];
        } 
        i++; j++; bTable[i] = j;
    }
    return bTable;
}

int kmpMatching(const string &pattern, const string &text) {
    vector<int> bTable = kmpPreprocess(pattern);
    int i = 0, j = 0;
    while(i < text.size()) {
        while(j >= 0 && text[i] != pattern[j]) {
            j = bTable[j]; // j doesn't reset all the way to 0
        }
        i++; j++;
        if(j == pattern.size()) {
            return i - j;
        }
    }
    return -1;
}
// ________________________________________________________________________________
// Main
//  g++ string_matching.cpp 
// ________________________________________________________________________________
int main() {

    // [-1, 0, 0, 0, 1, 2, 0, 1, 2] 
    cout << kmpPreprocess("abcabeabf") << endl;

    string pattern = "dog";
    string text = "The quick brown fox jumps over the lazy dog";
    cout << "[naive] found at index " << naiveMatching(pattern, text) << endl;
    cout << "[kpm] found at index " << kmpMatching(pattern, text) << endl;

    pattern = "aaab";
    text = "aaaaaaaaaaaab";
    cout << "[naive] found at index " << naiveMatching(pattern, text) << endl;
    cout << "[kpm] found at index " << kmpMatching(pattern, text) << endl;

    return 0;
}