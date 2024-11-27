#include <stdio.h>
#include <stdlib.h>


// Defina a estrutura AlunoInfo com um campo nota do tipo float e um campo nome do tipo char*
typedef struct alunoInfo AlunoInfo;
struct alunoInfo
{
	float nota;
	char* nome;
};

// Defina a estrutura Aluno que representa uma lista encadeada de alunos
typedef struct aluno Aluno;
struct aluno
{
	AlunoInfo dados;		// se tivesse * tem que alocar!!!
	Aluno* prox;
};


void copy(char* dst, char* src)
{
	if (*src == '\0')
		*dst = '\0';

	else
	{
		*dst = *src;
		copy(1 + dst, 1 + src);
	}
}


int len(char* str)
{
	if (*str == '\0')
		return 0;

	else
	{
		return 1 + len(1 + str);
	}
}


Aluno* criaAluno(float nota, char* nome)
{
	Aluno* novo = (Aluno*)malloc(sizeof(Aluno));
	if (novo == NULL)
		return NULL;


	novo->dados.nota = nota;
	novo->dados.nome = (char*)malloc(sizeof(char) * (len(nome) + 1));
	if (novo->dados.nome == NULL)
		return NULL;
	copy(novo->dados.nome, nome);
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
		printf("Erro de alocacao\n");
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
		return novo;
	}
	head->prox = insereFimRecursivo(head->prox, nota, nome);
	return head;
}


// Implemente a função void imprime(Aluno* head)
void imprime(Aluno* head)
{
	if (head == NULL)
		return;

	printf("%s\t%.2f\n", head->dados.nome, head->dados.nota);
	imprime(head->prox);
}


// Implemente a função void escreveArquivoBin(Aluno* head, char* nomeArquivo)
//     a função deve gravar primeiro um int indicando o total de elementos
void escreveArquivoBin(Aluno* head, char* nomeArquivo)
{
	FILE* arqBin = fopen(nomeArquivo, "wb");
	if (arqBin == NULL)
	{
		printf("Erro ao abrir o arquivo\n");
		exit(2);
	}

	int totalEl = 0;
	Aluno* p = head;
	while (p != NULL)
	{
		p = p->prox;
		totalEl++;
	}

	fwrite(&totalEl, sizeof(int), 1, arqBin);

	p = head;
	while (p != NULL)
	{

		fwrite(&p->dados.nota, sizeof(float), 1, arqBin);
		fwrite(p->dados.nome, sizeof(char), len(p->dados.nome) + 1, arqBin);
		p = p->prox;
	}

	fclose(arqBin);
}


void libera(Aluno* head)
{
	Aluno* p = head;
	while (p != NULL)
	{
		Aluno* temp = p->prox;
		free(p->dados.nome);
		free(p);
		p = temp;
	}
}


void liberaRec(Aluno* head)
{
	if (head == NULL)
		return;

	free(head->dados.nome);
	liberaRec(head->prox);
	free(head);
}

int main(void)
{
	Aluno* a = insereInicio(NULL, 8.5f, "Joao");
	Aluno* b = insereInicio(a, 7.5f, "Maria");
	insereFim(b, 6.7f, "Bruno");
	imprime(b);


	return 0;
}