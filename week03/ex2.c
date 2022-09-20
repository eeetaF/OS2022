#include <stdio.h>
#include <math.h>

// Define a structure Point with 2 real number fields x and y
struct Point {
    double x;
    double y;
};

// Write a function area that will compute the area of the triangle whose vertices are A(x1, y1), B(x2, y2), and C(x3, y3
double area(struct Point A, struct Point B, struct Point C) {
    return 0.5 * fabs(A.x * B.y - B.x * A.y + B.x * C.y - C.x * B.y + C.x * A.y - A.x * C.y);
}

double distance(struct Point A, struct Point B) {
    return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}

int main() {
    //Write a main function to define A(2.5, 6), B(1, 2.2) and C(10, 6) as the vertices of the triangle ABC.
    struct Point A, B, C;
    A.x = 2.5;
    A.y = 6;
    B.x = 1;
    B.y = 2.2;
    C.x = 10;
    C.y = 6;

    // Find the distance between A and B, then calculate the area of ABC.
    printf("%f\n", distance(A, B));
    printf("%f\n", area(A, B, C));

    return 0;
}
