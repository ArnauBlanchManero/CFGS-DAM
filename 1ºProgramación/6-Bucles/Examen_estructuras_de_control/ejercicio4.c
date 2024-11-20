#include <stdio.h>
#include <stdlib.h>

int main(){
	int suma = 0;
	int n;
	scanf("%d", &n);
	for(int i = 0; i <= n; i++){
		suma += i;
	}
	printf("La suma de los primeros %d números es %d.\n", n, suma);
	return 0;
}
