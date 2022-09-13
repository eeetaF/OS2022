#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {

    int a = INT_MAX;
    unsigned short b = USHRT_MAX;
    long c = LONG_MAX;
    float d = FLT_MAX;
    double f = DBL_MAX;

    printf("%s%d%s%lu%s", "integer: MAX=", a, " SIZE=", sizeof(a), "\n");
    printf("%s%d%s%lu%s", "unsigned short: MAX=", b, " SIZE=", sizeof(b), "\n");
    printf("%s%li%s%lu%s", "long: MAX=", c, " SIZE=", sizeof(c), "\n");
    printf("%s%f%s%lu%s", "float: MAX=", d, " SIZE=", sizeof(d), "\n");
    printf("%s%f%s%lu%s", "double: MAX=", f, " SIZE=", sizeof(f), "\n");

    return 0;
}
