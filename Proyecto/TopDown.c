#include <stdio.h>
#define n 4

int min(int a, int b) { return a < b ? a : b; }

int lineasProduccion(int a[][n], int t[][n], int *e, int *x) {
  int linea1[n], linea2[n], i;

  linea1[0] = e[0] + a[0][0];
  linea2[0] = e[1] + a[1][0];

  for (i = 1; i < n; ++i) {
    linea1[i] = min(linea1[i - 1] + a[0][i], linea2[i - 1] + t[1][i] + a[0][i]);
    linea2[i] = min(linea2[i - 1] + a[1][i], linea1[i - 1] + t[0][i] + a[1][i]);
  }
  return min(linea1[n - 1] + x[0], linea2[n - 1] + x[1]);
}

int main() {
  int a[][n] = {{4, 5, 3, 2}, {2, 10, 1, 4}};
  int t[][n] = {{0, 7, 4, 5}, {0, 9, 2, 8}};
  int e[] = {10, 12}, x[] = {18, 7};

  printf("%d", lineasProduccion(a, t, e, x));

  return 0;
}
