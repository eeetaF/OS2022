#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    int fd[2];
    char s[1024];
    pid_t p;

    if (pipe(fd) < 0) {
        fprintf(stderr, "Pipe Failed");
        return 1;
    }

    p = fork();
    if (p < 0) {
        fprintf(stderr, "Fork Failed");
        return 1;
    }
    else if (p == 0) {
        close(fd[1]);
        read(fd[0], s, 1024);
        printf("Received: %s", s);
        close(fd[0]);
    } else {
        printf("Enter a message: ");
        fgets(s, 1024, stdin);
        close(fd[0]);
        write(fd[1], s, strlen(s) + 1);
        close(fd[1]);
    }
}