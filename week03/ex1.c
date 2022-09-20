#include <stdio.h>
#include <stdlib.h>

// Write a function foo to calculate the birth year of the person, given the age.
int foo(int age) {
    return 2022 - age;
}

int main() {
    // declare a pointer q to a constant integer x whose constant value is 10
    const int x = 10;
    const int *q = &x;

    // Create 5 contiguous memory cells of type constant integer and referred by a constant pointer p
    const int *const p = malloc(5 * sizeof(int));

    // these 5 cells hold the ages of 5 students in years. Read the ages from stdin, and store them in these cells.
    int *ms = (int *) p; // ms - memory cell

    printf("Enter ages: ");
    for (int i = 0; i < 5; ++i) {
        scanf("%d", &ms[i]);
        ms[i] = foo(ms[i]);
        printf("Birth year: %d\n", ms[i]);
    }

    free(ms);
    return 0;
}
