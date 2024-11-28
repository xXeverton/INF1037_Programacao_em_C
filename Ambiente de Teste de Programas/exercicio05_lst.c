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

void imprimeRec(No* lst)
{
	if (lst == NULL)
		return;

	else
	{
		printf("%d\t%-20s\t%c\n", lst->ident, lst->nome, lst->sexo);
		imprimeRec(lst->prox);
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
	novo->prox = prox;
	return novo;
}

// funcao que faz copia de uma lista encadeada de forma recursiva
No* fazCopia(No* lst)
{
	if (lst == NULL)
		return NULL;

	else
	{
		No* novo = (No*)malloc(sizeof(No));		// Alocar a memoria para um novo No
		if (novo == NULL)
		{
			free(novo);
			return NULL;
		}
		// copia os dados para o novo No
		novo->ident = lst->ident;
		copyRec(novo->nome, lst->nome);
		novo->sexo = lst->sexo;
		novo->prox = fazCopia(lst->prox);

		return novo;
	}
}


int main(void)
{
	No* d = cria(4, "Luiza", 'M', NULL);
	No* c = cria(3, "Magalhaes", 'H', d);
	No* b = cria(2, "Vanuza", 'M', c);
	No* a = cria(1, "Nathi", 'M', b);
	printf("Lista original:\n");
	imprimeRec(a);


	printf("Copia: \n");
	No* copia = fazCopia(a);
	if (copia == NULL)
	{
		printf("Erro ao alocar memoria\n");
		exit(1);
	}
	imprimeRec(copia);


	return 0;
}