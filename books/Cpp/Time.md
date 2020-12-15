---
title: Time
mathjax: true
layout: default
toc: true
---



# Time

* [C++](Introduction.html)


The C++ standard library does not provide a proper date type. C++ inherits the structs and functions for date and time manipulation from C. 

* 24:00 Sunday or 00:00 Monday are both midnight meaning Sunday to Monday
* 12 pm is noon
* 12 am is midnight
* Number of SECONDS since 00:00 hours, Jan 1, 1970 UTC

```
  1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  1
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  1
12                                              pm  1   2   3   4   5   6   7   8   9   10  11  12
24                                             noon                                             0 
midnight                                                                                     midnight
 ```

<details>
<summary> <strong> cat time.cpp </strong> </summary>

<p markdown="block">
```cpp
{% include_relative src/time.cpp %}
````
</p></details>




## References

*  https://www.epochconverter.com/
* https://en.cppreference.com/w/cpp/chrono/c/strftime