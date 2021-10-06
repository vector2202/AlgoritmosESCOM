/**
 * Titutlo Busqueda de fibonacci
 * 
 * este codigo busca un elemento en un arreglo usando el
 * algoritmo de busqueda de fibonacci
 *
 * @date 9/2021
 * @version 1
 * @author "Los ultimos"
 *
 * compilacion gcc -lm tiempo.c bfibonacci.c -o bfibonacci
 * ejecución ./bfibonacci size key < input
 */
#include <stdio.h>
#include <stdlib.h>
#include "tiempo.h"

//funcion que dice cual numero es menor
int min (int x, int y);
//funcion que buscar un numero en un arreglo
int busquedafibonacci (int arr [], int x, int n);

int main(int argc, char* argv[])
{
    int i;
    double utime0, stime0, wtime0, utime1, stime1, wtime1;
    int size = atoi(argv[1]);
    int key = atoi(argv[2]);
    int *array = (int *)malloc(size * sizeof(int));
    for (i = 0; i < size; i++)
	scanf("%d", array + i);
    printf("Busqueda fibonacci (key:%d size:%d).\n\n", key, size);
    //******************************************************************
    // Iniciar el conteo del tiempo para las evaluaciones de rendimiento
    //*****************************************************************
    uswtime(&utime0, &stime0, &wtime0);
    //******************************************************************
    // Evaluar los tiempos de ejecución
    //******************************************************************
    int index = busquedafibonacci(array, key, size);
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

//entran dos numeros y retorna el menor de los dos
int min (int x, int y) {return (x <= y) ? x : y;}
/**
 * busqueda fibonacci
 *
 * Entra n el cual buscara dos numero de la serie de fibonacci que
 * mas cerca a n y se sumaran, con ese numero entrara al segundo
 * while hasta que la suma de los dos numeros de la serie de fibonacci
 * sean menor a 1, una vez entrando al while se define i que se define
 * entre la suma del rango +auxfm2 o n-1 el que sea menor es el que i
 * tendra su valor  despues  entra a un if si el donde compara la
 * posicion i con el numero a buscar, si es menor i a x se dezpalazan
 * los valores  y se resntan al numero de la serie fibonacci. si no
 * entra al if  esta otra comparacion donde  se compara que el numero
 * de la posicion i sea mayor a x y dezplaza los valores y resta de los
 * dos numeros de la serie fibonacci y si no entra a este if es por
 * que el numero a comparar es el numero buscado por lo cual retorna
 * i que es la posicion. si el numero a buscar no esta dentro del
 * rango de limite inferior y superior, regresa que no lo encontro,
 * esto lo sabemos porque tenemos un arreglo ordenado.
 * 
 * @param un arreglo ordenado su tamaño y la llave a buscar
 * @return la posicion donde se encontro el numero o si no se encontro un -1
*/
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
	    return i+1;	   
    }
 //se comprara el ultimo elemento con numbusc
    if (auxf1 && arr [rango + 1] == x){
	return rango + 1;
    }
    //si no se encuentra se retorna -1
    return -1;
}
