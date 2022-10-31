#include "solve.h"
#include <math.h>
#include <stdio.h>
#include <assert.h>

static number f(number x);
static number fp(number x);
static void solve_bin_test(void);
static void solve_NR_test(void);
static void solve_sec_test(void);

int main(void)
{
  solve_bin_test();
  solve_NR_test();
  solve_sec_test();
  return 0;
}

number f(number x)  // x0 in (3, 4)
{
  return exp(x) - 10*x;
}

number fp(number x)
{
  return exp(x) - 10;
}

void solve_bin_test(void)
{
  number x0 = solve_bin(f, 3, 4);
  printf("%s: f(%lg) = %lg\n", __func__, x0, f(x0));
  assert(fabs(f(x0)) < 1e-15);
  assert(isnan(solve_bin(f, 2, 3)));
  assert(isnan(solve_bin(f, 4, 5)));
  assert(isnan(solve_bin(f, NAN, 4)));
  assert(isnan(solve_bin(f, 3, NAN)));
  assert(isnan(solve_bin(f, NAN, NAN)));
}

void solve_NR_test(void)
{
  number x0 = solve_NR(f, fp, 4);
  printf("%s: f(%lg) = %lg\n", __func__, x0, f(x0));
  assert(fabs(f(x0)) < 1e-15);
  assert(isnan(solve_NR(f, fp, NAN)));
}

void solve_sec_test(void)
{
  number x0 = solve_sec(f, 3, 4);
  printf("%s: f(%lg) = %lg\n", __func__, x0, f(x0));
  assert(fabs(f(x0)) < 1e-15);
  assert(isnan(solve_sec(f, NAN, 4)));
  assert(isnan(solve_sec(f, 3, NAN)));
  assert(isnan(solve_sec(f, NAN, NAN)));
  assert(fabs(solve_sec(f, 4, 5) - x0) < 1e-15);
  assert(fabs(solve_sec(f, 2, 3) - x0) < 1e-15);
}
