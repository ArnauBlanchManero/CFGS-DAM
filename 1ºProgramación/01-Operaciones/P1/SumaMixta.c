#include <stdio.h>
#include <stdlib.h>

int main(){
	int num1, num2;
	float resultado_suma, resultado_resta, resultado_multiplicacion, resultado_division;
	printf("Introduce dos números que quieras operar: ");
	scanf("%d", &num1);
	printf(" y ");
	scanf("%d", &num2);
	resultado_suma = num1 + num2;
	resultado_resta = num1 - num2;
	resultado_multiplicacion = num1 * num2;
	resultado_division = num1 / num2;
	printf("Suma: %f\nResta: %f\nMultiplicacion: %f\nDivision: %f\n", resultado_suma, resultado_resta, resultado_multiplicacion, resultado_division);
	return 0;
}
