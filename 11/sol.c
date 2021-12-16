/*
enshu 11
67170575
Akira Itai
 
gcc sol.c -lm -o a
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define P 5
#define N 23

void calc_cov(double data[N][P], double A[P][P]) {
  double mean[P] = {0};
  for (int j = 0; j < P; j++) {
    for (int i = 0; i < N; i++) {
      mean[j] += data[i][j];
    }
  }
  mean[j] /= N;

  for (int k = 0; k < P; k++) {
    for (int l = 0; l < P; l++) {
      A[k][l] = 0.0;
      for (int i = 0; i < N; i++) {
        A[k][l] += (data[i][k] - mean[k]) * (data[i][l] - mean[l]);
      }
      A[k][l] /= N;
    }
  }
  return;
}

void print_vec(double x) {
  for (int i = 0; i < P; i++) {
    printf("%lf ", x[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  double lambda;
  double data[][P] = {};
  double A[P][P];
  double x[P] = {};
  x[0] = 1;

  calc_cov(data, A);

  poweigen(A, x, &lambda);
  printf("*** 第１主成分 : ");
  print_vec(x);

  return 0;
}
