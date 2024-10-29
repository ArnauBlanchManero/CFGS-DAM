#include <stdio.h>
#include <stdlib.h>

int main(){
  int num;
  printf("Introduce un número");
  scanf("%d", &num);
  if (num % 2 == 0){
    printf("El número %d es par", num);
  } else {
    prinf("El número %d es impar", num);
  }
  return 0;
}
