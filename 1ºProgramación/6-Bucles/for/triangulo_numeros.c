#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

int main(){
	int i, j, num;
	printf("Hasta qué número quieres el triángulo? ");
	scanf("%d", &num);
	for (i=1; i<=num; i++){
		for (j=1; j<=i; j++){
			printf("%d ", j);
		}
		printf("\n");
	}
	return EXIT_SUCCESS;
}
