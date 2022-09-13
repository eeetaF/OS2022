#include <stdio.h>
long long tribonacci(long long n) {
    if (n <= 0)
        return 0;
    if (n <= 2)
        return 1;
    long long p1 = 0, p2 = 1, p3 = 1, ni = n;
    for (int i = 3; i <= ni; i++) {
        n = p1 + p2 + p3;
        p1 = p2;
        p2 = p3;
        p3 = n;
    }
    return n;
}

int main() {
    printf("%lld, %lld", tribonacci(4), tribonacci(36));

    return 0;
}
