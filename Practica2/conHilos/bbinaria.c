/**
 * Titutlo Busqueda binaria
 * 
 * este codigo busca un elemento en un arreglo usando
 * el algoritmo de busqueda binaria
 *
 * @date 9/2021
 * @version 1
 * @author "Los ultimos"
 *
 * compilacion gcc -lm -lpthread tiempo.c bbinaria.c -o bbinaria
 * ejecución ./bbinaria size key threads < input
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "tiempo.h"

int binaria(int, int);
//*****************************************************************
//VARIABLES GLOBALES
//*****************************************************************
int NumThreads;	//Número de threads
int size; //tamaño de problema
int key; //valor a buscar
int* array;// arreglo a manejar
int keyfound = 0;//bandera que dice si se encontro el elemento
/**
 * Procesar
 *
 * Esta funcion procesa cada uno de los hilos creados a partir
 * de un numthreads dado y se le asigna cierto rango dependiendo
 * del hilo, a partir de ahi busca el elemento en el arreglo
 * usando el algoritmo dado pero solo busca en ese rango que esta
 * dado por limite inferior y superior, si lo encuentra nos va a
 * imprimir que hilo se encontro y en que posicion y keyfound se
 * pone en 1 indicando que ya no se hagan mas busquedas, si no,
 * la bandera de keyfound nunca va a cambiar y al terminar el
 * procesamiento de hilos vamos a ver que jamas se encontro la
 * llave en ningun hilo.
 * 
 * @param un numero de hilo casteado a void*
 * @return void*
*/
void* procesar(void* id)
{	
    int n_thread = (int)id;
    int inicio,fin,i,a;
    
    //Revisar la parte de los datos a procesar	
    inicio = (n_thread * size) / NumThreads;
    if(n_thread == NumThreads-1)	
	fin = size-1;
    else
	fin = ((n_thread+1) * size) / NumThreads - 1;
        
    int indexfound = binaria(inicio, fin);
    if (indexfound != -1) {
      printf("El hilo %d encontro el numero %d en la posicion %d.\n", n_thread, key, indexfound);
      keyfound = 1;
    }
}
/**
 * binaria
 * 
 * Realiza el algoritmo de busqueda binaria sobre un arreglo ordenado
 *
 * Este algoritmo parte en mitades el arreglo ordenado, de
 * tal manera que con cada comparacion elimina una mitad del
 * arreglo, haciendo asi la busqueda mas rapida, va calculando
 * la mitad entre 2 limites del arreglo y si la llave es menor,
 * recorre el limite superior, si es mayor entonces recorre el
 * limite inferior y si es igual devuelve esa posicion que es
 * la mitad entre ambos limites, al final si el limite inferior
 * es mayor al superior o viceversa quiere decir que ya analizo
 * todas las posiciones posibles no encontro la llave, por lo
 * tanto el numero no esta en el arreglo.
 * 
 * @param un limite inferior y un limite superior del arreglo a buscar
 * @return la posicion donde se encontro el numero o si 
 * no se encontro un -1
*/
int binaria(int l, int r)
{
    if(keyfound == 1)
	return -1;
    int h;
    while(l <= r)
    {
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
int main(int argc, char *argv[])
{
    double utime0, stime0, wtime0, utime1, stime1, wtime1;
    size = atoi(argv[1]);
    key = atoi(argv[2]);
    NumThreads = atoi(argv[3]);
    array = (int *)malloc(size * sizeof(int));
    int i;
    for (i = 0; i < size; i++)
	scanf("%d", array+i);
    printf("Busqueda binaria (key:%d size:%d threads:%d).\n\n",
	   key, size, NumThreads);
    //******************************************************************
    // Iniciar el conteo del tiempo para las evaluaciones de rendimiento
    //******************************************************************
    uswtime(&utime0, &stime0, &wtime0);
    pthread_t *thread = malloc(NumThreads * sizeof(pthread_t));
    //*******************************************************************
    // Procesar desde cada hilo "procesar"
    //*******************************************************************
    // Crear los threads con el comportamiento "segmentar"
    for (i = 1; i < NumThreads; i++) {
	if (pthread_create(&thread[i], NULL, procesar, (void *)i) != 0) {
            perror("El thread no  pudo crearse");
            exit(-1);
	}
    }
    // El main ejecuta el thread 0
    procesar(0);
    // Esperar a que terminen los threads (Saludar)
    for (i = 1; i < NumThreads; i++)
	pthread_join(thread[i], NULL);
    
    if (keyfound == 0)
	printf("Ningun hilo encontro el numero %d en el arreglo.\n", key);
    //******************************************************************
    // Evaluar los tiempos de ejecución
    //******************************************************************
    uswtime(&utime1, &stime1, &wtime1);
    // Cálculo del tiempo de ejecución del programa
    printf("Tiempo real: %.10e s\n", wtime1 - wtime0);
    free(array);
    return 0;
}
