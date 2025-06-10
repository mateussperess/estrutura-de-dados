#include <stdio.h>

struct disciplina
{
  char nome[25];
  int carga_horaria;
  int semestre;
};

typedef struct disciplina Disciplina;

void ler_disciplinas(Disciplina array_disciplinas[5]);

int main() {
  Disciplina disciplinas[5] = {
    "Probabilidade", 60, 3,
    "Banco de Dados II", 80, 3,
    "Banco de Dados I", 80, 2,
    "Desenv backend", 90, 1,
    "Desenv frontent", 90, 1,
  };

  ler_disciplinas(disciplinas);

  return 0;
}

void ler_disciplinas(Disciplina array_disciplinas[5]) {
  printf("Disciplinas do usuario: \n");
  printf("============================================ \n");

  for (int i = 0; i < 5; i++)
  {
    // printf("Nome: %s - Carga Horaria: %i - Semestre: %i \n", d[i].nome, d[i].carga_horaria, d[i].semestre);    
    printf("Nome: %s \n", array_disciplinas[i].nome);
    printf("Nome: %d \n", array_disciplinas[i].carga_horaria);
    printf("Nome: %d \n", array_disciplinas[i].semestre);
    printf("============================================ \n");
  }
}

