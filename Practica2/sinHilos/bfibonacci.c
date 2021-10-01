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
#include "tiempo.h"

//funcion que dice cual numero es menor
int min (int x, int y);
//funcion que buscar un numero en un arreglo
int busquedafibonacci (int arr [], int x, int n);

int main(int argc, char* argv[]) {
  int keys[] = {322486,     14700764,   3128036,    6337399,   61396,
                2147445644, 1295390003, 450057883,  187645041, 1980098116,
                152503,     5000,       1493283650, 214826,    1843349527,
                1360839354, 2109248666, 2147470852, 0};
  int i, k, sizek = 20;
  double utime0, stime0, wtime0, utime1, stime1, wtime1;
  double sum = 0;
  int size = atoi(argv[1]);
  int *array = (int *)malloc(size * sizeof(int));
  for (i = 0; i < size; i++)
    scanf("%d", array + i);
  for (k = 0; k < sizek; k++) {
    int key = keys[k];
    printf("Busqueda fibonacci (key:%d size:%d): ", key, size);

    //******************************************************************
    // Iniciar el conteo del tiempo para las evaluaciones de rendimiento
    //*****************************************************************
    uswtime(&utime0, &stime0, &wtime0);
    //******************************************************************
    // Evaluar los tiempos de ejecución
    //******************************************************************
    int index = busquedafibonacci(array, key, size);
    uswtime(&utime1, &stime1, &wtime1);
    // Cálculo del tiempo de ejecución del programa
    printf(" %.10e s\n", wtime1 - wtime0);
    sum += (wtime1 - wtime0);
  }
  free(array);
  printf("Promedio: %10e\n\n", sum / sizek);
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
