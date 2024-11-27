#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

int main(){
	
	const int LIMITE = 100; // Definir una constante
	printf("El valor de LIMITE es: %d\n", LIMITE);
//	LIMITE = 200; // Esto daría error poruqe LIMITE es constante
	
	const int cambia = 10;
//	int * trampa = &cambia; // Esta asignación asigna un warning
//	*trampa = 20;
	printf("El valor de cambia es: %d\n", cambia);
	
	int num = 1;
	const int* ptr = &num;
	printf("Valor: %d\n", *ptr);
//	*ptr = 2; // Esto daría error poruqe el contenido del puntero es constante.
	num = 2;
	printf("Nuevo valor: %d\n", *ptr);
	int trampa2 = 3;
	ptr = &trampa2;
	printf("Nuevo valor2 %d\n", *ptr);

	int numero = 10;
	int* const p = &numero;
	printf("Valor: %d\n", *p);
	*p = 20;
	numero = 30;
	printf("Nuevo valor: %d\n", *p);
	int trampa3 = 40;
//	p = &trampa3; // Esto daría error poruqe el contenido del puntero es constante.
	printf("Nuevo valor2 %d\n", *p);
	return EXIT_SUCCESS;
}
