#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct pessoa {
  char nome[20];
  int idade;
} Pessoa;

typedef struct fila {
  int inicio;
  int fim;
  int tamanho;
  Pessoa dados[MAX];
} Fila;

Fila* criar_fila();
int fila_vazia(Fila* fila);
int fila_cheia(Fila* fila);
int enfileirar(Fila* fila, Pessoa pessoa);
void imprimir(Fila* fila);
int desenfileirar(Fila* fila);

int main() {
  Fila* fila = criar_fila();
  Pessoa p1 = {"Mateus", 20};
  Pessoa p2 = {"Ana", 18};
  Pessoa p3 = {"Jeremias", 20};
  Pessoa p4 = {"Kamily", 18};
  Pessoa p5 = {"Juca", 25};

  enfileirar(fila, p1);
  enfileirar(fila, p2);
  enfileirar(fila, p3);
  enfileirar(fila, p4);
  enfileirar(fila, p5);

  imprimir(fila);

  desenfileirar(fila);
  desenfileirar(fila);
  desenfileirar(fila);
  desenfileirar(fila);
  desenfileirar(fila);

  imprimir(fila);
  return 0;
}

Fila* criar_fila() {
  Fila* fila = (Fila*) malloc(sizeof(Fila));
  if(fila == NULL) return NULL;

  fila->inicio = 0;
  fila->fim = 0;
  fila->tamanho = 0;

  return fila;
}

int fila_vazia(Fila* fila) {
  if(fila == NULL) return -1;
  if(fila->tamanho == 0) return 1;
  return 0;
}

int fila_cheia(Fila* fila) {
  if(fila == NULL) return -1;
  if(fila->tamanho == MAX) return 1;
  return 0;
}

int enfileirar(Fila* fila, Pessoa pessoa) {
  if(fila == NULL) return -1;

  if(fila_cheia(fila) != 1) {
    fila->dados[fila->fim] = pessoa;
    fila->fim = (fila->fim + 1) % MAX;
    fila->tamanho++;
    // printf("Novo inicio: %i\n", fila->inicio);
    return 1;
  }

  return 0;
}

void imprimir(Fila* fila) {
  if(fila == NULL) return;

  if(fila_vazia(fila) != 1) {
    printf("\n====== Fila ======\n");
    int index = fila->inicio;
    for (int j = 0; j < fila->tamanho; j++)
    {
      printf("%s, ", fila->dados[index].nome);
      index = (index + 1) % MAX;
    } 
  } else {
    printf("\nA fila esta vazia! \n");
  }
}

int desenfileirar(Fila* fila) {
  if(fila == NULL) return -1;

  if(fila_vazia(fila) != 1) {
    Pessoa pessoa_removida = {"", 0};
    fila->dados[fila->inicio] = pessoa_removida;
    fila->inicio = (fila->inicio + 1) % MAX;
    fila->tamanho--;
    return 1;
  }

  return 0;
}