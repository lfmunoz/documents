
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_READ 1024


/*
    -rw-r--r-- 1 luis luis    4 Nov 15 11:36 text.tmp
    00000000: 6162 6300                                abc.
*/
int main_1(int argc, char * argv[]) {

    char buffer[MAX_READ];
    ssize_t numRead, numWritten;
    int sourceFd, dstFd;

    mode_t filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
    S_IROTH | S_IWOTH; /* rw-rw-rw- */

    char filename[] = "text.tmp";
    char data[]  = "abc";


    dstFd= open(filename, O_WRONLY | O_CREAT | O_EXCL, filePerms);
    if (dstFd == -1) {
        printf("[Error] - open \n");
        return -1;
    }


    if (write(dstFd, data, 4) != 4) {
        printf("couldn't write whole buffer \n");
    }

    return 0;

}


/* 
    ...
    00000ff0: 0000 0000 0000 0000 0000 0000 0000 0000  ................
    00001000: 6162 6300                                abc.
*/
int main(int argc, char * argv[]) {

    char buffer[MAX_READ];
    ssize_t numWritten;
    int dstFd;

    mode_t filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
    S_IROTH | S_IWOTH; /* rw-rw-rw- */

    char filename[] = "text.tmp";
    char data[]  = "abc";


    dstFd= open(filename, O_RDWR | O_CREAT | O_EXCL, filePerms);
    if (dstFd == -1) {
        printf("[Error] - open \n");
        return -1;
    }

    // 4096 = 0x1000
    if(lseek(dstFd, 4096, SEEK_CUR) == -1) {
        printf("[Error] - seek \n");
        return -1;
    }

    if (write(dstFd, data, 4) != 4) {
        printf("couldn't write whole buffer \n");
    }

    return 0;

}


/*

4-2. Write a program like cp that, when used to copy a regular file that contains holes
(sequences of null bytes), also creates corresponding holes in the target file.

*/

int mainx(int argc, char * argv[]) {

    char buffer[MAX_READ];
    ssize_t numRead, numWritten;
    int sourceFd, destinationFd;

    mode_t filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
    S_IROTH | S_IWOTH; /* rw-rw-rw- */

    if(argc < 3) {
        printf("[Error] - must specify file to read and file to write \n");
        return -1;
    }

    printf("argc = %d \n", argc);
    for(int i = 0; i < argc; i++) {
        printf("argv[%d] = %s \n", i, argv[i]);
    }

    sourceFd = open(argv[1], O_RDONLY | O_CREAT, filePerms);
    if (sourceFd == -1) {
        printf("[Error] - open \n");
        return -1;
    }

    destinationFd = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, filePerms);
    if (destinationFd == -1) {
        printf("[Error] - open \n");
        return -1;
    }

    while ((numRead = read(sourceFd, buffer, MAX_READ)) > 0) {
        if (write(destinationFd, buffer, numRead) != numRead) {
            printf("couldn't write whole buffer \n");
        }
    }


    return 0;
}

