#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// ex1
//int conta_linhas(file* arquivo)
//{
//	int contador = 0;
//	while (feof(arquivo) == 0)
//	{
//		char linha[256] = "";
//		fscanf(arquivo, "%[^\n]", linha);
//		fgetc(arquivo);
//		++contador;
//	}
//
//	return contador;
//}
//
//
// ex2 
//int conta_caracter(file* arquivo, char c)
//{
//	int contador = 0;
//	char ch;
//
//	while (!feof(arquivo))
//	{
//		fscanf(arquivo, "%c", &ch);
//		if (c == ch)
//		{
//			++contador;
//		}
//	}
//
//	return contador;
//}
//
//

// ex3
void imprime_arquivo(FILE* arq)
{
	char linha[256];
	while (!feof(arq))
	{
		fscanf(arq, "%[^\n]", linha);
		fgetc(arq);
		printf("%s\n", linha);
	}
}


// ex4
void merge_arquivo(FILE* arq1, FILE* arq2, FILE* saida)
{

	char ch;
	while ((ch = fgetc(arq1)) != EOF)
	{
		fprintf(saida, "%c", ch);
	}


	while ((ch = fgetc(arq2)) != EOF)
	{
		fprintf(saida, "%c", ch);
	}


	
}


// ex10
void criptografia(FILE* entrada, FILE* saida)
{
	int key = 1;
	char linha[256] = "";
	char linha_cripto[256] = "";
	while (!feof(entrada))
	{
		fscanf(entrada, "%[^\n]", linha);
		fgetc(entrada);	
		int tamanho = strlen(linha);
		printf("%s\n", linha);
		for (int i = 0; i < tamanho; ++i)
		{
			linha_cripto[i] = linha[i] + key;
		}
		linha_cripto[tamanho] = '\0';	

		fprintf(saida, "%s\n", linha_cripto);
	}
}


void descriptografia(FILE* entrada, FILE* saida)
{
	int key = 1;
	char linha[256] = "";
	char linha_decripto[256] = "";
	while (!feof(entrada))
	{
		fscanf(entrada, "%[^\n]", linha);
		fgetc(entrada);
		int tamanho = strlen(linha);
		for (int i = 0; i < tamanho; ++i)
		{
			linha_decripto[i] = linha[i] - key;
		}
		linha_decripto[tamanho] = '\0';
		fprintf(saida, "%s\n", linha_decripto);
	}
}


int main(void)
{

	return 0;
}