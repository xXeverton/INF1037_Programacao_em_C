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


void copyRec(char* dst, char* src)
{
	if (*src == '\0')
	{
		*dst = '\0';
	}

	else
	{
		*dst = *src;
		copyRec(1 + dst, 1 + src);
	}
}


// criacao de um Candidato
Candidato* criaCandidato(int inscricao, char* nome, int idade, float nota)
{
	Candidato* novo = (Candidato*)malloc(sizeof(Candidato));
	if (novo == NULL)
	{
		return NULL;
	}

	novo->inscricao = inscricao;
	copyRec(novo->nome, nome);
	novo->idade = idade;
	novo->nota = nota;
	return novo;
}


void exibeTodosCandidatos(Candidato** v, int n)
{
	printf("%-10s\t%-51s\t%-10s\t%-10s\n", "inscricao", "nome", "idade", "nota");
	for (int i = 0; i < n; ++i)
	{
		Candidato* p = v[i];
		printf("%-10d\t%-51s\t%-10d\t%-10.2f\n", p->inscricao, p->nome, p->idade, p->nota);
	}
}


Candidato* buscaInscricao(Candidato** v, int n, int inscricao)
{
	for (int i = 0; i < n; ++i)
	{
		Candidato* p = v[i];
		if (v[i]->inscricao == inscricao)
			return p;
	}

	return NULL;
}



int main(void)
{
	Candidato* vpcandidato[8];
	int i;
	Candidato* pont;
	vpcandidato[0] = criaCandidato(444, "Luiz", 34, 7.8f);
	vpcandidato[1] = criaCandidato(111, "Rita", 56, 8.8f);
	vpcandidato[2] = criaCandidato(999, "Rute", 32, 7.1f);
	vpcandidato[3] = criaCandidato(555, "Dina", 27, 6.4f);
	vpcandidato[4] = criaCandidato(777, "Lana", 35, 5.3f);
	vpcandidato[5] = criaCandidato(666, "Tais", 29, 9.8f);
	vpcandidato[6] = criaCandidato(222, "Cris", 31, 7.2f);
	vpcandidato[7] = criaCandidato(333, "Vera", 44, 5.4f);
	exibeTodosCandidatos(vpcandidato, 8);
	pont = buscaInscricao(vpcandidato, 8, 777);
	if (pont == NULL)
	{
		printf("Candidato nao encontrado\n");
	}
	else
	{
		printf("Candidato encontrado: %s\n", pont->nome);
	}
	/* inclua aqui a parte referente ao teste da função buscaInscricao: leitura de uma inscrição, chamada da função e exibição
	dos dados do candidato, se encontrado */
	for (i = 0; i < 8; i++)
		free(vpcandidato[i]);
	


	return 0;
}