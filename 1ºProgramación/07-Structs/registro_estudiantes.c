#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

struct estudiante{
	char nombre[50];
	int edad;
	float promedio;
};

int main(){
	struct estudiante persona; // Tego que definir el nombre del struct y luego el nombre de la variable
	printf("Introduce el nombre del estudiante: ");
	scanf(" %s", persona.nombre);
	printf("Introduce la edad del estudiante: ");
	scanf("%d", &persona.edad);
	printf("Introduce la nota promedio del estudiante: ");
	scanf("%f", &persona.promedio);
	printf("El estudiante %s con %d años tiene %.2f de nota media.\n", persona.nombre, persona.edad, persona.promedio);
	return EXIT_SUCCESS;
}
