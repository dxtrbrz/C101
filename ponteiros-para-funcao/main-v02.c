#include <stdio.h>
#include <stdarg.h>

const double a = 2;
const double b = 3;
const double c = 5;

double somatorio(register int num, ...); 
double produtorio(register int num, ...);
double media(register int num, ... );


int main() {

  double (*ptr[]) (int num, ...) = {  somatorio,
                                      produtorio,
                                      media
                                    };

  for (register int i=0; i<3; i++) {  
    printf("%.2f\n", (*ptr[i]) (3, a, b, c));
  }

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

double media(register int num, ... ) {
  va_list argptr;
  double soma;
  int ind = num;

  va_start(argptr, ind);
  
  for ( ; ind; ind--) {
    soma += va_arg(argptr, double);
  }
  va_end(argptr);

  return soma/num;
}

