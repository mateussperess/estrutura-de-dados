#include <stdio.h>
int main() {
  float nota = 9.5;
  float* p; // p é um ponteiro que aponta para um endereço de memória do tipo float
  p = &nota; // p armazena o endereço de memória da variável nota
  
  printf("%f \n", nota); // mostra o valor da variavel

  printf("%p \n", &nota); // mostra o endereço de nota (variável) armazenado na memória

  printf("%p \n", p); // mostra o valor da variável p (endereço da memória -> linha 5)

  printf("%p \n", &p); // mostra o endereço de p (variável) armazenado na memória 

  printf("%f \n", *p); // pega o endereço para onde o ponteiro aponta, e mostra o conteúdo do endereço da memória armazenada

  return 0;
}