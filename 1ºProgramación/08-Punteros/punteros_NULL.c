#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

int main(){
	int* dir;
	printf("Direccion de memoria: %p\n", dir);
	//printf("Contenido de dir: %d\n", *dir);
	int* null = NULL;
	printf("Direccion de memoria: %p\n", null);
	printf("Contenido de dir: %d\n", *null);
	
	return EXIT_SUCCESS;
}
