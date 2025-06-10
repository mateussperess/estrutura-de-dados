#include <stdio.h>
#include <string.h>

int main() {
  char str1[20];
  char str2[20];

  printf("Informe um nome: ");
  scanf("%s", &str1);

  printf("Informe um nome: ");
  scanf("%s", &str2);

  int result = strcmp(str1, str2); 

  if(result > 0) {
    printf("O nome %s vem antes do nome %s. %i ", str2, str1, result);
  } else {
    printf("O nome %s vem antes do nome %s. %i ", str1, str2, result);
  }

  return 0;
}