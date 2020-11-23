---
title: C++ - Data Types
mathjax: true
layout: default
toc: true
---

# Data Types




A valid **identifier** is a sequence of one or more letters, digits or underscore characters (_).

## Primitive

char, float, bool, double, int


## Variables

```cpp
// Declaration
int a;
float mynumber;

int a, b, c;

int a;
int b;
int c;

// Initialization
int a = 1, b = 1;
```



## Conversion

```cpp

// String to Integer
int stoi (const string&  str, size_t* idx = 0, int base = 10);
int i_dec = std::stoi (str_dec,&sz);


```



## Modifiers


```cpp
const int Constant1=96;

// declares that Constant2 is a variable pointer to a constant integer and
//  is an alternative syntax which does the same
const int * Constant2
int const * Constant2

// declares that Constant3 is constant pointer to a variable integer and
int * const Constant3

// declares that Constant4 is constant pointer to a constant integer.
int const * const Constant4

```

 Basically **const** applies to whatever is on its immediate left (other than if there is nothing there in which case it applies to whatever is its immediate right).



## Arrays


```cpp
//  Contents are undetermined at the point the array is declared
int foo [5];

int foo [5] = { 16, 2, 77, 40, 12071 }; 

// This creates an array of five int values, each initialized with a value of zero:
int foo [5] = { }; 

// compiler will assume automatically a size for the array that matches the number of values included between the braces {}:
int foo [] = { 16, 2, 77, 40, 12071 };

// universal initialization
int foo[] { 10, 20, 30 };

// Access to an element of the array.
foo[2] = 30;        

```

## Multidimensional Arrays


{% raw %}
```cpp
int main() {

    int i = 0;

    int x[3][4] = {0, 1 ,2 ,3 ,4 , 5 , 6 , 7 , 8 , 9 , 10 , 11};
    int x[3][4] = {{0,1,2,3}, {4,5,6,7}, {8,9,10,11}};

}
```
{% endraw %}


```cpp



//With the only difference that with multidimensional arrays 
//the compiler remembers the depth of each imaginary dimension for us.


// Specify the size of columns of 2D array
void processArr(int a[][10]) {
   // Do something
}

// Pass array containing pointers
// When callingint *array[10];
for(int i = 0; i < 10; i++)
   array[i] = new int[10];
processArr(array);

void processArr(int *a[10]) {
   // Do Something
}



// Pass a pointer to a pointer
int x() {
    int **array;
    array = new int *[10];
    for(int i = 0; i <10; i++)
       array[i] = new int[10];
    processArr(array);
}
void processArr(int **a) {
   // Do Something
}

void printMatrix(int matrix[], int r, int c){
     for(int i=0;i<r;i++)
    {
         for(int j=0;j<c;j++)
         {
              cout<<matrix[i*c+j]<<" ";   
         }   
         cout<<endl;
    }   
}

void printMatrix(int *matrix, int r, int c){
     for(int i=0;i<r;i++) {
         for(int j=0;j<c;j++) {
             cout << *(arr+i*c+j);
         }   
         cout<<endl;
    }   
}

printMatrix((int*)arr, 2,2)


// pass only column
// | 1 | 2 | 3 | 4 |
// c tells it how many to skip
void fun(int arr[][c], int r) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
}

int main() {
    int arr[2][2] = {
        {1,2}, {3,4}
    };
    fun(arr, 2);
    return 0;
}
```