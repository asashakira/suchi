#include <bits/stdc++.h>
using namespace std;

#define N 4

void gauss_jordan(double a[N][N+1], int size) {
  for (int k = 0; k < size; k++) {
    if (a[k][k] == 0) {
      cout << "swap" << '\n';
      swap(a[k], a[k+1]);
      for (int i = 0; i < size; i++) {
        for (int j = 0; j < size+1; j++) {
          printf("%8.5lf ", a[i][j]);
        }
        printf("\n");
      }
    }
    double pivot = a[k][k];
    printf("pivot = a[%d][%d] = %.5lf\n", k, k, pivot);
    cout << '\n';
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

    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size+1; j++) {
        printf("%8.5lf ", a[i][j]);
      }
      printf("\n");
    }
  }
}

int main(int argc, char *argv[]) {
  double a[][N+1] = {
    {2, 4, 1, -3, 0},
    {-1, -2, 2, 4, 10},
    {4, 2, -3, 5, 2},
    {5, -4, -3, 1, 6},
  };

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N+1; j++) {
      printf("%8.5lf ", a[i][j]);
    }
    printf("\n");
  }

  gauss_jordan(a, N);
  cout << '\n';
  for (int i = 0; i < N; i++) {
    printf("x%d = %.15f\n", i, a[i][N]);
  }

  return 0;
}
