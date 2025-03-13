#include <stdio.h>
#include <stdlib.h>

int main(){
	int num;
	scanf("%d", &num);
	if (num > 0){
		printf("El número %d es positivo.\n", num);
	}else if (num < 0){
		printf("El número %d es negativo.\n", num);
	}else if (num == 0){
		printf("El número ingresado es cero.\n");
	}
	return 0;
}
