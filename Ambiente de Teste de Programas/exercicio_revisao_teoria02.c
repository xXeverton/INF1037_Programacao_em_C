#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 21

// Defina a estrutura AlunoInfo com um campo nota do tipo float e um campo nome do tipo vetor de char com no maximo 21 carcateres
typedef struct alunoInfo AlunoInfo;
struct alunoInfo
{
	float nota;
	char nome[MAX];
};


// Defina a estrutura Aluno que representa uma lista encadeada de alunos
typedef struct aluno Aluno;
struct aluno
{
	AlunoInfo info;
	Aluno* prox;
};


// Funcao auxiliar que cria Aluno* criaAluno(Aluno* head, float nota, char nome)
Aluno* criaAluno(float nota, char* nome)
{
	Aluno* novo = (Aluno*)malloc(sizeof(Aluno));
	if (novo == NULL)
		return NULL;

	novo->info.nota = nota;
	strcpy(novo->info.nome, nome);
	novo->prox = NULL;

	return novo;
}

// Implemente a função Aluno* insereInicio(Aluno* head, float nota, char* nome)
Aluno* insereInicio(Aluno* head, float nota, char* nome)
{
	Aluno* novo = criaAluno(nota, nome);
	if (novo == NULL)
		return NULL;

	novo->prox = head;
	return novo;
}

//	Implemente a função void insereFim(Aluno* head, float nota, char* nome)
void insereFim(Aluno* head, float nota, char* nome)
{
	Aluno* novo = criaAluno(nota, nome);
	if (novo == NULL)
	{
		printf("Erro ao alocar memoria\n");
		exit(1);
	}

	Aluno* p = head;
	while (p->prox != NULL)
	{
		p = p->prox;
	}

	p->prox = novo;
}


// Implemente a função Aluno* insereFimRecursivo(Aluno* head, float nota, char* nome)
Aluno* insereFimRecursivo(Aluno* head, float nota, char* nome)
{
	if (head == NULL)
	{
		Aluno* novo = criaAluno(nota, nome);
		if (novo == NULL)
			return NULL;
		head = novo;
	}
	head->prox = insereFimRecursivo(head->prox, nota, nome);
	return head;
}


// Implemente a função void imprime(Aluno* head)
void imprime(Aluno* head)
{
	if (head == NULL)
	{
		return;
	}
	printf("%.2f %s\n", head->info.nota, head->info.nome);
	imprime(head->prox);
}


// Implemente a função void escreveArquivoBin(Aluno* head, char* nomeArquivo)
//     a função deve gravar primeiro um int indicando o total de elementos
void escreveArquivoBin(Aluno* head, char* nomeArquivo)
{
	int num = 0;
	for (Aluno* p = head; p != NULL; p = p->prox)
	{
		num++;
	}
	
	FILE* arqbin = fopen(nomeArquivo, "wb");
	if (arqbin == NULL)
	{
		printf("Erro ao abrir arquivo\n");
		exit(1);
	}

	fwrite(&num, sizeof(int), 1, arqbin);

	for (Aluno* p = head; p != NULL; p = p->prox)
	{
		fwrite(&p->info, sizeof(AlunoInfo), 1, arqbin);
	}

	fclose(arqbin);
}



// Implemente a funcao void leArquivoBin(Aluno* head)
//		a funcao tem de ler primeiro um int indicando o total de elementos
void leArquivoBin(Aluno* head, char* nomeArquivo)
{
	FILE* arqbin = fopen(nomeArquivo, "rb");
	if (arqbin == NULL)
	{
		printf("Erro ao abrir arquivo\n");
		exit(1);
	}
	int num = 0;
	fread(&num, sizeof(int), 1, arqbin);
	printf("%d\n", num);
	
	Aluno a;
	while (!feof(arqbin))
	{
		fread(&a.info, sizeof(Aluno), 1, arqbin);
		//fread(&a.info.nota, sizeof(float), 1, arqbin);
		//fread(nome, sizeof(char), MAX, arqbin);
		//printf("%.2f %s\n", nota, nome);
		printf("%.2f %s\n", a.info.nota, a.info.nome);
	}

	fclose(arqbin);
}



int main(void)
{
	Aluno* a = insereInicio(NULL, 10.0f, "Gabriel");
	Aluno* b = insereInicio(a, 10.0f, "Everton");
	insereFim(b, 9.9f, "Felipe");
	imprime(b);
	escreveArquivoBin(b, "saida_g2_final.dat");
	leArquivoBin(b, "saida_g2_final.dat");

	return NULL;
}