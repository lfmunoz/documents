// 3. Add debugging statements 
#include <stdio.h>


int fib(int i) {
    for(int s = 0; s < i; s++) printf(" ");
    printf("i = %d \n", i);
    if(i == 0 ) return 1;
    if(i == 1 ) return 1;
    return fib(i) + fib(i - 1);
}

int main() {
    printf("Fib of 0 is %d \n", fib(0));
    printf("Fib of 1 is %d \n", fib(1));
    printf("Fib of 2 is %d \n", fib(2));
    printf("Fib of 5 is %d \n", fib(5));
    return 0;
}

