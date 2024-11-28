#include <stdio.h>
#include <stdlib.h>

#define PI 3.14


struct ponto
{
	float x;
	float y;
};
typedef struct ponto Ponto;


struct circulo
{
	Ponto* centro;
	float raio;
};
typedef struct circulo Circulo;


Circulo* criaCirculo(float x, float y, float raio)
{
	Circulo* c = (Circulo*)malloc(sizeof(Circulo));
	if (c == NULL)
	{
		printf("Erro ao alocar memoria para o circulo\n");
		exit(1);
	}

	c->centro = (Ponto*)malloc(sizeof(Ponto));
	if (c->centro == NULL)
	{
		printf("Erro ao alocar memoria para o centro\n");
		exit(1);
	}

	c->centro->x = x;
	c->centro->y = y;
	c->raio = raio;
	return c;
}


void imprimeCirculo(Circulo* c)
{
	printf("Centro: (%.2f, %.2f)\tRaio: %.2f\n", c->centro->x, c->centro->y, c->raio);
}


float calculaArea(Circulo* c)
{
	return (float)PI * (c->raio) * (c->raio);
}


int main(void)
{
	float x; 
	float y;
	float raio;
	printf("Digite um ponto (x,y) como centro:\n");
	scanf("%f,%f", &x, &y);
	printf("Digite um valor para o raio\n");
	scanf("%f", &raio);
	Circulo* c = criaCirculo(x, y, raio);
	imprimeCirculo(c);
	float area = calculaArea(c);
	printf("Area: %.2f\n", area);
	

	return 0;
}