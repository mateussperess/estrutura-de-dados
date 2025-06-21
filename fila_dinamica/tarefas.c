#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tarefa
{
  char titulo[30];
  int duracao;
} Tarefa;

typedef struct elemento
{
  Tarefa tarefa;
  struct elemento *proximo;
} Elemento;

typedef struct fila
{
  Elemento *inicio;
  Elemento *fim;
  int tamanho;
} Fila;

Fila *criar_fila();
Tarefa criar_tarefa();
int enfileirar(Fila *fila, Tarefa tarefa);
int executar_proxima_tarefa(Fila *fila);
void consultar_proxima_tarefa(Fila *fila);
void estimar_tempo(Fila* fila);
void listar_tarefas(Fila* fila);

int main()
{
  int opt;
  Fila *fila = criar_fila();
  if (fila == NULL)
    return 1;

  do
  {
    printf("O que voce deseja fazer? \n");
    printf("1 - Criar tarefa \n");
    printf("2 - Executar proxima tarefa \n");
    printf("3 - Consultar proxima tarefa \n");
    printf("4 - Estimar tempo de execucao da fila de tarefas \n");
    printf("5 - Listar tarefas \n");
    printf("0 - Encerrar programa \n");
    scanf("%i", &opt);

    switch (opt)
    {
      case 0: {
        printf("Encerrando programa...");
        break;
      }
      case 1:
      {
        Tarefa tarefa = criar_tarefa();
        enfileirar(fila, tarefa);
        break;
      }

      case 2:
      {
        executar_proxima_tarefa(fila);
        break;
      }

      case 3:
      {
        consultar_proxima_tarefa(fila);
        break;
      }

      case 4:
      {
        estimar_tempo(fila);
        break;
      }

      case 5: {
        listar_tarefas(fila);
        break;
      }

      default:
      {
        printf("Opcao invalida, tente novamente! \n");
        break;
      }
    }
  } while (opt != 0);

  return 0;
}

Fila *criar_fila()
{
  Fila *fila = (Fila *)malloc(sizeof(Fila));
  if (fila == NULL)
    return NULL;

  fila->inicio = NULL;
  fila->fim = NULL;
  fila->tamanho = 0;

  return fila;
}

Tarefa criar_tarefa()
{
  Tarefa tarefa;
  printf("Informe o titulo da tarefa: ");
  scanf("%s", &tarefa.titulo);
  printf("Informe a duracao da tarefa: ");
  scanf("%i", &tarefa.duracao);

  // printf("Tarefa criada! \n");
  // printf("Titulo: %s \n", tarefa.titulo);
  // printf("Duracao: %i \n", tarefa.duracao);

  return tarefa;
}

int enfileirar(Fila *fila, Tarefa tarefa)
{
  if (fila == NULL)
    return -1;

  Elemento *elemento = (Elemento *)malloc(sizeof(Elemento));
  if (elemento == NULL)
    return -1;

  elemento->tarefa = tarefa;
  elemento->proximo = NULL;

  if (fila->inicio == NULL)
  {
    fila->inicio = elemento;
    fila->fim = elemento;
    fila->tamanho++;
  }
  else
  {
    fila->fim->proximo = elemento;
    fila->fim = elemento;
    fila->tamanho++;
  }

  printf("========================\n");
  printf("Nova tarefa cadastrada! \n");
  printf("Titulo: %s \n", elemento->tarefa.titulo);
  printf("Duracao: %i \n", elemento->tarefa.duracao);
  printf("========================\n");

  return 1;
}

int executar_proxima_tarefa(Fila *fila)
{
  if (fila->inicio == NULL)
  {
    printf("Nao ha tarefas a serem executadas! \n");
    return -1;
  }

  Elemento *tarefa_executar = fila->inicio;
  fila->inicio = fila->inicio->proximo;

  if (fila->inicio == NULL)
  {
    fila->fim = NULL;
  }

  fila->tamanho--;
  printf("Tarefa %s executada! \n", tarefa_executar->tarefa.titulo);
  free(tarefa_executar);

  return 1;
}

void consultar_proxima_tarefa(Fila *fila)
{
  if (fila == NULL)
    return;
  if (fila->inicio == NULL)
  {
    printf("Nao ha uma proxima tarefa a ser executada! \n");
    return;
  }
  printf("=========================\n");
  printf("Proxima tarefa a ser executada: %s \n", fila->inicio->tarefa.titulo);
  printf("=========================\n");
}

void estimar_tempo(Fila* fila) {
  if(fila == NULL) return;
  if(fila->inicio == NULL) {
    printf("Nao ha tempo a ser estimado pois nao ha tarefas pendentes! \n");
    return;
  }

  int tempo_total = 0;

  Elemento* atual = fila->inicio;
  while (atual != NULL)
  {
    tempo_total += atual->tarefa.duracao;
    atual = atual->proximo;
  }

  printf("Tempo total estimado para a execucao das tarefas pendentes: %i minutos \n", tempo_total);
}

void listar_tarefas(Fila* fila) {
  if(fila == NULL) return;
  if(fila->inicio == NULL) {
    printf("Nao ha tarefas para listar, fila vazia!\n");
    return;
  }
  
  printf("=========================\n");
  printf("Listando fila de tarefas \n");
  printf("=========================\n");
  
  Elemento* atual = fila->inicio;
  int contador_tarefas = 1;
  while (atual != NULL)
  {
    printf("Tarefa %i: \n", contador_tarefas);
    printf("Titulo: %s \n", atual->tarefa.titulo);
    printf("Duracao: %i \n", atual->tarefa.duracao);
    printf("=========================\n");
    contador_tarefas++;
    atual = atual->proximo;
  }

}