#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno{
    int matricula;
    char nome[20];
    float media;
    struct aluno* proximo_aluno;
} Aluno;

typedef struct lista {
    Aluno* inicio;
} Lista;

Lista* criar_lista();
Aluno* procurar(Lista* lista, int matricula);
int inserir(Lista* lista, Aluno* aluno);
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

    remover(alunos, 1);
    remover(alunos, 7);
    remover(alunos, 9);

    // procurar(alunos, 2);

    imprimir(alunos);

    liberar_lista(alunos);
    imprimir(alunos);

    return 0;
}

Lista* criar_lista() {
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    if(lista != NULL) {
        lista->inicio = NULL;
        printf("A lista foi criada com sucesso! \n");
    } else {
        printf("A lista nao foi criada! \n");
    }

    return lista;
}

Aluno* procurar(Lista* lista, int matricula) {
    if(lista == NULL || matricula == 0) return NULL;

    Aluno* atual = lista->inicio;

    while(atual != NULL && atual->matricula != matricula) {
        atual = atual->proximo_aluno;
    }

    if(atual == NULL) {
        printf("Matricula nao encontrada! \n");
    } else {
        printf("Aluno encontrado! \n");
    }

    return atual;
}

int inserir(Lista* lista, Aluno* aluno) {
    if(lista == NULL) return -1;

    Aluno* atual = lista->inicio;

    if(lista->inicio == NULL) {
        lista->inicio = aluno;
        return 1;
    }

    Aluno* anterior = NULL;

    while(atual != NULL && atual->media >= aluno->media) {
        anterior = atual;
        atual = atual->proximo_aluno;
    }

    if(anterior == NULL) { // caso o aluno inserido tenha a maior média de todos os outros
        aluno->proximo_aluno = lista->inicio;
        lista->inicio = aluno;
    } else { // insere o aluno entre 'anterior' e 'atual', mantendo a ordem da lista
        aluno->proximo_aluno = atual;
        anterior->proximo_aluno = aluno;
    }

    return 1;
}

void imprimir(Lista* lista) {
    if(lista == NULL) return -1;

    if(lista->inicio == NULL) {
        printf("Lista vazia! \n");
        return 1;
    }

    printf("Lista de Alunos: \n");
    printf("----------------------------------------\n");

    Aluno* atual = lista->inicio;

    while(atual != NULL) {
        printf("%i - %s - %.1lf \n", atual->matricula, atual->nome, atual->media);
        atual = atual->proximo_aluno;
    }

    printf("----------------------------------------\n");
}

int remover(Lista* lista, int matricula) {
    if(lista == NULL || lista->inicio == NULL) return -1;

    Aluno* atual = lista->inicio;
    Aluno* anterior = NULL;

    while(atual != NULL && atual->matricula != matricula) {
        anterior = atual;
        atual = atual->proximo_aluno;
    }

    if(atual == NULL) {
        printf("Matricula nao encontrada! \n");
        return -1;
    }

    if(anterior == NULL) {
        lista->inicio = atual->proximo_aluno;
    } else {
        anterior->proximo_aluno = atual->proximo_aluno;
    }

    printf("Aluno '%s' removido com sucesso! \n", atual->nome);

    free(atual);
    return 1;
}

int liberar_lista(Lista* lista) {
    if(lista == NULL) return 0;

    Aluno* atual = lista->inicio;
    Aluno* proximo;

    while(atual != NULL) {
        proximo = atual->proximo_aluno;
        free(atual);
        atual = proximo;
    }

    lista->inicio = NULL;
    return 1;
}
