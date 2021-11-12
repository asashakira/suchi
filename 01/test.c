#include <stdio.h>
#include <stdlib.h>

void change(int ***A) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      A[0][i][j] = 6;
    }
  }
}

void solve(int ***A) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      printf("%d\n", A[0][i][j]);
    }
  }
}

signed main() {
  int **A = (int **)malloc(sizeof(int *));
  int n = 0;
  A[n] = (int *)malloc(2*sizeof(int));
  A[n][0] = n;
  A[n][1] = n;
  n++;
  for (int i = 0; i < 2; i++) {
    A = (int **)realloc(A, (n+1)*sizeof(int *));
    A[n] = (int *)malloc(2*sizeof(int));
    A[n][0] = n;
    A[n][1] = n;
    n++;
  }

  solve(&A);
  change(&A);
  solve(&A);

  return 0;
}
