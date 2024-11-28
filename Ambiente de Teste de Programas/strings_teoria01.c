#include <stdio.h>

char toUpper(char c) {
    if (c >= 'a' && c <= 'z') {
        c = (c - 'a') + 'A';
    }
    return c;
}

void toUpper2(char* c) {
    if (*c >= 'a' && *c <= 'z') {
        *c = (*c - 'a') + 'A';
    }
}

int main(void) {
    char s[] = "Everton";

    int i = 0;
    while (s[i] != '\0') {
        printf("%c", s[i]);
        ++i;
    }

    printf("\n");

    for (int i = 0; s[i] != '\0'; ++i) {
        printf("%c", s[i]);
    }

    printf("\n");

    printf("%s", s);

    char s1[] = "Bom dia"; // Forma Certa
    char* p = "alo alo";   // Forma Errada

    s[4] = '#';
    p[3] = '@'; // Não pode fazer!

    return 0;
}