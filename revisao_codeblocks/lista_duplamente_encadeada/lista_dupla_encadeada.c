#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
    int codigo;
    char nome[30];
    double nota;
    struct aluno* proximo_aluno;
    struct aluno* anterior_aluno;
} Aluno;

typedef struct lista {
    struct aluno* inicio;
} Lista;

Lista* criar_lista();
void imprimir_lista_original(Lista* lista);
int buscar_elemento_inicio(Lista* lista);
int inserir_inicio(Lista* lista, Aluno* aluno);
int remover_inicio(Lista* lista);
int buscar_elemento_nome(Lista* lista, char nome[30]);
int ordenar_lista_asc(Lista* lista);
int ordenar_lista_desc(Lista* lista);

int inserir_ao_final(Lista* lista, Aluno* aluno);
int remocao_ao_final(Lista* lista);
int buscar_ao_final(Lista* lista);

int buscar_ao_meio(Lista* lista);
int inserir_meio(Lista* lista, Aluno* aluno);
int remover_meio(Lista* lista);

int main() {
    Lista* lista = criar_lista();

    // posso fazer assim e passar a por referência com &
    Aluno a1 = {1, "Zeca", 10.0, NULL, NULL};

    // ou posso fazer assim e passar apenas o 'aluno01' como parâmetro, que é o recomendado:
    Aluno* aluno01 = (Aluno*) malloc(sizeof(Aluno));
    *aluno01 = (Aluno){1, "Zeca", 10.0, NULL, NULL};

    Aluno a2 = {2, "Carlos", 10.0, NULL, NULL};
    Aluno a3 = {3, "Ana", 10.0, NULL, NULL};
    Aluno a4 = {4, "Mateus", 10.0, NULL, NULL};
    Aluno a5 = {5, "Jeremias", 10.0, NULL, NULL};
    Aluno a6 = {6, "Bruna", 10.0, NULL, NULL};

    inserir_inicio(lista, &a1);
    inserir_inicio(lista, aluno01);
    inserir_inicio(lista, &a2);
    inserir_inicio(lista, &a3);
    inserir_inicio(lista, &a4);
    inserir_inicio(lista, &a5);


    imprimir_lista_original(lista);

    /// printf("Removendo aluno ao meio da lista: \n");
    // remover_meio(lista);
    // imprimir_lista_original(lista);

    /// printf("Inserindo aluno ao meio da lista: \n");
    // inserir_meio(lista, &a5);
    // imprimir_lista_original(lista);

    ///printf("Busca ao meio da lista: \n");
    // buscar_ao_meio(lista);
    // imprimir_lista_original(lista);

    /// printf("Buscando ultimo aluno da lista: \n");
    // buscar_ao_final(lista);

    /// printf("Remocao ao final \n");
    // remocao_ao_final(lista);
    // imprimir_lista_original(lista);

    /// printf("Insercao ao final: \n ");
    // inserir_ao_final(lista, &a5);
    // imprimir_lista_original(lista);

    /// printf("Lista apos ordenacao asc \n");
    // ordenar_lista_asc(lista);
    //imprimir_lista_original(lista);

    /// printf("Lista apos ordenacao asc \n");
    // ordenar_lista_desc(lista);
    // imprimir_lista_original(lista);

    /// printf("Buscando elemento nome \n");

    // buscar_elemento_nome(lista, "Mateus");
    /// printf("Buscando elemento inicio \n");
    // buscar_elemento_inicio(lista);

    /// printf("Lista de alunos apos remocao inicial: \n");
    // remover_inicio(lista);
    // remover_inicio(lista);
    // imprimir_lista_original(lista);

    return 0;
}

Lista* criar_lista() {
    Lista* lista = (Lista*) malloc(sizeof(Lista));

    if(lista != NULL) {
        lista->inicio = NULL;
    }

    return lista;
}

