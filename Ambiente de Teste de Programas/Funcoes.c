#define _CRT_SECURE_NO_DEPRECATE  

#include <stdio.h>
#include <math.h>
#include <string.h>
#include "functions.h"


// Ex1
int soma(int a, int b)
{
	return a + b;
}


// Ex2
int valorAbsoluto(int a)
{
	return abs(a);
}


// Ex3: feito em aula

// Ex4
void dec2hex(int a)
{
	printf("%x", a);
}


// Ex6
float retorna_gf(float ce, float cg, float mat, float pt)
{
	return calcula_percent(ce, 40) + calcula_percent(cg, 20) + calcula_percent(mat, 15) + calcula_percent(pt, 25);
}


// Ex7 
float calcula_preco(int codigo)
{
	float preco_basico = (codigo / 100) * 15.00f + (codigo % 100);
	int percent_desc = (codigo % 100);
	printf("Preco basico: $%.2f\n", preco_basico);
	printf("Percentual desconto: $%d\n", percent_desc);

	return preco_basico - calcula_percent(preco_basico, percent_desc);
}


// Ex8
int soma_dig(int num)
{
	return (num / 10) + (num % 10);
}


void gera_senha(int dia, int mes, int ano)
{
	int s_dia = soma_dig(dia);
	int s_mes = soma_dig(mes);
	int s_ano = soma_dig(ano%100);

	char res[8];
	char m[3];
	char a[3];
	ano = ano % 100;

	// converte inteiro para string;	
	sprintf(res, "%d", s_dia);
	sprintf(m, "%d", s_mes);
	sprintf(a, "%d", s_ano);
	
	strcat(res, m);
	strcat(res, a);

	printf("%s", res);
}


// Ex9 






int main(void)
{

	

	return 0;
}