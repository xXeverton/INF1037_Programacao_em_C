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
	// procurar elemento na lista, guardando anterior
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
	// procura posicao de insercao
	while (p != NULL && (p->info < val))
	{
		a = p;
		p = p->prox;
	}
	// cria novo elemento
	novo = (Elemento*)malloc(sizeof(Elemento));
	if (novo == NULL)
	{
		return NULL;
	}

	if (a == NULL)		// insere no inicio
	{
		novo->prox = lst;
		lst = novo;
	}
	else				// insere no meio da lista
	{
		novo->prox = a->prox;
		a->prox = novo;
	}

	return lst;
}

// Uso de funcoes recursivas em Listas Encadeadas

// Funcao imprime recursiva
void lst_imprime_rec(Elemento* lst)
{
	if (!lst_vazia(lst))
	{	// imprime primeiro elemento
		printf("info: %d\n", lst->info);
		// imprime sub-lista
		lst_imprime_rec(lst->prox);

	}
}


// Funcao imprime recursiva invertida
//void lst_imprime_rec(Elemento* lst)
//{
//	if (!lst_vazia(lst))
//	{
//		// imprime sub-lista
//		lst_imprime_rec(lst->prox);
//		// imprime ultimo elemento
//		printf("info: %d\n", lst->info);
//	}
//}



// Funcao retira recursiva
Elemento* lst_retira_rec(Elemento* lst, int val)
{
	if (!lst_vazia(lst))
	{
		// verifica se o elemento a ser retirada e o primeiro
		if (lst->info == val)
		{
			Elemento* t = lst;		// temporario para poder liberar
			lst = lst->prox;
			free(t);
		}
		// retira de sub-lista
		else
		{
			lst->prox = lst_retira_rec(lst->prox, val);
		}
	}
	return lst;
}


// Igualdade de listas
int lst_igual(Elemento* lst1, Elemento* lst2)
{
	Elemento* p1;		// ponteiro para percorrer l1
	Elemento* p2;		// ponteiro para percorrer l2
	for (p1 = lst1, p2 = lst2; p1 != NULL && p2 != NULL; p1 = p1->prox, p2 = p2->prox)
	{
		if (p1->info != p2->info)
			return 0;
	}
	return (p1 == p2);		// retrun 1
}


// Igualdade de listas ( Recursiva )
int lst_igual_rec(Elemento* lst1, Elemento* lst2)
{
	if (lst1 == NULL && lst2 == NULL)
		return 1;
	else
		if (lst1 == NULL || lst2 == NULL)
			return 0;
		else
			return (lst1->info == lst2->info) && lst_igual_rec(lst1->prox, lst2->prox);
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