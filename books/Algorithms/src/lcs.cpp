#include <bits/stdc++.h>
using namespace std;

using uint = unsigned int;

// ________________________________________________________________________________
// HELPER METHODS
// ________________________________________________________________________________
template <typename T> 
ostream& operator<<(ostream& os, const vector<T>& v) { 
    os << "["; 
    for (unsigned int i = 0; i < v.size(); ++i) { 
        os << v[i]; 
        if (i != v.size() - 1) 
            os << ", "; 
    } 
    os << "]\n"; 
    return os; 
} 


// ________________________________________________________________________________
// Longest Common Subsequence Naive
// ________________________________________________________________________________
string a;
string b;
int lcs(uint i, uint j) {
    if (a.length() < i || b.length() < j) {
        return 0;
    }
    if (a[i] == b[j]) {
        return 1 + lcs(i + 1, j + 1);
    }
    return max(lcs(i, j + 1), lcs(i + 1, j));
}

// ________________________________________________________________________________
// Longest Common Subsequence Memoization
// ________________________________________________________________________________
vector<vector<int>>  lcs_m(string a, string b) {
    vector<vector<int>> lcsTable(a.size()+1, vector<int>(b.size()+1));
    for (int i = 1; i < lcsTable.size(); i++) {
        for (int j = 1; j < lcsTable[0].size(); j++) {
            if (a[i] == b[j]) {
                lcsTable[i][j] = 1 +  lcsTable[i-1][j-1];
            } else {
                lcsTable[i][j] = max(lcsTable[i][j-1], lcsTable[i-1][j]);
            }
        }
    }
    return lcsTable;
}


// ________________________________________________________________________________
// Main
//  g++ lcs.cpp
// ________________________________________________________________________________
int main() {

    a = "stone";
    b = "longest";
    cout << lcs(0, 0) << endl;

    cout << lcs_m(a, b) << endl;
    return 0;
}


/********************************************************************************
# OUTPUT
./lcs.elf
4
[[0, 0, 0, 0, 0, 0, 0, 0]
, [0, 0, 0, 0, 0, 0, 1, 1]
, [0, 1, 1, 1, 1, 1, 1, 1]
, [0, 1, 2, 2, 2, 2, 2, 2]
, [0, 1, 2, 2, 3, 3, 3, 3]
, [0, 1, 2, 2, 3, 3, 3, 4]
]

********************************************************************************/
