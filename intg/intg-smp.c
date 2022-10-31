#include "intg.h"
#include <stdio.h>
#include <math.h>

static number f(number x)
{
  return exp(-x) / x;
}

int main(void)
{
  printf("intg_trap-11:   %lg\n", (double)intg_trap(f, 1, 100, 10));
  printf("intg_trap-101:  %lg\n", (double)intg_trap(f, 1, 100, 100));
  printf("intg_trap-1001: %lg\n", (double)intg_trap(f, 1, 100, 1001));
  printf("intg_samp-11:   %lg\n", (double)intg_simp(f, 1, 100, 5));
  printf("intg_samp-101:  %lg\n", (double)intg_simp(f, 1, 100, 50));
  printf("intg_samp-1001: %lg\n", (double)intg_simp(f, 1, 100, 500));
  printf("intg_cheb-11:   %lg\n", (double)intg_cheb(f, 1, 100, 11));
  printf("intg_cheb-101:  %lg\n", (double)intg_cheb(f, 1, 100, 101));
  printf("intg_cheb-1001:  %lg\n", (double)intg_cheb(f, 1, 100, 1001));
  return 0;
}
