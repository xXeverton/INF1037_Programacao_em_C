#include <stdio.h>




int main(void)
{
	// assumindo que nenhuma pessoa pode ter idade 0 e 999	

	int idade = 999;
	int maior = 0;
	int menor = 999;
	int contador = 0;
	int soma = 0;
	
	while (1)
	{
		printf("Informe sua idade:\n");
		scanf("%d", &idade);

		if (idade == 0)
		{
			break;
		}
		
		soma += idade;
		++contador;

		if (idade < menor)
		{
			menor = idade;
		}

		if (idade > maior)
		{
			maior = idade;
		}

	}
								
	printf("Media idade: %.2f \nMenor idade: %d \nMaior idade: %d\n", ((float)soma / contador), menor, maior);


	return 0; 
}	