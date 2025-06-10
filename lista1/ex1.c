#include <stdio.h>

int print(int vetor[], int tamanho, int ordem);

int main() {

  int vetor[] = {1, 2, 3, 4, 5};
  int ordem = -1;

  print(vetor, 5, ordem);
  return 0;
}

int print(int vetor[], int tamanho, int ordem) {
  if(ordem > 0) 
  {
    for(int i = 0; i < tamanho; i++) 
    {
      printf("%i ", vetor[i]);
    }
  } else if(ordem < 0) {
    for(int i = tamanho - 1; i >= 0; i--)
    {
      printf("%i ", vetor[i]);
    }
  }
}
