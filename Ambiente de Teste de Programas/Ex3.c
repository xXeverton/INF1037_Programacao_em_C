#include <stdio.h>

int main(void) {
	float p1;
	float p2;
	int peso1 = 3;
	int peso2 = 7;


	printf("Informe a p1 e p2:");
	scanf("%f %f", &p1, &p2);

	float media = (float)((p1 * peso1) + (p2 * peso2)) / (peso1 + peso2);
	printf("\nA media eh:%.2f", media);

	return 0;
}