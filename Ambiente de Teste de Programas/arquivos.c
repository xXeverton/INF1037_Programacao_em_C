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
//void imprime_arquivo(file* arq)
//{
//	char linha[256];
//	while (!feof(arq))
//	{
//		fscanf(arq, "%[^\n]", linha);
//		fgetc(arq);
//		printf("%s\n", linha);
//	}
//}


// ex4
FILE* merge_arquivo(FILE* arq1, FILE* arq2)
{
	char linha[256] = "";
	FILE* saida = fopen("saida.txt", "w");
	while (!feof(arq1))
	{
		fscanf(arq1, "%s", linha);
		fgetc(arq1);
		fprintf(saida, linha);
	}

	while (!feof(arq2))
	{
		fscanf(arq2, "%s", linha);
		fgetc(arq2);
		fprintf(saida, linha);
	}

	return saida;
}


int main(void)
{
	FILE* entrada0 = fopen("entrada0.txt", "r");
	FILE* entrada1 = fopen("entrada1.txt", "r");
	FILE* saida = merge_arquivo(entrada0, entrada1);

	fclose(entrada0);
	fclose(entrada1);
	fclose(saida);
	return 0;
}