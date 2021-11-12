/*
 * 67170575
 * Akira Itai
 *
gcc sol.c -lm -o a
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 1.0e-10
#define MAX_LOOPS 10

#define M 4

char *S[M] = {
  "x",
  "f(x)",
  "f'(x)",
  "Δx",
};

double f(double x) {
  return exp(x) - 1/x;
}

double df(double x) {
  return exp(x) + 1/x/x;
}

double newton(double x0) {
  double x = x0, dx;
  int count = 0;
  do {
    dx = -f(x) / df(x);

    double a[] = {x, f(x), df(x), dx};
    for (int j = 0; j < M; j++) {
      if (j != 0) printf(" ");
      printf("%18.15lf", a[j]);
    }
    printf("\n");

    x += dx;
  } while (fabs(dx/x) > EPS && count < MAX_LOOPS);

  return x;
}

int main(int argc, char *argv[]) {
  double x = 1.0, dx = -f(x) / df(x);

  printf("f(x) = e^x - (1/x) = 0, x0 = 1\n\n");
  for (int i = 0; i < M; i++) {
    if (i != 0) printf(" ");
    printf("%18s", S[i]);
  }
  printf("\n");

  printf("ans = %.15lf\n", newton(x));

  return 0;
}
