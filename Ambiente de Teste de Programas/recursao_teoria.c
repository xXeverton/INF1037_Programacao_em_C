#include <stdio.h>
#include <stdlib.h>



struct elemento
{
	int info;
	struct elemento* prox;
};
typedef struct elemento Elemento;


int lenStr(char* str)
{
	if (*str == '\0')
		return NULL;
	return 1 + lenStr(1 + str);
}


void printStr(char* str)
{
	if (*str == '\0')
		return;

	else
	{
		printf("%c", *str);
		printStr(1 + str);
	}
}


void copyStr(char* dst, char* src)
{
	if (*src == '\0')
		*dst = '\0';

	else 
	{
		*dst = *src;
		copyStr(1 + dst, 1 + src);
	}
}


double power(double base, double exp)
{
	if (exp == 0)
		return 1;

	return base * power(base, exp - 1);
}


int fat(int n)			// fat(0)=1; fat(n)=n*fat(n-1)
{
	if (n == 0)
		return 1;

	return n * fat(n - 1);
}


int fib(int n)		//fib(0)=0; fib(1)=1; fib(n)=fib(n-1)+fib(n-2) if n > 1
{
	if (n == 0)
		return 0;

	else if (n == 1)
		return 1;

	return fib(n - 1) + fib(n - 2);

}


Elemento* cria(int info, Elemento* prox)
{
	Elemento* p = (Elemento*)malloc(sizeof(Elemento));
	if (p == NULL)
		return NULL;

	p->info = info;
	p->prox = prox;
	return p;
}


void printLst(Elemento* lst)
{
	if (lst == NULL)
		return;

	printf("info: %d\n", lst->info);
	printLst(lst->prox);

}


// Do final para o inicial
void freeLst(Elemento* lst)
{
	if (lst == NULL)
		return;
	freeLst(lst->prox);
	free(lst);
}


// Do inicial para o final
//void freeLst(Elemento* lst)
//{
//	if (lst == NULL)
//		return;
//
//	Elemento* prox = lst->prox;
//	free(lst);
//	freeLst(prox);
//}


int equalLst(Elemento* a, Elemento* b)			// 1 if equal, 0 otherside
{
	if (a == NULL && b == NULL)
		return 1;

	else if (a == NULL || b == NULL)
		return 0;
	
	else // a != NULL && b != NULL
		return (a->info == b->info) && equalLst(a->prox, b->prox);
}


// Mais dificil de entender até agora!
Elemento* removeLst(Elemento* lst, int value)	//return pointer to head
{
	if (lst == NULL)
		return NULL;
	
	if (lst->info == value)
	{
		Elemento* e = lst;
		lst = lst->prox;
		free(e);
	}

	else
	{
		lst->prox = removeLst(lst->prox, value);
	}

	return lst; // * Entender!!
}


int main(void)
{
	printf("%d\n", lenStr("Everton"));
	printStr("Everton");
	printf("\n");
	char nome[15] = "";
	copyStr(nome, "Everton");
	printf("%s\n", nome);
	printf("%lf\n", power(2, 5));
	printf("%d\n", fat(5));
	printf("%d\n", fib(5));

	return 0;
}