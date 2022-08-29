#include <stdio.h>

int main(void) {
  int base, altura;
  float area;

  printf("Digite o valor da base: ");
  scanf("%d", &base);
  printf("Digite o valor da altura:  ");
  scanf("%d", &altura);

  area= (base * altura)/2;

  printf("O valor da area eh %f m2", area);

  
  return 0;
}