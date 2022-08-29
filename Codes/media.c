#include <stdio.h>
#include <stdlib.h>

int main(void) {
  float notas, notaN, media;
  int c;
  
  c=1;
  notas = 0;
  
  while (c <=4){
    printf("Nota %d: ", c);
    scanf("%f", &notaN);
    
    notas += (notaN * c);
    c++;
  }

  media= notas/10;

  printf("A media do aluno eh %.1f", media);

  
  return 0;
}