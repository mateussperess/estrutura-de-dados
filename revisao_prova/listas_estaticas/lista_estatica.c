#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

typedef struct
{
  int codigo;
  char nome[30];
  double preco;
} Produto;

typedef struct
{
  int tamanho;
  Produto *produtos[MAX];
} Lista;

Lista *criarLista();
Produto *criarProduto();
int inserirProduto(Lista* lista, Produto* produto, int index);
void imprimirLista(Lista* lista);
Produto* buscarProdutoPeloNome(Lista* lista, char nome[30]);
void liberarLista(Lista *lista);

int main()
{
  Lista *lista = criarLista();
  int qtdProdutos;

  if (lista != NULL)
  {
    printf("Informe a quantidade de produtos: ");
    scanf("%i", &qtdProdutos);

    if(qtdProdutos <= MAX) {
      for (int i = 0; i < qtdProdutos; i++)
      {
        Produto* produto = criarProduto();
  
        if (produto != NULL)
        {
          if(inserirProduto(lista, produto, i) == 1) {
            printf("Produto adicionado! \n");
          }
        }
      }
    } else {
      printf("ERRO! A quantidade de produtos inserida ultrapassa o limite maximo de produtos na lista. ");
    }

    char nomeProduto[30];
    printf("Informe o nome do produto para procurar: ");
    scanf("%s", nomeProduto);

    Produto* resultBusca = buscarProdutoPeloNome(lista, nomeProduto);
    
    if (resultBusca != NULL)
    {
      printf("Produto %s encontrado!\n", nomeProduto);
      printf("--- Dados do Produto --- \n");
      printf("Codigo do produto: %i \n", resultBusca->codigo);
      printf("Nome do produto: %s \n", resultBusca->nome);
      printf("Preco do produto: R$%.2lf \n", resultBusca->preco);
    }

    imprimirLista(lista);
  }

  liberarLista(lista);
  return 0;
}

Lista *criarLista()
{
  Lista *lista = (Lista *)malloc(sizeof(Lista));
  if (lista == NULL)
    return 0;
  else
    lista->tamanho = 0;
    return lista;
}

Produto *criarProduto()
{
  Produto *produto;
  produto = (Produto *)malloc(sizeof(Produto));
  if (produto == NULL)
    return NULL;

  printf("Informe o codigo do produto: ");
  scanf("%i", &produto->codigo);
  printf("Informe o nome do produto: ");
  scanf("%s", &produto->nome);
  printf("Informe o preco do produto: ");
  scanf("%lf", &produto->preco);

  return produto;
}

int inserirProduto(Lista* lista, Produto* produto, int index) {
  if(lista == NULL || produto == NULL) return -1;
  if(index < 0 || index >= MAX) return -1;

  lista->produtos[index] = produto;
  lista->tamanho++;

  return 1;
}

void imprimirLista(Lista* lista) {
  if (lista == NULL) return;

  printf("--- Lista de Produtos --- \n");
  for (int i = 0; i < lista->tamanho; i++)
  {
    printf("Codigo do produto: %i \n", lista->produtos[i]->codigo);
    printf("Nome do produto: %s \n", lista->produtos[i]->nome);
    printf("Preco do produto: %.2lf \n", lista->produtos[i]->preco);
    printf("----------------\n");
  }
}

void liberarLista(Lista *lista)
{
  if (lista == NULL)
    return;

  for (int i = 0; i < lista->tamanho; i++)
  {
    free(lista->produtos[i]);
  }

  free(lista);
}

Produto* buscarProdutoPeloNome(Lista* lista, char nome[30]) {
  if(lista == NULL || nome == NULL) return NULL;

  for (int i = 0; i < lista->tamanho; i++)
  {
    if(lista->produtos[i] != NULL) {
      if (strcmp(lista->produtos[i]->nome, nome) == 0)
      {
        return lista->produtos[i];
      }
    }
  }

  return NULL;
}
