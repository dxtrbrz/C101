#include <stdio.h>
#include <stdarg.h>

const double a = 2;
const double b = 3;
const double c = 5;

double somatorio(register int num, ...); 

int main() {

  double (*ptr) (int num, ...) = somatorio;

  double soma = (*ptr) (3, a, b, c); 
  printf("%.2f\n", soma);

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
