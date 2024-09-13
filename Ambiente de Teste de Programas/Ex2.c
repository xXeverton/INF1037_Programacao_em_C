#include <stdio.h>


int main(void) {
	int dias_decorridos;
	printf("Informe o numero de dias decorridos:");
	scanf("%d", &dias_decorridos);

	int semanas = dias_decorridos / 7;
	int dias = dias_decorridos % 7;

	printf("\nForma decorridos %d semanas e %d dias", semanas, dias);

	return 0;
}