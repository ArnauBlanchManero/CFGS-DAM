#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

int main(){
	int x = 10;
	int *p; // Esta variable es de tipo "int *", es decir, puntero a entero.
		// Esto quiere decir que va a almacenar la dirección de memoria de una variable de tipo entero.
	p = &x;
	printf("Valor de x: %d\n", x); // 10
	printf("Dirección de x: %p\n", &x);  
	printf("Valor de p: %p\n", p);
	printf("Dirección de p: %p\n", &p);
	// El * se usa para decir que hay en la direccion de memoria de la variable
	// El & se usa para decir en que direccion de memoria está guardada la variable
	return EXIT_SUCCESS;
}
