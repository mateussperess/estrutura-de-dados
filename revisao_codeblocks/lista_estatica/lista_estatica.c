#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

typedef struct aluno {
    int codigo;
    char nome[30];
    double nota;
} Aluno;

typedef struct lista {
    int tamanho;
    Aluno* alunos[MAX];
} Lista;

Lista* criar_lista();
int lista_cheia(Lista* lista);
Aluno* criar_aluno(int codigo, char nome[30], double nota);
int inserir_final(Lista* lista, Aluno* aluno);
void imprimir_lista_original(Lista* lista);
// selection sort
void imprimir_lista_asc(Lista* lista);
void imprimir_lista_desc(Lista* lista);

int buscar_aluno_nome(Lista* lista, char nome[30]);
int remover_aluno_final(Lista* lista);
int inserir_inicio(Lista* lista, Aluno* aluno);
int remover_inicio(Lista* lista);

int inserir_meio(Lista* lista, Aluno* aluno);
int remover_meio(Lista* lista);
int buscar_aluno_meio(Lista* lista);

int main() {
    Lista* lista = criar_lista();
    Aluno* aluno1 = criar_aluno(1, "Mateus", 10.0);
    Aluno* aluno2 = criar_aluno(2, "Jeremias", 9.5);
    Aluno* aluno3 = criar_aluno(3, "Ana", 9.5);
    Aluno* aluno4 = criar_aluno(4, "Juca", 6.0);

    inserir_final(lista, aluno1);
    inserir_final(lista, aluno2);
    inserir_final(lista, aluno3);
    inserir_inicio(lista, aluno4);

    imprimir_lista_original(lista);

    // printf("*** Alino do Meio *** \n");
    // buscar_aluno_meio(lista);
    // inserir_meio(lista, aluno4);
    // printf("** Lista apos insercao no meio*** \n");
    // imprimir_lista_original(lista);

    // printf("** Lista apos remocao no meio*** \n");
    // remover_meio(lista);
    // imprimir_lista_original(lista);

    //printf("** Lista apos remocao no inicio*** \n");
    //remover_inicio(lista);
    //imprimir_lista_original(lista);

    // remover_aluno_final(lista);
    // printf("** Lista apos remocao *** \n");
    // imprimir_lista_original(lista);

    // imprimir_lista_asc(lista);
    // imprimir_lista_desc(lista);
    // buscar_aluno_nome(lista, "Mateus");

    for(int i = 0; i < lista->tamanho; i++) {
        free(lista->alunos[i]);
    }

    free(lista);
    return 0;
}

Lista* criar_lista() {
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    if(lista == NULL) return NULL;

    lista->tamanho = 0;

    return lista;
}

int lista_cheia(Lista* lista) {
    if(lista == NULL) return -1;
    if(lista->tamanho == MAX) return 1;

    return 0;
}

Aluno* criar_aluno(int codigo, char nome[30], double nota) {
    Aluno* aluno = (Aluno*) malloc(sizeof(Aluno));
    if(aluno == NULL) return NULL;

    aluno->codigo = codigo;
    strcpy(aluno->nome, nome);
    aluno->nota = nota;

    return aluno;
}

int inserir_final(Lista* lista, Aluno* aluno) {
    if(lista == NULL || aluno == NULL) return -1;

    if(lista_cheia(lista) == 1) {
        printf("Lista cheia! \n");
        return -1;
    }

    lista->alunos[lista->tamanho] = aluno;
    lista->tamanho++;

    return 1;
}

void imprimir_lista_original(Lista* lista) {
    if(lista == NULL) return;

    printf("** Lista original ***\n");
    for(int i = 0; i < lista->tamanho; i++) {
        printf("Codigo do aluno: %i \n", lista->alunos[i]->codigo);
        printf("Nome do aluno: %s \n", lista->alunos[i]->nome);
        printf("Nota do aluno: %.2lf \n", lista->alunos[i]->nota);
        printf("****** \n");
    }
}

