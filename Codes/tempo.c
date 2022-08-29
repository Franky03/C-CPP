#include <stdio.h>

int main(void) {
  int segundos, minutos, horas;

  printf("Digite os segundos: ");
  scanf("%d", &segundos);

  minutos= segundos / 60;
  segundos%= 60;

  if(minutos>=60){
    horas= minutos / 60;
    minutos%= 60;
    printf("%d hora(s), ", horas);
  }

  if(minutos!=0){
    printf("%d minutos e ", minutos);
  }

  printf("%d segundos",segundos);

  return 0;
}