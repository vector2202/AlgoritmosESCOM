/**
 * Titutlo Busqueda de fibonacci
 * 
 * este codigo busca un elemento en un arreglo usando el algoritmo de busqueda de fibonacci
 *
 * @date 9/2021
 * @version 1
 * @author "Los ultimos"
 */
#include <stdio.h>
#include <stdlib.h>

//funcion que dice cual numero es menor
int min (int x, int y);
//funcion que buscar un numero en un arreglo
int busquedafibonacci (int arr [], int x, int n);

int main(int argc, char* argv[]) {
    int size = atoi(argv[1]);
    int i, key;
    int* array = (int *)malloc(size * sizeof(int));
    for (i = 0; i < size; i++)
	scanf("%d", array+i);
    printf("Ingresa el numero a buscar:");
    scanf("%d", &key);

    int index = busquedafibonacci(array, key, size);
    if (index >= 0)
	printf("El numero %d se encontro en la posicion %d.\n", key, index);
    else
        printf("El numero %d no esta en el arreglo.\n", key);
    return 0;
}

//entran dos numeros y retorna el menor de los dos
int min (int x, int y) {return (x <= y) ? x : y;}
// funcion de busqueda donde retorna la posicion del valor buscado, en caso de que no se encuntre retorna -1
int busquedafibonacci (int arr [], int x, int n)
{
    int auxf2,auxf1,auxfm;//auxf2 tomara el valor de n-1 y auxf1 n-2 y auxfm almacenera el numero mas pequeño
    int rango,i;
    auxf2 = 0;
    auxf1 = 1;
    auxfm= auxf2 + auxf1;
    
    while(auxfm < n){ //se inicia ciclo hasta que auxfm sea menor a n
        auxf2 = auxf1;
        auxf1 = auxfm;
        auxfm= auxf2 + auxf1;
    }
    
    rango = -1;// rango toma el valor de -1 
 //el ciclo entra hasta que ya no queden numeros a buscar ,compararemos elindice de auxfm2  y su auxfm1 llegara a tener valor 1 enotnces auxfm2 se vuelve en 0
    while (auxfm > 1) {
        // verifica  si auxfm2 es no es vacio
        i = min(rango + auxf2, n - 1);
 
        //Si numbuscar es mayor que el valor de  auxfm2  el arreglo se dezplaza a i
        if (arr [i] <x) {
            auxfm= auxf1;
            auxf1 = auxf2;
            auxf2 = auxfm- auxf1;
            rango = i;
        }
        //en cambio si  es mayor que el valor en arr[auxfm2],  dezplazamos el arreglo a i+1 
        else if (arr [i]> x) {
            auxfm= auxf2;
            auxf1 = auxf1 - auxf2;
            auxf2 = auxfm- auxf1;
        }
 
       // si el elemnto es encontrado se retorna la posicion i
        else
	    return i;	   
    }
 //se comprara el ultimo elemento con numbusc
    if (auxf1 && arr [rango + 1] == x){
    	 return rango + 1;
	}
       
    //si no se encuentra se retorna -1
    return -1;
}