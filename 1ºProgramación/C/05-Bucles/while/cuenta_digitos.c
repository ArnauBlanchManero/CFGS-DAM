#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

int main(){
	int num1;
	int contador = 0;
	printf("Escribe un número y yo le daré cuántos dígitos tiene: ");
	scanf("%d", &num1);
	int inicial = num1;

	do{
		num1 = num1 / 10;
		contador ++;
	} while(num1 != 0);

	printf("El número %d tiene %d cifras\n", inicial, contador);
	return EXIT_SUCCESS;
}
