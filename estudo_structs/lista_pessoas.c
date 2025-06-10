#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct
{
  char nome[20];
  int idade;
  double altura;
} Pessoa;

typedef struct
{
  int tamanho;
  Pessoa* pessoas[MAX];
} Lista;

// FUNÇÕES
Lista* criarLista();

Pessoa* criarPessoa();

int inserirPessoaLista(Pessoa* pessoa, Lista* lista, int index);

int imprimirLista(Lista* lista);

int lerPessoa(Pessoa* pessoa);

int main()
{
  Lista* lista = criarLista();

  int qtdPessoas;
  printf("Quantas pessoas voce quer cadastrar? \n");
  scanf("%i", &qtdPessoas);

  for (int i = 0; i < qtdPessoas; i++)
  {
    printf("-----Dados da pessoa %i----- \n", (i + 1));
    Pessoa* pessoa = criarPessoa();
    inserirPessoaLista(pessoa, lista, i);
  }
  
  printf("--------------------------- \n");
  imprimirLista(lista);

  for (int i = 0; i < lista->tamanho; i++)
  {
    free(lista->pessoas[i]);    
  }

  free(lista);
  return 0;
}

Lista* criarLista() {
  Lista* lista = (Lista*) malloc(sizeof(Lista));

  if(lista != NULL) {
    lista->tamanho = 0;
    printf("Lista criada com sucesso... \n");
  } else {
    printf("ERRO! Lista nao foi criada... \n");
  }

  return lista;
}

Pessoa *criarPessoa()
{
  Pessoa *pessoa;
  pessoa = (Pessoa *)malloc(sizeof(Pessoa));

  if (pessoa != NULL)
  {
    printf("Informe o nome da pessoa: ");
    scanf("%s", &pessoa->nome);

    printf("Informe a idade da pessoa: ");
    scanf("%i", &pessoa->idade);

    printf("Informe a altura da pessoa: ");
    scanf("%lf", &pessoa->altura);

    printf("Pessoa criada com sucesso... \n");
  } else {
    printf("Nao foi possivel criar a pessoa...");
  }

  return pessoa;
}

int inserirPessoaLista(Pessoa* pessoa, Lista* lista, int index) {
  if(lista == NULL || pessoa == NULL) {
    printf("ERRO! Nao existe uma lista/pessoa cadastrada!");
    return -1;
  }
  
  if(lista->tamanho >= MAX) {
    printf("ERRO! A lista ja esta cheia!");
    return -1;
  }

  lista->pessoas[index] = pessoa;
  lista->tamanho++;
  return 1;
}

int imprimirLista(Lista* lista) {
  if(lista == NULL) {
    printf("ERRO! Nao existe uma lista/pessoa cadastrada!");
    return -1;
  }

  for (int i = 0; i < lista->tamanho; i++)
  {
    lerPessoa(lista->pessoas[i]);
  }
}

int lerPessoa(Pessoa* pessoa) {
  if(pessoa != NULL) {
    printf("Nome: %s \n", pessoa->nome);
    printf("Idade: %i \n", pessoa->idade);
    printf("Altura: %.2lf \n", pessoa->altura);
    printf("--------------------------- \n");
    return 1;
  } else {
    printf("ERRO! Pessoa nao existe... \n");
  }

  return -1;
}
