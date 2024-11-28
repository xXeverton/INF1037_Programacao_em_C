#include <stdio.h>
#include <stdlib.h>

struct candidato
{
	int inscricao;
	char nome[51];
	int idade;
	float nota;
};
typedef struct candidato Candidato;


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


Candidato* criaCandidato(int inscricao, char* nome, int idade, float nota)
{
	Candidato* c = (Candidato*)malloc(sizeof(Candidato));
	if (c == NULL)
	{
		return NULL;
	}

	c->inscricao = inscricao;
	copy(c->nome, nome);
	c->idade = idade;
	c->nota = nota;

	return c;
}

void exibeTodosCandidatos(Candidato** v, int n)
{
	printf("%-10s %-20s %-10s %-10s\n", "Inscricao", "Nome", "Idade", "Nota");
	for (int i = 0; i < n; ++i)
	{
		Candidato* p = v[i];
		printf("%-10d %-20s %-10d %-10.2f\n", p->inscricao, p->nome, p->idade, p->nota);
	}
}


Candidato* buscaIdentidae(Candidato** v, int n, int inscricao)
{
	for (int i = 0; i < n; ++i)
	{
		Candidato* p = v[i];
		if (p->inscricao == inscricao)
		{
			return p;
		}
	}
	return NULL;
}


//Candidato** montaListaCandidadtos(int* inscricoes, char** nomes, int* idades, float* notas, int n)
//{
//	Candidato** v = (Candidato**)malloc(sizeof(Candidato*) * n);
//	if (v == NULL)
//	{
//		return NULL;
//	}
//
//	for (int i = 0; i < n; ++i)
//	{
//		Candidato* p = v[i];
//		p = criaCandidato(inscricoes[i], nomes[i], idades[i], notas[i]);
//		if (p == NULL)
//		{
//			return NULL;
//		}
//	}
//}



int main(void)
{
	Candidato* vpcandidato[8];
	int i;
	Candidato* pont;

	vpcandidato[0] = criaCandidato(444, "Luiz", 34, 7.8f);
	vpcandidato[1] = criaCandidato(111, "Rita", 56, 8.8f);
	vpcandidato[2] = criaCandidato(999, "Rute", 32, 7.1f);
	vpcandidato[3] = criaCandidato(555, "Dina", 27, 6.4f);
	vpcandidato[4] = criaCandidato(777, "Lana", 35, 9.3f);
	vpcandidato[5] = criaCandidato(666, "Tais", 29, 9.8f);
	vpcandidato[6] = criaCandidato(222, "Cris", 31, 7.2f);
	vpcandidato[7] = criaCandidato(333, "Vera", 44, 5.4f);

	exibeTodosCandidatos(vpcandidato, 8);

	/* inclua aqui a parte referente ao teste da função
	   buscaInscricao: leitura de uma inscrição, chamada da função e
	   exibição dos dados do candidato, se encontrado */

	Candidato* encontrou = buscaIdentidae(vpcandidato, 8, 668);
	if (encontrou == NULL)
	{
		printf("\nCandidato nao encontrado!\n");
	}
	else
	{
		printf("\nCandidato encontrado! \nNome:%s\n", encontrou->nome);
	}

	for (i = 0; i < 8; i++)
		free(vpcandidato[i]);

	return 0;
}
