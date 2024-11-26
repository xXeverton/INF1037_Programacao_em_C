#include <stdio.h>
#include <stdlib.h>


struct elemento 
{
	int info;
	struct elemento* prox;
};
typedef struct elemento Elemento;


// funcao de criacao
Elemento* lst_cria(void)
{
	return NULL;
}

// cria um novo elemento e retorna
Elemento* lst_criaNo(int val)
{
	Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
	if (novo != NULL)
	{
		novo->info = val;
		novo->prox = NULL;
	}
	return novo;
}

// insercao de um novo elemento: retorna o novo primeiro no para atualizar a lista
Elemento* lst_insere(Elemento* lst, int val)
{
	Elemento* novo = lst_criaNo(val);
	novo->prox = lst;
	return novo;
}

// funcao de imprimir a lista
void lst_imprime(Elemento* lst)
{
	Elemento* p;
	for (p = lst; p != NULL; p = p->prox)
	{
		printf("info: %d\n", p->info);
	}
}

// verifica se a lista eh vazia retorna 1 se sim e 0 se nao
int lst_vazia(Elemento* lst)
{
	return (!lst);
}

// funcao que busca um elemento na lista
Elemento* busca(Elemento* lst, int val)
{
	Elemento* p;
	for (p = lst; p != NULL; p = p->prox)
	{
		if (p->info == val)
			return p;
	}

	return NULL;
}


// funcao que retira elemento
Elemento* lst_retira(Elemento* lst, int val)
{
	Elemento* a = NULL;
	Elemento* p = lst;
	while (p != NULL && (p->info != val))
	{
		a = p;
		p = p->prox;
	}
	if (p == NULL)
	{
		return lst;
	}
	else if (a == NULL)
	{
		lst = p->prox;
	}
	else
	{
		a->prox = p->prox;
	}
	free(p);
	return lst;
}


// libera lista
void lst_libera(Elemento* lst)
{
	Elemento* p = lst;
	while (p != NULL)
	{
		Elemento* t = p->prox;
		free(p);
		p = t;
	}
}


Elemento* lst_insere_ordenado(Elemento* lst, int val)
{
	Elemento* a = NULL;
	Elemento* p = lst;
	while (p != NULL && p->info < val)
	{
		a = p;
		p = p->prox;
	}
	Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
	if (novo == NULL)
		return NULL;

	if (a == NULL)
	{
		novo->info = val;
	}


}

int main(void)
{
	return 0;
}