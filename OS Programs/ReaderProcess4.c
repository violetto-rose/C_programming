/*Develop a C program which demonstrates interprocess communication between a reader process and a writer process. Use mkfifo, open, read, write and close APIs in your program.

Instructions for Execution:
1.	Run Reader Process
2.	Then Run Writer Process*/

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h> 
#define MAX_BUF 1024
int main()
{
    int fd;
    /* A temp FIFO file is not created in reader */
    char *myfifo = "myfifo";
    char buf[MAX_BUF];
    /* open, read, and display the message from the FIFO */
    fd = open(myfifo, O_RDONLY);
    read(fd, buf, MAX_BUF);
    printf("Writer: %s\n", buf);
    close(fd);
    return 0;
}