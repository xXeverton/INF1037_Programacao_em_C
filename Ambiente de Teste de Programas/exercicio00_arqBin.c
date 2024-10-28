#include <stdio.h>
#include <stdlib.h>


struct medidas
{
	float peso;
	float altura;
};
typedef struct medidas Medidas;


struct cliente
{
	char nome[81];
	int id;
	char genero;
	Medidas m;
};
typedef struct cliente Cliente;


struct acimaDoPeso
{
	char* nome;
	float indice;
};
typedef struct acimaDoPeso AcimaPeso;


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


int len(char* s)
{
	int l = 0;
	while (*s)
	{
		s++;
		l++;
	}
	return l;
}



Cliente** montaVetorClientes(FILE* arq, int n)
{
	Cliente** v = (Cliente**)malloc(sizeof(Cliente*) * n);
	if (v == NULL) return NULL;


	for (int i = 0; i < n; ++i)
	{	
		v[i] = (Cliente*)malloc(sizeof(Cliente));
		if (v[i] == NULL) return NULL;

		fread(v[i], sizeof(Cliente), 1, arq);
	}

	return v;
}


float bodyMassIndex(Cliente c, int* status)
{	
	float indice = c.m.peso / c.m.altura;
	if (indice < 25.0f) *status = 0;
	else *status = 1;
	return indice;
}


void imprime(Cliente** v, int qtd)
{
	for (int i = 0; i < qtd; ++i)
	{
		int status;
		printf("%s , %d, %c, %.2f, %.2f", v[i]->nome, v[i]->id, v[i]->genero, v[i]->m.peso, v[i]->m.altura);
		float bmi = bodyMassIndex(*v[i], &status);
		printf(" BMI = %.2f, ", bmi);
		if (status == 0) printf("abaixo do peso\n");
		else printf("acima do peso\n");
	}
}

int contaAcimaPeso(Cliente** v, int qtd)
{
	int contador = 0;
	for (int i = 0; i < qtd; ++i)
	{
		if ((v[i]->m.peso / v[i]->m.altura) >= 25.0f)
			contador++;
	}
	return contador;
}

AcimaPeso** criaAcimaPeso(Cliente** v, int qtd)
{
	int contador = contaAcimaPeso(v, qtd);

	AcimaPeso** p = (AcimaPeso**)malloc(sizeof(AcimaPeso*) * contador);
	if (p == NULL)
		return NULL;

	for (int i = 0; i < contador; ++i)
	{
		p[i] = (AcimaPeso*)malloc(sizeof(AcimaPeso));
		if (p[i] == NULL)
			return NULL;
	}


	int j = 0;
	for (int i = 0; i < qtd; ++i)
	{
		if ((v[i]->m.peso / v[i]->m.altura) >= 25.0f)
		{	
			p[j]->nome = (char*)malloc(sizeof(char) * (len(v[i]->nome) + 1));
			copy(p[j]->nome, v[i]->nome);
			p[j]->indice = v[i]->m.peso / v[i]->m.altura;
			++j;
		}
	}
	return p;
}


void imprimeAcimaPeso(AcimaPeso** p, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%s: %.2f\n", p[i]->nome, p[i]->indice);
	}
}

float mediaBMI(AcimaPeso** vClientes, int n)
{

	float soma = 0.0f;
	for (int i = 0; i < n; ++i)
	{
		soma += vClientes[i]->indice;
	}
	return soma / n;
}


void liberaClientes(Cliente** v, int qtd)
{
	for (int i = 0; i < qtd; ++i)
	{
		free(v[i]);
	}
	free(v);
	printf("Cleintes liberados com sucesso!\n");
}


void liberaAcimaPeso(AcimaPeso** p, int n)
{
	for (int i = 0; i < n; ++i)
	{
		free(p[i]->nome);
		free(p[i]);
	}
	free(p);
	printf("Memoria liberadas com sucesso!\n");
}


int main(void)
{
	FILE* arq = fopen("clientes.dat", "rb");
	int qtd;
	// oq vai escrever, o tipo, quantidade, aonde vai escrever
	fread(&qtd, sizeof(int), 1, arq);
	/*printf("%d\n", qtd);*/

	Cliente** v = montaVetorClientes(arq, qtd);
	if (v == NULL)
	{
		printf("Erro ao alocar memoria\n");
		exit(1);
	}
	imprime(v, qtd);
	printf("\n");


	AcimaPeso** p = criaAcimaPeso(v, qtd);
	if (p == NULL)
	{
		printf("Erro ao alocar memoria\n");
		exit(1);
	}

	int n = contaAcimaPeso(v, qtd);
	float media = mediaBMI(p, n);
	printf("%d pessoas acima do peso\n", n);
	printf("Media BMI acima do peso: %.2f\n", media);
	imprimeAcimaPeso(p, n);
	

	printf("\n");
	liberaClientes(v, qtd);
	liberaAcimaPeso(p, n);

	fclose(arq);
	return 0;
}