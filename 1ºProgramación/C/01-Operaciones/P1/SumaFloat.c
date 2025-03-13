#include <stdio.h>
#include <stdlib.h>

int main(){
	float num1, num2, resultado_suma, resultado_resta, resultado_multiplicacion, resultado_division;
	printf("Introduce el primer número que quieras operar: ");
	scanf("%f", &num1);
	printf("Introduce el segundo número: ");
	scanf("%f", &num2);
	resultado_suma = num1 + num2;
	resultado_resta = num1 - num2;
	resultado_multiplicacion = num1 * num2;
	resultado_division = num1 / num2;
	printf("Suma: %f\nResta: %f\nMultiplicacion: %f\nDivision: %f\n", resultado_suma, resultado_resta, resultado_multiplicacion, resultado_division);
	return 0;
}
