#include <stdio.h>
#include <stdlib.h>

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



#define N 3

struct grauDoAluno
{
	float prova;
	float avPratica;
};
typedef struct grauDoAluno Grau;

struct aluno
{
	int mat;
	char nome[51];
	Grau grau;
};
typedef struct aluno Aluno;


Aluno* criaAluno(char* nome, int mat, float prova, float avPratica)
{
	Aluno* a = (Aluno*)malloc(sizeof(Aluno));
	if (a == NULL)
	{
		return NULL;
	}

	a->mat = mat;
	a->grau.prova = prova;
	a->grau.avPratica = avPratica;
	copy(a->nome, nome);


	return a;
}


void mostraAprovados(Aluno** v, int n)
{

	for (int i = 0; i < n; ++i)
	{
		Aluno* p = v[i];
		if ((p->grau.prova + p->grau.avPratica) >= 5.0f)
		{
			printf("Nome: %s\tMatricula: %d\tProva: %.2f\tavPratica: %.2f\n", p->nome, p->mat, p->grau.prova, p->grau.avPratica);
		}
	}
}


void libera(Aluno** v, int n)
{
	for (int i = 0; i < n; ++i)
	{
		free(v[i]);
	}
	free(v);
	printf("Memoria liberada com sucesso\n");
}


int main(void)
{

	char* nomes[N] = {
		"Everton",
		"Gabriel",
		"Lucio",
	};

	int mat[N] = {
		2320462,
		2320463,
		2320464,
	};

	float provas[N] = {
		5.0f,
		2.9f,
		3.9f,
	};

	float avPraticas[N] = {
		5.0f,
		2.9f,
		0.4f,
	};

	Aluno** v = (Aluno**)malloc(sizeof(Aluno*) * N);
	if (v == NULL)
	{
		printf("Erro ao alocar memoria\n");
		exit(1);
	}
	for (int i = 0; i < N; ++i)
	{
		Aluno* a = criaAluno(nomes[i], mat[i], provas[i], avPraticas[i]);
		if (a == NULL)
		{
			printf("Erro ao alocar memoria\n");
			exit(2);
		}
		v[i] = a;
	}

	mostraAprovados(v, N);
	libera(v, N);


	return 0;
}