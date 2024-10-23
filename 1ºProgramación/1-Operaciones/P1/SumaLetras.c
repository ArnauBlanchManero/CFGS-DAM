#include <stdio.h>
#include <stdlib.h>

int main(){
	int uno = 1;
	int dos = 2;
	int veintiocho = 28;
	char a = 'a';
	
	char resultadochar1 = uno + a;
	char resultadochar2 = dos + a;
	char resultadochar3 = veintiocho + a;


 	int resultadoint1 = uno + a;
 	int resultadoint2 = dos + a;
	int resultadoint3 = veintiocho + a;

	
	printf("Si los resultados son caracteres:\na + 1 = %c\na + 2 = %c\na + 28 = %c\nSi los resultados son enteros:\na + 1 = %d\na + 2 = %d\na + 28 = %d\n", resultadochar1, resultadochar2, resultadochar3, resultadoint1, resultadoint2, resultadoint3);


	

	return 0;
}
