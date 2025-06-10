#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct aluno{
    int matricula;
    char nome[20];
    float media;
    struct aluno* anterior_aluno;
    struct aluno* proximo_aluno;
} Aluno;

typedef struct lista {
    Aluno* inicio;
} Lista;

Lista* criar_lista();
Aluno* procurar(Lista* lista, int matricula);
int inserir(Lista* lista, Aluno* aluno);
void imprimir(Lista* lista);
int remover(Lista* lista, int matricula);
int liberar_lista(Lista* lista);

int main() {
    Lista* alunos = criar_lista();

    Aluno mucio = {1, "Mucio", 6.2};
    Aluno eslebao = {2, "Eslebao", 8.5};
    Aluno raoni = {3, "Raoni", 4.4};
    Aluno genovena = {4, "Genovena", 3.7};
    Aluno estela = {5, "Estela", 6.2};
    Aluno willy = {6, "Willy", 9.2};
    Aluno marvin = {7, "Marvin", 10};

    inserir(alunos, &mucio);
    inserir(alunos, &eslebao);
    inserir(alunos, &raoni);
    inserir(alunos, &genovena);
    inserir(alunos, &estela);
    inserir(alunos, &willy);
    inserir(alunos, &marvin);

    imprimir(alunos);

    procurar(alunos, 11);

    remover(alunos, 1);
    remover(alunos, 7);
    remover(alunos, 9);
    remover(alunos, 4);

    imprimir(alunos);

    liberar_lista(alunos);
    imprimir(alunos);
    return 0;
}

Lista* criar_lista() {
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    if(lista == NULL) {
        printf("Erro: a lista nao foi criada! \n");
    } else {
        printf("A lista foi criada com sucesso! \n");
        lista->inicio = NULL;
    }

    return lista;
}

Aluno* procurar(Lista* lista, int matricula) {
    if(lista == NULL || lista->inicio == NULL) return NULL;

    Aluno* atual = lista->inicio;

    while(atual != NULL && atual->matricula != matricula) {
        atual = atual->proximo_aluno;
    }

    if(atual == NULL) {
        printf("Aluno nao encontrado! \n");
    } else {
        printf("Aluno encontrado! \n");
    }

    return atual;
}

int inserir(Lista* lista, Aluno* aluno) {
    if(lista == NULL) return -1;

    Aluno* novo = (Aluno*) malloc(sizeof(Aluno));
    if(novo == NULL) return -1;

    *novo = *aluno;
    novo->anterior_aluno = NULL;
    novo->proximo_aluno = NULL;

    if(lista->inicio == NULL) {
        lista->inicio = novo;
        return 1;
    }

    Aluno* atual = lista->inicio;
    Aluno* anterior = NULL;

    while(atual != NULL && atual->media >= aluno->media) {
        anterior = atual;
        atual = atual->proximo_aluno;
    }

    novo->anterior_aluno = anterior;
    novo->proximo_aluno = atual;

    if(anterior != NULL) { // se o novo aluno nao vai ficar na primeira posicao da fila
        anterior->proximo_aluno = novo;
    } else { // se o novo aluno vai ficar na primeira posicao da fila
        lista->inicio = novo;
    }

    if(atual != NULL) {
        atual->anterior_aluno = novo;
    }

    return 1;
}

void imprimir(Lista* lista) {
    if(lista == NULL) return;

    if(lista->inicio == NULL) {
        printf("Lista vazia! \n");
        return;
    }

    Aluno* atual = lista->inicio;

    printf("Lista de Alunos: \n");
    printf("----------------------------------------\n");

    while(atual != NULL) {
        printf("%i - %s - %.1lf \n", atual->matricula, atual->nome, atual->media);
        atual = atual->proximo_aluno;
    }

    printf("----------------------------------------\n");
}


int remover(Lista* lista, int matricula) {
    if(lista == NULL) return -1;

    Aluno* atual = lista->inicio;
    Aluno* anterior = NULL;
    Aluno* proximo = NULL;

    while(atual != NULL && atual->matricula != matricula) {
        anterior = atual;
        atual = atual->proximo_aluno;
    }

    if(atual == NULL) {
        printf("Matricula nao encontrada! \n");
        return 1;
    }

    proximo = atual->proximo_aluno;

    if(anterior == NULL) { // se a remoção é o primeiro elemento da lista
        proximo->anterior_aluno = NULL;
        lista->inicio = proximo;
        printf("Aluno '%s' removido com sucesso! \n", atual->nome);
        free(atual);
    } else { // se a remoção é no meio da lista

        if(proximo != NULL) {
            proximo->anterior_aluno = anterior;
        }

        anterior->proximo_aluno = proximo;
        printf("Aluno '%s' removido com sucesso! \n", atual->nome);
        free(atual);
    }

    return 1;
}

int liberar_lista(Lista* lista) {
    if(lista == NULL) return -1;

    Aluno* atual = lista->inicio;
    Aluno* anterior = NULL;

    while(atual != NULL) {
        anterior = atual;
        atual = atual->proximo_aluno;
        free(anterior);
    }

    lista->inicio = NULL;
    printf("Lista liberada! \n");
    return 1;
}
