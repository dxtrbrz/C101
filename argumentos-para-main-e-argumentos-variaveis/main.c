#include <stdio.h>
#include <stdarg.h>

const double a = 10;
const double b = 15;
const double c = 0.5;

double somatorio(register int num, ...); 
double produtorio(register int num, ...);

int main() {

  printf("%.2f\n", somatorio(3, a, b, c));
  printf("%.2f\n", produtorio(3, a, b, c));

  return 0;
}

double somatorio(register int num, ...) {
  va_list argptr;
  double soma;

  va_start(argptr, num);
  for( ; num; num--) {
    soma += va_arg(argptr, double);
  }
  va_end(argptr);

  return soma;
};

double produtorio(register int num, ...){
  va_list argptr;
  double produto = 1;

  va_start(argptr, num);
  for ( ; num; num--){
    produto *= va_arg(argptr, double);
  }
  va_end(argptr);

  return produto;
}

