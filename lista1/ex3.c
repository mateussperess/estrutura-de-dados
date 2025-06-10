#include <stdio.h>

void sort(int vetor[], int tamanho);

int main()
{
  int tamanho;
  printf("Insira os valores para o vetor: \n");
  scanf("%i", &tamanho);

  int vetor[tamanho];

  for (int i = 0; i < tamanho; i++)
  {
    printf("vetor[%i]: ", i);
    scanf("%i", &vetor[i]);
  }

  sort(vetor, tamanho);

  printf("Vetor ordenado: ");
  for (int i = 0; i < tamanho; i++)
  {
    printf("%i ", vetor[i]);
  }
  return 0;
}

void sort(int vetor[], int tamanho) // tamanho = 5
{
  for (int i = 0; i < (tamanho - 1); i++)
  {
    {
      int trocou = 0;

      for (int j = 0; j < (tamanho - i - 1); j++) // (5 - 0(i) - 1) = 4
      {
        if (vetor[j] > vetor[j + 1])
        {
          int temp = vetor[j];     
          vetor[j] = vetor[j + 1]; 
          vetor[j + 1] = temp;     
          trocou = 1; // flag
          
          //? exemplificando a logica 
          // vetor = [5, 3, 8, 4, 2]
          // j = 0
          // int temp = vetor[0];  // temp = 5 -> armazena-se o valor de vetor[i] para que ele nao seja perdido
          // vetor[0] = vetor[1];  // vetor[0] = 3 -> (5 vira 3)
          // vetor[1] = temp;      // vetor[1] = 5 -> (3 vira 5)
          // vetor = [3, 5, 8, 4, 2] -> e depois repete, incrementando o indice
        }
      }

      if (trocou == 0)
      {
        break;
      }
    }
  }
}

