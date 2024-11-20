#include <stdio.h>
#include <stdlib.h>

int main(){
	int numero;
	do{
		scanf("%d", &numero);
		if(numero > 10 || numero < 1)
			printf("Número no válido.\n");
	} while (numero > 10 || numero < 1);
	printf("Has ingresado el número %d.\n", numero);
	return 0;
}
