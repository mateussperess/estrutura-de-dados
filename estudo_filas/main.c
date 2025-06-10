#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
    char nome[20];
    double nota;
} Aluno;

typedef struct elemento {
    Aluno aluno;
    struct elemento* proximo;
} Elemento;

typedef struct fila {
    struct elemento* inicio;
    struct elemento* fim;
} Fila;

Fila* criar_fila();
int fila_vazia(Fila* fila);
int inserir_fila(Fila* fila, Aluno aluno);
void imprimir_fila(Fila* fila);
int remover_fila(Fila* fila);
Fila* liberar_fila(Fila* fila);

int main() {
    Fila* fila = criar_fila();
    // printf("%i", fila_vazia(fila));

    Aluno al1 = {"Mateus", 10.0};
    Aluno al2 = {"Jeremias", 10.0};
    Aluno al3 = {"Ana Laura", 10.0};

    inserir_fila(fila, al1);
    inserir_fila(fila, al2);
    inserir_fila(fila, al3);

    remover_fila(fila);
    remover_fila(fila);

    imprimir_fila(fila);

    liberar_fila(fila);
    imprimir_fila(fila);
    return 0;
}

Fila* criar_fila() {
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    if(fila == NULL) return NULL;

    fila->inicio = NULL;
    fila->fim = NULL;

    return fila;
}

int fila_vazia(Fila* fila) {
    if(fila == NULL) return -1;
    if(fila->inicio == NULL) return 1; // retorna 1 se a fila estiver vazia
    return 0;
}

int inserir_fila(Fila* fila, Aluno aluno) {
    if(fila == NULL) return -1;

    Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
    if(!novo) return -1;

    novo->aluno = aluno;
    novo->proximo = NULL;

    if(fila->inicio == NULL) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->proximo = novo;
        fila->fim = novo;
    }

    return 1;
}

void imprimir_fila(Fila* fila) {
    if(fila == NULL|| fila->inicio == NULL) return NULL;
    Elemento* atual = fila->inicio;

    while(atual != NULL) {
        printf("%s \n", atual->aluno.nome);
        atual = atual->proximo;
    }
}

int remover_fila(Fila* fila) {
    if(fila == NULL || fila->inicio == NULL) return -1;

    Elemento* inicio_fila = fila->inicio;
    fila->inicio = fila->inicio->proximo;

    if(fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(inicio_fila);
    return 1;
}

Fila* liberar_fila(Fila* fila) {
    if(fila == NULL) return NULL;

    while (!fila_vazia(fila)) {
        remover_fila(fila);
    }

    free(fila);
    return NULL;
}
