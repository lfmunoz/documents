

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_READ 1024

/*

4-1. The tee command reads its standard input until end-of-file, writing a copy of the input
to standard output and to the file named in its command-line argument. (We show
an example of the use of this command when we discuss FIFOs in Section 44.7.)
Implement tee using I/O system calls. By default, tee overwrites any existing file with
the given name. Implement the –a command-line option (tee –a file), which causes tee
to append text to the end of a file if it already exists. (Refer to Appendix B for a
description of the getopt() function, which can be used to parse command-line
options.)


*/
int main(int argc, char * argv[]) {

    char buffer[MAX_READ + 1];
    ssize_t numRead, numWritten;
    int outputFd;

    mode_t filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
    S_IROTH | S_IWOTH; /* rw-rw-rw- */

    if(argc < 2) {
        printf("[Error] - must specify file to write to \n");
        return -1;
    }

    printf("argc = %d \n", argc);
    for(int i = 0; i < argc; i++) {
        printf("argv[%d] = %s \n", i, argv[i]);
    }

    outputFd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, filePerms);
    if (outputFd == -1) {
        printf("[Error] - open \n");
        return -1;
    }

    numRead = read(STDIN_FILENO, buffer, MAX_READ);
    if (numRead == -1) {
        printf("[Error] - read \n");
        return -1;
    }
    buffer[numRead] = '\0';

    numWritten = write(STDOUT_FILENO, buffer, numRead);
    if (numWritten == -1) {
        printf("[Error] - write stdout \n");
        return -1;
    }
    numWritten = write(outputFd, buffer, numRead);
    if (numWritten == -1) {
        printf("[Error] - write %s \n", argv[1]);
        return -1;
    }


    return 0;
}

