#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elemento
{
  char nome[20];
  struct elemento* proximo;
} Elemento;

typedef struct lista
{
  Elemento* inicio;
} Lista;

Lista* criar_lista();
int lista_vazia(Lista* lista);
int inserir_pessoa_inicio(char nome[20], Lista* lista);
void imprimir_lista(Lista* lista);
int inserir_pessoa_fim(char nome[20], Lista* lista);
int buscar(char nome[20], Lista* lista);

int main() {
  Lista* lista = criar_lista();
  int lista_vazia_var = lista_vazia(lista);

  char nome1[20] = "Mateus", nome2[20] = "Ana Laura", nome3[20] = "Jeremias", nome4[20] = "Regis";

  inserir_pessoa_inicio(nome1, lista);
  inserir_pessoa_inicio(nome2, lista);

  inserir_pessoa_fim(nome3, lista);
  inserir_pessoa_fim(nome4, lista);

  imprimir_lista(lista);

  printf("\n");
  buscar("Mateus", lista);
  return 0;
}

Lista* criar_lista() {
  Lista* lista = malloc(sizeof(Lista));
  if(lista != NULL) lista->inicio = NULL;
  return lista;
}

int lista_vazia(Lista* lista) {
  if(lista->inicio == NULL) return 0;
  return 1;
}

int inserir_pessoa_inicio(char nome[20], Lista* lista) {
  if(lista == NULL) return -1;
  if(nome == NULL) return -1;

  Elemento* elemento = malloc(sizeof(Elemento));
  if(elemento == NULL) return -1;

  strcpy(elemento->nome, nome); // strcpy copia a string da direita para a variável da esquerda
  elemento->proximo = lista->inicio;
  lista->inicio = elemento;

  return 1;
}

void imprimir_lista(Lista* lista) {
  if(lista == NULL) return;

  printf("Lista: \n");

  Elemento* atual = lista->inicio;

  while (atual != NULL)
  {
    printf("%s \n", atual->nome);
    atual = atual->proximo;
  }
}

int inserir_pessoa_fim(char nome[20], Lista* lista) {
  if(lista == NULL) return -1;
  if(nome == NULL) return -1;

  Elemento* elemento =lista->inicio;
  Elemento* ultimo_elemento = malloc(sizeof(Elemento));

  if (elemento == NULL) return -1;
  if (ultimo_elemento == NULL) return -1;

  while (elemento->proximo != NULL)
  {
    elemento = elemento->proximo;
    
    if (elemento->proximo == NULL) // chegou no ultimo -> sai do laço
    {
      break;
    }
  }

  elemento->proximo = ultimo_elemento;
  strcpy(ultimo_elemento->nome, nome); 
  ultimo_elemento->proximo = NULL;

  return 1;
}

int buscar(char nome[20], Lista* lista) {
  if(lista == NULL) return -1;
  if(nome == NULL) return -1;
  if(lista_vazia(lista) == 0) return -1;

  Elemento* atual = lista->inicio;

  while (atual != NULL)
  {
    if (strcmp(nome, atual->nome) == 0)
    {
      printf("Encontrou %s! \n", atual->nome);
      return 1;
    } 

    atual = atual->proximo;
  }
  
  return -1;
}