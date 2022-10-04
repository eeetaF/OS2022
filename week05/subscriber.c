#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char s[1024];
    int fd;

    char *fifo = "/tmp/ex1";
    mkfifo(fifo, 0666);

    while (1) {
        fd = open(fifo, O_RDONLY);

        read(fd, s, 1024);
        printf("Received: %s", s);
        close(fd);
    }
}