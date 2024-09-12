#include <stdio.h>


int main(void)
{
	int qtd;
	printf("Informe a quantidade de brindes:\n");
	scanf("%d", &qtd);


	int dia;
	int mes;

	for(int i = 0; i < qtd; ++i )
	{
		printf("Informe sua data de nascimento (dia/mes):\n");
		scanf("%d/%d", &dia, &mes);

		if (dia % mes == 0)
		{
			printf("Parabens\n");
		}
	}

	printf("Promocao encerrada!\n");




	return 0;
}