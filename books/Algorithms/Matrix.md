---
title: Algorithms
mathjax: true
layout: default
toc: true
---






# 2D Algorithms

```
------> y-axis
| A B
| C D      
V
x-axis

A = (0,0), B = (0, 1), C = (1, 0) , D = (1,1)

```

<details>
<summary> matrix.cpp </summary>

<p markdown="block">
```cpp
{% include_relative src/matrix.cpp %}
````
</p></details>  


```
size_t index( int x, int y ) const { return x + m_width * y; }
array = new int[ width * height ];
array[ index( x, y )]
```

