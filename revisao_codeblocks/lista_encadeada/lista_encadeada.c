#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
    int codigo;
    char nome[30];
    double nota;
    struct aluno* proximo_aluno;
} Aluno;

typedef struct lista {
    Aluno* inicio;
} Lista;

Lista* criar_lista();
void imprimir_lista(Lista* lista);
int inserir_inicio(Lista* lista, Aluno* aluno);
int remover_inicio(Lista* lista);
int buscar_primeiro_elemento(Lista* lista);
int buscar_aluno_nome(Lista* lista, char nome[30]);
int ordenar_list_asc(Lista* lista);
int ordenar_list_desc(Lista* lista);

int inserir_final(Lista* lista, Aluno* aluno);
int remover_final(Lista* lista);
int buscar_ultimo_elemento(Lista* lista);

int buscar_aluno_meio(Lista* lista);
int inserir_meio(Lista* lista, Aluno* aluno);
int remover_meio(Lista* lista);

int main () {
    Lista* lista = criar_lista();

    Aluno a1 = {1, "Zeca", 10.0, NULL};
    Aluno a2 = {2, "Carlos", 10.0, NULL};
    Aluno a3 = {3, "Ana", 10.0, NULL};
    Aluno a4 = {4, "Mateus", 10.0, NULL};
    Aluno a5 = {5, "Jeremias", 10.0, NULL};
    Aluno a6 = {6, "Bruna", 10.0, NULL};

    inserir_inicio(lista, &a1);
    inserir_inicio(lista, &a2);
    // inserir_inicio(lista, &a3);
    // inserir_inicio(lista, &a4);
    // inserir_inicio(lista, &a5);
    // inserir_inicio(lista, &a6);

    imprimir_lista(lista);

    //printf("** Apos remover aluno no meio ***\n");
    //remover_meio(lista);
    //imprimir_lista(lista);

    printf("** Apos inserir aluno no meio ***\n");
    inserir_meio(lista, &a6);
    imprimir_lista(lista);

    // imprimir_lista(lista);

    // buscar_aluno_meio(lista);

    //buscar_ultimo_elemento(lista);
    //remover_final(lista);
    //imprimir_lista(lista);

    //inserir_final(lista, &a4);
    //imprimir_lista(lista);


    //printf("*** Lista ordenada pelo nome ASC*** \n");
    //ordenar_list_asc(lista);
    //imprimir_lista(lista);
    //printf("*** Lista ordenada pelo nome DESC*** \n");
    //ordenar_list_desc(lista);
    //imprimir_lista(lista);


    // buscar_aluno_nome(lista, "Mateus");

    // buscar_primeiro_elemento(lista);

    // printf("*** Lista apos remover o elemento do inicio *** \n");
    // remover_inicio(lista);
    // imprimir_lista(lista);

    return 0;
}

Lista* criar_lista() {
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    if(lista != NULL) {
        lista->inicio = NULL;
    }

    return lista;
}

void imprimir_lista(Lista* lista) {
    if(lista == NULL) return;

    Aluno* atual = lista->inicio;

    printf("*** Lista de Alunos ***\n");
    while(atual != NULL) {
        printf("Aluno: %i \n", atual->codigo);
        printf("Nome: %s \n", atual->nome);
        printf("Nota: %.2lf \n", atual->nota);
        printf("********\n");
        atual = atual->proximo_aluno;
    }
}

int inserir_inicio(Lista* lista, Aluno* aluno) {
    if(lista == NULL || aluno == NULL) return -1;

    Aluno* novo_aluno = (Aluno*) malloc(sizeof(Aluno));
    if(novo_aluno == NULL) return -1;

    novo_aluno->codigo = aluno->codigo;
    strcpy(novo_aluno->nome, aluno->nome);
    novo_aluno->nota = aluno->nota;

    novo_aluno->proximo_aluno = lista->inicio;
    lista->inicio = novo_aluno;

    return 1;
}

int remover_inicio(Lista* lista) {
    if(lista == NULL) return -1;

    Aluno* tempAluno = lista->inicio;
    lista->inicio = tempAluno->proximo_aluno;

    free(tempAluno);
    return 1;
}

int buscar_primeiro_elemento(Lista* lista) {
    if(lista == NULL) return -1;

    if(lista->inicio != NULL) {
        printf("*** Primeiro Aluno da Lista *** \n");
        printf("Aluno: %i \n", lista->inicio->codigo);
        printf("Nome: %s \n", lista->inicio->nome);
        printf("Nota: %.2lf \n", lista->inicio->nota);
        return 1;
    }

    return -1;
}

int buscar_aluno_nome(Lista* lista, char nome[30]) {
    if(lista == NULL || lista->inicio == NULL) return -1;

    Aluno* atual = lista->inicio;

    while(atual != NULL) {
        if(strcmp(atual->nome, nome) == 0) {
            printf("ACHOU!");
            return 1;
        }

        atual = atual->proximo_aluno;
    }

    return -1;
}

int ordenar_list_asc(Lista* lista) {
    if(lista == NULL) return -1;

    int trocou;
    Aluno* atual;
    Aluno* proximo;

    do {
        trocou = 0;
        atual = lista->inicio;

        while(atual->proximo_aluno != NULL) {
            proximo = atual->proximo_aluno;

            if(strcmp(atual->nome, proximo->nome) > 0) {
                int tempCodigo = atual->codigo;
                char tempNome[30];
                strcpy(tempNome, atual->nome);
                double tempNota = atual->nota;

                atual->codigo = proximo->codigo;
                strcpy(atual->nome, proximo->nome);
                atual->nota = proximo->nota;

                proximo->codigo = tempCodigo;
                strcpy(proximo->nome, tempNome);
                proximo->nota = tempNota;

                trocou = 1;
            }
            atual = atual->proximo_aluno;
        }
    } while (trocou == 1);

    return 1;
}

