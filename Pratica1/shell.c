#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tiempo.h"

void rellenarlista(int [], int);
void shell(int*, int);

int main(int argc, char* argv[])
{
    double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
    int size = atoi(argv[1]); //tamaño del arreglo
    int* Array = malloc(size * sizeof(int)); //solicitamos memoria dinamica

    rellenarlista(Array, size); // rellenar el arreglo
    printf("\nOrdenamiento shell. n = %d\n", size);
    uswtime(&utime0, &stime0, &wtime0); //Iniciamos el conteo
    shell(Array, size);  // ordenamiento shell
    uswtime(&utime1, &stime1, &wtime1); // Evaluar tiempos de ejecucion
    //Calculo de tiempo de ejecucion del programa
    printf("\nReal (Tiempo total): %.10e s\n", wtime1 - wtime0);
    printf("User (Tiempo de procesamiento en CPU): %.10e s\n", utime1 - utime0);
    printf("Sys (Tiempo en acciónes de E/S): %.10e s\n", stime1 - stime0);
    printf("CPU/Wall   %.10f %% \n\n",
           100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
    free(Array); //Liberar la memoria dinamica
    return 0;
}
/** rellenarlista
 *
 * Rellena un arreglo dado con una entrada dada
 *
 * @param un arreglo y su tamaño
 * @return void
 */
void rellenarlista(int A[], int size) {
    int element, i;
    for (i = 0; i < size; i++) {
	scanf("%d", &element);
	A[i] = element;
    }
}
/**
 * Shell
 *
 * Ordena un arreglo aplicando el metodo de ordenamiento shell
 *
 * @param un arreglo y su tamaño
 * @return void
 */
void shell(int* A, int n)
{
    int k, b, temp, i;
    k = trunc(n/2);
    while(k >= 1){
	b = 1;
	while(b > 0){
	    b = 0;
	    for(i = k; i < n; i++){
		if (A[i-k] > A[i]){
		    temp = A[i];
		    A[i] = A[i-k];
		    A[i-k] = temp;
		    b ++;
		}
	    }
	}
	k = trunc(k/2);
    } 	
}
