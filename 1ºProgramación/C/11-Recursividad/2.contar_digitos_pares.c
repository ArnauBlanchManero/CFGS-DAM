#include <stdio.h>
#include <stdlib.h>

/*
	Escribe una función recursiva que, dado un número entero, cuente la cantidad de dígitos que son pares 
	(por ejemplo, en 2846 hay 3 dígitos pares: 2, 8, 4, el 6 también es par, total 4).
*/

int cuenta_digitos_pares(int n);
int esPar(int p);

int main(){
	int num;
	printf("Escribe un número: ");
	scanf("%d", &num);
	int recuento = cuenta_digitos_pares(num);
	printf("El número %d tiene %d dígitos pares\n", num, recuento);
	return 0;
}

int cuenta_digitos_pares(int n){
	if (n/10 <= 0){
		if (esPar(n)){
			return 1;
		}
		return 0;
	}
	int siguiente_n = n/10;
	int resto = n%10;
	if(esPar(resto)){
		return 1 + cuenta_digitos_pares(siguiente_n);
	}
	return cuenta_digitos_pares(siguiente_n);
}

int esPar(int p){
	if(p%2){
		return 0;
	}
	return 1;
}