/*
 * enshu 04
 *
 * 67170575
 * Akira Itai
 *
gcc sol.c -lm -o a
 */

#include <stdio.h>

double func(double x) {
  return 4/(1+x*x);
}

double trapizoid(double a, double b, int n) {
  double h = (b-a) / n;
  double s = (func(a) + func(b)) / 2.0;

  for (int i = 1; i < n; i++) {
    s += func(a + h*i);
  }

  return s*h;
}

int main(int argc, char *argv[]) {
  double a = 0.0, b = 1.0;

  printf("  n                ans\n");
  for (int n = 1; n <= 256; n*=2) {
    printf("%3d  %.15f\n", n, trapizoid(a, b, n));
  }
}
