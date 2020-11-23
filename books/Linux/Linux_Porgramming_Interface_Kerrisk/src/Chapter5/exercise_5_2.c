

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_READ 1024

/*

5-2. Write a program that opens an existing file for writing with the O_APPEND flag, and
then seeks to the beginning of the file before writing some data. Where does the
data appear in the file? Why?

To the end of the file. O_APPEND is guaranted to always
write to the end of file, even if you lseek to the beginning.

*/
int main(int argc, char * argv[]) {

    ssize_t numWritten;
    int outputFd;

    mode_t filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
    S_IROTH | S_IWOTH; /* rw-rw-rw- */

    char filePath[] = "data.tmp";

    outputFd = open(filePath, O_WRONLY | O_APPEND, filePerms);
    if (outputFd == -1) {
        printf("[Error] - open \n");
        return -1;
    }

    if(lseek(outputFd , 0, SEEK_SET) == -1) {
        printf("[Error] - lseek \n");
        return -1;
    }

    numWritten = write(outputFd, filePath, 8);
    if (numWritten == -1) {
        printf("[Error] - write %s \n", argv[1]);
        return -1;
    }

    return 0;
}

