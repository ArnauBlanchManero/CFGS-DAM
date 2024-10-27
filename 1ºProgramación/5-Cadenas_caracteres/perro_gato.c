#include <stdio.h>
#include <stdlib.h>

int main(){
	int eleccion;
	int barra = 92;
	int comillas = 34;
	printf("Qué quieres que dibuje?\n1- Perro\n2- Gato\n(escribe 1 o 2): ");
	scanf("%d", &eleccion);
	if (eleccion == 1){
		printf("Voy a dibujar un perro\n");      
		printf("   ___\n");      
		printf(" __/_  `.  .-%c%c%c-.\n", comillas, comillas, comillas);      
		printf(" %c_,` | %c-'  /   )`-'\n", barra, barra);      
		printf("  %c%c) `%c`    %c  ((`%c`\n", comillas, comillas, comillas, barra, comillas);      
		printf(" ___Y  ,    .'7 /|\n");      
		printf("(_,_-_/...-` (_/_/\n");      
	} else if (eleccion == 2){
		printf("Voy a dibujar un gato\n");
		printf("_._     _,-'%c%c`-._\n", comillas, comillas);      
		printf("(,-._,'(         |%c`-/|\n", barra);      
		printf("    `-.-' %c )-`( , o o)\n", barra);      
		printf("          `-    %c`_`%c'-\n", barra, comillas);      
	} else {
		main();
	}
	return 0;
}
