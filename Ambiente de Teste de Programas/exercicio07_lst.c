#include <stdio.h>
#include <stdlib.h>


typedef struct no NoLista;
struct no
{
	int info;
	NoLista* prox;
};


NoLista* cria(int info, NoLista* prox)
{
	NoLista* novo = (NoLista*)malloc(sizeof(NoLista));
	if (novo == NULL)
		return NULL;

	novo->info = info;
	novo->prox = prox;

	return novo;
}


void imprimeLst(NoLista* lst)
{
	if (lst == NULL)
		return;

	printf("%d\n", lst->info);
	imprimeLst(lst->prox);
}

// Funcao insere na posicao k, caso nao exista a posicao insere no final
// retorna a cabeca da lista atualizada
NoLista* insereNaPosicao(NoLista* lst, int info, int k)
{
	NoLista* ant = NULL;
	NoLista* p = lst;
	int index = 1;
	while ((p != NULL) && (index < k))
	{
		ant = p;
		p = p->prox;
		index++;
	}

	NoLista* novo = (NoLista*)malloc(sizeof(NoLista));
	if (novo == NULL)
		return NULL;
	novo->info = info;

	if (ant == NULL)
	{
		novo->prox = lst;
		lst = novo;
	}

	else
	{
		novo->prox = ant->prox;
		ant->prox = novo;
	}

	return lst;
}


NoLista* eliminaValor(NoLista* lst, int info)
{
	NoLista* a = NULL;
	NoLista* p = lst;
	while (p != NULL)
	{
		// se o no atual contem o valor a ser removido
		if (p->info == info)
		{
			// caso especial: se o valor a ser removido for a cabeca da lista
			if (a == NULL)
			{
				lst = p->prox;
			}
		
			else
			{
				a->prox = p->prox;		// remove o no ligando o anterior ao proximo
			}

			NoLista* temp = p;		// salva o nó atual para liberá-lo
			p = p->prox;			// avança para o próximo nó
			free(temp);				// libera o nó atual
		}

		else
		{
			a = p;
			p = p->prox;
		}
	}
	return lst;
}


// funcao que elimina repeticoes - deixa apenas um valor e as repeticoes sao eliminadas
// retorna a cabeca da lista
NoLista* eliminaRepeticoes(NoLista* lst)
{
	// ponterio para percorrer a lista
	NoLista* p = lst;
	while (p != NULL)
	{
		// remove todas repeticoes do valor atual
		p->prox = eliminaValor(p->prox, p->info);
		p = p->prox; //avanca para o proximo no
	}

	return lst; // retorna a lista sem repeticoes
}


int main(void)
{

	int v[5] = { 22, 22, 10, 10, 22 };
	NoLista* lst = NULL;
	for (int i = 0; i < 5; ++i)
	{
		lst = cria(v[i], lst);
		if (lst == NULL)
		{
			printf("Erro ao alocar memoria\n");
			exit(1);
		}
	}

	printf("Antes:\n");
	imprimeLst(lst);
	lst = insereNaPosicao(lst, 50, 4);
	//lst = eliminaValor(lst, 22);
	lst = eliminaRepeticoes(lst);
	printf("Depois\n");
	imprimeLst(lst);


	return 0;
}