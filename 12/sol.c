/*
enshu 12
67170575
Akira Itai
 
gcc sol.c -lm -o a
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func1(double x, double y) {
  return y-12*x-3;
  return y;
}

double euler(double (*func)(double, double), double x0, double y0, double xn, int n) {
  double h = (xn - x0) / n;
  double x = x0;
  double y = y0;

  for (int i = 1; i <= n; i++) {
    y += func(x, y) * h;
    x = x0 + i*h;
    printf("%g %g\n", x, y);
  }
  return y;
}

int main(int argc, char *argv[]) {
  for (int n = 10; n <= 10000; n*=10) {
    double x0 = 0.0;
    double y0 = 1.0;
    double xn = 1.0;
    printf("n: %d ans: y(%g) = %g\n", n, xn, euler(func1, x0, y0, xn, n));
  }
  return 0;
}
