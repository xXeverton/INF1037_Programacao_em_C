#include <stdio.h>
/*
*	Aula Vetores:
*	Aonde o elemento esta na memoria?
*	Formula para encontrar o endereco: &v[i] = &v[0] +i*sizeof(int)
*
*/

#define N 4
#define NUMF 3


void troca(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void imprime(int* x, int n) {
    for (int i = 0; i < n; ++i)
        printf("%d\n", x[i]); // printf("%d\n", *(x+i));
}

int main(void) {
    int a = 2;
    int b = 3;

    // inicializacao do array de 4 elmentos
    int v[N];
    float w[NUMF] = { 3.0f, 5.3f, 7.785f }; // outra forma de inicializar um array
    v[0] = 5;
    v[1] = 3;
    v[2] = 6;
    v[3] = 11; // &v[0] + 3 * sizeof(int)

    for (int i = 0; i < N; ++i)
        v[i] = i;

    for (int i = 0; i < N; ++i)
        printf("%d, ", v[1]);

    // Fazer o for de tras pra frente
    for (int i = N - 1; i >= 0; --i)
        printf("%d, ", v[1]);

    printf("%d\n", v[1]);

    printf("%d\n", sizeof(v) / sizeof(int));
    return 0;

}