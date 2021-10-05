/**
 * Titutlo Busqueda lineal
 * 
 * este codigo busca un elemento en un arreglo usando el
 * algoritmo de busqueda lineal
 *
 * @date 9/2021
 * @version 1
 * @author "Los ultimos"
 */

#include <stdio.h>
#include <stdlib.h>
#include "tiempo.h"
int busquedaLineal(int [], int, int);
/**
 *
 * busquedaLineal
 *
 * Esta funcion busca un numero dentro de una lista.
 *
 * Se ingresa su tamaño y compara cada elemento del arreglo desde
 * la posicion 0 con la llave, en caso de que el numero si este en
 * el arreglo la funcion devuelve la posicion mas 1 donde se encuentra
 * el numero, en caso contrario regresa un -1.
 *
 * @param un arreglo su tamaño y la llave a buscar
 * @return la posicion donde se encontro el numero o si no se encontro un -1
*/
int busquedaLineal(int array[], int size, int key)
{
    int i;
    for (i = 0; i < size; i++)
        if (array[i] == key)
            return i+1;
    return -1;
}
int main(int argc, char *argv[])
{
    int i;
    double utime0, stime0, wtime0, utime1, stime1, wtime1;
    int size = atoi(argv[1]);
    int key = atoi(argv[2]);
    int *array = (int *)malloc(size * sizeof(int));
    for (i = 0; i < size; i++)
	scanf("%d", array + i);
    printf("Busqueda lineal (key:%d size:%d).\n\n", key, size);
    //******************************************************************
    // Iniciar el conteo del tiempo para las evaluaciones de rendimiento
    //******************************************************************
    uswtime(&utime0, &stime0, &wtime0);
    //******************************************************************
    // Evaluar los tiempos de ejecución
    //******************************************************************
    int index = busquedaLineal(array, size, key);
    if (index != 1)
	printf("El numero %d se encontro en la posicion %d.\n", key, index);
    else
	printf("El numero %d no existe en el arreglo.\n", key);
    uswtime(&utime1, &stime1, &wtime1);
    // Cálculo del tiempo de ejecución del programa
    printf("Tiempo real: %.10e s\n", wtime1 - wtime0);
    free(array);
    return 0;
}
