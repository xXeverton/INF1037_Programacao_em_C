#include <stdio.h>
#include <stdlib.h>

// TIRAR DUVIDA !!!!!
// Nao finalizado!
// tutorial seguido: https://www.geeksforgeeks.org/sublist-search-search-a-linked-list-in-another-list/

#define TRUE 1
#define FALSE 0


typedef struct noLista NoLista;
struct noLista
{
	int codigo;
	char nome[5];
	NoLista* prox;
};


void copyRec(char* dst, char* src)
{
	if (*src == '\0')
	{
		*dst = '\0';
	}

	else
	{
		*dst = *src;
		copyRec(1 + dst, 1 + src);
	}
}


NoLista* cria(int codigo, char* nome, NoLista* prox)
{
	NoLista* novo = (NoLista*)malloc(sizeof(NoLista));
	if (novo == NULL)
		return NULL;

	novo->codigo = codigo;
	copyRec(novo->nome, nome);
	novo->prox = prox;

	return novo;
}


void lstImprime(NoLista* lst)
{
	if (lst == NULL)
		return;

	printf("%d\t%-5s\n", lst->codigo, lst->nome);
	lstImprime(lst->prox);
}


// Verifica se uma lista esta continda numa outra lista
// Retorna TRUE se esta contida e FALSE caso contrario
int estaContida(NoLista* l1, NoLista* l2)
{
	NoLista* p1 = l1;
	NoLista* p2 = l2;
	
	// Se as duas listas sao vazias retorna TRUE
	if ((p1 == NULL) && (p2 == NULL))
		return TRUE;

	// Se uma das listas for vazia e a outra nao retorna FALSE
	if ((p1 == NULL) || (p2 == NULL))
		return FALSE;

	// Percorrer a segunda lista pegando os nos um por um
	while (l2 != NULL)
	{
		// Inicialize o ponteiro da segunda lista com o atual no da segunda lista
		p2 = l2;

		// Comece a combinar a primeira lista com a segunda lista
		while (p1 != NULL)
		{
			// Se segunda lista ficar vazia e a primeira nao
			if (p2 == NULL)
				return FALSE;

			// Se o codigo e o mesmo, va para o proximo codigo nas duas listas
			else if (p1->codigo == p2->codigo)
			{
				p1 = p1->prox;
				p2 = p2->prox;
			}

			// Se nao forem iguais, entao quebre o loop
			else break;
		}

		// Retorne TRUE se a primeira lista for percorrida completamente, isso significa que esta contida
		if (p1 == NULL)
			return TRUE;

		// initialize p1 com a primeira lista novamente
		p1 = l1;

		// E va para o proximo no da segunda lista
		l2 = l2->prox;
	}
	return FALSE;
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

	int c1[7] = { 999,777,666,558,446,333,111 };

	NoLista* lst1 = NULL;
	for (int i = 0; i < 7; ++i)
	{
		lst1 = cria(c1[i], n1[i], lst1);
		if (lst1 == NULL)
			return NULL;
	}

	printf("Lista 1:\n");
	lstImprime(lst1);

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
	lstImprime(lst2);
	


	return 0;
}