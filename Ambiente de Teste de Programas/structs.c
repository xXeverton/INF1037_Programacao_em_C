#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct aluno
{
	char nome[81];
	int idade;
	float media;
};
typedef struct aluno Aluno; // nome antigo + nome novo 
// aqui definimos a estrutura com outro nome
// Uma boa pratica de programacao eh colocar a struct com letra minuscula e o typedef com letra maiuscula 

void funcao()
{

}



int main(void)
{
	Aluno a;
	a.idade = 10;

	Aluno* p;
	p->idade = 10;

	Aluno v[10];
	v[4].idade = 10;


	

	return 0;
}