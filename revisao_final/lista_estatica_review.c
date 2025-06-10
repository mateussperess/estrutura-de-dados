#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct aluno {
    int codigo;
    char nome[20];
    double nota;
} Aluno;

typedef struct lista {
    int tamanho;
    Aluno* alunos[MAX];
} Lista;

Lista* criar_lista();
Aluno* criar_aluno(int codigo, char nome[20], double nota);
int inserir__ao_final(Lista* lista, Aluno* aluno);
void imprimir_lista_original(Lista* lista);
Lista* ordenar_nome_asc(Lista* lista);

int main() {
    Lista* lista = criar_lista();

    Aluno* a1 = criar_aluno(1, "Mateus", 10.0);
    Aluno* a2 = criar_aluno(2, "Jeremias", 9.0);
    Aluno* a3 = criar_aluno(3, "Ana", 8.5);

    inserir__ao_final(lista, a1);
    inserir__ao_final(lista, a2);

    ordenar_nome_asc(lista);

    imprimir_lista_original(lista);

    return 0;
}

Lista* criar_lista() {
    Lista* lista = (Lista*) malloc(sizeof(Lista*));
    if(lista != NULL) {
        lista->tamanho = 0;
    }

    return lista;
}

Aluno* criar_aluno(int codigo, char nome[20], double nota) {
    Aluno* aluno = (Aluno*) malloc(sizeof(Aluno));
    if(aluno == NULL) return NULL;

    aluno->codigo = codigo;
    strcpy(aluno->nome, nome);
    aluno->nota = nota;

    return aluno;
}

int inserir__ao_final(Lista* lista, Aluno* aluno) {
    if(lista == NULL) return -1;

    lista->alunos[lista->tamanho] = aluno;
    lista->tamanho++;
    return 1;
}


void imprimir_lista_original(Lista* lista) {
    if(lista == NULL) return;

    printf("--- Lista de Alunos --- \n");
    for(int i = 0; i < lista->tamanho; i++) {
        printf("Codigo: %i\n", lista->alunos[i]->codigo);
        printf("Nome: %s\n", lista->alunos[i]->nome);
        printf("Nota: %.2lf\n", lista->alunos[i]->nota);
    }
    printf("----------------------- \n");
}

Lista* ordenar_nome_asc(Lista* lista) {
    if(lista == NULL) return -1;

    for(int i = 0; i < lista->tamanho; i++) {
        for(int j = i + 1; j < lista->tamanho; j++) {
            if(strcmp(lista->alunos[i], lista->alunos[j]) < 0) { // se i vem antes de j, troca
                Aluno* tempAluno = lista->alunos[i];
                lista->alunos[i] = lista->alunos[j];
                lista->alunos[j] = tempAluno;
            }
        }
    }

    return lista;
}
