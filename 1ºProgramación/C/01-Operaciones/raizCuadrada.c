#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	double raiz;
	int valor;
	
	double radio, area;

	printf("Introduzca un número para calcular su raíz ");
	scanf("%d", &valor);
	raiz = sqrt(valor);
	printf("La raíz cuadrada de %d es %lf\n", valor, raiz);

	printf("Introduzca el radio del círculo para calcular su área ");
	scanf("%lf", &radio);
	area = radio * radio * M_PI;
	printf("El área del círculo es %lf\n", area);
	return 0;
}
