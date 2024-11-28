#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int len(char* s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        ++i;
    }
    return i;
}


int main(void)
{
    //char s[81];
    // na pior das hipoteses não printar nada caso não identifique o que eu quero

    //scanf("%[]", s); // pega apenas as queeu pedir
    //scanf("%[^aeiou]", s); // pega tudo menos isso
    //scanf("%[^\n]", s);  // Pega tudo incluindo espaços


    char s[] = "bom dia, tudo bem?";
    char s2[120];

    int n = len(s);


    printf("%d\n", n);

    strcpy(s2, s);
    printf("%s\n", s2);
    s2[2] = '@';

    printf("%s\n", s2);
    printf("%s\n", s);

    if (strcmp(s, s2) == 0)
    {
        printf("Iguais!\n");
    }
    else
    {
        printf("Diferentes!\n");
    }

    printf("%d\n", strcmp("ana", "Ana"));

    return 0;
}