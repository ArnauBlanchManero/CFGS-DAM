#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

int main(){
	int numeros[5] = {10, 20, 30, 40, 50};
	int *p = numeros+5;
	// Otra opción es p = &numeros[5] pero estarías accediendo a la sexta posición y puede que sea espacio protegido.
	for(int i = 5; i>0; i--){
		printf("Elemento %d: %d\n", i, *(p-i));
	}
	return EXIT_SUCCESS;
}
