#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

int main(){
	int opcion = 0;
	// Es necesario (no obligatorio) inicializar la variable 
	// poruqe el primer uso de la variable es de lectura.
	while(opcion != 4){
		printf("Introduce un número (4 para salir): ");
		scanf("%d", &opcion);
	}
	return EXIT_SUCCESS;
}
