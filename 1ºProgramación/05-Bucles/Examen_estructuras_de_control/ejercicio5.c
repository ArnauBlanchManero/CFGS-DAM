#include <stdio.h>
#include <stdlib.h>

int main(){
	int num = 0;
	int suma = 0;
	while(num >= 0){
		suma += num;
		scanf("%d", &num);
	}
	printf("La suma de los números ingresados es %d.\n", suma);
	return 0;
}
