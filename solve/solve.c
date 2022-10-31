#include "solve.h"
#include <math.h>
#include <stdio.h>

FILE *solve_logging;

number solve_bin(number f(number), number x1, number x2)
{
  number y1, y2;
  number x, y;

  if(isnan(x1) || isnan(x2))
    return NAN;
  if(isnan((y1 = f(x1))) || isnan((y2 = f(x2))))
    return NAN;
  if(y1 == 0)
    return x1;
  if(y2 == 0)
    return x2;
  if(signbit(y1) == signbit(y2))
    return NAN;
  for(;;)
  {
    if(solve_logging)
      fprintf(solve_logging, "%s: %+-23.13la%+-21.13la\n", __func__, (double)x1, (double)x2);
    if(isnan((x = (x1 + x2) / 2)) || isnan((y = f(x))))
      return NAN;
    if(x == x1 || x == x2 || y == 0)
      return x;
    if(signbit(y) == signbit(y1))
      x1 = x, y1 = y;
    else
      x2 = x, y2 = y;
  }
}

// IMPORTANT: dead loop avoidance yet to be implemented
number solve_NR(number f(number), number fp(number), number x)
{
  number y, yp, x_new;

  if(isnan(x))
    return NAN;
  for(;;)
  {
    if(solve_logging)
      fprintf(solve_logging, "%s: %+-21.13la\n", __func__, (double)x);
    if(isnan((y = f(x))) || isnan((yp = fp(x))) || isnan((x_new = x - y / yp)))
      return NAN;
    if(x_new == x)
      return x;
    x = x_new;
  }
}

// IMPORTANT: dead loop avoidance yet to be implemented
number solve_sec(number f(number), number x1, number x2)
{
  number y1, y2;
  number x, y;

  if(isnan(x1) || isnan(x2))
    return NAN;
  if(isnan((y1 = f(x1))) || isnan((y2 = f(x2))))
    return NAN;
  for(;;)
  {
    if(solve_logging)
      fprintf(solve_logging, "%s: %+-23.13la%+-21.13la\n", __func__, (double)x1, (double)x2);
    if(isnan((x = x2 - y2 * ((x1 - x2) / (y1 - y2)))) || isnan((y = f(x))))
      return NAN;
    if(x == x1 || x == x2)
      return x;
    x1 = x2, y1 = y2;
    x2 = x, y2 = y;
  }
}
