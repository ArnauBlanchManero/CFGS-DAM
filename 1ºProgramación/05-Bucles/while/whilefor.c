#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

int main(){
	int i;
	for (/*valor inicial*/ i=0; /*condicion*/ i<5; /*codigo entre vueltas*/ i=i+1){
		printf("%d ", i);
	}
	printf("Terminé, finalizé, concluí, acabé\n");
	
	// Traducimos a while
	i=0;
	while(i<5){
		printf("%d ", i);
		i= i+1;
	}
	printf("Terminando el while\n");
	return EXIT_SUCCESS;
}
