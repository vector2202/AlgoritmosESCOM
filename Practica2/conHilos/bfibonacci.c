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
#include <pthread.h>
#include "tiempo.h"

//funcion que dice cual numero es menor
int min (int x, int y);
//funcion que buscar un numero en un arreglo
int busquedafibonacci (int, int);
//*****************************************************************
//VARIABLES GLOBALES
//*****************************************************************

int NumThreads;	//Número de threads
int size; //tamaño de problema
int key; //valor a buscar
int* arr;// arreglo a manejar
int keyfound = 0;//bandera que dice si se encontro el elemento

/**
 * Procesar
 *
 * Esta funcion procesa cada uno de los hilos creados a partir de un numthreads dado
 * y se le asigna cierto rango dependiendo del hilo, a partir de ahi busca el elemento
 * en el arreglo pero solo en ese rango, si lo encuentra nos va a imprimir en que hilo
 * se encontro y en que posicion, si no, la bandera de keyfound nunca va a cambiar y al
 * terminar el procesamiento de hilos vamos a ver que jamas se encontro la llave en ningun hilo.
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
	fin = size - 1;
    else
	fin = ((n_thread+1) * size) / NumThreads - 1;
        
    int indexfound = busquedafibonacci(inicio, fin);
    if (indexfound != -1) {
      printf(
          "El hilo %d encontro el numero %d en la posicion %d.\n",
          n_thread, key, indexfound);
      keyfound = 1;
    }
}
int main(int argc, char* argv[]) {
    size = atoi(argv[1]);
    key = atoi(argv[2]);
    NumThreads = atoi(argv[3]);
    arr = (int *)malloc(size * sizeof(int));
    int i;
    for (i = 0; i < size; i++)
	scanf("%d", arr+i);
    printf("\nBusqueda de fibonacci (key:%d size:%d threads:%d).\n\n", key, size, NumThreads);

    //******************************************************************
    //Iniciar el conteo del tiempo para las evaluaciones de rendimiento
    //******************************************************************
    double utime0, stime0, wtime0,utime1, stime1, wtime1;
    uswtime(&utime0, &stime0, &wtime0);
    pthread_t* thread = malloc(NumThreads * sizeof(pthread_t));
    //*******************************************************************
    //Procesar desde cada hilo "procesar"
    //*******************************************************************
    //Crear los threads con el comportamiento "segmentar"
    for (i = 1; i < NumThreads; i++) 
    {
	if (pthread_create (&thread[i], NULL, procesar,(void*)i) != 0 ) 
	{
	    perror("El thread no  pudo crearse");
	    exit(-1);
	}
    }
    //El main ejecuta el thread 0
    procesar(0);
    //Esperar a que terminen los threads (Saludar)
    for (i = 1; i < NumThreads; i++) pthread_join (thread[i], NULL);

    if(keyfound == 0)
	printf("Ningun hilo encontro el numero %d en el arreglo.\n", key);
    //******************************************************************
    // Evaluar los tiempos de ejecución
    //******************************************************************
    uswtime(&utime1, &stime1, &wtime1);
    // Cálculo del tiempo de ejecución del programa
    printf("\n");
    printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
    printf("user (Tiempo de procesamiento en CPU's) %.10e s\n",
           utime1 - utime0);
    printf("%d threads (Tiempo de procesamiento aproximado por cada thread en "
           "CPU) %.10e s\n",
           NumThreads, (utime1 - utime0) / NumThreads);
    printf("sys (Tiempo en acciónes de E/S)  %.3e s\n", stime1 - stime0);
    printf("CPU/Wall   %.10f %% \n",
           100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
    printf("\n");
    return 0;
}
/**
 * min
 *
 * Esta funcion dados dos numeros, te regresa el menor de ellos haciendo una comparacion.
 *
 * @param un entero x y un entero y.
 * @return el menor de ambos enteros
*/
int min (int x, int y) {return (x <= y) ? x : y;}
/**
 * busqueda fibonacci
 *
 * Entra n el cual buscara dos  numero de la serie de fibonacci que mas cerca a n y se sumaran, con ese
 * numero entrara al segundo while hasta que la suma de los dos numeros de la serie de fibonacci sean menor
 * a 1, una vez entrando al while se define i  que se define entre la suma del rango +auxfm2 o n-1 el que sea
 * menor es el que i tendra su valor  despues  entra a un if si el donde  compara la posicion i con el numero a
 * buscar, si es menor i a x  se dezpalazan los valores  y se resntan al numero de la serie fibonacci.  si no
 * entra al if  esta otra comparacion donde  se compara que el numero de la posicion i sea mayor a x y dezplaza
 * los valors y resta de los dos numeros de la serie fibonacci y si no entra a este if es por que el numero a
 * comparar es el numero buscado por lo cual retorna i que es la posicion. si el numero a buscar no esta dentro del
 * rango de limite inferior y superior, regresa que no lo encontro, esto lo sabemos porque tenemos un arreglo ordenado.
 * 
 * @param un limite inferior y un limite superior del arreglo a buscar
 * @return la posicion donde se encontro el numero o si no se encontro un -1
*/
int busquedafibonacci (int l, int r)
{
    if(keyfound == 1)
	return -1;
    if(key < arr[l] || key > arr[r])
	return -1;
    int auxf2,auxf1,auxfm;//auxf2 tomara el valor de n-1 y auxf1 n-2 y auxfm almacenera el numero mas pequeño
    int rango,i;
    auxf2 = 0;
    auxf1 = 1;
    auxfm= auxf2 + auxf1;
    
    while(auxfm < r){ //se inicia ciclo hasta que auxfm sea menor a n
        auxf2 = auxf1;
        auxf1 = auxfm;
        auxfm= auxf2 + auxf1;
    }
    
    rango = -1;// rango toma el valor de -1 
 //el ciclo entra hasta que ya no queden numeros a buscar ,compararemos elindice de auxfm2  y su auxfm1 llegara a tener valor 1 enotnces auxfm2 se vuelve en 0
    while (auxfm > 1) {
        // verifica  si auxfm2 es no es vacio
        i = min(rango + auxf2, r);
 
        //Si numbuscar es mayor que el valor de  auxfm2  el arreglo se dezplaza a i
        if (arr [i] < key) {
            auxfm = auxf1;
            auxf1 = auxf2;
            auxf2 = auxfm- auxf1;
            rango = i;
        }
        //en cambio si  es mayor que el valor en arr[auxfm2],  dezplazamos el arreglo a i+1 
        else if (arr [i] > key) {
            auxfm = auxf2;
            auxf1 = auxf1 - auxf2;
            auxf2 = auxfm- auxf1;
        }
 
       // si el elemnto es encontrado se retorna la posicion i
        else
	    return i+1;	   
    }
 //se comprara el ultimo elemento con numbusc
    if (auxf1 && arr [rango + 1] == key){
    	 return rango + 1;
	}
       
    //si no se encuentra se retorna -1
    return -1;
}
