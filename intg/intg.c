#include "intg.h"
#include <math.h>

number intg_trap(number f(number), number x1, number x2, int n)
{
  int i;
  number d = x2 - x1, x, I;

  if(n == 0)
    return NAN;
  I = f(x1) / 2;
  for(i = 1; i < n; ++i)
  {
    x = x1 + d * i / n;  // more precisely
    I += f(x);
  }
  I += f(x2) / 2;
  return I * (d / n);
}

number intg_simp(number f(number), number x1, number x2, int n)
{
  int i;
  number d = x2 - x1, l = d / n / 2, x, I;

  if(n == 0)
    return NAN;
  I = f(x1) / 6 + f(x1 + l) * (2.0 / 3);
  for(i = 1; i < n; ++i)
  {
    x = x1 + d * i / n;  // more precisely
    I += f(x) / 3 + f(x + l) * (2.0 / 3);
  }
  I += f(x2) / 6;
  return I * (d / n);
}

number intg_cheb(number f(number), number x1, number x2, int n)
{
  int i;
  number d = x2 - x1, d2 = d / 2, theta, x, I = 0;

  for(i = 0; i < n; ++i)
  {
    theta = (i + 0.5) * M_PI / n;
    x = x1 + d2 * (1 + cos(theta));
    I += f(x) * sin(theta);
  }
  return M_PI * I * (d2 / n);
}
