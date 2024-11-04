#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo a estrutura 'Aluno'
struct aluno {
    char nome[81];   // Nome do aluno
    int idade;       // Idade do aluno
    float media;     // Média do aluno
};
typedef struct aluno Aluno; // Renomeando 'struct aluno' para 'Aluno' usando typedef

void funcao() {
    // Função vazia, pode ser implementada mais tarde
}

int main(void) {
    // Exemplo 1: Declarando e acessando diretamente uma estrutura
    Aluno a;          // Declara uma variável 'a' do tipo Aluno
    a.idade = 10;     // Atribui 10 para o campo 'idade' da estrutura 'a'

    // Exemplo 2: Usando um ponteiro para uma estrutura
    Aluno* p = &a;    // Inicializa o ponteiro 'p' para apontar para a estrutura 'a'
    p->idade = 20;    // Acessa o campo 'idade' via o ponteiro 'p'

    // Exemplo 3: Usando um array de estruturas
    Aluno v[10];      // Declara um array de 10 estruturas do tipo Aluno
    v[4].idade = 15;  // Atribui 15 ao campo 'idade' do 5º elemento do array

    // Exemplo 4: Usando um array de ponteiros para estruturas
    Aluno* vp[10];              // Declara um array de 10 ponteiros para Aluno
    vp[5] = &v[4];              // Inicializa o ponteiro 'vp[5]' para apontar para 'v[4]'
    vp[5]->idade = 25;          // Acessa o campo 'idade' da estrutura 'v[4]' através de 'vp[5]'

    // Exemplo 5: Usando um array de ponteiros para inteiros
    int* x[10];                 // Declara um array de 10 ponteiros para inteiros
    int valor = 30;             // Define um valor inteiro
    x[6] = &valor;              // Inicializa o ponteiro 'x[6]' para apontar para 'valor'
    *(x[6]) = 40;               // Modifica o valor de 'valor' através de 'x[6]'

    // Exemplo 6: Usando um ponteiro para um inteiro
    int num = 50;               // Define um valor inteiro
    int* ptr = &num;            // Inicializa o ponteiro 'ptr' para apontar para 'num'
    *ptr = 60;                  // Modifica o valor de 'num' através do ponteiro 'ptr'

    // Saída para confirmar as alterações
    printf("Idade de 'a': %d\n", a.idade);               // Saída: 20
    printf("Idade de 'v[4]': %d\n", v[4].idade);         // Saída: 25
    printf("Valor: %d\n", valor);                        // Saída: 40
    printf("Num: %d\n", num);                            // Saída: 60

    return 0;
}
