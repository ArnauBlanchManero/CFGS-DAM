#include <stdio.h>
#include <stdlib.h>

int main(){
  int num;
  printf("Introduce un número: ");
  scanf("%d", &num);
  if (num % 2 == 0){
    printf("El número %d es par\n", num);
  } else {
    printf("El número %d es impar\n", num);
  }
  return 0;
}
