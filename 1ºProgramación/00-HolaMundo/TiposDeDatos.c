#include <stdio.h>
#include <stdlib.h>

int main(){
	double num;
	printf("Introduce un número entero o decimal: ");
	scanf("%lf", &num);
	printf("Has intrtoducido: %.15lf\n", num);
	char c;
	printf("Introduce un caracter: ");
	scanf(" %c", &c);
	printf("Has introducido: %c\n", c);
	char str[50]; //Ya guarda la dirección de memoria
	printf("Introduce una palabra: ");
	scanf(" %s", str); // No hace falta poner &
	printf("Has introducido la palabra: %s\n", str);
	return 0;
}
