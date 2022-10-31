#pragma once

#ifndef number
#define number double
#endif  /* number */

#include <stdio.h>

number solve_bin(number f(number), number x1, number x2);
number solve_NR(number f(number), number fp(number), number x);
number solve_sec(number f(number), number x1, number x2);

extern FILE *solve_logging;
