#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


struct item* cria_lista(int tamanho) {
    struct item* prox = NULL;
    register int i=tamanho;
    struct item* novo_item;

    for (; i; i--){
      novo_item = malloc(sizeof(struct item));
      novo_item->prox = prox;
      novo_item->valor = tamanho - i;
      prox = novo_item;
    }

  return novo_item;
}

struct item* adiciona_a_lista(struct item* lista, int valor, unsigned int pos) {
  register unsigned int idx=0;

  struct item* item_atual = lista;

  while (item_atual->prox) {
    if (idx == pos) {
      struct item* novo_item = NULL;
      novo_item = malloc(sizeof(struct item));

      novo_item->prox = item_atual->prox;
      novo_item->valor = valor;
      item_atual->prox = novo_item;

    }
    idx++;
    item_atual = item_atual->prox;
    
  }
  return lista;
}

struct item* retira_da_pilha(struct item* pilha) {
  if (pilha) {
    struct item* temp = pilha;
    pilha = pilha->prox;
    free(temp);
    return pilha;
  }
  else return NULL;
}

struct item* adiciona_a_pilha(struct item* pilha, int novo_valor) {
  struct item* novo_item = NULL;
  novo_item = malloc(sizeof(struct item));
  novo_item->valor = novo_valor;
  novo_item->prox = pilha;
  return novo_item;
}

struct item* limpa_lista(struct item* lista) {
  do {
    lista = retira_da_pilha(lista);
  } while (lista);
  return NULL;
}

unsigned int tamanho_lista(struct item* lista) {
  struct item* item_atual = lista;
  register unsigned int contador = 0;

  while (item_atual) {
    contador++;
    item_atual = item_atual->prox;
  }
  return contador;
}

void print_lista(struct item* ptr) {
  if (ptr) {
    do {
      printf("%d\t",ptr->valor);
      ptr = ptr->prox;
    } while (ptr);
    printf("\n");
  }
  else printf("vazia\n");
}
