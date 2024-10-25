#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*
 * 	Autor: Arnau Blanch
 */
//int main();
int es_mayuscula(char letra);
void calcular_factorial();
int encontrar_maximo(int num1, int num2);
double convertir_celsius_a_farenheit(double celsius);
void intercambiar_numeros();
double calcular_potencia(double base , int exponente);

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
			resultado = pow(radio,2) * M_PI;
			printf("El área del círculo con radio %.0f es %.2f\n", radio, resultado);
		}
	} else if (figura == 2){
		printf("Introduce el lado del cuadrado: ");
		scanf("%f", &lado);
		if (lado < 0){
			printf("Error en la función calcular_area_figura.\n");
		} else {
			resultado = pow(lado,2);
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
	char letra; //Para el caso 1
	// Para mostrar el menú de inicio
	printf("Selecciona una opción:\n
	1. Verificar si un carácter es mayúscula.\n
	2. Calcular el factorial de un número.\n
	3. Encontrar el máximo de dos números.\n
	4. Convertir de grados Celsius a Farenheit.\n
	5. Intercambiar dos números.\n
	6. Calcular la potencia de un número.\n
	7. Salir\n");
	printf("Opción: ");
	scanf("%d", &opcion);
	switch (opcion){ // Dependiendo del número que haya introducido el usuario voy a llamar a una función o a otra.
		case 1:
			printf("Introduce un carácter: ");
			scanf(" %c", &letra);
			int es_mayuscula(char letra);
			break;
		case 2:
			void calcular_factorial();
			break;
		case 3:
			int encontrar_maximo(int num1, int num2);
			break;
		case 4:
			double convertir_celsius_a_farenheit(double celsius);
			break;
		case 5:
			void intercambiar_numeros();
			break;
		case 6:
			double calcular_potencia(double base , int exponente);
			break;
		case 7:
			break;
		default:
			printf("Introduce un número entre el 1 y el 7.\n");
			main();
	}	
	return EXIT_SUCCESS;
}
