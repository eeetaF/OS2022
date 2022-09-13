#include <stdio.h>
void T (int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}
void R (int height) {
    for (int i = 0; i < height/2; i++) {
        for (int j = 0; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    for (int i = height/2; i < height; i++) {
        for (int j = 0; j < height-i; j++) {
            printf("*");
        }
        printf("\n");
    }
}
void S (int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= height; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    printf("Enter a desired shape (T, R, S): ");
    char shape;
    scanf("%c", &shape);

    printf("Enter height: ");
    int height;
    scanf("%d", &height);

    switch (shape) {
        case 'T':
            T(height);
            break;
        case 'R':
            R(height);
            break;
        case 'S':
            S(height);
            break;
        default:
            break;
    }

    return 0;
}
