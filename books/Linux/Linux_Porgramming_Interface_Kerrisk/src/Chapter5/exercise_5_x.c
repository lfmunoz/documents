

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>



int main(int argc, char * argv[]) {

     return main5_6(argc, argv);
}

/*

5-4. Implement dup() and dup2() using fcntl() and, where necessary, close(). (You may
ignore the fact that dup2() and fcntl() return different errno values for some error
cases.) For dup2(), remember to handle the special case where oldfd equals newfd. In
this case, you should check whether oldfd is valid, which can be done by, for example,
checking if fcntl(oldfd, F_GETFL) succeeds. If oldfd is not valid, then the function
should return –1 with errno set to EBADF .

*/
int main5_4(int argc, char * argv[]) {

     return 0;
}


/*
5-5. Write a program to verify that duplicated file descriptors share a file offset value
and open file status flags.
*/


/*
5-6. After each of the calls to write() in the following code, explain what the content of
the output file would be, and why:

fd1 = open(file, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
fd2 = dup(fd1);
fd3 = open(file, O_RDWR);

write(fd1, "Hello,", 6); // Hello,
write(fd2, "world", 6);  // Hello,world
lseek(fd2, 0, SEEK_SET); 
write(fd1, "HELLO,", 6); // HELLO,world
write(fd3, "Gidday", 6); // Gidday,world



*/
int main5_6(int argc, char * argv[]) {

     int fd1, fd2, fd3;
     char file[] = "data.tmp";

     fd1 = open(file, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
     fd2 = dup(fd1);
     fd3 = open(file, O_RDWR);

     write(fd1, "Hello,", 6); // Hello,
     write(fd2, "world", 6);  // Hello,world
     lseek(fd2, 0, SEEK_SET); 
     write(fd1, "HELLO,", 6); // HELLO,world
     write(fd3, "Gidday", 6); // Giddayworld

     return 0;
}



/*
5-7.
Implement readv() and writev() using read(), write(), and suitable functions from the
malloc package (Section 7.1.2).

*/