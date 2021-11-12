/*
 * 67170575
 * Akira Itai
 *
gcc sol.c -lm -o a
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 1.0e-6

double f(double x) {
  return 10000*sqrt(x);
  return 4.0/(1+x*x);
  return 1.0/x;
}

double simpson(double a, double b, int n) {
  double h = (b-a) / n;
  double s = f(a) + f(b) + 4.0*f(a+h);
  
  for (int k = 1; k < n/2; k++) {
    s += 2.0*f(a + 2*k*h) + 4.0*f(a + (2*k+1)*h);
  }
  return s * h/3.0;
}

int main(int argc, char *argv[]) {
  double a = 0.0;
  double b = 1.0;
  double prev = 1001001001, ans = 0;
  
  for (int n = 2; fabs(prev-ans) > EPS; n*=2) {
    prev = ans;
    ans = simpson(a, b, n);
    printf("%f %f %d %.15f\n", a, b, n, ans);
  }

  return 0;
}
