#include <stdio.h>
#include <stdlib.h>

int main(){
	int num;
	scanf("%d", &num);
	(num % 2 == 0) ? printf("El número %d es par.\n", num) : printf("El número %d es impar.\n", num);
	return 0;
}
