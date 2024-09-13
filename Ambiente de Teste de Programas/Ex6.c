#include <stdio.h>

void situacao(float media) {
	if (media >= 5.0f)
		printf("Aprovado!");

	else if (media < 3.0f)
		printf("Reprovado!");

	else if (media > 3.0f && media < 5.0f)
		printf("Em final!");
}

void mensagem(float media) {
	if (media > 9.0f)
		printf("Parabens!");
}


int main(void) {
	int matricula;
	int n1;
	int n2;
	printf("Informe sua matricula:");
	scanf("%d", &matricula);

	printf("\nInforme sua nota:");
	scanf("%d %d", &n1, &n2);

	float media = (n1 + n2) / 2;

	situacao(media);
	mensagem(media);





	return 0;
}