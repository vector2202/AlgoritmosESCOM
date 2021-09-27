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
    int size = atoi(argv[1]);
    int i, key = atoi(argv[2]);
    int* array = (int *)malloc(size * sizeof(int));
    for (i = 0; i < size; i++)
	scanf("%d", array+i);
    
    int index = exponencial(array, size, key);
    if (index != -1)
        printf("El numero %d se encontro en la posicion %d.\n", key, index);
    else
        printf("El numero %d no esta en el arreglo.\n", key);
}
