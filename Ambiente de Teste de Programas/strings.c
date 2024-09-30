#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int len(char* s)
{
	if (*s == '\0')
		return 0;
	return 1 + len(s + 1);
}


/*
* 1) Escreva a função contaB, que recebe uma cadeia e retorna (devolve) 2 valores: o número de ´b´s  e o número de
* ´B´s. Por exemplo: Cadeia recebida: “Barbudinho bonito”. Tem 1 ‘B’ e 2 ‘b’. Escreva o programa completo para testar a sua função.*
*/
void contaBs(char* s)
{
	int qb = 0;
	int qB = 0;
	for (int i = 0; s[i] != '\0'; ++i)
	{
		if (s[i] == 'b')
		{
			++qb;
		}
		else if (s[i] == 'B')
		{
			++qB;
		}
	}

	printf("%s tem %d 'B' e %d 'b'", s, qB, qb);
}


// ex2
int contaNaoLetra(char* s)
{
	if (*s == '\0') // caso base
		return 0;
	else if ((*s < 'A') || (*s > 'Z' && *s < 'a') || *s > 'z') // caso não seja uma letra -> Lembrar!
		return 1 + contaNaoLetra(s + 1);
	return contaNaoLetra(s + 1); // caso seja uma letra
}


// ex3
int busca(char* str, char c)
{
	if (*str == '\0')
		return 0;
	else if (*str == c)
		return 1;
	return busca(str + 1, c);
}


// ex4
void maiusculo(char* str)
{
	if (*str == '\0')
		return;
	else if (*str >= 'a' && *str <= 'z')
		*str = *str - ('a' - 'A');

	maiusculo(str + 1);
}


// ex5
int comprimento(char* s)
{
	if (*s == '\0')
		return 0;
	return 1 + comprimento(s + 1);
}

// ex6
void eliminaAB(char* s)
{
	// iniciar dois contadores e verificar para da string
	for (int i = 0,j = i; s[i] != '\0'; ++i)
	{
		if (*s == 'A' && *(s + 1) == 'B') // verifica se a letra eh requisitada
		{
			i += 2;
			
		}
		s[j] = s[i];
		s[j + 1] = s[i + 1];
		++j;
	}
}

// ex7 -> Recordar!
void elimina(char* s1, char* s2) {
	int len_s2 = len(s2);
	int i = 0;
	int j = 0;

	while (s1[i] != '\0')
	{
		// Verifica se a subcadeia 's2' é encontrada
		if (strncmp(&s1[i], s2, len_s2) == 0) 
		{
			i += len_s2; // Pula a sequência encontrada
		}
		else 
		{
			s1[j++] = s1[i++]; // Copia o caractere atual
		}
	}
	s1[j] = '\0'; // Adiciona o terminador de string
}


// ex8
int palindromo(char* s, int n)
{
	int contador = 0;
	for (int i = 0, j = n-1; s[i] != '\0'; ++i, --j)
	{
		if (s[i] == s[j])
		{
			++contador;
		}
	}

	if (contador == n)
		return 1;

	return 0;
}


// ex9
char* retorna_nome(char* s)
{
	char e1[] = "de ";
	char e2[] = "da ";
	char e3[] = ". ";

	// elimina "de " "da " e ". "
	elimina(s, e1);
	elimina(s, e2);
	elimina(s, e3);

	// verificar quantos nomes possui a cadeia
	int qtd_nomes = 0;
	for (int i = 0; s[i] != '\0'; ++i)
	{
		if (s[i] == ' ')
			++qtd_nomes;
	}
	qtd_nomes++;

	// Fazer uma vetor para armazenar os nomes
	char** vetor = (char**)malloc(qtd_nomes * sizeof(char*));
	if (vetor == NULL)
	{
		return NULL;
	}


	// alocar espaco para os nomes e copiar os nomes
	for (int i = 0; i < qtd_nomes; ++i)
	{
		char temp[21];
		int tamanho = 0;
		for (int j = 0; s[j] != ' '; ++j)
		{
			temp[j] = s[j];
			++tamanho;
		}
		temp[tamanho] = '\0';

		vetor[i] = (char*)malloc((tamanho + 1) * sizeof(char));
		if (vetor[i] == NULL)
		{
			return NULL;
		}

		strcpy(vetor[i], temp);
	}


	// montar a string
	char resposta[101];
	int qtd_caracteres = 0;
	char virgula[] = ", ";
	char ponto[] = ". ";
	strcpy(resposta, vetor[qtd_nomes-1]);
	strcat(resposta, virgula);
	for (int i = 0; i < (qtd_nomes - 1); ++i)
	{
		strcat(resposta, vetor[i][0]);
		strcat(resposta, ponto);
	}

	for (int i = 0; i < qtd_nomes; ++i)
	{
		free(vetor[i]);
	}
	free(vetor);
	
	char* resposta_final = (char*)malloc((strlen(resposta) + 1) * sizeof(char));
	if (resposta_final == NULL)
	{
		return NULL;
	}

	strcpy(resposta_final, resposta);
	return resposta_final;
}



int main(void)
{
	char s1[] = "Joao Jose da Silva";
	char* s2 = retorna_nome(s1);

	printf("%s\n", s1);


	return 0;
}





