#include <stdio.h>
#include <stdlib.h>
#define n 5

/**
 * Devuelve el minimo dados dos enteros dados
 * @param a primer numero a comparar
 * @param b el segundo numero a comparar
 * @return el menor numero de ambos
 */
int min(int a, int b) { return (a <= b) ? a : b; }

/**
 * Resuelve el problema de lineas de produccion explorando todos los caminos
 * posibles (quedarse en la linea actual o cambiarse) y devuelve el menor
 * de ambos caminos
 * @param a los tiempos que se tarda cada estacion en hacer un trabajo
 * @param t los tiempos que tarda cambiarse de una linea a otra
 * @param x los tiempos de salida de cada linea
 * @param i el numero de estacion que estamos explorando
 * @param camino el tiempo acumulado dado el camino tomado
 * @param linea la linea de produccion en la que estamos
 * @return el menor tiempo posible de todos los caminos posibles
 */
int solbruta(int a[2][n], int t[2][n - 1], int x[], int i, int camino,
             int linea) {
  if (i >= n)
    return camino + x[linea];
  int quedarse = 0, cambiarse = 0;
  // nos quedamos en la linea
  quedarse = solbruta(a, t, x, i + 1, camino + a[linea][i], linea);
  // nos cambiamos de linea
  cambiarse = solbruta(a, t, x, i + 1, camino + t[linea][i] + a[linea][i],
                       (linea == 0) ? 1 : 0);
  return min(quedarse, cambiarse);
}

int main() {

  int a[2][n] = {{8, 10, 4, 5, 9}, {9, 6, 7, 5, 6}}; // t de las estaciones
  int t[2][n - 1] = {{2, 3, 1, 3}, {2, 1, 2, 2}}; // cambio de estacion
  int e[2] = {3, 5};                              // entrada a la linea
  int x[2] = {2, 1};                              // salida de la linea
  // Que camino inicial es mejor?
  int camino = ((e[0] + a[0][0]) <= (e[1] + a[1][0])) ? (e[0]) : (e[1]);
  int lp = ((e[0]) == camino) ? 0 : 1; // Que linea elegimos ?
  printf("%d", solbruta(a, t, x, 0, camino, lp));
  return 0;
}
