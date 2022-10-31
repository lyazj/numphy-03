#include "solve.h"
#include <math.h>
#include <stdio.h>

static number f(number x)
{
  return x - 2 * sin(x);
}

static number fp(number x)
{
  return 1 - 2 * cos(x);
}

int main(void)
{
  number x0;

  solve_logging = stdout;
  x0 = solve_bin(f, 1.5, 2.5);
  fprintf(stderr, "solve_bin: %lg (%la)\n", x0, x0);
  x0 = solve_NR(f, fp, 2.5);
  fprintf(stderr, "solve_NR:  %lg (%la)\n", x0, x0);
  x0 = solve_sec(f, 1.5, 2.5);
  fprintf(stderr, "solve_sec: %lg (%la)\n", x0, x0);
}