void imprimir_lista_original(Lista* lista) {
    if(lista == NULL) return;

    Aluno* atual = lista->inicio;

    printf("*** Lista de Alunos ***\n");

    while(atual != NULL) {
        printf("Codigo: %i \n", atual->codigo);
        printf("Nome: %s \n", atual->nome);
        printf("Nota: %.2lf \n", atual->nota);
        printf("********\n");

        atual = atual->proximo_aluno;
    }
}

int buscar_elemento_inicio(Lista* lista) {
    if(lista == NULL || lista->inicio == NULL) return -1;

    Aluno* primeiro_aluno = lista->inicio;
    printf("*** Dados do primeiro aluno *** \n");
    printf("Codigo: %i \n", primeiro_aluno->codigo);
    printf("Nome: %s \n", primeiro_aluno->nome);
    printf("Nota: %.2lf \n", primeiro_aluno->nota);
    printf("********\n");

    return 1;
}

int inserir_inicio(Lista* lista, Aluno* aluno) {
    if(lista == NULL) return -1;

    if(lista->inicio == NULL) {
        aluno->anterior_aluno = NULL;
        aluno->proximo_aluno = NULL;
        lista->inicio = aluno;
        return 1;
    }

    aluno->anterior_aluno = NULL;
    lista->inicio->anterior_aluno = aluno;
    aluno->proximo_aluno = lista->inicio;
    lista->inicio = aluno;

    return 1;
}

int remover_inicio(Lista* lista) {
    if(lista == NULL) return -1;

    Aluno* aluno = lista->inicio;

    if(aluno->proximo_aluno == NULL) {
        lista->inicio = NULL;
        free(aluno);
        return 1;
    }


    aluno->anterior_aluno = NULL;
    lista->inicio = aluno->proximo_aluno;
    lista->inicio->anterior_aluno = NULL;

    free(aluno);
    return 1;
}

int buscar_elemento_nome(Lista* lista, char nome[30]) {
    if(lista == NULL) return -1;

    Aluno* atual = lista->inicio;

    while(atual != NULL) {
        if(strcmp(atual->nome, nome) == 0) {
            printf("!!! Achou !!! \n");
            printf("*** Dados de %s *** \n", atual->nome);
            printf("Codigo: %i \n", atual->codigo);
            printf("Nome: %s \n", atual->nome);
            printf("Nota: %.2lf \n", atual->nota);
            printf("********\n");
            return 1;
        }

        atual = atual->proximo_aluno;
    }

    return 1;
}

int ordenar_lista_asc(Lista* lista) {
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

    } while(trocou == 1);

    return 1;
}

