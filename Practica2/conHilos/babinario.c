/**
 * Titulo Busqueda con un arbol binario
 *
 * Este codigo busca un numero dentro de un arbol binario de busqeda
 * 
 * @date 9/2021
 * @version 1
 * @author "Los ultimos"
 */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <pthread.h>
#include "tiempo.h"
//Estructura del arbol binario
struct node{
    int data;
    struct node* left;
    struct node* right;
};

int isempty(struct node*);
int search(struct node*, int);
struct node* push(int,struct node*);
//*****************************************************************
//VARIABLES GLOBALES
//*****************************************************************
int NumThreads;	//Número de threads
int size; //tamaño de problema
int key; //valor a buscar
struct node** arrayTree;
int keyfound = 0;//bandera que dice si se encontro el elemento

/**
 * Procesar
 *
 * Esta funcion procesa cada uno de los hilos creados a partir de
 * un numthreads dado y se le asigna indice dependiendo del hilo,
 * a partir de ahi busca el elemento en el numero de arbol del
 * numero de hilo, pero solo ese arbol, si lo encuentra mediante
 * keyfound dice que se encontro y ya ningun otro hilo hace mas
 * busquedas despues de esto, si no lo encuentra keyfound nunca
 * cambia y al terminar el procesamiento de hilos vamos a ver
 * que jamas se encontro la llave en ningun hilo ni arbol.
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
        
    int indexfound = search(arrayTree[n_thread], key);
    if (indexfound != -1) {
      printf(
          "El hilo %d encontro el numero %d.\n",
          n_thread, key);
      keyfound = 1;
    }
}
/**
 * isempty 
 *

 * Evalua un arbol binario y devuelve si este es vacio o no.
 *
 * Esta funcion compara si el apuntador que le estamos pasando
 * es vacio, comparando este con nulo, si es asi, devuelve un 1
 * que es equivalente a verdadero, si no es asi, o sea el
 * apuntador no es nulo, devuelve un 0, indicando que no es vacio
 *
 * @param un arbol binario.
 * @return 1 si el arbol es vacio, 0 si no lo es.
 */
int isempty(struct node* root){return root == NULL;}

/**
 * push 
 *
 * Inserta un elemento en el arbol binario.
 *
 * Esta funcion recibe un arbol binario y un elemento y busca
 * si es vacio el arbol, si lo es lo inserta, si no va comparando
 * con el elemento del nodo hasta ver donde lo debe de insertar
 * dependiendo si es mas grande o mas pequeño en relacion a los
 * elementos de los nodos, de esta manera los elementos mas pequeños
 * van en el subarbol izquierdo, y los mas grandes en el derecho.
 *
 * @param un arbol binario y el elemento a insertar
 * @return un arbol binario con el nuevo elemento insertado.
 */
struct node* push(int dataToInsert, struct node* root)
{
    if (isempty(root)) {
	struct node* new_node = malloc(sizeof(struct node));
	new_node->data = dataToInsert;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
    }
    else if(dataToInsert < root->data)
	root->left = push(dataToInsert, root->left);
    else
	root->right = push(dataToInsert, root->right);
    return root;
}

/**
 * search
 *
 * esta funcion busca un numero en un arbol binario
 *
 * va comparando el elemento de la raiz con el numero a buscar
 * y si es mas grande el nodo entonces recorre a su subarbol
 * izquierdo y sino al derecho. asi hasta encontrar el numero
 * o llegar a un nodo vacio, al final nos dice si el numero
 * se encontro o no. si keyfound esta en 1, ni busca porque
 * ese numero ya se encontro.
 *
 * @param un arbol binario y la llave a buscar
 * @return void
 */
int search(struct node* root, int key)
{
    if(keyfound == 1)
	return -1;
    struct node* aux = root;
    while(!isempty(aux) && key != aux->data)
	aux = (key < aux->data) ? aux->left : aux->right;
    if(isempty(aux))
	return -1;
    else
        return 1;
}

int main(int argc, char* argv[]){
    double utime0, stime0, wtime0, utime1, stime1, wtime1;
    size = atoi(argv[1]);
    key = atoi(argv[2]);
    NumThreads = atoi(argv[3]);
    arrayTree = (struct node **)malloc(NumThreads * sizeof(struct node));
    int i, element, j;
    for (j = 0; j < NumThreads; j++) {
	for (i = 0; i < size / NumThreads; i++) {
	    scanf("%d", &element);
	    arrayTree[j] = push(element, arrayTree[j]);
	}
    }
    printf("Busqueda arbol binario (key:%d size:%d threads:%d)\n\n", key, size, NumThreads);
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
    return 0;
}
