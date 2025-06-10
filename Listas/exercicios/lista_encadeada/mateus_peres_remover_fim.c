
  // // 1) Função:

  // int remover_valor_final(Lista* lista) {
  //   if(lista == NULL) {
  //     return 0;
  //   }

  //   Elemento* elemento_anterior = NULL;
  //   Elemento* elemento_atual = lista->inicio;
    
  //   while (elemento_atual != NULL)
  //   {
  //     if(elemento_atual->proximo == NULL) {

  //       if(elemento_anterior == NULL) { 
  //         lista->inicio = NULL;

  //       } else {
  //         elemento_anterior->proximo = NULL;
  //       }
  //       free(elemento_atual);
  //       return 1;
  //     }

  //     elemento_anterior = elemento_atual;
  //     elemento_atual = elemento_atual->proximo;
  //   }

  //   return 0;
  // }

  // // 2) Em listas simplesmente encadeadas, é necessário percorrer todos os elementos até o final para remover o último, 
  // // já que não temos um ponteiro direto para o elemento anterior;

  // // 3) Tornaria mais eficiente apenas o acesso ao último elemento, mas como a lista é simplesmente encadeada 
  // // (ou seja, sem um ponteiro para o elemento anterior), ainda precisaríamos percorrer a lista inteira para encontrar o penúltimo elemento, e ajustar os ponteiros.

  // // 4) Seria necessário atualizar o ponteiro para o final sempre que elementos forem inseridos ou removidos no fim da lista, afetando as operações de 
  // // inserção e remoção no início/final respectivamente, porém torna essas operações mais eficientes ;

  // // 5) É possível tornar a remoção mais eficiente ao implementar a lista como duplamente encadeada, garantindo o acesso direto ao elemento anterior. 
  // // Uma possível outra alternativa seria manter um ponteiro para o fim da lista, e ao mesmo tempo incluir um ponteiro para o elemento anterior em cada nó da lista
