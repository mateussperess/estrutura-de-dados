#include <stdio.h>
#include <stdlib.h>

int main() {
  int* ptr = malloc(5 * sizeof(int));

  if(ptr == NULL) {
    printf("Falha ao alocar memoria! \n");
    return 1;
  }

  printf("%d", ptr);
  
  return 0;
}

// 8788664