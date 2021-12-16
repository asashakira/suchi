#include <bits/stdc++.h>
using namespace std;

#define TERMS 2

void set_coeff(double fmat[][TERMS], double py[], double coeff[][TERMS+1], int dnum) {
  for (int i = 0; i < TERMS; i++) {
    for (int j = 0; j < TERMS; j++) {
      coeff[i][j] = 0.0;
      for (int k = 0; k < dnum; k++) {
        coeff[i][j] += fmat[k][i] * fmat[k][j];
      }
    }
    coeff[i][TERMS] = 0.0;
    for (int k = 0; k < dnum; k++) {
      coeff[i][TERMS] += fmat[k][i] * py[k];
    }
  }
}

void gauss_jordan(double a[TERMS][TERMS+1], int size) {
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


signed main(int argc, char *argv[]) {
  //double px[] = {0.2, 0.5, 1, 2, 4, 8, 10};
  //double py[] = {12.1, 4.9, 2.9, 2.1, 2.1, 3.4, 4.3};
  double px[] = {0, 1, 2, 3, 4};
  double py[] = {1, 2, 1, 0, 4};
  int dnum = sizeof(px) / sizeof(px[0]);
  double coeff[TERMS][TERMS+1], fmat[dnum][TERMS];
  for (int j = 0; j < dnum; j++) {
    fmat[j][0] = px[j];
    fmat[j][1] = 1;
  }
  set_coeff(fmat, py, coeff, dnum);
  for (int i = 0; i < TERMS; i++) {
    for (int j = 0; j < TERMS+1; j++) {
      printf("%f ", coeff[i][j]);
    }
    printf("\n");
  }
  gauss_jordan(coeff, TERMS);
  for (int i = 0; i < TERMS; i++) {
    printf("w%d = %.15f\n", i, coeff[i][TERMS]);
  }
  return 0;
}
