#include <stdio.h>
#include <stdlib.h>

typedef struct informacao Informacao;
struct informacao
{
	int codigo;
	char nome[31];
};


typedef struct no No;
struct no
{
	Informacao* info;
	No* prox;
};



int main(void)
{



	return 0;
}