


    i = 1,2,3,4,5; is equivalent to (i = 1),2,3,4,5; //  i = 1
    i = (1,2,3,4,5); seq is evaluated and gives 5 therefore // i = 5



C language (as well as C++) is historically a mix of two completely different programming styles,
 which one can refer to as "statement programming" and "expression programming"

Branching in expression programming is done through ?: operator and, alternatively,
 through short-circuit evaluation properties of && and || operators. 
 (Expression programming has no cycles though. And to replace them with recursion you'd 
 have to apply statement programming.)


Operator , in nothing else than a separator of sequential expressions in C, i.e. operator ,
 in expression programming serves the same role as ; does in statement programming.


The difference is that two expressions separated by a semicolon form two separate statements, 
while comma-separation keeps all as a single expression. 

int a, b; --- variable declaration list is comma separated, but these are not comma operators
int a=5, b=3; --- this is also a comma separated variable declaration list



if (something) dothis(), dothat(), x++;
this is equivalent to
if (something) { dothis(); dothat(); x++; }


int main() {

    int i = 0;

    int x[3][4] = {0, 1 ,2 ,3 ,4 , 5 , 6 , 7 , 8 , 9 , 10 , 11};
    int x[3][4] = {{0,1,2,3}, {4,5,6,7}, {8,9,10,11}};


}


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

