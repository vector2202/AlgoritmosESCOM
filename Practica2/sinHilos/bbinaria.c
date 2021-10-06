/**
 * Titutlo Busqueda binaria
 * 
 * este codigo busca un elemento en un arreglo usando el
 * algoritmo de busqueda binaria
 *
 * @date 9/2021
 * @version 1
 * @author "Los ultimos"
 *
 * compilacion gcc -lm tiempo.c bbinaria.c -o bbinaria
 * ejecución ./bbinaria size key < input
 */
#include <stdio.h>
#include <stdlib.h>
#include "tiempo.h"
int binaria(int [], int, int);
/**
 * binaria
 * 
 * Realiza el algoritmo de busqueda binaria sobre un arreglo ordenado
 *
 * Este algoritmo parte en mitades el arreglo ordenado, de tal manera
 * que con cada comparacion elimina una mitad del arreglo, haciendo
 * asi la busqueda mas rapida, va calculando la mitad entre 2 limites
 * del arreglo y si la llave es menor, recorre el limite superior que
 * es mitad - 1, si es mayor entonces recorre el limite inferior que
 * es mitad + 1 y si es igual devuelve esa posicion que es la mitad
 * entre ambos limites + 1, al final si el limite inferior es mayor
 * al superior o viceversa quiere decir que ya analizo todas las
 * posiciones posibles y no encontro la llave, por lo tanto el
 * numero no esta en el arreglo.
 * 
 * @param un arreglo ordenado su tamaño y la llave a buscar
 * @return la posicion donde se encontro el numero o si no se encontro un -1
*/
int binaria(int array[], int size, int key){
    int l = 0, r = size - 1;
    int h;
    while(l <= r){
	h = l + (r - l)/2;
	if(key < array[h])
	    r = h - 1;
	else if(key > array[h])
	    l = h + 1;
	else
	    return h+1;
    }
    return -1;
}
int main(int argc, char *argv[]){
    int i;
    double utime0, stime0, wtime0, utime1, stime1, wtime1;
    int size = atoi(argv[1]);
    int key = atoi(argv[2]);
    int *array = (int *)malloc(size * sizeof(int));
    for (i = 0; i < size; i++)
	scanf("%d", array + i);
    printf("Busqueda binaria (key:%d size:%d).\n\n ", key, size);
    //******************************************************************
    // Iniciar el conteo del tiempo para las evaluaciones de rendimiento
    //******************************************************************
    uswtime(&utime0, &stime0, &wtime0);
    //******************************************************************
    // Evaluar los tiempos de ejecución
    //******************************************************************
    int index = binaria(array, size, key);
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
