#include <stdio.h>
#include <stdlib.h>

typedef struct No{
  int valor;
  struct No* proximo;
} No;

typedef struct Lista{
  No* inicio;      
  int tamanho;
} Lista;

Lista* criar_lista();
int lista_vazia(Lista* lista);
int inserir_no_inicio(int valor, Lista* lista);

int inserir_ordem_asc(int valor, Lista* lista);

void imprimir(Lista* lista);

int main() {
  Lista* lista = criar_lista();
  // inserir_no_inicio(10, lista);
  inserir_ordem_asc(30, lista);
  inserir_ordem_asc(20, lista);
  inserir_ordem_asc(10, lista);
  imprimir(lista);


  // lista_vazia(lista);
  return 0;
}

Lista* criar_lista() {
  Lista* lista;
  lista = (Lista*) malloc(sizeof(Lista));

  if (lista)
  {
    printf("\nLista criada!");
    lista->inicio = NULL;
  }
  
  return lista;
}

int lista_vazia(Lista* lista) {
  if(lista == NULL) return -1;

  if(lista->inicio == NULL) {
    printf("\nLista vazia!");
    return 1;
  }

  return 0;
}

int inserir_no_inicio(int valor, Lista* lista) {
  if(lista == NULL) return -1;

  No* no = (No*) malloc(sizeof(No));
  if(!no) return 1;

  no->valor = valor;

  no->proximo = lista->inicio;

  lista->inicio = no;
  printf("Valor %i inserido no inicio da lista!", no->valor);
  return 1;
}

int inserir_ordem_asc(int valor, Lista* lista) {
  if(lista == NULL) return -1;

  No* elemento = (No*) malloc(sizeof(No));
  if(!elemento) return -1;

  if(lista_vazia(lista)) {
    elemento->valor = valor;
    elemento->proximo = NULL;
    lista->inicio = elemento;
    return 1;   
  } 

  No* no_atual;

  if(valor < lista->inicio->valor) {
    elemento->valor = valor;
    elemento->proximo = lista->inicio;
    lista->inicio = elemento;
  } else {
    No* elemento_anterior = NULL;
    No* elemento_atual = lista->inicio;

    while (elemento_atual != NULL && elemento_atual->valor < valor)
    {
      elemento_anterior = elemento_atual;
      elemento_atual = elemento_atual->proximo;
    }

    elemento->valor = valor;
    elemento->proximo = elemento_atual;
    elemento_anterior->proximo = elemento;
  }

  return 1;
}

void imprimir(Lista* lista) {
  if (lista == NULL) {
    return;
  }

  printf("\nLista: ");

  No* atual = lista->inicio;

  while (atual != NULL) {
    printf("%d ", atual->valor);
    atual = atual->proximo;
  }

  printf("\n");
}