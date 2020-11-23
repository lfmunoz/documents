

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_READ 1024

/*

5-3. This exercise is designed to demonstrate why the atomicity guaranteed by opening
a file with the O_APPEND flag is necessary. Write a program that takes up to three
command-line arguments:

$ atomic_append filename num-bytes [x]

This file should open the specified filename (creating it if necessary) and append
num-bytes bytes to the file by using write() to write a byte at a time. By default, the
program should open the file with the O_APPEND flag, but if a third command-line
argument (x) is supplied, then the O_APPEND flag should be omitted, and instead the
program should perform an lseek(fd, 0, SEEK_END) call before each write(). 

Run two instances of this program at the same time without the x argument to write
1 million bytes to the same file:

$ atomic_append f1 1000000 & atomic_append f1 1000000

Repeat the same steps, writing to a different file, but this time specifying the x argument:

$ atomic_append f2 1000000 x & atomic_append f2 1000000 x

List the sizes of the files f1 and f2 using ls –l and explain the difference.




With append
-rw-r--r-- 1 luis luis 10000000 Nov 16 20:27 append.tmp

Without append
-rw-r--r-- 1 luis luis  5000000 Nov 16 20:27 noAppend.tmp




*/
int main(int argc, char * argv[]) {

    ssize_t numWritten;
    int outputFd;

    mode_t filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
    S_IROTH | S_IWOTH; /* rw-rw-rw- */

    char append[] = "append.tmp";
    char noAppend[] = "noAppend.tmp";

    if(argc < 2) {
        printf("[Error] - must specify file to write to \n");
        return -1;
    }


    int numOfBytes = atoi(argv[1]);
    printf(" numOfBytes = %d \n", numOfBytes);

    if(argc == 2) {
        outputFd = open(noAppend, O_WRONLY | O_CREAT, filePerms);
        if (outputFd == -1) {
            printf("[Error] - open \n");
            return -1;
        }
        if(lseek(outputFd , 0, SEEK_SET) == -1) {
            printf("[Error] - lseek \n");
            return -1;
        }
    } else {
        outputFd = open(append, O_WRONLY | O_APPEND |O_CREAT, filePerms);
        if (outputFd == -1) {
            printf("[Error] - open \n");
            return -1;
        }
    }
    unsigned char c = 0xAB;

    for(int i = 0; i < numOfBytes; i++) {
        numWritten = write(outputFd, &c, 1);
        if (numWritten == -1) {
            printf("[Error] - write %s \n", argv[1]);
            return -1;
        }
    }
    
    return 0;
}

