#include <stdio.h>
#include <stdlib.h>


typedef struct medico Medico;
struct medico
{
	char nomeDoMed[51]; /* nome do medico */
	float valorDaConsulta; /* valor da consulta com esse medico */
	Medico* prox; /* ponteiro para o pr�ximo m�dico da lista */
};


typedef struct especialidade Especialidade;
struct especialidade
{
	char nomeEsp[21]; /*nome da especialidade */
	Medico* lstMedicos; /* ponteiro para o primeiro n� de uma lista
	simplesmente encadeada de m�dicos dessa especialidade */
};






int main(void)
{


	return 0;
}