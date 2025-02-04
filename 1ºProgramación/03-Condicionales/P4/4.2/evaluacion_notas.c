#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

int main(){
	int nota;

	printf("Introduce la calificación: ");
	scanf("%d", &nota);

	printf("Resultado: ");
	(nota >= 5) ? printf("Aprobado\n") : printf("Suspendido\n");	
	return EXIT_SUCCESS;
}
