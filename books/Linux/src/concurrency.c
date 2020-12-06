#include <pthread.h>
#include <stdio.h>

static int glob = 0;

// Loop 'arg' times incrementing 'glob'
/*
mov eax, counter
inc eax
mov counter, eax
*/
static void *threadFuncIncGlob(void *arg) {
    int loops = 1000 * 100 * 10;  // 1 million
    int loc, j;
    for (j = 0; j < loops; j++) {
        loc = glob;
        loc++;
        glob = loc;
    }
    return NULL;
}

/*
gcc -O0 concurrency.c -o concurrency.elf -pthread
./concurrency.elf
glob = 1017103
*/
int main(int argc, char *argv[]) {
    int s;
    pthread_t t1, t2;

    s = pthread_create(&t1, NULL, threadFuncIncGlob, NULL);
    if (s != 0) printf("pthread_create %d", s);

    s = pthread_create(&t2, NULL, threadFuncIncGlob, NULL);
    if (s != 0) printf("pthread_create %d", s);

    s = pthread_join(t1, NULL);
    if (s != 0) printf("pthread_join %d", s);

    s = pthread_join(t2, NULL);
    if (s != 0) printf("pthread_join %d", s);

    printf("glob = %d\n", glob);

    return 0;
}
