#ifndef _LISTA_DEFINED
#define _LISTA_DEFINED

struct item {
  int valor;
  struct item* prox;
};

struct item* cria_lista(int tamanho);
struct item* adiciona_a_lista(struct item* lista, int value, unsigned int pos);
struct item* adiciona_a_pilha(struct item* pilha, int novo_valor);
struct item* retira_da_pilha(struct item* pilha);
struct item* limpa_lista(struct item* pilha);


void print_lista();

#endif