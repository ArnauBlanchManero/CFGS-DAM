#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

int main(){
	int i = 10;
	do{
		printf("%d ", i);
		i--;
	} while (i != 0);
	printf("\n");
	return EXIT_SUCCESS;
}
