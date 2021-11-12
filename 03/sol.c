/*
 * enshu 03
 *
 * 67170575
 * Akira Itai
 *
gcc sol.c -lm -o a
 */

#include <stdio.h>

double lagrange(double *px, double *py, int points, double x) {
  double y = 0.0;
  for (int i = 0; i < points; i++) {
    double L = 1.0;
    for (int j = 0; j < points; j++) {
      if (i == j) continue;
      L *= (x-px[j]) / (px[i]-px[j]);
    }
    y += L*py[i];
  }
  return y;
}

int main(int argc, char *argv[]) {
  double px[] = {1.0, 1.3, 1.6, 2.0};
  double py[] = {-0.403, -0.158, 0.896, 1.513};
  int size = sizeof(px) / sizeof(px[0]);
  double y = 0.0;
  printf("%f %.15f\n", y, lagrange(py, px, size, y));
}
