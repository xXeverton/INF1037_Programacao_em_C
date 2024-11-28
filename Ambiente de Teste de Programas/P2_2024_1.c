#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHA 26
#define TRUE 1
#define FALSE 0

typedef struct node Node;
struct node
{
	char* nome;
	int telefone;
	Node* prox;
};


typedef struct agenda Agenda;
struct agenda
{
	Node* vetor[26];
};


Agenda* criaAgenda(void)
{
	Agenda* a = (Agenda*)malloc(sizeof(Agenda));
	if (a == NULL)
		return NULL;

	for (int i = 0; i < ALPHA; ++i)
	{
		a->vetor[i] = NULL;
	}

	return a;
}


Node* insereNode(Node* head, char* nome, int telefone)
{
	Node* novo = (Node*)malloc(sizeof(Node));
	if (novo == NULL)
	{
		return NULL;
	}

	novo->nome = (char*)malloc(sizeof(char) * (strlen(nome) + 1));
	if (novo->nome == NULL)
		return NULL;

	strcpy(novo->nome, nome);
	novo->telefone = telefone;
	novo->prox = head;

	return novo;
}


int inserePessoa(Agenda* head, char* nome, int telefone)
{

	int index = nome[0] - 'A'; /* Para retornar a posição exata da lista*/

	head->vetor[index] = insereNode(head->vetor[index], nome, telefone);
	if (head == NULL)
		return FALSE;

	return TRUE;
}

void exibeAgenda(Agenda* a, char letra)
{
	int index = letra - 'A'; /* Para retornar a posição exata da lista*/
	Node* p = a->vetor[index];
	printf("%c:\n", letra);
	if (p == NULL)
	{
		printf("\tNao existe pessoas com essa letra\n");
	}
	else
	{
		for (; p != NULL; p = p->prox)
		{
			printf("\t%s: %d\n", p->nome, p->telefone);
		}
	}
}

void liberaAgenda(Agenda* a)
{
	for (int i = 0; i < ALPHA; ++i)
	{
		Node* p = a->vetor[i];
		while (p != NULL)
		{
			Node* temp = p->prox;
			free(p->nome);
			free(p);
			p = temp;
		}
	}
	printf("Memoria liberada com sucesso\n");
}


int main(void)
{

	Agenda* a = criaAgenda();
	if (a == NULL)
	{
		printf("Erro ao alocar memoria\n");
		exit(1);
	}
	inserePessoa(a, "Fred", 50000005);
	inserePessoa(a, "Zoe", 80000008);
	inserePessoa(a, "Ada", 40000004);
	inserePessoa(a, "Frida", 60000006);
	inserePessoa(a, "Yoda", 90000009);
	inserePessoa(a, "Feynman", 70000007);

	exibeAgenda(a, 'A');
	exibeAgenda(a, 'F');
	exibeAgenda(a, 'Y');
	exibeAgenda(a, 'Z');
	

	liberaAgenda(a);

	return 0;
}