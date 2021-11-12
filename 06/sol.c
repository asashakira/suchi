/*
enshu 06
67170575
Akira Itai
 
gcc sol.c -lm -o a
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 5

void gauss_jordan(double a[N][N+1], int size) {
  for (int k = 0; k < size; k++) {
    double pivot = a[k][k];
    for (int i = k; i < size+1; i++) {
      a[k][i] /= pivot;
    }
    for (int j = 0; j < size; j++) {
      if (j == k) continue;
      double s = a[j][k];
      for (int i = k; i < size+1; i++) {
        a[j][i] -= s*a[k][i];
      }
    }

    printf("k = %d\n", k);
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size+1; j++) {
        printf("%10.5lf ", a[i][j]);
      }
      printf("\n");
    }
    printf("\n");
  }
}

int main(int argc, char *argv[]) {
  double coeff[][N+1] = {
    {2, 7, -1, 5, -3, 6},
    {1, -4, 2, -1, 6, 1},
    {3, 1, -9, -2, 1, -2},
    {10, -2, -5, 8, -7, 4},
    {-4, 3, 12, -4, -2, -10},
  };

  gauss_jordan(coeff, N);
  for (int i = 0; i < N; i++) {
    printf("x%d = %.15f\n", i, coeff[i][N]);
  }

  return 0;
}
