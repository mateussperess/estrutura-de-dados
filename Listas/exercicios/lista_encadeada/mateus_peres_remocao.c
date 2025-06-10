// int remover(int valor, Lista* lista) {
//   if(lista == NULL) {
//     return 0;
//   }

//   if(buscar(valor, lista)) {
//     Elemento* elemento_anterior = NULL;
//     Elemento* elemento_atual = lista->inicio;

//     while (elemento_atual != NULL)
//     {
//       if(elemento_atual->valor == valor) {
//         if (elemento_anterior == NULL)
//         {
//           lista->inicio = elemento_atual->proximo;
//         } else {
//           elemento_anterior->proximo = elemento_atual->proximo;
//         }

//         free(elemento_atual);
//         return 1;
//       }

//       elemento_anterior = elemento_atual;
//       elemento_atual = elemento_atual->proximo;
//     }
    
//     return 1;
//   }
  
//   printf("ERRO! Elemento para remover nao encontrado!");
//   return 0;
// }