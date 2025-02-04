#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

int main(){
	int num1;
	int num2 = 0;
	printf("Escribe un número y yo le daré la vuelta: ");
	scanf("%d", &num1);
	int inicial = num1;

	while(num1 != 0){
		num2 = (num2 * 10) + (num1 % 10);
		num1 = num1 / 10;
	}

	printf("El número %d al revés es %d\n", inicial, num2);
	return EXIT_SUCCESS;
}