int ordenar_lista_desc(Lista* lista) {
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

int inserir_ao_final(Lista* lista, Aluno* aluno) {
    if(lista == NULL) return -1;

    if(lista->inicio == NULL) {
        aluno->anterior_aluno = NULL;
        aluno->proximo_aluno = NULL;
        lista->inicio = aluno;
        return 1;
    }

    Aluno* atual = lista->inicio;

    while(atual->proximo_aluno != NULL) {
        atual = atual->proximo_aluno;
    }

    aluno->anterior_aluno = atual;
    aluno->proximo_aluno = NULL;
    atual->proximo_aluno = aluno;
    return 1;
}

int remocao_ao_final(Lista* lista) {
    if(lista == NULL) return -1;

    Aluno* atual = lista->inicio;

    if(atual->proximo_aluno == NULL) {
        lista->inicio = NULL;
        free(atual);
        return 1;
    }

    Aluno* anterior = NULL;

    while(atual->proximo_aluno != NULL) {
        atual = atual->proximo_aluno;
        anterior = atual->anterior_aluno;
    }

    anterior->proximo_aluno = NULL;
    free(atual);

    // printf("Ultimo: %s \n", atual->nome);
    // printf("penultimo: %s \n", anterior->nome);
    return 1;
}


int buscar_ao_final(Lista* lista) {
    if(lista == NULL) return -1;

    Aluno* atual = lista->inicio;
    if(atual->proximo_aluno == NULL) {
        printf("!!! ACHOU !!! \n");
        printf("Codigo: %i", atual->codigo);
        printf("Nome: %s", atual->nome);
        printf("Nota: %.2lf", atual->nota);
        printf("******** \n");
    }

    while(atual->proximo_aluno != NULL) {
        atual = atual->proximo_aluno;
    }

    printf("!!! ACHOU !!! \n");
    printf("Codigo: %i \n", atual->codigo);
    printf("Nome: %s \n", atual->nome);
    printf("Nota: %.2lf \n", atual->nota);
    printf("******** \n");
    return 1;
}

int buscar_ao_meio(Lista* lista) {
    if(lista == NULL) return -1;

    Aluno* atual = lista->inicio;

    if(atual->proximo_aluno == NULL) {
        printf("Aluno do meio da lista (a lista so possui ele): %s \n", atual->nome);
        printf("******** \n");
        return 1;
    }

    int tamanhoLista = 0;
    while(atual->proximo_aluno != NULL) {
        atual = atual->proximo_aluno;
        tamanhoLista++;
    }

    tamanhoLista++;

    int meio_lista = (tamanhoLista / 2);
    int controlador = 0;

    Aluno* aluno_meio = lista->inicio;
    while(controlador != meio_lista) {
        aluno_meio = aluno_meio->proximo_aluno;
        controlador++;

        if(controlador == meio_lista) {
            printf("Aluno do meio da lista: %s \n", aluno_meio->nome);
            printf("******** \n");
            return 1;
        }
    }

    printf("Tamanho da lista: %i \n", tamanhoLista);
    return -1;
}

int inserir_meio(Lista* lista, Aluno* aluno) {
    if(lista == NULL) return -1;

    Aluno* atual = lista->inicio;
    if(atual->proximo_aluno == NULL) {
        printf("Aluno do meio da lista (a lista so possui ele): %s \n", atual->nome);
        printf("******** \n");
        return 1;
    }

    int tamanhoLista = 0;
    while(atual->proximo_aluno != NULL) {
        atual = atual->proximo_aluno;
        tamanhoLista++;
    }

    tamanhoLista++;

    int meioLista = (tamanhoLista / 2);
    int controlador = 0;
    Aluno* aluno_anterior_meio = lista->inicio;

    while(controlador != meioLista) {
        aluno_anterior_meio = aluno_anterior_meio->proximo_aluno;
        controlador++;

        if(controlador == meioLista) {
            aluno_anterior_meio = aluno_anterior_meio->anterior_aluno;
            break;
        }
    }

    aluno->proximo_aluno = aluno_anterior_meio->proximo_aluno;
    aluno_anterior_meio->proximo_aluno = aluno;

    return 1;
}

int remover_meio(Lista* lista) {
    if(lista == NULL) return -1;
    Aluno* atual = lista->inicio;

    if(atual->proximo_aluno == NULL) {
        lista->inicio = NULL;
        free(atual);
        return 1;
    }

    int tamanhoLista = 0;
    while(atual->proximo_aluno != NULL) {
        atual = atual->proximo_aluno;
        tamanhoLista++;
    }

    tamanhoLista++;
    int meioLista = (tamanhoLista / 2);
    int controlador = 0;
    Aluno* aluno_meio = lista->inicio;

    while(controlador != meioLista) {
        aluno_meio = aluno_meio->proximo_aluno;
        controlador++;

        if(controlador == meioLista) {
            printf("Aluno do meio: %s \n", aluno_meio->nome);
            break;
        }
    }

    aluno_meio->anterior_aluno->proximo_aluno = aluno_meio->proximo_aluno;
    aluno_meio->proximo_aluno->anterior_aluno = aluno_meio->anterior_aluno;
    free(aluno_meio);
    return 1;
}
