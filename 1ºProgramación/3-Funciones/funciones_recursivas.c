#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*
 * 	Autor: Arnau Blanch
 */
//int main();

int es_mayuscula(char letra){
	if (letra > 64 && letra < 91){ // Si el caracter se encuentra entre esos números significa que es mayúscula porque en la tabla ASCII las letras mayúsculas están comprendidas entre el 64 y el 91.
		return 1; // Devuelve true
	} else {
		return 0; // Devuelve false
	}
}

int multiplica(int num){ // Esta función es necesaria para calcular el factorial de un número
	if (num == 1){
		return 1;
	} else {
		return num *= multiplica(num-1); // Irá multiplicando los números hasta llegar a 1
	}
}

void calcular_factorial(){
	int numero, factorial;
	printf("Introduce un número entero positivo: ");
	scanf("%d", &numero);
	factorial = multiplica(numero);
	printf("El factorial de %d es %d\n", numero, factorial);
}

int encontrar_maximo(int num1, int num2){
	if(num1 >= num2){
		return num1;
	} else if (num2 >= num1){
		return num2;
	} else {
		printf("Error en la función encontrar_máximo\n");
	}
}

double convertir_celsius_a_farenheit(double celsius){
	return celsius * 1.8 + 32;
}

void intercambiar_numeros(){
	int num1, num2, respaldo;
	printf("Introduce el primer número: ");
	scanf("%d", &num1);
	printf("Introduce el segundo número: ");
	scanf("%d", &num2);	
	respaldo = num1;
	num1 = num2;
	num2 = respaldo;
	printf("Después de intercambiar, el primer número es %d, el segundo número es %d\n", num1, num2);
}

double calcular_potencia(double base , int exponente){
	if(exponente == 0){
		return 1;
	} else {
	exponente--;
	return base *= calcular_potencia(base, exponente);
	}
}

int main(){
	int opcion;
	char letra; //Para el caso 1
	int num1, num2; // Para el caso 3
	double celsius, farenheit; // Para el caso 4
	double base; int exponente; // Para el caso 6
	// Para mostrar el menú de inicio
	printf("Selecciona una opción:\n	1. Verificar si un carácter es mayúscula.\n	2. Calcular el factorial de un número.\n	3. Encontrar el máximo de dos números.\n	4. Convertir de grados Celsius a Farenheit.\n	5. Intercambiar dos números.\n	6. Calcular la potencia de un número.\n	7. Salir\n");
	printf("Opción: ");
	scanf("%d", &opcion);
	switch (opcion){ // Dependiendo del número que haya introducido el usuario voy a llamar a una función o a otra.
		case 1:
			printf("Introduce un carácter: ");
			scanf(" %c", &letra);
			if (es_mayuscula(letra)){
				printf("El carácter %c es mayúscula.\n", letra);
			} else {	
				printf("El carácter %c no es mayúscula.\n", letra);
			}
			break;
		case 2:
			calcular_factorial();
			break;
		case 3:
			printf("Introduce un número: ");
			scanf("%d", &num1);
			printf("Introduce otro número: ");
			scanf("%d", &num2);
			int max = encontrar_maximo(num1, num2);
			printf("El máximo entre %d y %d es %d\n", num1, num2, max);
			break;
		case 4:
			printf("Introduce la temperatura en Celsius: ");
			scanf("%lf", &celsius);
			farenheit = convertir_celsius_a_farenheit(celsius);
			printf("La temperatura en Farenheit es %.1f\n", farenheit);
			break;
		case 5:
			intercambiar_numeros();
			break;
		case 6:
			printf("Introduce la base: ");
			scanf("%lf", &base);
			printf("Introduce el exponente: ");
			scanf("%d", &exponente);
			double resultado = calcular_potencia(base, exponente);
			printf("%.1lf elevado a la %d es %.1lf\n", base, exponente, resultado);
			break;
		case 7:
			break;
		default:
			printf("Introduce un número entre el 1 y el 7.\n");
			main();
	}	
	return EXIT_SUCCESS;
}
