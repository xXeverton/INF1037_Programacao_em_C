#include <stdio.h>
#include <stdlib.h>

// Tirar duvida!!

typedef struct noLista NoLista;
struct noLista
{
	int codigo;
	char nome[51];
	NoLista* prox;
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


NoLista* cria(int codigo, char* nome, NoLista* prox)
{
	NoLista* e = (NoLista*)malloc(sizeof(NoLista));
	if (e == NULL)
		return NULL;

	e->codigo = codigo;
	copyRec(e->nome, nome);
	e->prox = prox;
	return e;
}


void imprimeRec(NoLista* lst)
{
	if (lst == NULL)
	{
		return;
	}
	printf("codigo: %d nome: %s\n", lst->codigo, lst->nome);
	imprimeRec(lst->prox);
}


NoLista* mergeLista(NoLista* l1, NoLista* l2)
{
	NoLista* ant1 = NULL;
	NoLista* ant2 = NULL;
	NoLista* p1 = l1;
	NoLista* p2 = l2;
	for (; p1 != NULL && p2 != NULL; p1 = p1->prox, p2 != p2->prox)
	{
		if (p1->codigo == p2->codigo)
		{
			ant2 = p2->prox;
			free(p2);
			p2 = ant2;
		}

		else if (p1->codigo > p2->codigo)
		{
			
		}

	}
}


int main(void)
{
	char* n1[7] = {
		"bia",
		"rosa",
		"cadu",
		"lara",
		"cris",
		"rui",
		"leo",
	};

	int c1[7] = {999,777,666,558,446,333,111};

	NoLista* lst1 = NULL;
	for (int i = 0; i < 7; ++i)
	{
		lst1 = cria(c1[i], n1[i], lst1);
		if (lst1 == NULL)
			return NULL;
	}

	imprimeRec(lst1);

	return 0;
}