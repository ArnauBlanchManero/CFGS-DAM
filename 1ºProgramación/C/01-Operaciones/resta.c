#include <stdio.h>
#include <stdlib.h>
int main () {
	float numero1 = 6;
	float numero2 = 4;
	int resta,multiplicación;
	float división;
	resta = numero1-numero2;
	multiplicación = numero1*numero2;
	división = numero1/numero2;
	printf("Resta=%d\n",resta);
	printf("Multiplicación=%d\n",multiplicación);
	printf("División=%f\n",división);
	return EXIT_SUCCESS;
}
