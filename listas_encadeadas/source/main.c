#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {
  struct item* head = NULL;

  head = cria_lista(10);

  print_lista(head);
  head = retira_da_pilha(head);
  print_lista(head);
  head = adciona_a_pilha(head,10);
  print_lista(head);
  head = limpa_lista(head);

  return 0;
}
