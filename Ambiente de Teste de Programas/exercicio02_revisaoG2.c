#include <stdio.h>
#include <stdlib.h>


struct avaliacao
{
	float valorVendidoNoMes;
	int numeroDeFaltas;
};
typedef struct avaliacao Avaliacao;


struct vendedor
{
	int inscricao;
	char nome[51];
	float salário_base;
	Avaliacao aval;
};
typedef struct vendedor Vendedor;


float calculaExtra(Avaliacao a)
{
	if ((a.numeroDeFaltas < 2) && (a.valorVendidoNoMes > 2000.0f))
		return 180.0f;

	else if (((a.numeroDeFaltas >= 2) && (a.numeroDeFaltas < 4)) && (a.valorVendidoNoMes > 2000.0f))
		return 150.0f;

	else if (((a.numeroDeFaltas >= 4) && (a.numeroDeFaltas < 6)) && (a.valorVendidoNoMes > 5000.0f))
		return 120.0f;

	else
		return 0.0f;
}


float calculaValorTotalDaFolha(int qtdVendedores, Vendedor* v)
{
	float total = 0.0f;
	for (int i = 0; i < qtdVendedores; ++i)
	{
		Vendedor p = v[i];
		total += (p.salário_base + calculaExtra(p.aval));
	}
	return total;
}


Vendedor** obtemRelacaoDemitidos(int qtdVendedores, Vendedor* v, int* totalDemitidos)
{
	for (int i = 0; i < qtdVendedores; ++i)
	{
		Vendedor p = v[i];
		if (p.aval.numeroDeFaltas >= 10)
			*totalDemitidos += 1;
	}

	if (*totalDemitidos == 0)
		return NULL;

	Vendedor** demitidos = (Vendedor**)malloc(sizeof(Vendedor*) * (*totalDemitidos));
	if (demitidos == NULL)
	{
		printf("Erro ao alocar memoria\n");
		return NULL;
	}

	int index = 0;
	for (int i = 0; i < qtdVendedores; ++i)
	{
		if (v[i].aval.numeroDeFaltas >= 10)
		{ 
			demitidos[index] = &v[i];
			index++;
		}
	}
	return demitidos;

}


Vendedor obtemMelhorVendedor(int qtdVendedores, Vendedor* v)
{
	float maior = 0.0f;
	int index = -1;
	for (int i = 0; i < qtdVendedores; ++i)
	{
		Vendedor p = v[i];
		if (p.aval.valorVendidoNoMes > maior)
		{
			maior = p.aval.valorVendidoNoMes;
			index = i;
		}
	}
	
	return v[index];
}

void imprime(Vendedor* v, int qtd)
{
	for (int i = 0; i < qtd; ++i)
	{
		Vendedor p = v[i];
		printf("%d\t%15s\tR$%.2f\tR$%.2f\t%d\n", p.inscricao, p.nome, p.salário_base, p.aval.valorVendidoNoMes, p.aval.numeroDeFaltas);

	}
}

void imprimeDemitidos(Vendedor** v, int qtd)
{
	printf("Relacao de demitidos:\n");
	for (int i = 0; i < qtd; ++i)
	{
		Vendedor* p = v[i];
		printf("%d\t%15s\tR$%.2f\tR$%.2f\t%d\n", p->inscricao, p->nome, p->salário_base, p->aval.valorVendidoNoMes, p->aval.numeroDeFaltas);

	}
}


void libera(Vendedor** v, int qtd)
{
	for (int i = 0; i < 0; ++i)
	{
		free(v[i]);
	}
	free(v);
	printf("Memoria liberada com sucesso!\n");
}


int main(void)
{
	Vendedor vVendedor[10] = { {1, "Ana Silva", 1000,{3000,1}},
		{2, "Pedro Duarte",2000,{3010,3}},
		{3, "Joao Filho", 1000,{3020,4}},
		{4, "Maria Gomes", 3000,{3030,15}},
		{5, "Silvio Lins", 1000,{6000,15}},
		{6, "Marcia Morais",2000,{6010,3}},
		{7, "Bruno Rodrigues",3000,{6020,4}},
		{8, "Thais Silva", 4000,{6030,7}},
		{9, "Ricardo Costa", 5000,{3040,7}},
		{10, "Julia Neves", 10000,{1000,0}} };
	//Continue a implementação do programa!


	int qtd = 10;
	imprime(vVendedor, qtd);
	printf("Total folha de pagamento: R$%.2f\n", calculaValorTotalDaFolha(qtd, vVendedor));
	int qtdDemitidos = 0;
	Vendedor** demitidos = obtemRelacaoDemitidos(qtd, vVendedor, &qtdDemitidos);
	if (demitidos == NULL)
		exit(1);

	printf("\n");
	imprimeDemitidos(demitidos, qtdDemitidos);

	Vendedor melhorVendedor = obtemMelhorVendedor(qtd, vVendedor);
	printf("Melhor vendedor: %s\n", melhorVendedor.nome);


	libera(demitidos, qtdDemitidos);

	return 0;
}