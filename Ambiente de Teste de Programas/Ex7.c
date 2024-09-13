#include <stdio.h>

int imprimiSomaPar(int x, int y)
{
	int indice = x;
	int soma = 0;
	for (int i = x; i <= y; ++i)
	{

		if (indice % 2 == 0)
		{
			soma += indice;
		}
		indice++;
	}

	return soma;
}

int main(void) {
	int x;
	int y;

	printf("Informe um numero:");
	scanf("%d", &x);
	printf("\nInforme um numero maior que x:");
	scanf("%d", &y);

	int res = imprimiSomaPar(x, y);
	printf("\n soma = %d", res);








	return 0;
}