#include <stdio.h>
#include <stdlib.h>


struct pedido
{
	int matricula;				/* matricula do aluno que solicita a bolsa */
	char tipoDoPedido[21];		/* “soc”, “ic”, “mest”, “dout” */
	struct pedido* prox;		/* ponteiro para o proximo pedido */
};
typedef struct pedido Pedido;


void copyRec(char* dst, char* src)
{
	if (*src == '\0')
		*dst = '\0';

	else
	{
		*dst = *src;
		copyRec(1 + dst, 1 + src);
	}
}


void imprimeRec(Pedido* lst)
{
	if (lst == NULL)
		return;

	else
	{
		printf("Matricula: %d \tTipo do pedido: %s\n", lst->matricula, lst->tipoDoPedido);
		imprimeRec(lst->prox);
	}
}


Pedido* cria(int matricula, char* tipoDoPedido, Pedido* prox)
{
	Pedido* e = (Pedido*)malloc(sizeof(Pedido));
	if (e == NULL)
		return NULL;

	e->matricula = matricula;
	copyRec(e->tipoDoPedido, tipoDoPedido);
	e->prox = prox;
	return e;
}


//int maiorMatricula(Pedido* lst)		
//{
//	if (lst == NULL)
//		return -1;
//	
//	Pedido* e = lst;
//	lst = lst->prox;
//	if (e->matricula < lst->matricula)
//}


int maiorMatricula(Pedido* lst)
{
	int maior = 0;
	Pedido* p;
	for (p = lst; p != NULL; p = p->prox)
	{
		maior = maior > p->matricula ? maior : p->matricula;
	}
	return maior;
}



int main(void)
{
	Pedido* n5 = cria(201, "ic", NULL);
	Pedido* n4 = cria(415, "dout", n5);
	Pedido* n3 = cria(101, "ic", n4);
	Pedido* n2 = cria(205, "soc", n3);
	Pedido* n1 = cria(203, "ic", n2);
	imprimeRec(n1);
	int maior = maiorMatricula(n1);
	printf("Maior matricula: %d\n", maior);


	return 0;
}