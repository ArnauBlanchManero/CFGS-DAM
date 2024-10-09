#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * 	Autor: Arnau Blanch
 */

int calcularRaiz(){
	int valor;
	double raiz;

	printf("Introduzca un número para calcular su raíz: ");
	scanf("%d", &valor);
	raiz = sqrt(valor);
	printf("La raíz cuadrada de %d es %lf\n", valor, raiz);

}

int calcularArea(){
	double radio, area;

	printf("Introduzca el radio del círculo para calcular su área ");
	scanf("%lf", &radio);
	area = radio * radio * M_PI;
	printf("El área del círculo es %lf\n", area);
}

int main(){
	
	calcularRaiz();
	calcularRaiz();
	calcularRaiz();

	calcularArea();
	calcularArea();
	calcularArea();

	return 0;
}

