/*
enshu 07
67170575
Akira Itai
 
gcc sol.c -lm -o a
*/
#include <bits/stdc++.h>
using namespace std;

#define N 3

void print_array(double a[][N], int size) {
  for (int j = 0; j < size; j++) {
    for (int i = 0; i < size; i++) {
      printf("%f ", a[j][i]);
    }
    printf("\n");
  }
  printf("\n");
}

void print_vec(double v[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%f ", v[i]);
  }
  printf("\n");
}

void lu_decomp(double a[][N], int size) {
  for (int k = 0; k < size; k++) {
    double pivot = a[k][k];
    for (int i = k+1; i < size; i++) {
      a[k][i] /= pivot;
    }
    for (int j = k+1; j < size; j++) {
      double s = a[j][k];
      for (int i = k+1; i < size; i++) {
        a[j][i] -= s*a[k][i];
      }
    }
  }
  return;
}

void lu_solve(double lu[][N], double *b, int size) {
  double y[size];
  for (int j = 0; j < size; j++) {
    y[j] = b[j];
    for (int i = 0; i < j; i++) {
      y[j] -= lu[j][i] * y[i];
    }
    y[j] /= lu[j][j];
  }
  printf("前進代入\n");
  for (int i = 0; i < size; i++) {
    printf("y[%d] = %lf\n", i, y[i]);
  }
  cout << '\n';

  for (int j = size-1; j >= 0; j--) {
    b[j] = y[j];
    for (int i = j+1; i < size; i++) {
      b[j] -= lu[j][i] * b[i];
    }
  }
  return;
}

int main(int argc, char *argv[]) {
  double a[][N] = {
    {2, -4, 6},
    {-1, 3, -4},
    {1, 1, -2},
  };
  double b[] = {5, -3, 2};

  double c[][N] = {
    {2, -3, 4},
    {-3, 7, -1},
    {4, -3, 9},
  };
  double d[] = {1, -2, 3};

  print_array(a, N);
  lu_decomp(a, N);
  printf("L = \n");
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (j < i) printf("%6.2lf ", a[i][j]);
      else printf("%6.2lf", 0.0);
    }
    cout << '\n';
  }
  cout << '\n';

  printf("U = \n");
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i < j) printf("%6.2lf ", a[i][j]);
      else if (i == j) printf("%6.2lf", 1.0);
      else printf("%6.2lf", 0.0);
    }
    cout << '\n';
  }
  cout << '\n';

  lu_solve(a, b, N);
  printf("ans = ");
  print_vec(b, N);

  return 0;
}
