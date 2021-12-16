/*
enshu 09
67170575
Akira Itai
 
gcc sol.c -lm -o a
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 2
#define EPS 1e-5

void print_vec(double x[]) {
  for (int i = 0; i < N; i++) {
    printf("%6.3f ", x[i]);
  }
  printf("\n");
}

void multi_mat_vec(double y[], double A[][N], double x[]) {
  for (int i = 0; i < N; i++) {
    y[i] = 0.0;
    for (int j = 0; j < N; j++) {
      y[i] += A[i][j] * x[j];
    }
  }
}

double inner_prod(double x[], double y[]) {
  double prod = 0.0;
  for (int i = 0; i < N; i++) {
    prod += x[i] * y[i];
  }
  return prod;
}

void normalize_vec(double y[], double x[]) {
  double length = sqrt(inner_prod(y, y));
  for (int i = 0; i < N; i++) {
    x[i] = y[i] / length;
  }
}

void poweigen(double A[][N], double *x, double *eigen_value) {
  double y[N];
  double l = 0.0, old_l = 1.0;

  while (fabs(l-old_l) > EPS*fabs(l)) {
  //for (int i = 0; i < 2; i++) {
    old_l = l;
    multi_mat_vec(y, A, x);
    l = inner_prod(x, y);
    normalize_vec(y, x);
  }
  *eigen_value = l;
}

signed main(int argc, char *argv[]) {
  double lambda;
  double A[][N] = {
    {1, -1},
    {-1, 2}
  };
  double x[] = {1, 0};

  poweigen(A, x, &lambda);
  printf("*** eigen 1 : %f | ", lambda);
  print_vec(x);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      A[i][j] -= lambda * x[i] * x[j];
    }
  }

  x[0] = 1; x[1] = 0;
  poweigen(A, x, &lambda);
  printf("*** eigen 2 : %f | ", lambda);
  print_vec(x);
  return 0;
}
