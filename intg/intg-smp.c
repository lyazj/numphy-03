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
  r = intg_trap(f, 1, 100, 9);
  printf("intg_trap-10:   %8.6lf  %.1e\n", (double)r, (double)(r - RESULT));
  r = intg_trap(f, 1, 100, 99);
  printf("intg_trap-100:  %8.6lf  %.1e\n", (double)r, (double)(r - RESULT));
  r = intg_trap(f, 1, 100, 999);
  printf("intg_trap-1000: %8.6lf  %.1e\n", (double)r, (double)(r - RESULT));
  r = intg_simp(f, 1, 100, 9);
  printf("intg_samp-10:   %8.6lf  %.1e\n", (double)r, (double)(r - RESULT));
  r = intg_simp(f, 1, 100, 99);
  printf("intg_samp-100:  %8.6lf  %.1e\n", (double)r, (double)(r - RESULT));
  r = intg_simp(f, 1, 100, 999);
  printf("intg_samp-1000: %8.6lf  %.1e\n", (double)r, (double)(r - RESULT));
  r = intg_cheb(f, 1, 100, 10);
  printf("intg_cheb-10:   %8.6lf  %.1e\n", (double)r, (double)(r - RESULT));
  r = intg_cheb(f, 1, 100, 100);
  printf("intg_cheb-100:  %8.6lf  %.1e\n", (double)r, (double)(r - RESULT));
  return 0;
}
