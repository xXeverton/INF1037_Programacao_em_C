#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int len(char* s)
{
	if (*s == '\0')
		return 0;
	return 1 + len(s + 1);
}


// ex1
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
char* retorna_nome(void)
{
	printf("Informe um nome completo:\n");
	char nome[201] = "";
	scanf("%[^\n]", nome);
	int i;
	for (i = len(nome)-1; i >= 0; --i)
	{
		if (nome[i] == ' ')
		{
			break;
		}
	}
	
	printf("%d\n", i);

	char resultado[201] = "";

	strcpy(resultado, &nome[i + 1]);

	printf("%s\n", resultado);

	if (i == -1)
	{
		char* r = (char*)malloc((len(resultado) + 1) * sizeof(char));
		if (r == NULL)
		{
			return NULL;
		}
		strcpy(r, resultado);
		return r;
	}

	int prox = strlen(resultado);

	resultado[prox] = ',';
	prox++;
	resultado[prox] = ' ';
	prox++;


	for (int j = 0; j < i; ++j)
	{
		if (nome[j] >= 'A' && nome[j] <= 'Z')
		{
			resultado[prox] = nome[j];
			prox++;
			resultado[prox] = '.';
			prox++;
			resultado[prox] = ' ';
			prox++;
		}
	}

	resultado[prox - 1] = '\0';


	char* r = (char*)malloc((len(resultado) + 1) * sizeof(char));
	if (r == NULL)
	{
		return NULL;
	}
	strcpy(r, resultado);
	return r;

}


// ex10 
int	maiorQueX(int n, int* v, int x)
{
	// Caso base: quando o tamanho do vetor eh 0, nao ha elementos para comparar
	if (n == 0)
	{
		return 0;
	}

	// verifica se o ultimo elemento do vetor eh maior que x
	int count = (v[n - 1] > x) ? 1 : 0;

	// Chamada recursiva para o restante do vetor
	return count + maiorQueX(n - 1, v, x);
}


// ex11
int conta_digitos(int n, int k)
{
	// Caso base:se n for 0, significa que nao ha mais digitos para verificar
	if (n == 0)
	{
		return 0;
	}

	// verifica se o ultimo digito de n eh igual a k
	int count = (n % 10 == k) ? 1 : 0;

	// chamada recursiva removendo o ultimo digito
	return count + conta_digitos(n / 10, k);
}



int main(void)
{	
	
	return 0;
}





