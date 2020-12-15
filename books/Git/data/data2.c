// 2. Change to factorial
#include <stdio.h>


int factorial(int i) {
    if(i == 0 ) return 1;
    if(i == 1 ) return 1;
    return factorial(i) * factorial(i - 1);
}

int main() {
    printf("factorial of 0 is %d \n", factorial(0));
    printf("factorial of 1 is %d \n", factorial(1));
    printf("factorial of 2 is %d \n", factorial(2));
    printf("factorial of 5 is %d \n", factorial(5));
    return 0;
}

