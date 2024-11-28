#include <stdio.h>
#include <stdlib.h>

struct paciente
{
	char nome[41];
	float valor;
	char tipo[11];
};
typedef struct paciente Paciente;


int contaLinhas(char* nomeArq)
{
	int cont = 0;
	FILE* arq = fopen(nomeArq, "r");
	if (arq == NULL)
	{
		printf("Erro ao abrir o arquivo\n");
		exit(1);
	}

	while (!feof(arq))
	{
		char linha[200] = "";
		fscanf(arq,"%[^\n]\n", linha);
		cont++;
	}

	fclose(arq);
	return cont;
}


char* gravaRegistro(Paciente** pac, char* nomeArq, int qtd)
{
	FILE* arq = fopen(nomeArq, "r");
	if (arq == NULL)
	{
		printf("Erro ao abrir arquivo\n");
		return NULL;
	}

	int i = 0;
	while (!feof(arq))
	{
		fscanf(arq, "%[^=]= %f; %[^\n]\n", pac[i]->tipo, &pac[i]->valor, pac[i]->nome);
		i++;
	}

	char* nomeArqBin = "registros.dat";
	FILE* arqbin = fopen(nomeArqBin, "wb");
	if (arqbin == NULL)
	{
		printf("Erro ao abrir o arquivo\n");
		return NULL;
	}

	for (int i = 0; i < qtd; ++i)
	{
		fwrite(pac[i], sizeof(Paciente), 1, arqbin);
		printf("Gravado registro %d\n", i + 1);
	}

	fclose(arqbin);
	fclose(arq);

	return nomeArqBin;
}


void libera(Paciente** pac, int qtd)
{
	for (int i = 0; i < qtd; ++i)
	{
		free(pac[i]);
	}
	free(pac);
}


void imprimeRegistro(char* nomeArqBin, int qtd)
{	
	FILE* arqbin = fopen(nomeArqBin, "rb");
	if (arqbin == NULL)
	{
		printf("Erro ao abrir o arquivo\n");
		exit(1);
	}

	Paciente** p = (Paciente**)malloc(sizeof(Paciente*) * qtd);
	if (p == NULL)
	{
		printf("Erro na alocacao\n");
		exit(1);
	}
	for (int i = 0; i < qtd; ++i)
	{
		p[i] = (Paciente*)malloc(sizeof(Paciente));
		if (p == NULL)
		{
			printf("Erro ao alocar memoria\n");
			exit(1);
		}
	}

	for (int i = 0; i < qtd; ++i)
	{
		fread(p[i], sizeof(Paciente), 1, arqbin);
		printf("%s = %.2f; %s\n", p[i]->tipo, p[i]->valor, p[i]->nome);
	}
	
	libera(p, qtd);
}



int main(void)
{
	char* nomeArq = "teste_arquivo.txt";
	int qtd_linha = contaLinhas(nomeArq);
	Paciente** pac = (Paciente**)malloc(sizeof(Paciente*) * qtd_linha);
	if (pac == NULL)
	{
		printf("Erro ao alocar memoria\n");
		exit(1);
	}

	for (int i = 0; i < qtd_linha; ++i)
	{
		pac[i] = (Paciente*)malloc(sizeof(Paciente));
		if (pac == NULL)
		{
			printf("Erro ao alocar memoria\n");
			exit(1);
		}
	}

	char* nomeArqBin = gravaRegistro(pac, nomeArq, qtd_linha);
	if (nomeArqBin == NULL)
	{
		printf("Erro\n");
		exit(1);
	}

	imprimeRegistro(nomeArqBin, qtd_linha);
	libera(pac, qtd_linha);


	return 0;
}