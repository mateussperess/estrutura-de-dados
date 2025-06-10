#include <stdio.h>

int lerVetor(int vetor[], int tamanho);
void printarVetor(int vetor[], int tamanho);
int r_sort(int vetor[], int tamanho);

int main()
{
  int tamanho;

  printf("Informe a quantidade de elementos: ");
  scanf("%i", &tamanho);

  int vetor[tamanho];

  lerVetor(vetor, tamanho);

  printf("Vetor criado... \n");
  printarVetor(vetor, tamanho);

  printf("Reorganizando vetor... \n");
  r_sort(vetor, tamanho);
  printarVetor(vetor, tamanho);

  return 0;
}

int lerVetor(int vetor[], int tamanho)
{
  for (int i = 0; i < tamanho; i++)
  {
    printf("Vetor[%i]: ", i);
    scanf(" %i", &vetor[i]);
  }
}

void printarVetor(int vetor[], int tamanho)
{
  printf("[ ");

  for (int i = 0; i < tamanho; i++)
  {
    printf("%i", vetor[i]);
    if (i != (tamanho - 1))
    {
      printf(", ");
    }
  }

  printf(" ] \n");
}

int r_sort(int vetor[], int tamanho)
{
  if (tamanho == 1)
  {
    return 1;
  }

  for (int i = 0; i < (tamanho - 1); i++)
  {
    if (vetor[i] > vetor[i + 1])
    {
      int temp = vetor[i];
      vetor[i] = vetor[i + 1];
      vetor[i + 1] = temp;
    }
  }

  return r_sort(vetor, (tamanho - 1));
}
