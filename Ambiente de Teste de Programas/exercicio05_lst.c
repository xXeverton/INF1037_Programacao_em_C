#include <stdio.h>
#include <stdlib.h>


typedef struct no No;
struct no
{
	int ident;		/* identidade da pessoa */
	char nome[20];	/* nome da pessoa */
	char sexo;		/* ‘H’ (homem) ou ‘M’ (mulher) */
	No* prox;		/* ponteiro para o próximo elemento */
};


void copyRec(char* dst, char* src)
{
	if (*src == '\0')
		*dst = '\0';

	else
	{
		*dst = *src;
		copyRec(dst + 1, src + 1);
	}
}


No* cria(int id, char* nome, char sexo, No* prox)
{
	No* novo = (No*)malloc(sizeof(No));
	if (novo == NULL)
		return NULL;

	novo->ident = id;
	copyRec(novo->nome, nome);
	novo->sexo = sexo;
	novo->prox;
	return novo;
}


No* fazCopia(No* lst)
{
	if (lst == NULL)
		return NULL;

	else
	{

	}
}


int main(void)
{

	return 0;
}