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


void copyRec(char* dst, char* src)
{
	if (*src == '\0')
		*dst = '\0';

	else
	{
		*dst = *src;
		copyRec(1 + dst, 1 + src);
	}
}


void imprime(No* lst)
{
	No* p = lst;
	for (; p != NULL; p = p->prox)
	{
		printf("codigo: %d nome: %s\n", p->info->codigo, p->info->nome);
	}
}


No* cria(int codigo, char* nome, No* prox)
{
	No* n = (No*)malloc(sizeof(No));
	if (n == NULL)
		return NULL;
	
	n->info = (Informacao*)malloc(sizeof(Informacao));
	if (n->info == NULL)
		return NULL;

	n->info->codigo = codigo;
	copyRec(n->info->nome, nome);
	n->prox = prox;
	return n;
}


No* quebraAoMeio(No* lista)
{
	int num = 0;
	for (No* n = lista; n != NULL; n = n->prox)
	{
		++num;
	}
	if (num < 2)
	{
		return NULL;
	}
	int metade = num / 2;
	if (num % 2 == 1)
	{
		++metade;
	}
	No* ant = NULL;
	No* p = lista;
	for ()
}




int main(void)
{
	No* n4 = cria(4, "d", NULL);
	No* n3 = cria(3, "c", n4);
	No* n2 = cria(2, "b", n3);
	No* n1 = cria(1, "a", n2);
	imprime(n1);
	



	return 0;
}
