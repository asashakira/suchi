/*
enshu 09
67170575
Akira Itai
 
gcc sol.c -lm -o a
*/
#include <bits/stdc++.h>
using namespace std;

#define N 2
#define EPS 1e-5

void print_vec(double x[]) {
  for (int i = 0; i < N; i++) {
    cout << x[i] << ' ';
  }
  printf("\n");
}

void print_mat(double A[][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << A[i][j] << ' ';
    }
    cout << '\n';
  }
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

  //while (fabs(l-old_l) > EPS*fabs(l)) {
  for (int i = 0; i < 2; i++) {
    old_l = l;
    multi_mat_vec(y, A, x);
    l = inner_prod(x, y);
    normalize_vec(y, x);
    cout << l << '\n';
    printf("x%d = ", i+1); print_vec(x);
    printf("y%d = ", i+1); print_vec(y);
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

  double a = 0.5257, b = -0.8507, lamb = 2.6180;
  double B[][N] = {
    {a*a, a*b},
    {a*b, b*b}
  };
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      B[i][j] = A[i][j] - lamb * B[i][j];
    }
  }
  print_mat(B);
  cout << '\n';

  double y[N];
  x[0] = 1; x[1] = 0;
  multi_mat_vec(y, B, x);
  print_vec(x);
  for (int i = 0; i < N; i++)
    x[i] = y[i];
  multi_mat_vec(y, B, x);
  print_vec(x);
  print_vec(y);
  normalize_vec(y, x);
  print_vec(x);

  multi_mat_vec(y, B, x);
  cout << '\n';
  print_vec(x);
  print_vec(y);
  cout << inner_prod(x, y) << '\n';

  //cout << "x0 = "; print_vec(x);
  //poweigen(B, x, &lambda);
  //printf("*** eigen 1 : %f | ", lambda);
  //print_vec(x);

  return 0;
}
