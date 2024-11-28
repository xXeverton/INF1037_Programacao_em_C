#include <stdio.h>
#include <stdlib.h>

#define PROD 10
#define PEDIDOS 8

void copy(char* dst, char* src)
{
	while (*src)
	{
		*dst = *src;
		++dst;
		++src;
	}
	*dst = '\0';
}


struct produtos
{
	int codigo;
	char nome[16];
	float preco;
	int quantidade;
};
typedef struct produtos Produtos;

struct pedido
{
	int codigo;
	int quantidade;
};
typedef struct pedido Pedidos;


Produtos** criaProdutos(int* codigo, char** nome, float* preco, int* quantidade)
{
	Produtos** prod = (Produtos**)malloc(sizeof(Produtos*) * PROD);
	if (prod == NULL)
	{
		return NULL;
	}

	for (int i = 0; i < PROD; ++i)
	{
		prod[i] = (Produtos*)malloc(sizeof(Produtos));
		if (prod[i] == NULL)
		{
			return NULL;
		}
	}


	for (int i = 0; i < PROD; ++i)
	{
		prod[i]->codigo = codigo[i];
		copy(prod[i]->nome, nome[i]);
		prod[i]->preco = preco[i];
		prod[i]->quantidade = quantidade[i];
	}

	return prod;
}


Pedidos* lPedidos(int* codigos, int* quantidade, int qtdPedidos)
{
	Pedidos* listaPedidos = (Pedidos*)malloc(sizeof(Pedidos) * PEDIDOS);
	if (listaPedidos == NULL)
	{
		return NULL;
	}

	for (int i = 0; i < qtdPedidos; ++i)
	{
		listaPedidos[i].codigo = codigos[i];
		listaPedidos[i].quantidade = quantidade[i];
	}

	return listaPedidos;
}


void atualizaEstoque(Produtos** prod, int n, Pedidos* listaPedidos)
{
	int encontrei = 0;
	for (int i = 0; i < n; ++i)
	{
		Produtos* p = prod[i];
		if ((p->codigo == listaPedidos[i].codigo) && (p->quantidade >= listaPedidos[i].quantidade))
		{
			printf("Estoque suficiente para pedido\n");
			p->quantidade -= listaPedidos[i].quantidade;
		}
		else if ((p->codigo == listaPedidos[i].codigo) && (p->quantidade < listaPedidos[i].quantidade))
		{
			printf("Estoque insuficiente\n");
		}
		else
		{
			++encontrei;
		}
	}
	if (encontrei == n)
	{
		printf("Produto nao encontrado\n");
	}
}


void imprimeProdutos(Produtos** prod, int n)
{
	printf("%-10s %-20s %-15s %-10s\n", "Codigo", "Nome", "Preco", "Quantidade");
	for (int i = 0; i < n; ++i)
	{
		Produtos* p = prod[i];
		printf("%-10d %-20s R$%-13.2f %-10d\n", p->codigo, p->nome, p->preco, p->quantidade);
	}
}

void libera(Produtos** prod, int n)
{
	for (int i = 0; i < n; ++i)
	{
		free(prod[i]);
	}
	free(prod);
	printf("Memoria liberada com sucesso\n");
}


int main(void)
{
	int qtdProdutos = PROD;
	int codigos[PROD] = { 1,2,3,4,5,6,7,8,9,10 };

	char* nomes[PROD] = {
		"PS5",
		"PS4",
		"PS3",
		"XBOX SERIES S",
		"XBOX SERIE X",
		"MOUSE",
		"TECLADO",
		"PROCESSADOR",
		"MEMORIA RAM",
		"MONITOR",
	};

	float precos[PROD] = {
		4500.0f,
		2300.0f,
		1200.0f,
		1990.0f,
		4500.0f,
		50.0f,
		130.0f,
		345.0f,
		80.0f,
		699.0f,
	};


	int quantidade[PROD] = { 1,2,3,4,5,6,7,8,9,10 };


	int codigoPedidos[PEDIDOS] = { 1,2,3,4,5, 6, 7, 8 };

	int quantidadePedidos[PEDIDOS] = { 2,2,3,4,5,6,7,8 };


	Produtos** v = criaProdutos(codigos, nomes, precos, quantidade);
	if (v == NULL)
	{
		printf("Erro ao alocar memoria\n");
		exit(1);
	}

	imprimeProdutos(v, 10);

	Pedidos listaPedidos[PEDIDOS];
	for (int i = 0; i < PEDIDOS; ++i)
	{

		listaPedidos[i].codigo = codigoPedidos[i];
		listaPedidos[i].quantidade = quantidadePedidos[i];
	}

	atualizaEstoque(v, qtdProdutos, listaPedidos);
	printf("\n<---------------Lista Produtos Atualizada------------------------>\n");
	imprimeProdutos(v, qtdProdutos);


	libera(v, 10);
	return 0;
}