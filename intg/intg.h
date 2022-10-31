#pragma once

#ifndef number
#define number double
#endif  /* number */

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif  /* M_PI */

number intg_trap(number f(number), number x1, number x2, int n);
number intg_simp(number f(number), number x1, number x2, int n);
number intg_cheb(number f(number), number x1, number x2, int n);
