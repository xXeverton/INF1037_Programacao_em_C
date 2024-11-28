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
	NoLista* resultado = NULL;

	// caso base
	if (l1 == NULL)
		return l2;

	else if (l2 == NULL)
		return l1;

	// escolha l1 ou l2 e repita
	if (l1->codigo == l2->codigo)
	{
		NoLista* t = l2->prox;
		resultado = l1;
		free(l2);
		l2 = t;
		resultado->prox = mergeLista(l1->prox, l2);
	}
	else if (l1->codigo < l2->codigo)
	{
		resultado = l1;
		resultado->prox = mergeLista(l1->prox, l2);
	}

	else
	{
		resultado = l2;
		resultado->prox = mergeLista(l1, l2->prox);
	}

	return resultado;
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

	printf("Lista 1:\n");
	imprimeRec(lst1);

	char* n2[6] = {
		"lia",
		"rosa",
		"vera",
		"edu",
		"rui",
		"leo",
	};

	int c2[6] = { 888, 777,554,440,333,111 };

	NoLista* lst2 = NULL;
	for (int i = 0; i < 6; ++i)
	{
		lst2 = cria(c2[i], n2[i], lst2);
		if (lst2 == NULL) 
			return NULL;
	}

	printf("Lista 2\n");
	imprimeRec(lst2);

	NoLista* novaLst = mergeLista(lst1, lst2);
	printf("Nova Lista Merge:\n");
	imprimeRec(novaLst);

	return 0;
}