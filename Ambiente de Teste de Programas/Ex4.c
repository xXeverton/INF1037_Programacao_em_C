#include <stdio.h>


int main(void) {
	float largura;
	float altura;

	printf("Informe a largura:");
	scanf("%f", &largura);

	printf("Informe a altura:");
	scanf("%f", &altura);

	float perimetro = 2 * (altura + largura);
	float area = largura * altura;

	printf("\nA area eh %.2f o perimetro eh %.2f", area, perimetro);


	return 0;
}