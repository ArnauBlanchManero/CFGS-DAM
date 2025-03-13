#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 	Autor: Arnau Blanch
 */

int calcular_profundidad(char * parentesis, int abiertos){
	static int max = 0;
	if (parentesis[0] == '\0'){
		int retval = max;
		max = 0;
		return retval;
	}
	if (parentesis[0] == '('){
		abiertos += 1;
	}else if (parentesis[0] == ')'){
		abiertos -= 1;
	}
	max = abiertos > max ? abiertos : max;
	return calcular_profundidad(parentesis+1, abiertos);
}

int main(){
	char parentesis[50];
	printf("Escribe una cadena de parentesis: ");
	scanf("%s", parentesis);
	int maxima_profundidad = calcular_profundidad(parentesis, 0);
	printf("Maxima profundidad: %d\n", maxima_profundidad);
	printf("Escribe una cadena de parentesis: ");
	scanf("%s", parentesis);
	int maxima_profundidad2 = calcular_profundidad(parentesis, 0);
	printf("Maxima profundidad: %d\n", maxima_profundidad2);
	return EXIT_SUCCESS;
}
