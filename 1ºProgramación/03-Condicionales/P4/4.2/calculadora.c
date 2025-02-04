#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

int main(){
	
	// Declaramos las variables
	float num1, num2, resultado;
	char operador;
	
	// Pedimos al usuario lo que quiere operar
	printf("Introduce el primer número: ");
	scanf("%f", &num1);
	printf("Introduce el segundo número: ");
	scanf("%f", &num2);
	printf("Introduce el operador (+, -, *, /): ");
	scanf(" %c", &operador);

	// Vamos a calcular el resultado dependiendo del operador
	switch (operador){
		case '+' :
			resultado = num1 + num2;
			printf("Resultado: %.2f\n", resultado);
			break;	
		case '-' :
			resultado = num1 - num2;
			printf("Resultado: %.2f\n", resultado);
			break;
		case '*' :
			resultado = num1 * num2;
			printf("Resultado: %.2f\n", resultado);
			break;
		case '/' :
			resultado = num1 / num2;
			printf("Resultado: %.2f\n", resultado);
			break;
		default: 
			printf("Operador no válido\n");
	}

	return EXIT_SUCCESS;
}
