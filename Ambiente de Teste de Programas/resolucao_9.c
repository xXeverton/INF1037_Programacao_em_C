#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// A funcao qtdIniciais conta quantas iniciais existem no nome. A ideia aqui é encontrar letras maiusculas que aparecem depois de um espaco
int qtdIniciais(char* nome)
{
	int i = 0;
	while (*nome)
	{
		if (*nome == ' ' && *(nome + 1) != '\0' && (*(nome + 1) > 'A' && *(nome + 1) < 'Z'))
		{
			i++; // conta as letras maiusculas que vem apos um espacos
		}
		nome++;
	}
	return i;
}


// encontra e retorna o ultimo nome de uma string
char* ultimoNome(char* nome)
{
	char* ultNome;
	while (*nome)
	{
		if (*nome == ' ')
		{
			ultNome = (nome + 1); // Guarda o ponteiro que aponta para a proxima palavra.
		}
		nome++;
	}
	return ultNome;
}


// retorna as inicias do nome 
char* Iniciais(char* nome, int qtdIniciais)
{
	char* iniciais = (char*)malloc(sizeof(char) * (qtdIniciais + 1));
	int j = 0;
	iniciais[j++] = nome[0]; // A primeira inicial eh sempre o primeiro caracter do nome
	while (*nome)
	{
		if (*nome == ' ' && *(nome + 1) != '\0' && (*(nome + 1) > 'A' && *(nome + 1) < 'Z'))
		{
			iniciais[j++] = *(nome + 1);	// adiciona a inicial de cada nome encontrado 
		}
		nome++;
	}
	iniciais[j - 1] = '\0';	// finaliza a string de iniciais
	return iniciais;
}


char* montaNome(char* ultimoNome, char* iniciais)
{
	int tam = (strlen(iniciais) * 2) + strlen(ultimoNome) + 2; // +2 para virgula e espaco
	char* str = (char*)malloc(sizeof(char) * (tam + 1));	// aloca espaco para a nova string

	strcpy(str, ultimoNome);
	strcat(str, ", ");	// adiciona a virgula e espacos apos ultimo nome.

	int pos = strlen(ultimoNome) + 2;
	for (int i = 0; i < strlen(iniciais); i++)
	{
		str[pos++] = iniciais[i];
		str[pos++] = '.';	// adiciona um ponto apos cada inicial 

	}
	str[pos] = '\0';	// finaliza a string
	return str;

}



int main(void)
{
	char nome[] = "Joao Jose da Silva";
	int qtdIni = qtdIniciais(nome);
	char* ini = Iniciais(nome, qtdIni);
	char* ultNome = ultimoNome(nome);

	//printf("%s", ini);
	//printf("%s", ultNome);
	char* nomeFinal = montaNome(ultNome, ini);
	printf("%s\n", nomeFinal);

}