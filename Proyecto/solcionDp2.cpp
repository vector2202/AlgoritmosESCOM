#include <bits/stdc++.h>
#define n 4

int lineasProduccion(int a[][n], int t[][n], int *e, int *x) {
    int first, second, up, down;
    first = e[0] + a[0][0];
    second = e[1] + a[1][0];
    for (int i = 1; i < n; i++) {
	up = std::min(first + a[0][i], second + t[1][i] + a[0][i]);
	down = std::min(second + a[1][i], first + t[0][i] + a[1][i]);
	first = up;
	second = down;
    }
    return std::min(first + x[0], second + x[1]);
}

int main() {
  int a[][4] = {{4, 5, 3, 2}, {2, 10, 1, 4}};
  int t[][4] = {{0, 7, 4, 5}, {0, 9, 2, 8}};
  int e[] = {10, 12}, x[] = {18, 7};
  std::cout << lineasProduccion(a, t, e, x);
  return 0;
}
