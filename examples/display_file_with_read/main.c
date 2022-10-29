// read file.txt content using read() system call
// $ gcc main.c -o main
// $ ./main
// $ cat file.txt


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd;
    int buf_size = 4096;
    char buf[buf_size];
    int n;

    fd = open("file.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    while ((n = read(fd, buf, buf_size)) > 0) {
        write(1, buf, n); // write to console
    }

    close(fd);

    return 0;
}