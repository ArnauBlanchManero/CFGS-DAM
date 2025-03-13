#include <stdio.h>
#include <stdlib.h>

int main(){
	int * m = (int *) malloc(sizeof(int)*5);
	int * c = (int *) calloc(5,sizeof(int));
	printf("Lo que hay en malloc:\n");
	for(int i = 0; i < 5; i++){
		printf("%d - %d\n", i, m[i]);
	}
	printf("Lo que hay en calloc:\n");
	for(int i = 0; i < 5; i++){
		printf("%d - %d\n", i, c[i]);
	}
	free(m); // ¡QUE NO SE TE OLVINEN LOS FREE!
	free(c);
	printf("FIN\n");
	return 0;
}