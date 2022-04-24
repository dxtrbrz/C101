#include <stdio.h>
#include <math.h>

void transforma_quadrado(int *num);
void transforma_raiz(int *num);
void print_var(char *msg);
void print_ptr(char *msg);

int var, *ptr;

int main() {
  var = 7;
  ptr = &var;

  printf("\n------------------- Inicialização --------------------\n\
Identificador\tEndereço\tConteúdo\tConteúdo\n\t\t\t\t\t\tno destino\n");

  print_var("Var");
  print_ptr("Ptr");
  printf("\n------------------- Transforma var -------------------\n");

  transforma_quadrado(&var);
  printf("Identificador\tEndereço\tConteúdo\tConteúdo\n\t\t\t\t\t\tno destino\n");
  print_var("Var");
  print_ptr("Ptr");

  printf("\n------------------- Transforma ptr -------------------\n");
  transforma_raiz(ptr);
  printf("Identificador\tEndereço\tConteúdo\tConteúdo\n\t\t\t\t\t\tno destino\n");
  print_var("Var");
  print_ptr("Ptr");
}

void transforma_quadrado(int *num) {
  *num = *num * *num;
}

void transforma_raiz(int *num) {
  *num = sqrt(*num);
}

void print_var(char *msg) {
  printf("%s\t\t%p\t%d\t\t---\n", msg, &var, var);
}

void print_ptr(char *msg) {
  printf("%s\t\t%p\t%p\t%d\n", msg, &ptr, ptr, *ptr);
}