void imprimir_lista_asc(Lista* lista) {
    if(lista == NULL) return;

    Aluno* copia_alunos[MAX];

    for(int i = 0; i < lista->tamanho; i++) {
        copia_alunos[i] = lista->alunos[i];
    }

    for(int i = 0; i < lista->tamanho; i++) {
        for(int j = i + 1; j < lista->tamanho; j++) {
            if(strcmp(copia_alunos[i]->nome, copia_alunos[j]->nome) > 0) { // se i vem antes do j, troca
                Aluno* tempAluno = copia_alunos[i];
                copia_alunos[i] = copia_alunos[j];
                copia_alunos[j] = tempAluno;
            }
        }
    }

    printf("** Lista de Alunos ordenada ASC *** \n");
    for(int i = 0; i < lista->tamanho; i++) {
        printf("Codigo do aluno: %i \n", copia_alunos[i]->codigo);
        printf("Nome do aluno: %s \n", copia_alunos[i]->nome);
        printf("Nota do aluno: %.2lf \n", copia_alunos[i]->nota);
        printf("****** \n");
    }
}

void imprimir_lista_desc(Lista* lista) {
    if(lista == NULL) return;

    Aluno* copia_lista[MAX];

    for(int i = 0; i < lista->tamanho; i++) {
        copia_lista[i] = lista->alunos[i];
    }

    for(int i = 0; i < lista->tamanho; i++) {
        for(int j = i + 1; j < lista->tamanho; j++) {
            if(strcmp(copia_lista[i]->nome, copia_lista[j]->nome) < 0) {
                Aluno* tempAluno = copia_lista[i];
                copia_lista[i] = copia_lista[j];
                copia_lista[j] = tempAluno;
            }
        }
    }

    printf("** Lista de Alunos ordenada DESC *** \n");
    for(int i = 0; i < lista->tamanho; i++) {
        printf("Codigo do aluno: %i \n", copia_lista[i]->codigo);
        printf("Nome do aluno: %s \n", copia_lista[i]->nome);
        printf("Nota do aluno: %.2lf \n", copia_lista[i]->nota);
        printf("****** \n");
    }
}

int buscar_aluno_nome(Lista* lista, char nome[30]) {
    if(lista == NULL) return -1;

    for(int i = 0; i < lista->tamanho; i++) {
        if(strcmp(lista->alunos[i]->nome, nome) == 0) {
            printf("Achou! \n");
            return lista->alunos[i]->codigo;
        }
    }

    return -1;
}

int remover_aluno_final(Lista* lista) {
    if(lista == NULL) return -1;

    Aluno* aluno_remover = lista->alunos[(lista->tamanho - 1)];
    lista->alunos[(lista->tamanho - 1)] = NULL;
    free(aluno_remover);
    lista->tamanho--;

    return 1;
}

int inserir_inicio(Lista* lista, Aluno* aluno) {
    if(lista == NULL || aluno == NULL) return -1;

    if(lista_cheia(lista) == 1) {
        printf("Lista cheia! \n");
        return -1;
    }

    for(int i = lista->tamanho; i >= 0; i--) {
        lista->alunos[i + 1] = lista->alunos[i];
    }

    lista->alunos[0] = aluno;
    lista->tamanho++;
    return 1;
}

int remover_inicio(Lista* lista) {
    if(lista == NULL) return -1;

    Aluno* aluno_remover = lista->alunos[0];
    lista->alunos[0] = NULL;

    for(int i = 1; i < lista->tamanho; i++) {
        lista->alunos[i - 1] = lista->alunos[i];
    }

    free(aluno_remover);
    lista->tamanho--;
    return 1;
}

int inserir_meio(Lista* lista, Aluno* aluno) {
    if(lista == NULL || aluno == NULL) return -1;

    if (lista_cheia(lista) == 1) {
        printf("Lista cheia!\n");
        return -1;
    }

    int meio_lista = (lista->tamanho / 2);

    for(int i = lista->tamanho; i > meio_lista; i--) {
        lista->alunos[i] = lista->alunos[i - 1];
    }

    lista->alunos[meio_lista] = aluno;
    lista->tamanho++;
    return 1;
}

int remover_meio(Lista* lista) {
    if(lista == NULL) return -1;

    int meio_lista = (lista->tamanho / 2);
    Aluno* tempAluno = lista->alunos[meio_lista];

    for(int i = meio_lista; i < (lista->tamanho - 1); i++) {
        lista->alunos[i] = lista->alunos[i + 1];
    }

    lista->alunos[lista->tamanho - 1] = NULL;
    free(tempAluno);
    lista->tamanho--;
    return 1;
}

int buscar_aluno_meio(Lista* lista) {
    if(lista == NULL) return -1;

    int meio_lista = (lista->tamanho / 2);

    Aluno* aluno_meio = lista->alunos[meio_lista];

    if(aluno_meio != NULL) {
        printf("Achou! \n");
        printf("Nome do aluno: %s", aluno_meio->nome);
    }

    return 1;
}
