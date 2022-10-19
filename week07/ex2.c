#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n;
    printf("Enter N: ");
    scanf("%d", &n);

    int *p = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        p[i] = i;
        printf("%d ", p[i]);
    }

    free(p);
    return 0;
}
