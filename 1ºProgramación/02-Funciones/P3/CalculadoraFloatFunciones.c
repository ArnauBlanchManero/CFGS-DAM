#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * 	Código escrito por Arnau Blanch
 */

// Función para sumar num1 y num2
float sumar(float num1, float num2){
	float resultado = num1 + num2;
	return resultado;
}

// Función para restar num1 y num2
float restar(float num1, float num2){
	float resultado = num1 - num2;
	return resultado;
}

// Función para multiplicar num1 y num2
float multiplicar(float num1, float num2){
	float resultado = num1 * num2;
	return resultado;
}


// Función para dividir num1 y num2
float dividir(float num1, float num2){
	float resultado = num1 / num2;
	return resultado;
}

int main(){
	// Pedir los números que el usuario quiera con scanf
	float num1, num2;
	printf("Dime el primer número que vas a querer operar: ");
	scanf("%f",&num1);
	printf("\nAhora dime el segundo: ");
	scanf("%f",&num2);
	
	// Declarar las variables con las soluciones
	float suma = sumar(num1,num2);
	float resta = restar(num1,num2);
	float mult = multiplicar(num1,num2);
	float div = dividir(num1,num2);

	// Imprimir los resultados
	printf("Las operaciones de %.2f y %.2f redondeado a dos decimales es:\n- Suma: %.2f\n- Resta: %.2f\n- Multiplicacion: %.2f\n- Division: %.2f\n", num1, num2, suma, resta, mult, div);

	return 0;
}
