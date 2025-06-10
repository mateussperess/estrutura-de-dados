#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int shuffle(int vetor[], int tamanho);

int main()
{
  int vetor[] = {1, 2, 3, 4, 5};

  srand(time(NULL));

  shuffle(vetor, 5);
  return 0;
}

int shuffle(int vetor[], int tamanho)
{
  int aux;

  for (int i = tamanho - 1; i >= 0; i--)
  {
    aux = rand() % ((tamanho + 1) - 1);
    printf("%i ", vetor[aux]);
  }
}