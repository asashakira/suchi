#include <bits/stdc++.h>
using namespace std;

#define P 2
#define N 10
#define EPS 1e-5

void calc_cov(double data[N][P], double A[P][P]) {
  double mean[P] = {0};
  for (int j = 0; j < P; j++) {
    for (int i = 0; i < N; i++) {
      mean[j] += data[i][j];
    }
    mean[j] /= N;
    cout << mean[j] << '\n';
  }

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

void print_vec(double x[]) {
  for (int i = 0; i < P; i++) {
    printf("%6.3f ", x[i]);
  }
  printf("\n");
}

void multi_mat_vec(double y[], double A[][P], double x[]) {
  for (int i = 0; i < P; i++) {
    y[i] = 0.0;
    for (int j = 0; j < P; j++) {
      y[i] += A[i][j] * x[j];
    }
  }
}

double inner_prod(double x[], double y[]) {
  double prod = 0.0;
  for (int i = 0; i < P; i++) {
    prod += x[i] * y[i];
  }
  return prod;
}

void normalize_vec(double y[], double x[]) {
  double length = sqrt(inner_prod(y, y));
  for (int i = 0; i < P; i++) {
    x[i] = y[i] / length;
  }
}

void poweigen(double A[][P], double *x, double *eigen_value) {
  double y[P];
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

int main(int argc, char *argv[]) {
  double lambda;
  double data[N][P] = {0};
  double A[P][P];
  double x[P] = {0};
  x[0] = 1;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < P; j++)
      cin >> data[i][j];
  }

  calc_cov(data, A);
  for (int i = 0; i < P; i++) {
    for (int j = 0; j < P; j++)
      cout << A[i][j] << ' ';
    cout << '\n';
  }

  poweigen(A, x, &lambda);
  cout << lambda << '\n';
  printf("*** 第１主成分 : ");
  print_vec(x);

  return 0;
}
