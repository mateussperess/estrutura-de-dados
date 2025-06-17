#include <stdio.h>
#include <string.h>

typedef union
{
  int inteiro;
  float decimal;
  char texto[30];
} Payload;

typedef enum
{
  INTEIRO,
  DECIMAL,
  TEXTO
} TipoMensagem;

typedef struct
{
  TipoMensagem tipo;
  Payload dados;
} Mensagem;

void imprimirMensagem(Mensagem msg) {
  switch (msg.tipo)
  {
  case INTEIRO:
    printf("A mensagem eh do tipo INTEIRO. %i \n", msg.dados.inteiro);
    break;
  
  case DECIMAL: 
    printf("A mensagem eh do tipo DECIMAL: %f \n", msg.dados.decimal);
    break;
  
  case TEXTO: 
    printf("A mensagem eh do tipo TEXTO: %s \n", msg.dados.texto);
    break;
  default:
    printf("Tipo da mensagem eh desconhecido. \n");
  }
}

int main() {
  Mensagem msg1;
  msg1.tipo = INTEIRO;
  msg1.dados.inteiro = 18;

  Mensagem msg2;
  msg2.tipo = DECIMAL;
  msg2.dados.decimal = 18.01;

  Mensagem msg3;
  msg3.tipo = TEXTO;
  strcpy(msg3.dados.texto, "TESTE");

  imprimirMensagem(msg1);
  imprimirMensagem(msg2);
  imprimirMensagem(msg3);

  return 0;
}
