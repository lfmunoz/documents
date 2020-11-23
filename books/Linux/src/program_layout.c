#include <stdio.h> // standard io
#include <stdlib.h> // C standard library
#include <unistd.h> // unix standard library
#include <sys/types.h> // system types for linux

extern char etext; /* end of program text / start of initialized data */
extern char edata; //
extern char end;

char globBuf[65536];   /* Uninitialized data segment */
int primes[] = { 2, 3, 5, 7 };  /* Initialized data segment */


static int square(int x)  /* Allocated in frame for square() */
{
    int result;  /* Allocated in frame for square() */
    result = x * x;
    return result;  /* Return value passed via register */
}

static void doCalc(int val) /* Allocated in frame for doCalc() */
{
    printf("The square of %d is %d\n", val, square(val));
    if (val < 1000) {
        int t;                  /* Allocated in frame for doCalc() */
        t = val * val * val;
        printf("The cube of %d is %d\n", val, t);
    }
}

// gcc program_layout.c
int main(int argc, char *argv[])       /* Allocated in frame for main() */
{
    static int key = 9973;     /* Initialized data segment */
    static char mbuf[10240000];     /* Uninitialized data segment */
    char *p;                        /* Allocated in frame for main() */
    p = (char *) malloc(1024);              /* Points to memory in heap segment */
 
    doCalc(key);

    printf("PID = %d \n", getpid());
    printf("etext = %p \n", &etext);
    printf("edata = %p \n", &edata);
    printf("end = %p \n", &end);
    getchar();
    exit(EXIT_SUCCESS);
}