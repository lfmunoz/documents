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
// NaiveMatching
//  O(t) on average
//  O(t*p) worse case
//   If there is a mismatch we move p to the beginning and increment t, this means
//   that in the worse case we scan every p for every t  (t*p)
// ________________________________________________________________________________
int naiveMatching(const string &pattern, const string &text) {
    for(int t = 0; t < text.size(); t++) {
        bool found = true;
        for(int p = 0; p < pattern.size() && found; p++) {
            if (t+p >= text.size() || pattern[p] != text[t+p]) {
                found = false;
            }
        }
        if (found) return t;
    }
    return -1;
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