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

int busquedaLineal(int array[], int size, int key)
{
    int i;
    for (i = 0; i < size; i++)
        if (array[i] == key)
            return i;
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
    
    int index = busquedaLineal(array, size, key);
    if (index != -1)
        printf("El numero %d se encontro en la posicion %d.\n", key, index);
    else
        printf("El numero %d no esta en el arreglo.\n", key);
}
