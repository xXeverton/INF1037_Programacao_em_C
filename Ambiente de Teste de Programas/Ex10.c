#include <stdio.h>


int main(void)
{
	int qtd;
	printf("Informe a quantidade de alunos:\n");
	scanf("%d", &qtd);

	for (int i = 0; i < qtd; ++i)
	{
		int matricula = 0;
		printf("Informe sua matricula:\n");
		scanf("%d", &matricula);
		if (matricula == 0)
		{
			break;
		}

		int qtd_trabalhos = 0;
		printf("Informe a quantidade de trabalhos:\n");
		scanf("%d", &qtd_trabalhos);

		float nota = 0.0f;
		float soma = 0.0f;
		for (int j = 0; j < qtd_trabalhos; ++j)
		{
			printf("Informe seu trabalho[%d]:", j+1);
			scanf("%f", &nota);
			soma += nota;
		}

		printf("Matricula: %d\nMedia: %.2f\n", matricula, (soma / qtd_trabalhos));

	}


	return 0;
}