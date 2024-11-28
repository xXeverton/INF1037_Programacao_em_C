#include <stdio.h>
#include <stdlib.h>

#define TAM 6

typedef struct node Node;
struct node
{
	int end;
	float weight;
	Node* next;
};


typedef struct graph Graph;
struct graph
{
	Node* vetor[TAM];
};


typedef struct edge Edge;
struct edge
{
	int start;
	int end;
	float weight;
};


Graph* createGraph(void)
{
	Graph* g = (Graph*)malloc(sizeof(Graph));
	if (g == NULL)
		return NULL;


	return g;
}


void initializeGraph(Graph* g, int n) 
{
	
	for (int i = 0; i < TAM; ++i)
	{
		g->vetor[i] = NULL;
	}
}


Node* insereNode(Node* lst, int end, float weigth)
{
	Node* novo = (Node*)malloc(sizeof(Node));
	if (novo == NULL)
		return NULL;

	novo->end = end;
	novo->weight = weigth;
	novo->next = lst;

	return novo;
}


void setGraph(Graph* g, Edge* edges1, int n)
{
	for (int i = 0; i < n; ++i)
	{
		int index = edges1[i].start;
		g->vetor[index] = insereNode(g->vetor[index], edges1[i].end, edges1[i].weight);
		if (g->vetor[index] == NULL)
		{
			exit(1);
		}	
	}
}

void printGraph(Graph* g, int n)
{
	printf("Graph:\n");
	for (int i = 0; i < n; ++i)
	{
		Node* p = g->vetor[i];
		while (p != NULL)
		{
			printf("(");
			printf("%d -> %d, %.2f", i, p->end, p->weight);
			printf(") ");
			p = p->next;
		}
	}
	printf("\n");
}



float popularity(Graph* g, int n, int vertice)
{
	float soma = 0.0f;
	for (int i = 0; i < n; ++i)
	{
		Node* p = g->vetor[i];
		if (p->end == vertice)
		{
			while (p != NULL)
			{
				soma += p->weight;
				p = p->next;
			}
		}
	}

	return soma;
}


void freeGraph(Graph* g, int n)
{
	for (int i = 0; i < n; ++i)
	{
		Node* p = g->vetor[i];
		while (p != NULL)
		{
			Node* temp = p->next;
			free(p);
			p = temp;
		}
	}
	printf(">> Grafo liberado com sucesso!\n");
}


int main(void)
{
	Edge edges1[] = {
		{0,1,0.3f},
		{1,2,0.8f},
		{2,0,0.4f},
		{2,1,0.5f},
		{3,1,0.7f},
		{4,2,1.0f},
	};
	Graph* g = createGraph();
	setGraph(g, edges1, TAM);
	printGraph(g, TAM);


	for (int i = 0; i < TAM; i++)
	{
		float p = popularity(g, TAM, i);
		printf("Popularidade de %d = %.2f\n", i, p);
	}

	freeGraph(g, TAM);




	return 0;
}