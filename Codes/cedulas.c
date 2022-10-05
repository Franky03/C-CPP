#include <stdio.h>

int main(void) {
  int cedulas[6]= {100, 50, 20, 10, 5, 2};
  float moedas[6]= {1.0, 0.50, 0.25, 0.10, 0.05, 0.01};
  double valor;
  int nota, moeda;

  printf("Digite o valor: ");
  scanf("%lf", &valor);

  while(valor>=0.01)
  {
    if(valor>0){
      for(int i=0; i<=5; i++)
      {
        nota= (int) valor/cedulas[i];
        valor -= (cedulas[i] * nota);
      
        if(nota != 0)
        {
          printf("%d notas de %d\n", nota, cedulas[i]);
        }
      } 
    }
    
    for(int j=0; j<=5; j++)
    {
      moeda= (int) (valor/moedas[j]);
      valor -= ((moedas[j] * moeda));

      if(valor<0.5)
      {
        valor += 0.00000999999;
      }
      if(moeda != 0)
      {
        printf("%d moeda de %.2f\n", moeda, moedas[j]);
      }
   }
  }
  return 0;
}