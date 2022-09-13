#include <stdio.h>
#include <string.h>

int count(char s[], char a) { // innopolis, i
    int number = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == a)
            number++;
    }
    return number;
}

void countAll(char s[]) {
    if (s[0] <= 90 && s[0] >= 65) // if capital
        s[0] += 'a' - 'A';
    printf("%c:%d", s[0], count(s, s[0]));

    for (int i = 1; i < strlen(s); ++i) {
        if (s[i] <= 90 && s[i] >= 65) // if capital
            s[i] += 'a' - 'A';
        printf(", %c:%d", s[i], count(s, s[i]));
    }
}

int main() {
    printf("%s", "Enter a string: ");

    char s[256];
    scanf("%s", s);
    countAll(s);

    return 0;
}
