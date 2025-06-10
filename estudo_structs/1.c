#include <stdio.h>

typedef struct
{
  char nome[20];
  int ano;
  double km;
} Carro;

int main() {
  int quantidade;
  printf("Quantos carros deseja cadastrar? ");
  scanf("%i", &quantidade);

  Carro carros[quantidade];

  for (int i = 0; i < quantidade; i++)
  {
    Carro carro;
    printf("Informe o nome do carro: ");
    scanf("%s", &carro.nome);
    printf("Informe o ano do carro: ");
    scanf("%i", &carro.ano);
    printf("Informe a KM do carro: ");
    scanf("%d", &carro.km);

    carros[i] = carro;
  }

  printf("{ \n");
  for (int i = 0; i < quantidade; i++)
  {
    printf("  Nome do carro: %s \n", carros[i].nome);
    printf("  Ano do carro: %i \n", carros[i].ano);
    printf("  KM do carro: %d \n", carros[i].km);
    printf("  -------------------  \n ");
    if(i != (quantidade - 1)) {
      printf(", ");
    }
  }
  
  printf("} ");
  return 0;
}