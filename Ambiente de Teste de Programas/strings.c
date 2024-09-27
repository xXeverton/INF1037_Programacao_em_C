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
	for (int i = 0,j = i; s[i] != '\0'; ++i)
	{
		if (*s == 'A' && *(s + 1) == 'B')
		{
			i += 2;
		}

		s[j] = s[i];
		++j;

	}
}


int main(void)
{
	char s[] = "ABCDE";
	printf("%s\n", s);
	eliminaAB(s);
	printf("%s\n", s);





	return 0;
}





