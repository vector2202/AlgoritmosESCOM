/**
 * Titutlo Busqueda lineal
 * 
 * este codigo busca un elemento en un arreglo usando el algoritmo de busqueda lineal
 *
 * @date 9/2021
 * @version 1
 * @author "Los ultimos"
 */

#include <stdio.h>
#include <stdlib.h>
#include "tiempo.h"

int min (int x, int y) {return (x <= y) ? x : y;}
int binaria(int array[],int l, int size, int key)
{
    int r = size - 1;
    int h;
    while(l <= r)
    {
	h = l + (r - l)/2;
	if(key < array[h])
	    r = h - 1;
	else if(key > array[h])
	    l = h + 1;
	else
	    return h;
    }
    return -1;
}
int exponencial(int array[], int size, int key)
{
    if(array[0] == key)
	return 0;
    int i = 1;
    while(i < size && array[i] < key)
	i *= 2;
    return binaria(array, i/2, min(i, size-1), key);
}
int main(int argc, char *argv[])
{
  int keys[] = {322486,     14700764,   3128036,    6337399,    61396,
                10393545,   2147445644, 1295390003, 450057883,  187645041,
                1980098116, 152503,     5000,       1493283650, 214826,
                1843349527, 1360839354, 2109248666, 2147470852, 0};
  int i, k, sizek = 20;
  double utime0, stime0, wtime0, utime1, stime1, wtime1;
  double sum = 0;
  int size = atoi(argv[1]);
  int *array = (int *)malloc(size * sizeof(int));
  for (i = 0; i < size; i++)
    scanf("%d", array + i);
  for (k = 0; k < sizek; k++) {
    int key = keys[k];
    printf("Busqueda exponencial (key:%d size:%d): ", key, size);

    //******************************************************************
    // Iniciar el conteo del tiempo para las evaluaciones de rendimiento
    //******************************************************************
    double utime0, stime0, wtime0, utime1, stime1, wtime1;
    uswtime(&utime0, &stime0, &wtime0);
    //******************************************************************
    // Evaluar los tiempos de ejecución
    //******************************************************************
    int index = exponencial(array, size, key);
    uswtime(&utime1, &stime1, &wtime1);
    // Cálculo del tiempo de ejecución del programa
    printf(" %.10e s\n", wtime1 - wtime0);
    sum += (wtime1 - wtime0);
  }
  free(array);
  printf("Promedio: %10e\n\n", sum / sizek);
}
