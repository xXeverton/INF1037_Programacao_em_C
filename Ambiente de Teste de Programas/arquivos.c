#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// ex1
int conta_linhas(FILE* arquivo)
{
	int contador = 0;
	while (feof(arquivo) == 0)
	{
		char linha[256] = "";
		fscanf(arquivo, "%[^\n]", linha);
		fgetc(arquivo);
		++contador;
	}

	return contador;
}


// ex2 
int conta_caracter(FILE* arquivo, char c)
{
	int contador = 0;
	char ch;

	while (ch == ())
	{
		char linha[256] = "";
		fscanf(arquivo, "%[^c]", linha);
		fgetc(arquivo);
		++contador;
	}

	return contador
}




int main(void)
{
	FILE* entrada = fopen("entrada.txt", "r");
	int qtd_linhas = conta_linhas(entrada);
	printf("%d\n", qtd_linhas);

	fclose(entrada);
	return 0;
}