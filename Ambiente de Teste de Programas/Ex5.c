#include <stdio.h>

int main(void) {
	float num1;
	float num2;
	char op;

	printf("Digite: numero op numero\n");
	scanf("%f %c %f", &num1, &op, &num2);
	switch (op) {
	case '+':
		printf(" = %f", num1 + num2);
		break;
	case '-':
		printf(" = %f", num1 - num2);
		break;
	case '*':
		printf(" = %f", num1 * num2);
		break;
	case '/':
		printf(" = %f", num1 / num2);
		break;
	default:
		printf("Operador invalido!\n");
		break;
	}

	return 0;
}