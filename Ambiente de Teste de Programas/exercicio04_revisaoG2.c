#include <stdio.h>
#include <stdlib.h>


void leArq(char* arq, char* saidaTxt, char* saidaBin)
{
	FILE* entrada = fopen(arq, "r");
	if (entrada == NULL)
	{
		printf("Erro ao abrir arquivo texto\n");
		exit(1);
	}

	FILE* sTxt = fopen(saidaTxt, "w");
	if (sTxt == NULL)
	{
		printf("Erro ao abrir arquivo texto\n");
		exit(1);
	}

	FILE* sBin = fopen(saidaBin, "wb");
	if (sBin == NULL)
	{
		printf("Erro ao abrir arquivo binario\n");
		exit(1);
	}


	int qtdEstoque[5];
	char titulo[128] = "";
	while (!feof(entrada))
	{
		fscanf(entrada, "%[^/]/ %d %d %d %d %d\n", titulo, &qtdEstoque[0], &qtdEstoque[1], &qtdEstoque[2], &qtdEstoque[3], &qtdEstoque[4]);
		fprintf(sTxt, "%s\n", titulo);
		fwrite(&qtdEstoque, sizeof(int), 5, sBin);
	}
	fclose(sBin);
	fclose(sTxt);
	fclose(entrada);
}


void exibeArq(char* saidaTxt, char* saidaBin)
{
	FILE* stxt = fopen(saidaTxt, "r");
	if (stxt == NULL)
	{
		printf("Erro ao abrir arquivo texto\n");
		exit(1);
	}

	FILE* sBin = fopen(saidaBin, "rb");
	if (sBin == NULL)
	{
		printf("Erro ao abrir arquivo binario\n");
		exit(1);
	}


	char titulo[128] = "";
	int qtdEstoque[5];
	while (!feof(stxt))
	{
		fscanf(stxt, "%[^\n]\n", titulo);
		fread(qtdEstoque, sizeof(int), 5, sBin);
		int total = 0;
		for (int i = 0; i < 5; ++i)
		{
			total += qtdEstoque[i];
		}
		printf("Titulo: %s\t Media: %.2f\t Total: %d\n", titulo, (float)total / 5, total);
	}

	fclose(stxt);
	fclose(sBin);
}



int main(void)
{
	char* arq = "entrada_exercicio04_G2.txt";
	char* saidaTxt = "saida04_revisaoG2.txt";
	char* saidaBin = "saida04_revisaoG2.dat";

	leArq(arq, saidaTxt, saidaBin);
	exibeArq(saidaTxt, saidaBin);

	


	return 0;
}