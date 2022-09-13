#include <stdio.h>

int main() {

    printf("%s", "Enter a string: ");

    char s[256];
    short i = 0;

    while (1) {
        scanf("%c", &s[i]);
        if (s[i] == '.' || s[i] == '\n')
            break;
        i++;
    } i--;

    for (; i >= 0; i--)
        printf("%c",s[i]);

    return 0;
}
