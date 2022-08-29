#include <stdio.h>

int main(void) {
  int cedulas[7]= {100, 50, 20, 10, 5, 2, 1};
  int valor,nota;

  printf("Digite o valor: ");
  scanf("%d", &valor);

  while(valor!=0){
    for(int i=0; i<=7; i++){
      nota= valor/cedulas[i];
      valor %= cedulas[i];

    if(nota != 0){
      printf("%d notas de %d\n", nota, cedulas[i]);
    }
   }
  }
  
  return 0;
}