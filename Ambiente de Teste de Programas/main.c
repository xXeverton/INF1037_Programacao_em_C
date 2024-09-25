#include <stdio.h>
#include <stdlib.h>

#define N 8

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


// ex8
/*
Dado um vetor de n numeros reais, determinar os numeros que compoem o vetor e o numero de vezes que cada um
deles ocorre no mesmo.
Exemplo: v[8] = { ‐1.7,  3.0,  0.0,  1.5,  0.0, ‐1.7,  2.3, ‐1.7 }
Saída: ‐1.7 ocorre 3 vezes
3.0 ocorre 1 vez
0.0 ocorre 2 vezes
1.5 ocorre 1 vez
2.3 ocorre 1 vez
*/
void ocorrencia(double* v)
{
	// assumindo que 9999 e um numero especial invalido
	double jaEncontrei[N];
	for (int i = 0; i < N; ++i)
	{
		jaEncontrei[i] = 9999.0; // Preenchendo um vetor com a mesma quantidade de elementos do vetor
	}

	for (int i = 0; i < N; ++i)
	{
		double elemento = v[i];

		// verifica se o elemento ja foi encontrado antes
		int encontrei = 0;
		for (int k = 0; k < N; ++k)
		{
			if (jaEncontrei[k] == elemento)
			{
				encontrei = 1;
				break;
			}
		}

		if (encontrei == 1)
		{
			continue;
		}
		jaEncontrei[i] = elemento;

		// Se chegou aqui, e a primeira vez que encontrei esse elemento
		// Conta quantas vezes o elemento aparece
		int contador = 0;
		for (int j = 0; j < N; ++j)
		{
			double segundoElemento = v[j];
			if (segundoElemento == elemento)
			{
				++contador;
			}
		}

		printf("Elemento %f aparece %d vezes \n", elemento, contador);

	}
}


int* criaAprovados(int qtd_alunos, int* vinsc, float* vnota, int* qtd_aprovados)
{
	*qtd_aprovados = 0;
	// contando quantos foram aprovados
	for (int i = 0; i < qtd_alunos; ++i)
	{
		if (vnota[i] >= 5.0f)
		{
			*qtd_aprovados += 1;
		}
	}

	// alocando memoria 
	int qtd = *qtd_aprovados;
	int* ap = (int*)malloc(sizeof(int) * (qtd));
	if (ap == NULL)
	{
		return NULL;
	}

	for (int i = 0; i < qtd_alunos; ++i)
	{
		if (vnota[i] >= 5.0f)
		{
			ap[i] = vinsc[i];
		}
	}

	return ap;
}




int main(void)
{
	int qtd_alunos = 3;
	int qtd_aprovados;
	int vinsc[3] = { 2320462, 2320463, 2320464 };
	float vnota[3] = {0.0f, 3.0f, 2.0f};

	int* ap = criaAprovados(qtd_alunos, vinsc, vnota, &qtd_aprovados);
	if (ap == NULL)
	{
		printf("Memoria insuficiente\n");
		free(ap);
		exit(1);
	}

	if (qtd_aprovados == 0)
	{
		printf("Nenhum aluno aprovado!\n");
	}

	else{	printf("alunos aprovados:\n");
		for (int i = 0; i < qtd_aprovados; ++i)
		{
			printf("%d;\n", ap[i]);
		}
	}


	return 0;
}
