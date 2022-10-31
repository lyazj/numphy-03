#include "intg.h"
#include <assert.h>
#include <stdio.h>
#include <math.h>

static number f(number x);
static void intg_trap_test(void);
static void intg_simp_test(void);
static void intg_cheb_test(void);

int main(void)
{
  intg_trap_test();
  intg_simp_test();
  intg_cheb_test();
  return 0;
}

static number f(number x)
{
  return x*x + 1;
}

void intg_trap_test(void)
{
  number I = intg_trap(f, 0, 1, 2);
  printf("%lg\n", (double)I);
  assert(I == 1.375);
}

void intg_simp_test(void)
{
  number I = intg_simp(f, 0, 1, 2);
  printf("%lg\n", (double)I);
  assert(I == 4.0 / 3);
}

void intg_cheb_test(void)
{
  number I = intg_cheb(f, 0, 1, 1000);
  printf("%lg\n", (double)I);
  assert(fabs(I - 4.0 / 3) < 1e-5);
}
