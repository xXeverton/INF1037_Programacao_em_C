#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


/*1.Faça um programa que obtenha o dia de retirada
	e o dia da entrega de um livro da biblioteca(ambos no mesmo mês) e
	informe quantos dias o livro ficou emprestado.*/



int main(void) {

	printf("Informe o dia de retirada do livro:");
	int dia_r;
	int dia_entrega;
	scanf("%d", &dia_r);

	printf("\nInforme o dia de entrega do livro:");
	scanf("%d", &dia_entrega);

	printf("O total de transcorridos: %d", dia_entrega - dia_r);

	return 0;
}

