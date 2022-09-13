#include <stdio.h>
#include <math.h>

long long ipow(long long a, long long b) {
    long long ia = a;
    if (b <= 0)
        return 1;
    for (int i = 1; i < b; i++)
        a *= ia;
    return a;
}

long long convert(long long initial, short inumsys, short dnumsys) {
    // convert to base 10
    long long a = initial, i = 0, decimal = 0, final = 0;
    while (a > 0) {
        long long b = a % 10;
        decimal += b * ipow(inumsys, i);
        i++;
        a /= 10;
    }
    // convert to base dnumsys
    for (i = ceil(log((double) decimal) / log(dnumsys)); i >= 0; i--) {
        final *= 10;
        final += floor((double) (decimal / ipow(dnumsys, i)));
        decimal -= floor((double) ((decimal / ipow(dnumsys, i)) * ipow(dnumsys, i)));
    }
    return final;
}

short error(long long initial, short inumsys, short dnumsys) {
    if (inumsys > 10 || inumsys < 2 || dnumsys > 10 | dnumsys < 2)
        return 1;
    while (initial > 0) {
        if (initial % 10 >= inumsys)
            return 1;
        initial /= 10;
    }
    return 0;
}

int main() {
    printf("Enter a number: ");
    long long initial;
    scanf("%lld", &initial);

    printf("Enter initial num system: ");
    short inumsys;
    scanf("%hd", &inumsys);

    printf("Desired num system: ");
    short dnumsys;
    scanf("%hd", &dnumsys);


    if (error(initial, inumsys, dnumsys) == 1)
        printf("%s", "cannot convert!");
    else {
        printf("%lld", convert(initial, inumsys, dnumsys));
    }


    return 0;
}
