#include <stdio.h>

typedef struct ingrediente {
	char nome[21];
	int qtd;
} Ingrediente;


typedef struct receita {
	char nome[26];
	int n;
	Ingrediente v[10];
} Receita;





int main(void)
{
	Ingrediente i1 = {
		"Doce de Leite",
		3,
		{}
	}
	

	return 0;
}