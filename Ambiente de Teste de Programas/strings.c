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
* 1) Escreva a fun��o contaB, que recebe uma cadeia e retorna (devolve) 2 valores: o n�mero de �b�s  e o n�mero de
* �B�s. Por exemplo: Cadeia recebida: �Barbudinho bonito�. Tem 1 �B� e 2 �b�. Escreva o programa completo para testar a sua fun��o.*
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
	else if ((*s < 'A') || (*s > 'Z' && *s < 'a') || *s > 'z') // caso n�o seja uma letra -> Lembrar!
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
void maiuisculo(char* str, char c)
{
	if (*str == '\0')


}



int main(void)
{
	char s[] = "Brasi";
	int r = busca(s, 'l');
	printf("%d", r);



	return 0;
}





