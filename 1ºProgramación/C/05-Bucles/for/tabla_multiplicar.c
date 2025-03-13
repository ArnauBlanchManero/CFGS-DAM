#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

int main(){
	int i;
	int mult=5;
	for (i=1; i<=10; i++){
		printf("%d * %d = %d\n", mult, i, mult*i);
	}
	return EXIT_SUCCESS;
}
