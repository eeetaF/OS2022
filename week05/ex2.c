#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

typedef struct Thread {
    int id;
    char message[256];
} Thread;

void *printMessage(void *args) {
    Thread *arg = (Thread *) args;
    printf("Thread %d: %s\n", arg->id, arg->message);
}

int main(void) {
    Thread arrT[10];
    pthread_t arrPT[10];

    for (int i = 0; i < 10; i++) {
        arrT[i].id = i;
        printf("Tread %d is created\n", i);
        sprintf(arrT[i].message, "Hello from thread %d", i);

        pthread_create(&arrPT[i], NULL, printMessage, (void *) &arrT[i]);
        pthread_join(arrPT[i], NULL);
    }
}