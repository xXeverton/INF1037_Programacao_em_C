#include <stdio.h>
#include <stdlib.h>

// ex1
void calcula(float a, float b, float* soma, float* dif, float* prod)
{
	*soma = a + b;
	*dif = a - b;
	*prod = a * b;
}


// ex2
int razao(float a, float b, float* razao)
{
	if (a == 0 || b == 0)
		return 0;

	else 
	{
		*razao = a / b;
		return 1;
	}
		
}


// ex3
void converteHora(int total_segundos, int* hora, int* min, int* seg)
{
	*hora = total_segundos / 3600;
	*min = (total_segundos % 3600) / 60;
	*seg = total_segundos % 60;

}


// ex4
void verificaMedia(void)
{	

	int soma = 0;
	int v[10];
	for (int i = 0; i < 10; ++i)
	{
		printf("Informe um valor:\n");
		scanf("%d", &v[i]);
		soma += v[i];
	}

	int media = soma / 10;
	printf("Valor(es) igual(is) a media:\n");
	for (int i = 0; i < 10; ++i)
	{
		if (v[i] == media)
		{
			printf("%d ", v[i]);
		}
	}
}


// ex5
float prod_escalar(float* v1, float* v2, int n)
{
	float soma = 0.0f;
	for (int i = 0; i < n; ++i)
	{
		soma += v1[i] * v2[i];
	}

	return soma;
}


// ex6
float* prod_vetorial(float* u, float* v)
{
	float* produto = (float*)malloc( 3 * sizeof(float));
	if (produto == NULL)
	{
		printf("ERRO na alocação\n");
		exit(1);
	}

	produto[0] = u[0] * v[2] - u[2] * v[0];
	produto[1] = u[2] * v[0] - u[0] * v[2];
	produto[2] = u[0] * v[1] - u[1] * v[0];
	
	return produto;

}


// ex7
float* polinomio(float* a, float* k, int n)
{
	float* p = (float*)malloc(n * sizeof(float));
	if (p == NULL)
	{
		printf("ERRO na alocação\n");
		exit(1);
	}

	for (int i = 0; i < n; ++i)
	{
		p[i] = k[i] + a[i];
	}

	return p;
}


int main(void)
{

	float u[3] = { 1.0f, 2.0f, 3.0f };
	float v[3] = { 1.0f, 2.0f, 3.0f };
	float* produto = prod_vetorial(u, v);

	for (int i = 0; i < 3; ++i)
	{
		printf("%.2f\n", produto[i]);
	}

	free(produto);


	return 0;
}
