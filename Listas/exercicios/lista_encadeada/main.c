#include <stdio.h>
#include <stdlib.h>

typedef struct elemento
{
  int valor;
  struct elemento *proximo;
} Elemento;

typedef struct lista {
  Elemento* inicio;
} Lista;

Lista* criar_lista();
int lista_vazia(Lista* lista);
int inserir_inicio(int valor, Lista* lista);
void imprimir(Lista* lista);
int remover_inicio(Lista* lista);
Elemento* buscar(int valor, Lista* lista);
int remover(int valor, Lista* lista);
int remover_valor_final(Lista* lista);

int main() {
  Lista* lista = criar_lista();

  inserir_inicio(20, lista);
  inserir_inicio(33, lista);
  inserir_inicio(19, lista);
  imprimir(lista); // Lista: 19 33 20
  
  remover_inicio(lista);
  remover_inicio(lista);
  imprimir(lista); // Lista: 20
  
  inserir_inicio(45, lista); 
  inserir_inicio(55, lista); 
  inserir_inicio(65, lista); 
  imprimir(lista);
  
  buscar(45, lista);
  
  remover(20, lista);
  imprimir(lista);
  
  remover_valor_final(lista);
  imprimir(lista);
  remover_valor_final(lista);
  imprimir(lista);
  remover_valor_final(lista);
  imprimir(lista);

  return 0;
}

Lista* criar_lista() {
  Lista* lista; 
  lista = (Lista*) malloc(sizeof(Lista));
  if(lista != NULL) {
    lista->inicio = NULL;
  }

  return lista;
}

int lista_vazia(Lista* lista) {
  if (lista == NULL) {
    return -1;
  }

  if (lista->inicio == NULL) 
  {
    return 1;
  }

  return 0;
}

int inserir_inicio(int valor, Lista* lista) {
  if (lista == NULL)
  {
    return 0;
  }
  
  // aloca um novo elemento e define seu valor
  Elemento* novo = (Elemento*) malloc(sizeof(Elemento));

  // testa a alocação
  if (novo == NULL)
  {
    return 0;
  }
  
  novo->valor = valor;
 
  // ajusta o encadeamento
  novo->proximo = lista->inicio;
  lista->inicio = novo;
  return 1;
}

void imprimir(Lista* lista) {
  if (lista == NULL) {
    return;
  }

  printf("Lista: ");

  Elemento* atual = lista->inicio;

  while (atual != NULL) {
    printf("%d ", atual->valor);
    atual = atual->proximo;
  }

  printf("\n");
}

int remover_inicio(Lista *lista) {
  if(lista == NULL) {
    return 0;
  }

  if (lista->inicio == NULL){
    return 0;
  }
 
  Elemento* inicio = lista->inicio;
  lista->inicio = inicio->proximo;
  free(inicio);
}

Elemento* buscar(int valor, Lista* lista) {
  if(lista == NULL) {
    return 0;
  }

  Elemento* atual = lista->inicio;

  while (atual != NULL)
  {
    if (atual->valor == valor)
    {
      // printf("Achou! ");
      return atual;
    }

    atual = atual->proximo;
  }

  printf("Nao achou");
  return NULL;
}

int remover(int valor, Lista* lista) {
  if(lista == NULL) {
    return 0;
  }

  if(buscar(valor, lista)) {
    Elemento* elemento_anterior = NULL;
    Elemento* elemento_atual = lista->inicio;

    while (elemento_atual != NULL)
    {
      if(elemento_atual->valor == valor) {
        if (elemento_anterior == NULL)
        {
          lista->inicio = elemento_atual->proximo;
        } else {
          elemento_anterior->proximo = elemento_atual->proximo;
        }

        free(elemento_atual);
        return 1;
      }

      elemento_anterior = elemento_atual;
      elemento_atual = elemento_atual->proximo;
    }
    
    return 1;
  }
  
  printf("ERRO! Elemento para remover nao encontrado!");
  return 0;
}

// int remover_valor_final(Lista* lista) {
//   if(lista == NULL) {
//     return 0;
//   }

//   Elemento* elemento_anterior = NULL;
//   Elemento* elemento_atual = lista->inicio;
  
//   while (elemento_atual != NULL)
//   {
//     if(elemento_atual->proximo == NULL) {

//       if(elemento_anterior == NULL) { // caso em que o elemento final é o único na lista
//         lista->inicio = NULL;

//       } else {
//         remover(elemento_atual->valor, lista);
//         elemento_anterior->proximo = NULL;
  
//       }
//       free(elemento_atual);
//       return 1;
//     }

//     elemento_anterior = elemento_atual;
//     elemento_atual = elemento_atual->proximo;
//   }

//   return 0;
// }

  // 1) Função:
  int remover_valor_final(Lista* lista) {
    if(lista == NULL) {
      return 0;
    }

    Elemento* elemento_anterior = NULL;
    Elemento* elemento_atual = lista->inicio;
    
    while (elemento_atual != NULL)
    {
      if(elemento_atual->proximo == NULL) {

        if(elemento_anterior == NULL) { 
          lista->inicio = NULL;

        } else {
          elemento_anterior->proximo = NULL;
        }
        
        free(elemento_atual);
        return 1;
      }

      elemento_anterior = elemento_atual;
      elemento_atual = elemento_atual->proximo;
    }

    return 0;
  }
/*
  2) Em listas simplesmente encadeadas, é necessário percorrer todos os elementos até o final para remover o último, 
  já que não temos um ponteiro direto para o elemento anterior;

  3) Tornaria mais eficiente apenas o acesso ao último elemento, mas como a lista é simplesmente encadeada 
  (ou seja, sem um ponteiro para o elemento anterior), ainda precisaríamos percorrer a lista inteira para encontrar o penúltimo elemento, e ajustar os ponteiros.

  4) Seria necessário atualizar o ponteiro para o final sempre que elementos forem inseridos ou removidos no fim da lista, afetando as operações de 
  inserção e remoção no início/final respectivamente, porém torna essas operações mais eficientes ;

  5) É possível tornar a remoção mais eficiente ao implementar a lista como duplamente encadeada, garantindo o acesso direto ao elemento anterior. 
  Uma possível outra alternativa seria manter um ponteiro para o fim da lista, e ao mesmo tempo incluir um ponteiro para o elemento anterior em cada nó da lista
*/