/**
 * Titutlo Busqueda binaria
 * 
 * este codigo busca un elemento en un arreglo usando el algoritmo de busqueda binaria
 *
 * @date 9/2021
 * @version 1
 * @author "Los ultimos"
 */

#include <stdio.h>
#include <stdlib.h>

int binaria(int array[], int size, int key)
{
    int l = 0, r = size - 1;
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
int main(int argc, char *argv[])
{
    int size = atoi(argv[1]);
    int i, key;
    int* array = (int *)malloc(size * sizeof(int));
    for (i = 0; i < size; i++)
	scanf("%d", array+i);
    printf("Ingrese el numero a buscar: ");
    scanf("%d", &key);
    
    int index = binaria(array, size, key);
    if (index != -1)
        printf("El numero %d se encontro en la posicion %d.\n", key, index);
    else
        printf("El numero %d no esta en el arreglo.\n", key);
}
