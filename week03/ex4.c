#include <stdio.h>
#include <stdlib.h>

void *aggregate(void *base, size_t size, int n, void *initial_value, void *(*opr)(const void *, const void *)) {
    if (size == sizeof(int)) {
        int *p = (int *) base;
        int *q = (int *) initial_value;
        for (int i = 0; i < n; i++)
            q = opr(q, &p[i]);
        return q;
    } else if (size == sizeof(double)) {
        double *p = (double *) base;
        double *q = (double *) initial_value;
        for (int i = 0; i < n; i++)
            q = opr(q, &p[i]);
        return q;
    }
    return NULL;
}

void *intsum(const void *a, const void *b) {
    int *result = malloc(sizeof(int));
    *result = *(int *) a + *(int *) b;
    return result;
}

void *doubsum(const void *a, const void *b) {
    double *result = malloc(sizeof(double));
    *result = *(double *) a + *(double *) b;
    return result;
}

void *intmult(const void *a, const void *b) {
    int *result = malloc(sizeof(int));
    *result = *(int *) a * *(int *) b;
    return result;
}

void *doubmult(const void *a, const void *b) {
    double *result = malloc(sizeof(double));
    *result = *(double *) a * *(double *) b;
    return result;
}


int main() {
    //test the previous function on an array of 5 doubles and another array of 5 integers and print the result for each array to stdout.
    int a[5] = {132, -6, 1, 1, 3};
    double b[5] = {69.1, 1.1, 0.0, 5.5, 3.0};
    int one = 1;
    int zero = 0;

    printf("Int sum = %d\n", *(int *) aggregate(a, sizeof(int), 5, &zero, intsum));
    printf("Double sum = %f\n", *(double *) aggregate(b, sizeof(double), 5, &zero, doubsum));
    printf("Int mult = %d\n", *(int *) aggregate(a, sizeof(int), 5, &one, intmult));
    printf("Double mult = %f\n", *(double *) aggregate(b, sizeof(double), 5, &one, doubmult));

    return 0;
}
