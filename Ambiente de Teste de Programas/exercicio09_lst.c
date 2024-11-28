#include <stdio.h>
#include <stdlib.h>


typedef struct elemento Elemento;
struct elemento
{
	int info;
	Elemento* prox;
};


Elemento* cria(int info, Elemento* prox)
{
	Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
	if (novo == NULL)
	{
		return NULL;
	}

	novo->info = info;
	novo->prox = prox;
	return novo;
}


Elemento* insereOrd(Elemento* lst, int info)
{

	Elemento* a = NULL;
	Elemento* p = lst;
	Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
	if (novo == NULL)
		return NULL;
	novo->info = info;

	// caso especial: lista vazia
	if (lst == NULL)
	{
		novo->prox = novo; // unico no que aponta para si mesmo
		return novo;
	}

	// caso especial: insercao na cabeca (menor valor)
	if (info < p->info)
	{
		// encontrar o ultimo no
		while (p->prox != lst)
		{
			p = p->prox;
		}


		// ajustar os ponteiros 
		p->prox = novo;
		novo->prox = lst;
		return novo;		// novo no eh a cabeca da lista
	}

	// insercao no meio ou no final
	a = lst;
	p = lst->prox;
	while (p != lst && p->info < info)
	{
		a = p;
		p = p->prox;
	}

	// insercao entre a  e p
	novo->prox = a->prox;
	a->prox = novo;

	return lst;			// a cabeca permance a mesma
}


Elemento* transformaEmLstCircular(Elemento* lst)
{
	Elemento* p = lst;
	while (p->prox != NULL)
	{
		p = p->prox;
	}

	p->prox = lst;
	return lst;
}


void imprimeLstCircular(Elemento* lst)
{
	Elemento* p = lst;
	printf("%d\n", p->info);
	p = p->prox;
	while (p != lst)
	{
		printf("%d\n", p->info);
		p = p->prox;
	}
}


int main(void)
{

	Elemento* d = cria(11, NULL);
	Elemento* c = cria(9, d);
	Elemento* b = cria(7, c);
	Elemento* a = cria(3, b);

	a = transformaEmLstCircular(a);

	a = insereOrd(a, 8);
	imprimeLstCircular(a);




	return 0;
}