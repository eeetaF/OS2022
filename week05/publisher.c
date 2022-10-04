#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char s[1024];
    int fd;

    char *fifo = "/tmp/ex1";
    mkfifo(fifo, 0666);

    while (1) {
        fgets(s, 1024, stdin);
        fd = open(fifo, O_WRONLY);

        for (int i = 0; i < atoi(argv[1]); i++)
            write(fd, s, 1024);

        close(fd);
        sleep(1);
    }
}