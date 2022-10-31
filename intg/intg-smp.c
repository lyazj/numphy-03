#include "intg.h"
#include <stdio.h>
#include <math.h>

#define RESULT 0.2193839343955202736772

static number f(number x)
{
  return exp(-x) / x;
}

int main(void)
{
  number r;
  r = intg_trap(f, 1, 100, 10);
  printf("intg_trap-11:  \t%8lg\t%lg\n", (double)r, (double)(r - RESULT));
  r = intg_trap(f, 1, 100, 100);
  printf("intg_trap-101: \t%8lg\t%lg\n", (double)r, (double)(r - RESULT));
  r = intg_trap(f, 1, 100, 1000);
  printf("intg_trap-1001:\t%8lg\t%lg\n", (double)r, (double)(r - RESULT));
  r = intg_simp(f, 1, 100, 5);
  printf("intg_samp-11:  \t%8lg\t%lg\n", (double)r, (double)(r - RESULT));
  r = intg_simp(f, 1, 100, 50);
  printf("intg_samp-101: \t%8lg\t%lg\n", (double)r, (double)(r - RESULT));
  r = intg_simp(f, 1, 100, 500);
  printf("intg_samp-1001:\t%8lg\t%lg\n", (double)r, (double)(r - RESULT));
  r = intg_cheb(f, 1, 100, 11);
  printf("intg_cheb-11:  \t%8lg\t%lg\n", (double)r, (double)(r - RESULT));
  r = intg_cheb(f, 1, 100, 101);
  printf("intg_cheb-101: \t%8lg\t%lg\n", (double)r, (double)(r - RESULT));
  r = intg_cheb(f, 1, 100, 1001);
  printf("intg_cheb-1001:\t%8lg\t%lg\n", (double)r, (double)(r - RESULT));
  return 0;
}
