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

//*****************************************************************
//VARIABLES GLOBALES
//*****************************************************************
int NumThreads; //Número de threads
int N; //tamaño de problema

//Estructura del arbol binario
struct node{
    int data;
    struct node* left;
    struct node* right;
};

int isempty(struct node*);
void search(struct node*, int);
struct node* push(int,struct node*);

/**
 * isempty 
 *
 * Evalua un arbol binario y devuelve si este es vacio o no.
 *
 * Esta funcion compara si el apuntador que le estamos pasando es vacio, comparando este con nulo, si es asi, devuelve un 1 que es
 * equivalente a verdadero, si no es asi, o sea el apuntador no es nulo, devuelve un 0, indicando que no es vacio
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
 * Esta funcion recibe un arbol binario y un elemento y busca si es vacio el arbol, si lo es
 * lo inserta, si no va comparando con el elemento del nodo hasta ver donde lo debe de insertar
 * dependiendo si es mas grande o mas pequeño en relacion a los elementos de los nodos, de esta manera
 * los elementos mas pequeños van en el subarbol izquierdo, y los mas grandes en el derecho.
 *
 * @param un arbol binario y el elemento a insertar
 * @return un arbol binario con el nuevo elemento.
 */
struct node* push(int dataToInsert,struct node* root)
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
 * va comparando el elemento de la raiz con el numero a buscar y si es mas grande 
 * el nodo entonces recorre a su subarbol izquierdo y sino al derecho. asi hasta encontrar
 * el numero o llegar a un nodo vacio
 *
 * @param un arbol binario y la llave a buscar
 * @return void
 */
void search(struct node* root, int key)
{
    struct node* aux = root;
    while(!isempty(aux) && key != aux->data)
	aux = (key < aux->data) ? aux->left : aux->right;
    if(isempty(aux))
       printf("El numero %d no se encontro.\n", key);
    else
	printf("El numero %d se encontro.\n", key);
}

int main(int argc, char* argv[]){
    double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
    int i, element, key;
    int size = atoi(argv[1]); //Tamaño del arreglo que usaremos
    struct node* root = NULL; // Inicializar el arbol binario
    //Insertar los n de numeros en el arbol
    for (i = 0; i < size; i++) {
	scanf("%d", &element);
	root = push(element, root);
    }
    
    //printf("\nOrdenamiento con arbol binario de busqueda n = %d.\n", size);
    uswtime(&utime0, &stime0, &wtime0); //Iniciamos el conteo
    search(root, key); //Realizar el ordenamiento
    uswtime(&utime1, &stime1, &wtime1); // Evaluar tiempos de ejecucion
    
    //Calculo de tiempo de ejecucion del programa
    printf("\nReal (Tiempo total): %.10e s\n", wtime1 - wtime0);
    printf("User (Tiempo de procesamiento en CPU): %.10e s\n", utime1 - utime0);
    printf("Sys (Tiempo en acciónes de E/S): %.10e s\n", stime1 - stime0);
    printf("CPU/Wall   %.10f %% \n\n",
           100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
    free(root); // Liberar la memoria dinamica
    return 0;
}
