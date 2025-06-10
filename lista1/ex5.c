#include <stdio.h>

int lerVetor(int vetor[], int tamanho);
int printarVetorEx1(int vetor[], int tamanho, int ordem);
void sort(int vetor[], int tamanho);
void printarVetor(int vetor[], int tamanho);
int r_sort(int vetor[], int tamanho);

int main()
{
  int alunos;
  printf("Informe a quantidade de alunos: ");
  scanf("%i", &alunos);

  int vetorAlunos[alunos];
  lerVetor(vetorAlunos, alunos);

  int ordem = 1;
  printf("a) \n");
  printarVetorEx1(vetorAlunos, alunos, ordem);
  
  printf("\n");
  
  printf("b) \n");
  sort(vetorAlunos, alunos);
  printarVetor(vetorAlunos, alunos);
  
  printf("\n");
  printf("c) \n");
  ordem = -1;
  printarVetorEx1(vetorAlunos, alunos, ordem);
  
  printf("d) \n");
  r_sort(vetorAlunos, alunos);
  printarVetor(vetorAlunos, alunos);
}

int lerVetor(int vetor[], int tamanho)
{
  for (int i = 0; i < tamanho; i++)
  {
    printf("Vetor[%i]: ", i);
    scanf(" %i", &vetor[i]);
  }
}

int printarVetorEx1(int vetor[], int tamanho, int ordem)
{
  if (ordem > 0)
  {
    for (int i = 0; i < tamanho; i++)
    {
      printf("%i ", vetor[i]);
    }
  }
  else if (ordem < 0)
  {
    for (int i = tamanho - 1; i >= 0; i--)
    {
      printf("%i ", vetor[i]);
    }
  }
}

void sort(int vetor[], int tamanho)
{
  for (int i = 0; i < (tamanho - 1); i++)
  {
    int trocou = 0;

    for (int j = 0; j < (tamanho - i - 1); j++)
    {
      if (vetor[j] > vetor[j + 1])
      {
        int temp = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = temp;
        trocou = 1;
      }
    }

    if (trocou = 0)
    {
      break;
    }
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