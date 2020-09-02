
// ________________________________________________________________________________
//  INCLUDE
// ________________________________________________________________________________
#include <iostream>
#include <string>
#include <iterator>
#include <vector>

using namespace std;

// ________________________________________________________________________________
// VECTOR
// ________________________________________________________________________________

template <typename T> 
ostream& operator<<(ostream& os, const vector<T>& v) 
{ 
    os << "["; 
    for (unsigned int i = 0; i < v.size(); ++i) { 
        os << v[i]; 
        if (i != v.size() - 1) 
            os << ", "; 
    } 
    os << "]\n"; 
    return os; 
} 





int main() {

  // VECTOR
  vector<int> A = {1,3,4,5};
  // O(NlogN)
  sort(A.begin(), A.end()); 

  // O(logN)
  bool present = binary_search(A.begin(), A.end(), 3);

  A.push_back(100); 
  A.push_back(100); 

  // find first occurrence of 100
  vector<int>::iterator it = lower_bound(A.begin(), A.end(), 100);

  for(int &x : A) // reference 
  {
    x++;
  }

  for(int x : A) {
    count << x << " ";
  }
  cout << "\n";


  // SET


  // kept in ascending order
  // insert LogN 
  set<int> S;
  S.insert(1);
  S.insert(2);
  s.insert(-1);

  auto it = S.find(-1);
  if( it == S.end()) // not present


}
