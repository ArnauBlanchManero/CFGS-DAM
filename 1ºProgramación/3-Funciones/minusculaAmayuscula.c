#include <stdio.h>
#include <stdlib.h>

/*
 * 	Proyecto creado por Arnau Blanch
 */

char capitalizar(char letra_minuscula){
	char letra_mayuscula;

	// Le vamos a restar 32 a letra_minuscula porque en la tabla ASCII el número de cada letra minúscula es 32 veces posterior a su letra mayúscula.
	letra_mayuscula = letra_minuscula - 32;
	return letra_mayuscula;
}

int main(){
	
	// Creamos la función que guardará la letra que el usuario escriba.
	char letra_minuscula;
	printf("La letra que me proporciones, la convertiré en mayúscula. ");
	scanf("%c", &letra_minuscula);
	
	// Guardamos el resultado de capitalizar la letra en esta variable.
	char letra_mayuscula = capitalizar(letra_minuscula);

	// Lo imprimimos por pantalla.
	printf("Tu letra en mayúscula es... %c\n", letra_mayuscula);

	return 0;
}
