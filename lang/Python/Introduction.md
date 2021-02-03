---
title: Python
mathjax: true
layout: default
toc: true
---

# The Python Language

Python is a general-purpose, high-level programming language. Its design philosophy emphasizes code readability, and its syntax allows programmers to express concepts in fewer lines of code than would be possible in languages such as C. The language provides constructs intended to enable clear programs on both a small and large scale.



```python

#!/usr/bin/env python
print "Hello World\n"


```


# Conditional

* Case-statement - Not available in Python	
* ?: - Not available in Python

```python
 if x < 0:
    x = 0
    print ’Negative changed to zero’
 elif x == 0 or x == 1:
    print ’Zero or Single’
 else:
    print ’More’
```


# For-statement

```python
a = [’cat’,’window’, ’defenestrate’]
for x in a:
  print x, len(x)
```

```python
a = [’Mary’, ’had’, ’a’, ’little’, ’lamb’]
for i in range(len(a)):
  print i, a[[i]]
 
 
 
#Using additional state variable, such as index variable
# is considered non-pythonic. Use enumerate.
for idx, val in enumerate(ints):
    print idx, val 

```



```python
number = 23
running = True
 
while running:
   guess = int(raw_input('Enter an integer : '))
 
   if guess == number:
      print 'Congratulations, you guessed it.'
      running = False # this causes the while loop to stop
   elif guess < number:
      print 'No, it is a little higher than that.'
   else:
      print 'No, it is a little lower than that.'
else:
   print 'The while loop is over.'
   # Do anything else you want to do here
 
print 'Done' 

```



# Dictionaries


```python
x = {}
d = {"server": "mpilgrim", "database": "master"}
c = { 'uid'  : 105,
      'user' : ' berkley',
      'name' : 'alice'
    }

# This is how you access a value given a key.
>>> d["server"]
'mpilgrim'

# You can add new key−value pairs at any time
x["a"] = 1 # adds an entry for "a" with value 1
x["b"] = 2 # adds an entry for "b" with value 2
d["uid"] = "sa"

# You can not have duplicate keys in a dictionary. Assigning a value to an existing key will wipe out the old value.
d["database"] = "pubs"

# del lets you delete individual items from a dictionary by key.
del d[42]

# Three ways to loop through a dictionary
 
item = {...}
for key in item: # alternatively item.iterkeys(), or item.keys() in python 3
    print key, item[key]
 
# use .itervalues()
item = {...}
for value in item.itervalues(): # or item.values() in python 3
    print value
 
# use .iteritems()
item = {...}
for key, value in item.iteritems(): # or item.items() in python 3
    print key, value

```





# Lists

```python

li = ["a", "b", "mpilgrim", "z", "example"]

>>> li[4]
'example'

>>> li[−1]
'example'

# You can add new key−value pairs at any time
x["a"] = 1 # adds an entry for "a" with value 1
x["b"] = 2 # adds an entry for "b" with value 2
d["uid"] = "sa"

```


# List comprehensions

```python

>>> print [i for i in range(10)]
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
>>> print [i for i in range(20) if i%2 == 0]
[0,2, 4, 6, 8, 10, 12, 14, 16, 18]
 
>>> li = [1, 9, 8, 4]
>>> [elem*2 for elem in li]
[2,18, 16, 8]
```


# Tuples


```python

>>> t = ("a", "b", "mpilgrim", "z", "example")

```