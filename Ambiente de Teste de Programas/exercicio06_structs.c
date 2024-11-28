#include <stdio.h>
#include <stdlib.h>

// Questao complicada refazer!!

#define MAX_RECEITAS 5
#define MAX_INGREDIENTES 10


typedef struct ingrediente 
{
	char nome[21];
	int qtd;
} Ingrediente;


typedef struct receita 
{
	char nome[26];
	int n;
	Ingrediente v[MAX_INGREDIENTES];
} Receita;



void copy(char* dst, char* src)
{
	while (*src)
	{
		*dst = *src;
		++dst;
		++src;
	}
	*dst = '\0';
}


void imprimeReceita(Receita** receitas)
{
	for (int i = 0; i < MAX_RECEITAS; ++i)
	{
		printf("Receita %d: %s\n", i + 1, receitas[i]->nome);
		printf("Quantidade de ingredientes: %d\n", receitas[i]->n);
		for (int j = 0; j < receitas[i]->n; ++j)
		{
			printf("\tIngrediente %d: %s, quantidade: %d\n", j + 1, receitas[i]->v[j].nome, receitas[i]->v[j].qtd);
		}
	}
}


void libera(Receita** v)
{
	for (int i = 0; i < MAX_RECEITAS; ++i)
	{
		free(v[i]);
	}
	printf("Memoria Liberadas com Sucesso!\n");
}


int main(void)
{
	// vetor de ponteiros para receitas
	Receita* receitas[MAX_RECEITAS];
	
	// preencher o vetor de ponteiros de receitas
	for (int i = 0; i < MAX_RECEITAS; ++i)
	{
		char nomeTemp[26] = "";
		receitas[i] = (Receita*)malloc(sizeof(Receita));
		if (receitas[i] == NULL)
		{
			printf("Erro ao alocar memoria\n");
			exit(1);
		}
		
		printf("Digite o nome da receita %d: ", i + 1);
		scanf("%s", receitas[i]->nome);
		
		printf("Digite a quantidade de ingredientes: ");
		scanf("%d", &receitas[i]->n);
		


		// preenchendo os ingredientes
		for (int j = 0; j < receitas[i]->n; ++j)
		{
			printf("\tIngredientes %d:\n", j + 1);
			printf("\t\tNome: ");
			scanf("%s", receitas[i]->v[j].nome);

			printf("\t\tQuantidade: ");
			scanf("%d", &receitas[i]->v[j].qtd);
		}

	}

	printf("\n");
	imprimeReceita(receitas);
	printf("\n");
	libera(receitas);
	return 0;
}