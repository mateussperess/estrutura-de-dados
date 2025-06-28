#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa
{
  char nome[20];
  int idade;
} Pessoa;

typedef struct elemento
{
  struct elemento *proximo;
  Pessoa pessoa;
} Elemento;

typedef struct pilha
{
  Elemento *topo;
  int tamanho;
} Pilha;

Pilha *criar_pilha();
int imprimir_pilha(Pilha *pilha);
int push(Pilha *pilha, Pessoa pessoa);
int pop(Pilha *pilha);
Pessoa *peek(Pilha *pilha);
void liberar_pilha(Pilha *pilha);

int main()
{
  Pilha *pilha = criar_pilha();

  Pessoa p1 = {"Mateus", 20};
  Pessoa p2 = {"Jereias", 20};
  Pessoa p3 = {"Renan", 20};
  push(pilha, p1);
  push(pilha, p2);
  push(pilha, p3);

  imprimir_pilha(pilha);
  pop(pilha);
  pop(pilha);
  pop(pilha);

  Pessoa *pessoa_topo = peek(pilha);
  printf("Topo da fila: %s\n", pessoa_topo->nome);
  return 0;
}

Pilha *criar_pilha()
{
  Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));

  if (pilha == NULL)
  {
    printf("Erro ao alocar memoria para pilha. \n");
    return NULL;
  }

  pilha->topo = NULL;
  pilha->tamanho = 0;

  return pilha;
}

int imprimir_pilha(Pilha *pilha)
{
  if (pilha == NULL || pilha->tamanho == 0)
    return -1;

  Elemento *atual = pilha->topo;

  while (atual != NULL)
  {
    printf("Nome: %s | idade: %i \n", atual->pessoa.nome, atual->pessoa.idade);
    atual = atual->proximo;
  }

  return 1;
}

int push(Pilha *pilha, Pessoa pessoa)
{
  if (pilha == NULL)
    return -1;

  Elemento *elemento = (Elemento *)malloc(sizeof(Elemento));
  if (elemento == NULL)
    return -1;

  elemento->pessoa = pessoa;
  elemento->proximo = pilha->topo;
  pilha->topo = elemento;
  pilha->tamanho++;
  return 1;
}

int pop(Pilha *pilha)
{
  if (pilha == NULL)
    return -1;

  Elemento *remover = pilha->topo;
  pilha->topo = remover->proximo;
  pilha->tamanho--;
  free(remover);
  return 1;
}

Pessoa *peek(Pilha *pilha)
{
  if (pilha == NULL || pilha->tamanho == 0)
    return NULL;

  Elemento *first = pilha->topo;
  return &pilha->topo->pessoa;
}

void liberar_pilha(Pilha *pilha)
{

  if (pilha == NULL)
  {
    printf("A pilha nao existe! \n");
    return;
  }

  Elemento *atual = pilha->topo;

  while (atual != NULL)
  {
    pop(pilha);
  }

  free(pilha);
  pilha = NULL;
}