#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

int main(){
	int opcion;
	// No hace falta inicializarla 
	// porque el primer uso de la variable es de escritura.
	
	do{
		printf("Introduce un número (4 para salir): ");
		scanf("%d", &opcion);
	} while(opcion !=4);
	return EXIT_SUCCESS;
}
