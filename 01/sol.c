/*
 * 67170575
 * Akira Itai
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS (1e-10)

double f(double x) {
  return x*x*x + x - 1.0;
}

double bisection(double ***A, int *n, double a, double b) {
  int i = 0;
  while(fabs(a-b) > EPS) {
    *A = (double **)realloc(*A, (i+1)*sizeof(double *));

    double m = (a+b)/2.0;

    A[0][i] = (double *)malloc(6*sizeof(double));
    A[0][i][0] = a;
    A[0][i][1] = b;
    A[0][i][2] = m;
    A[0][i][3] = fabs(a-b);
    A[0][i][4] = f(a);
    A[0][i][5] = f(m);
    i++;

    if (f(a)*f(m) < 0.0) b = m;
    else a = m;
  }

  double ans = (a+b)/2;
  A[0][i] = (double *)malloc(6*sizeof(double));
  A[0][i][0] = a;
  A[0][i][1] = b;
  A[0][i][2] = ans;
  A[0][i][3] = fabs(a-b);
  A[0][i][4] = f(a);
  A[0][i][5] = f(ans);
  i++;

  *n = i;

  return ans;
}

int main(int argc, char *argv[]) {
  double a = 0.0, b = 1.0;
  double **A = (double **)malloc(sizeof(double *));
  int n = 0;

  double ans = bisection(&A, &n, a, b);
  printf("f(x) = x^3 + x - 1\n");

  printf("%14s ", "a");
  printf("%14s ", "b");
  printf("%14s ", "m");
  printf("%14s ", "|a-b|");
  printf("%14s ", "f(a)");
  printf("%14s ", "f(m)");
  printf("\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 6; j++) {
      printf("%14.11lf ", A[i][j]);
    }
    printf("\n");
  }

  printf("ans = %.15lf\n", ans);

  return 0;
}
