#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct
{
  int matricula;
  char nome[20];
  float media;
} Aluno;

typedef struct
{
  int tamanho;
  Aluno alunos[MAX];
} Lista;

Lista *criar_lista();
int lista_cheia(Lista *lista);
int procurar(Lista *lista, int mat);
int inserir(Lista *lista, Aluno aluno);
void imprimir(Lista *lista);
int remover(Lista *lista, int matricula);
int libera_lista(Lista **lista);

// extras
int alterar_aluno(Lista *lista, int matricula, Aluno aluno);
void imprimir_por_media(Lista *lista);

int main()
{
  Lista *lista = criar_lista();

  Aluno aluno1 = {1, "Mucio", 6.2};
  Aluno aluno2 = {2, "Eslebao", 8.5};
  Aluno aluno3 = {3, "Raoni", 4.4};
  Aluno aluno4 = {4, "Genovena", 3.7};
  Aluno aluno5 = {5, "Estela", 6.8};
  Aluno aluno6 = {6, "Willy", 9.2};
  Aluno aluno7 = {4, "Marvin", 10};

  printf(" %i", inserir(lista, aluno1));
  printf(" %i", inserir(lista, aluno2));
  printf(" %i", inserir(lista, aluno3));
  printf(" %i", inserir(lista, aluno4));
  printf(" %i", inserir(lista, aluno5));
  printf(" %i", inserir(lista, aluno6));
  printf(" %i \n", inserir(lista, aluno7));

  imprimir(lista);

  // remover(lista, 5);

  imprimir(lista);
  
  // imprimir_por_media(lista);
  
  Aluno alunoAlterado = {1, "Stela", 8.4};
  int resultAlteracao = alterar_aluno(lista, 1, alunoAlterado);
  imprimir(lista);

  libera_lista(&lista);

  return 0;
}

Lista *criar_lista()
{
  Lista *lista;
  lista = (Lista *)malloc(sizeof(Lista));

  if (lista != NULL)
  {
    lista->tamanho = 0;
    printf("Sucesso... a lista foi criada!");
    return lista;
  }

  printf("Erro: a lista nao foi criada!");
  return lista;
}

int lista_cheia(Lista *lista)
{
  if (lista == NULL)
  {
    printf("ERRO! nao existe uma lista!");
    return -1;
  }

  if (lista->tamanho == MAX)
  {
    return 1;
  }

  return 0;
}

int procurar(Lista *lista, int mat)
{
  if (lista == NULL)
  {
    printf("ERRO! nao existe uma lista!");
    return -1;
  }

  for (int i = 0; i < lista->tamanho; i++)
  {
    if (lista->alunos[i].matricula == mat)
    {
      return i;
    }
  }

  return -1;
}

int inserir(Lista *lista, Aluno aluno)
{
  if (lista == NULL)
  {
    printf("\nERRO! nao existe uma lista!");
    return -1;
  }

  if (lista_cheia(lista) > 0)
  {
    printf("\nERRO! A lista esta cheia!");
    return -1;
  }

  if (procurar(lista, aluno.matricula) != -1)
  {
    printf("\nERRO! Ja existe um aluno com essa matricula!");
    return -1;
  }

  int posicao = lista->tamanho;
  Aluno tempAluno;

  lista->alunos[lista->tamanho] = aluno;

  for (int i = (lista->tamanho) - 1; i >= 0; i--)
  {
    if (strcmp(aluno.nome, lista->alunos[i].nome) < 0)
    {
      tempAluno = lista->alunos[i];
      lista->alunos[i] = aluno;
      lista->alunos[i + 1] = tempAluno;
      posicao = i;
    }
  }

  lista->tamanho++;
  return posicao;
}

void imprimir(Lista *lista)
{
  printf("\nLista de alunos:\n");
  printf("\n--------------------------\n");

  for (int i = 0; i < lista->tamanho; i++)
  {
    printf("%i - %s - %.1lf \n", lista->alunos[i].matricula, lista->alunos[i].nome, lista->alunos[i].media);
  }

  printf("\n--------------------------\n");
}

int remover(Lista *lista, int matricula)
{
  if (lista == NULL)
  {
    printf("\nERRO! nao existe uma lista!");
    return -1;
  }

  int indiceAluno = procurar(lista, matricula);

  if (indiceAluno != -1)
  {
    Aluno alunoRemover = lista->alunos[indiceAluno];

    for (int i = indiceAluno; i < lista->tamanho; i++)
    {
      lista->alunos[i] = lista->alunos[i + 1];
    }

    lista->tamanho--;
    // printf("\n-----Dados do aluno removido -----");
    // printf("\n%i - %s ", alunoRemover.matricula, alunoRemover.nome);
    // printf("\n----------------------------------");

    printf("\nSucesso! Aluno removido da posicao %i", indiceAluno);
    return indiceAluno;
  }
  else
  {
    printf("\nERRO! Matricula nao encontrada!\n");
  }

  return -1;
}

int libera_lista(Lista **lista)
{
  free(*lista);
  printf("\n");
  printf("\nLiberando memoria...");
  return 1;
}

int alterar_aluno(Lista *lista, int matricula, Aluno aluno) {
  if (lista == NULL) {
    printf("\nERRO! nao existe uma lista!");
    return -1;
  }

  if (procurar(lista, matricula) == -1) {
    printf("\nERRO! Nao existe um aluno com essa matricula!");
    return -1;
  }

  if (aluno.matricula != matricula && procurar(lista, aluno.matricula) != -1) {
    printf("\nERRO! Ja existe um aluno com essa matricula!");
    return -1;
  }

  remover(lista, matricula);
  int posAluno = inserir(lista, aluno);
  printf("\nSucesso... aluno alterado e realocado na posicao %i!", posAluno);
  return posAluno;
}

void imprimir_por_media(Lista *lista)
{
  printf("\nLista de alunos (ordenados pela media):");
  printf("\n--------------------------\n");
  
  Aluno vetorAluno[lista->tamanho];
  
  for (int i = 0; i < lista->tamanho; i++)
  {
    vetorAluno[i] = lista->alunos[i];
  }

  for (int i = 0; i < lista->tamanho; i++)
  {
    for (int j = 0; j < (lista->tamanho - 1 - i); j++)
    {
      if (vetorAluno[j + 1].media > vetorAluno[j].media)
      {
        Aluno tempAluno = vetorAluno[j];
        vetorAluno[j] = vetorAluno[j + 1];
        vetorAluno[j + 1] = tempAluno;
      }
    }
  }

  for (int i = 0; i < lista->tamanho; i++)
  {
    printf("%i - %s - %.1lf \n", vetorAluno[i].matricula, vetorAluno[i].nome, vetorAluno[i].media);
  }

  printf("\n--------------------------\n");
}