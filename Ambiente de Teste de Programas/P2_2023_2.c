//Uma loja faz o registro de todos os seus clientes em um cadastro com listas simplesmente encadeadas, dividindo-os de acordo com a primeira letra de seu nome. Ou seja, o cadastro possui 26 listas, representando cada letra do alfabeto ingl�s.
//Cada cliente possui um nome, um n�mero identificador e uma pontua��o, chamada de "rating". 
//Implemente as fun��es a seguir.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Defina uma vari�vel ALPHA que cont�m o n�mero de letras do alfabeto ingl�s.
#define ALPHA 26

//Defina uma struct clist para guardar as informa��es individuais de cada cliente cadastrado. Essa struct deve conter um ponteiro para uma string que representa seu nome, um int identificador e um float representando seu "rating", al�m de um ponteiro para o pr�ximo cliente da lista. N�o use typedef para essa struct. (1.0 PTS)
struct clist {
	char* nome;
	int identificador;
	float rating;

	struct clist* prox;
};

//Defina uma struct cadastro que cont�m um vetor de ponteiros para structs clist. Esse vetor deve ser alocado estaticamente, com 26 espa�os representando cada letra do alfabeto. Use typedef para essa struct.
struct cadastro {
	struct clist* lista[ALPHA];
};
typedef struct cadastro Cadastro;

Cadastro* criaCadastro(void);
int insere(Cadastro* a, char* nome, int id, float rating);
void exibeCadastro(Cadastro* a);
float averageRating(Cadastro* a);
void liberaCadastro(Cadastro* a);


//Na main, teste todas as fun��es feitas e fa�a as verifica��es de erro. Em caso de erro de aloca��o de mem�ria na cria��o do cadastro ou ao inserir um novo cliente, apenas d� exit(1). (N�o � necess�rio emitir mensagem de erro). (1.0 PTS)
int main(void) {

	Cadastro* cadastro = criaCadastro();
	if (cadastro == NULL) exit(1);

	char* nomes[] = { "Fiona", "Zelda", "Ada Lovelace", "Fred", "Ahsoka", "Fani" };
	int ids[] = { 101, 102, 103, 104, 105, 106 };
	float ratings[] = { 2.0, 5.0, 4.5, 3.0, 5.0, 4.0 };

	for (int i = 0; i < 6; i++) {
		if (insere(cadastro, nomes[i], ids[i], ratings[i]) == 0) exit(1);
	}

	exibeCadastro(cadastro);

	printf("\nAverage Rating: %.2f\n", averageRating(cadastro));

	liberaCadastro(cadastro);
	printf("\nCadastro completamente liberado\n");

	return 0;
}

//Fa�a uma fun��o criaCadastro(void) que aloca mem�ria para um novo cadastro e inicializa o vetor est�tico dentro dela com NULL. Depois retorne esse cadastro. (1.5 PTS)
Cadastro* criaCadastro(void) {

	Cadastro* cadastro = (Cadastro*)malloc(sizeof(Cadastro));
	if (cadastro == NULL) return NULL;

	for (int i = 0; i < ALPHA; i++) {
		cadastro->lista[i] = NULL;
	}

	return cadastro;
}

//Fa�a uma fun��o insere(Cadastro* a, char* nome, int id, float rating), que recebe um cadastro e as informa��es de um novo cliente. Essa fun��o deve criar e preencher o novo cliente usando a struct clist e inser�-la no come�o da lista encadeada de sua respectiva inicial. Em caso de qualquer erro de aloca��o de mem�ria, a fun��o deve retornar 0. (2.0 PTS)
int insere(Cadastro* a, char* nome, int id, float rating) {

	struct clist* novo = (struct clist*)malloc(sizeof(struct clist));
	if (novo == NULL) return 0;

	novo->nome = (char*)malloc(sizeof(char) * (strlen(nome) + 1));
	if (novo->nome == NULL) return 0;

	strcpy(novo->nome, nome);
	novo->identificador = id;
	novo->rating = rating;

	int index = tolower(nome[0]) - 'a';

	novo->prox = a->lista[index];
	a->lista[index] = novo;

	return 1;
}


//Fa�a uma fun��o exibeCadastro(Cadastro* a) que recebe um cadastro e o exibe. A fun��o deve mostrar todas as letras e, para cada letra, exibir os clientes com nomes que come�am com aquela letra, como na figura (a figura da prova era exatamente o output inteiro desse c�digo). (1.5 PTS)
void exibeCadastro(Cadastro* a) {

	struct clist* p;

	for (int i = 0; i < ALPHA; i++) {

		p = a->lista[i];
		printf("%c:\n", 'A' + i);
		while (p != NULL) {
			printf("  %s: %d %.1f\n", p->nome, p->identificador, p->rating);

			p = p->prox;
		}

	}

	return;
}


//Fa�a uma fun��o averageRating(Cadastro* a) que recebe um cadastro, o percorre, e retorna a m�dia de rating entre todos os clientes cadastrados. (2.0 PTS)
float averageRating(Cadastro* a) {

	struct clist* p;
	float qnt = 0, total = 0;

	for (int i = 0; i < ALPHA; i++) {

		p = a->lista[i];
		while (p != NULL) {
			total += p->rating;
			qnt += 1;

			p = p->prox;
		}

	}

	return total / qnt;
}


//Escreva uma fun��o liberaCadastro que libera toda a mem�ria alocada durante o programa. (1.0 PTS)
void liberaCadastro(Cadastro* a) {

	struct clist* p;
	struct clist* temp;

	for (int i = 0; i < ALPHA; i++) {

		p = a->lista[i];
		while (p != NULL) {

			free(p->nome);
			temp = p->prox;
			free(p);
			p = temp;

		}

	}
	free(a);

	return;
}