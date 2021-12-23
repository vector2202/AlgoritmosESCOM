/**
 *@brief Algoritmo que resuelve el problema de lienas de produccion
 * usando dp
 * @author Los ultimos
 */
#include <bits/stdc++.h>
/**
 * Resuelve el problema de lineas de produccion usando Dp
 *
 * @param a los tiempos que se tarda cada estacion en hacer un trabajo
 * @param t los tiempos que tarda cambiarse de una linea a otra
 * @param e los tiempos de entrada de cada linea
 * @param x los tiempos de salida de cada linea
 * @param n el tamaño de lineas a usar
 * @return el menor tiempo posible de ruta
 */
int lineasProduccion(int** a, int** t, int *e, int *x, int n) {
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
    int n, m;
    std::cin >> n;
    int** a = new int *[2];
    a[0] = new int [n];
    a[1] = new int [n];
    int** t = new int *[2];
    t[0] = new int [n];
    t[1] = new int [n];
    int* e = new int[2], * x = new int [2];
    for(int i = 0; i < n; i++)
	std::cin >> a[0][i];
    for(int i = 0; i < n; i++)
	std::cin >> a[1][i];
    for(int i = 1; i < n; i++)
	std::cin >> t[0][i];
    for(int i = 1; i < n; i++)
	std::cin >> t[1][i];
    std::cin >> e[0] >> e[1] >> x[0] >> x[1];
	//int a[][4] = {{4, 5, 3, 2}, {2, 10, 1, 4}};
	//int t[][4] = {{0, 7, 4, 5}, {0, 9, 2, 8}};
//    int e[] = {10, 12}, x[] = {18, 7};
    std::cout << lineasProduccion(a, t, e, x, n);
    return 0;
}
