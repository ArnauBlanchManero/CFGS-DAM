#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

int main(){
	int i, j, lado;
	printf("Qué lado quieres que tenga el cuadrado? ");
	scanf("%d", &lado);
	for (i=1; i<=lado; i++){
		for (j=1; j<=lado; j++){
			printf("* ");
		}
		printf("\n");
	}
	return EXIT_SUCCESS;
}
