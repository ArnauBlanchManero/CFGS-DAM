#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
 * 	Autor: Arnau Blanch
 */

int main(){
	int r;
	srand(10); // Establece la semilla de generación de números aleatorios.
	srand(time(NULL)); // Coje como semilla el segundo en el que ejecutas el programa
	for  (int i = 0; i<5; i++){
		r = rand() % 11; // Hay que hacer mod 11 para que de numeros "aleatorios" entre 0 y 10 porque el resto de las divisiones serán 
		printf("%d\n", r); // Un ordenador no puede generar números aleatorios y tiene que seguir una secuencia de cálculo
	}
	return EXIT_SUCCESS;
}
