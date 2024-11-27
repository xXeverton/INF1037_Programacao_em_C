#include <stdio.h>
#include <stdlib.h>


void concate(char* dst, char* src)
{
	while (*dst != '\0')
	{
		++dst;
	}
	while (*src)
	{
		*dst = *src;
		++dst;
		++src;
	}
}

void copy(char* dst, char* src)
{
	while (*src)
	{
		*dst = *src;
		++dst;
		++src;
	}
}


int len(char* str)
{
	if (*str == '\0')
		return 0;
	return 1 + len(str + 1);
}


char* montaVetor(FILE* arq)
{
	char nome[81] = "";
	char profissao[81] = "";
	int n = fscanf(arq, " %[^:]: %[^\n]\n", nome, profissao);
	if (n == 0)
		return NULL;

	char* novo = (char*)malloc(sizeof(char) * (len(nome) + len(profissao) + 1));
	if (novo == NULL)
		return NULL;

	novo = "";
	copy(novo, profissao);
	concate(novo, " ");
	concate(novo, nome);
	return novo;
}



int main(void)
{
	char* entrada = "entrada_exercicio05_G2.txt";
	FILE* arq = fopen("entrada_exercicio05_G2.txt", "r");
	if (arq == NULL)
	{
		printf("Erro ao abrir arquivo\n");
		exit(1);
	}

	int n;
	fscanf(arq, "%d\n", &n);
	printf("%d\n", n);

	char** v = (char**)malloc(sizeof(char*) * (n));
	if (v == NULL)
	{
		printf("Erro ao alocar memoria\n");
	}

	while (!feof(arq) && )

	fclose(arq);
	return 0;
}