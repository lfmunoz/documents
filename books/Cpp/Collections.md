---
title: Collections
mathjax: true
layout: default
toc: true
---




# map

a std::map<K,V> is ordered based on the key, K, using std::less<K> to compare objects, by default.



# Vector

```cpp
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
```



# 2D Vector

```cpp
vector < vector < int > > Matrix(rows, vector< int >(columns,0));

// OR

  vector <vector<int>> v;
    v.resize(col,vector<int>(row));


    /** input from use **/
    for(int i=0; i<row; i++)
    {
       for(int j=0; j<col; j++)
       {
          cin>>v[i][j];
       }
    }

    for(int i=0;i<row; i++)
    {
       for(int j=0;j<col;j++)
       {
          cout<<v[i][j]<<" ";
       }
    }
    return 0;


```