int ordenar_list_desc(Lista* lista) {
    if(lista == NULL) return -1;

    int trocou;
    Aluno* atual;
    Aluno* proximo;


    do {
        trocou = 0;
        atual = lista->inicio;

        while(atual->proximo_aluno != NULL) {
            proximo = atual->proximo_aluno;

            if(strcmp(atual->nome, proximo->nome) < 0) {
                int tempCodigo = atual->codigo;
                char tempNome[30];
                strcpy(tempNome, atual->nome);
                double tempNota = atual->nota;

                atual->codigo = proximo->codigo;
                strcpy(atual->nome, proximo->nome);
                atual->nota = proximo->nota;

                proximo->codigo = tempCodigo;
                strcpy(proximo->nome, tempNome);
                proximo->nota = tempNota;
                trocou = 1;
            }

            atual = atual->proximo_aluno;
        }

    } while(trocou == 1);

    return 1;
}

int inserir_final(Lista* lista, Aluno* aluno) {
    if(lista == NULL) return -1;

    Aluno* novoAluno = (Aluno*) malloc(sizeof(Aluno));
    if(novoAluno == NULL) return -1;

    novoAluno->codigo = aluno->codigo;
    strcpy(novoAluno->nome, aluno->nome);
    novoAluno->nota = aluno->nota;
    novoAluno->proximo_aluno = NULL;

    if(lista->inicio == NULL) {
        lista->inicio = novoAluno;
    } else {
        Aluno* atual = lista->inicio;
        while(atual->proximo_aluno != NULL) {
            atual = atual->proximo_aluno;
        }

        atual->proximo_aluno = novoAluno;
    }

    return 1;
}

int remover_final(Lista* lista) {
    if(lista == NULL) return -1;

    Aluno* atual = lista->inicio;
    Aluno* anterior = NULL;

    if(atual->proximo_aluno == NULL) {
        free(atual);
        lista->inicio = NULL;
        return 1;
    }

    while(atual->proximo_aluno != NULL) {
        anterior = atual;
        atual = atual->proximo_aluno;
    }

    anterior->proximo_aluno = NULL;
    free(atual);

    return 1;
}


int buscar_ultimo_elemento(Lista* lista) {
    if(lista == NULL) return -1;

    Aluno* atual = lista->inicio;

    if(atual->proximo_aluno == NULL) {
        printf("*** Ultimo elemento: ***\n");
        printf("Aluno: %i \n", atual->codigo);
        printf("Nome: %s \n", atual->nome);
        printf("Nota: %.2lf \n", atual->nota);

        return 1;
    }

    while(atual->proximo_aluno != NULL) {
        atual = atual->proximo_aluno;
    }

    printf("*** Ultimo elemento: ***\n");
    printf("Aluno: %i \n", atual->codigo);
    printf("Nome: %s \n", atual->nome);
    printf("Nota: %.2lf \n", atual->nota);

    return 1;
}

int buscar_aluno_meio(Lista* lista) {
    if(lista == NULL) return -1;

    int tamanhoLista = 0;

    Aluno* atual = lista->inicio;

    while(atual->proximo_aluno != NULL) {
        atual = atual->proximo_aluno;
        tamanhoLista++;
    }

    int meio_lista = (tamanhoLista / 2);
    int controlador = 0;

    Aluno* aluno_meio = lista->inicio;

    while(controlador != meio_lista) {
        aluno_meio = aluno_meio->proximo_aluno;
        controlador++;

        if(controlador == meio_lista) {
            printf("Aluno do meio da lista: %s \n", aluno_meio->nome);
            break;
        }
    }

    return 1;
}

int inserir_meio(Lista* lista, Aluno* aluno) {
    if(lista == NULL || aluno == NULL) return -1;

    if(lista->inicio == NULL) {
        aluno->proximo_aluno = NULL;
        lista->inicio = aluno;
        return 1;
    }

    int tamanhoLista = 0;
    Aluno* atual = lista->inicio;

    while(atual != NULL) {
        atual = atual->proximo_aluno;
        tamanhoLista++;
    }

    int meio_lista = tamanhoLista / 2;
    int controlador = 0;

    Aluno* anterior_meio = lista->inicio;

    while(controlador != meio_lista - 1) {
        anterior_meio = anterior_meio->proximo_aluno;
        controlador++;
    }

    printf("Aluno ao meio da lista: %s \n", anterior_meio->nome);
    aluno->proximo_aluno = anterior_meio->proximo_aluno;
    anterior_meio->proximo_aluno = aluno;

    return 1;
}


int remover_meio(Lista* lista) {
    if(lista == NULL) return -1;
    if(lista->inicio->proximo_aluno == NULL) {
        lista->inicio = NULL;
        return 1;
    }

    int tamanhoLista = 0;

    Aluno* atual = lista->inicio;

    while(atual->proximo_aluno != NULL) {
        atual = atual->proximo_aluno;
        tamanhoLista++;
    }

    int meio_lista = (tamanhoLista / 2);
    Aluno* aluno_anterior = lista->inicio;
    int controlador = 0;

    while(controlador < meio_lista - 1) {
        aluno_anterior = aluno_anterior->proximo_aluno;
        controlador++;
    }

    Aluno* aluno_meio = aluno_anterior->proximo_aluno;
    printf("Aluno do meio: %s\n", aluno_meio->nome);

    aluno_anterior->proximo_aluno = aluno_meio->proximo_aluno;
    free(aluno_meio);

    return 1;
}
