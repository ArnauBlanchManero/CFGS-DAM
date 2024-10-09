#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*
 * 	Autor: Arnau Blanch
 */
//int main();
void es_vocal(char letra){
	switch(letra){
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
			printf("La letra %c es una vocal.\n", letra);	
			break;
		default: 
			printf("La letra %c no es una vocal.\n", letra);
	}
	//main();
}

void calcular_area_figura(){
	int figura;
	float radio;
	float lado;
	float resultado;
	printf("¿Qué figura deseas calcular (círculo=1, cuadrdado=2)? ");
	scanf("%d", &figura);
	if(figura == 1){
		printf("Introduce el radio del círculo: ");
		scanf("%f", &radio);
		if (radio < 0){
			printf("Error en la función calcular_area_figura.\n");
		} else {
			resultado = radio * radio * M_PI;
			printf("El área del círculo con radio %.0f es %.2f\n", radio, resultado);
		}
	} else if (figura == 2){
		printf("Introduce el lado del cuadrado: ");
		scanf("%f", &lado);
		if (lado < 0){
			printf("Error en la función calcular_area_figura.\n");
		} else {
			resultado = lado * lado;
			printf("El área del cuadrado con lado %.0f es %.2f\n", lado, resultado);
		}
	} else {
		printf("Error en la función calcular_area_figura.\n");
	}
	//main();
}

double calcular_promedio_tres_num(double num1, double num2, double num3){
	return (num1 + num2 + num3) / 3;
}
double calcular_promedio_cuatro_num(double num1, double num2, double num3, double num4){
	return (num1 + num2 + num3 + num4) / 4;
}

void calcular_promedio(){
	int numeros;
	double num1, num2, num3, num4, resultado;
	printf("¿Cuántos números deseas promediar (3 o 4)? ");
	scanf("%d", &numeros);
	if(numeros == 3){
		printf("Introduce el número 1: ");
		scanf("%lf", &num1);
		printf("Introduce el número 2: ");
		scanf("%lf", &num2);
		printf("Introduce el número 3: ");
		scanf("%lf", &num3);
		resultado = calcular_promedio_tres_num(num1, num2, num3);
		printf("El promedio de %.2lf, %.2lf, %.2lf es %.2lf\n", num1, num2, num3, resultado);
	} else if (numeros == 4){
		printf("Introduce el número 1: ");
		scanf("%lf", &num1);
		printf("Introduce el número 2: ");
		scanf("%lf", &num2);
		printf("Introduce el número 3: ");
		scanf("%lf", &num3);
		printf("Introduce el número 4: ");
		scanf("%lf", &num4);
		resultado = calcular_promedio_cuatro_num(num1, num2, num3, num4);
		printf("El promedio de %.2lf, %.2lf, %.2lf, %.2lf es %.2lf\n", num1, num2, num3, num4, resultado);
	} else {
		printf("Error en la función calcular_promedio\n");
	}
	//main();
}

void convertir_hora_24_a_12(){
	int hora24, hora12;
	printf("Introduce la hora en formato 24 horas: ");
	scanf("%d", &hora24);
	if (hora24 < 0 || hora24 > 23){
		printf("Hora no válida\n");
	} else if(hora24 > 12){
		hora12 = hora24 - 12;
		printf("La hora en formato de 12 horas es %dPM.\n", hora12);
	} else {
		hora12 = hora24;
		printf("La hora en formato de 12 horas es %dAM.\n", hora12);
	}
	//main();
}

void es_primo(){
	int numero;
	printf("Introduce un número menor de 10: ");
	scanf("%d", &numero);
	if (numero < 0 || numero > 10){
		printf("El número debe ser menor de 10\n");
	} else if (numero == 1 || numero == 2 || numero == 3 || numero == 5 || numero == 7){
		printf("El número %d es primo\n", numero);
	} else {
		printf("El número %d no es primo\n", numero);	
	}
	//main();
}

void comparar_3_numeros(){
	int num1, num2, num3;
	printf("Introduce el número 1: ");
	scanf("%d", &num1);
	printf("Introduce el número 2: ");
	scanf("%d", &num2);
	printf("Introduce el número 3: ");
	scanf("%d", &num3);
	if (num1 > num2){
		if (num1 > num3){
			printf("El mayor múmero es %d.\n", num1);
		} else if (num3 > num2){
			printf("El mayor número es %d.\n", num3);
		} else {
			printf("El mayor número es %d.\n", num2);
		}
	}else if(num2 > num3){
		printf("El mayor número es %d.\n", num2);
	} else {
		printf("El mayor número es %d.\n", num3);
	}
	//main();
}

int main(){
	int opcion;
	char letra;
	printf("Selecciona una opción:\n1. Verificar si una letra es una vocal.\n2. Calcular el área de una figura (círculo o cuadrado).\n3. Calcular el promedio de 3 o 4 números.\n4. Convertir una hora en formato de 24 horas a 12 horas.\n5. Verificar si un número menor de 10 es primo.\n6. Comparar tres números.\n7. Salir\n");
	scanf("%d", &opcion);
	switch (opcion){ // Dependiendo del número que haya introducido el usuario voy a llamar a una función o a otra.
		case 1:
			printf("Opción: %d\n", opcion);
			printf("Introduce una letra: ");
			scanf(" %c", &letra);	
			es_vocal(letra);
			break;
		case 2:
			printf("Opción: %d\n", opcion);
			calcular_area_figura();
			break;
		case 3:
			printf("Opción: %d\n", opcion);
			calcular_promedio();
			break;
		case 4:
			printf("Opción: %d\n", opcion);
			convertir_hora_24_a_12();
			break;
		case 5:
			printf("Opción: %d\n", opcion);
			es_primo();
			break;
		case 6:
			printf("Opción: %d\n", opcion);
			comparar_3_numeros();
			break;
		case 7:
			printf("Opción: %d\n", opcion);
		//	salir();
			break;
		default:
			printf("Introduce un número entre el 1 y el 7.\n");
			main();
	}	
	return EXIT_SUCCESS;
}
