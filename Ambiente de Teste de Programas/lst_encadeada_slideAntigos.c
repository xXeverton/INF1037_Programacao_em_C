#include <stdio.h>
#include <stdlib.h>


struct elemento
{
	int info;
	struct elemento* prox;
};
typedef struct elemento Elemento;


// funcao de criacao: retorna uma lista vazia
Elemento* lst_cria(void)
{
	return NULL;
}


// cria um novo elemento e o retorna 
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


// insercao no inicio: retorna o novo primeiro no para atualizar a lista
Elemento* lst_insere(Elemento* lst, int val)
{
	Elemento* novo = lst_criaNo(val);
	novo->prox = lst;
	return novo;
}


// funcao imprime: imprime valores dos elementos
void lst_imprime(Elemento* lst)
{
	Elemento* p;
	for (p = lst; p != NULL; p = p->prox)
	{
		printf("info = %d\n", p->info);
	}
}


// funcao vazia: retorna 1 se vazia ou 0 se nao vazia
int lst_vazia(Elemento* lst)
{
	return (lst == NULL);
}


// funcao busca: busca um elemento na lista
Elemento* busca(Elemento* lst, int v)
{
	Elemento* p;
	for (p = lst; p != NULL; p = p->prox)
	{
		if (p->info == v)
		{
			return p;
		}
	}

	return NULL;		// Nao achou o elemento
}


// funcao retira: retira elemento da lista
Elemento* lst_retira(Elemento* lst, int val)
{
	Elemento* a = NULL;		// ponteiro para elmento anterior
	Elemento* p = lst;		// ponteiro para percorrer a lista
	// procurar elemento na lista, guardadno anterior
	while (p != NULL && p->info != val)
	{
		a = p;
		p = p->prox;
	}
	// verifica se achou elemento
	if (p == NULL)
		return lst;		// nao achou: retorna lista original
	// retira elemento
	if (a == NULL)
		lst = p->prox;		// retira elemento do inicio
	else
		a->prox = p->prox;		// retira elemento do meio da lista
	free(p);
	return lst;
}


void lst_libera(Elemento* lst)
{
	Elemento* p = lst;
	while (p != NULL)
	{
		Elemento* t = p->prox;		// guardar referencia p/ proximo Elemento
		free(p);					// Libera a memoria apontada por p
		p = t;						// Faz p apontar para o proximo 
	}
}


// funcao insere_oredenado: insere elemento em ordem
Elemento* lst_insere_ordenado(Elemento* lst, int val)
{
	Elemento* novo;
	Elemento* a = NULL;		// ponteiro para percorrer elemento anterior
	Elemento* p = lst;		// ponteiro para percorrer a lista
}





int main(void)
{

	Elemento* lst;		// declara uma lista nao incializada
	lst = lst_cria();	// cria e inicializa lista como vazia

	lst = lst_insere(lst, 23);		// insere na lista o elemento 23
	lst = lst_insere(lst, 45);		// insere na lista o elemento 45

	lst_imprime(lst);

	return 0;
}