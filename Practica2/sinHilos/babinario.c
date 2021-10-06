/**
 * Titulo Busqueda con un arbol binario
 *
 * Este codigo busca un numero dentro de un arbol binario de busqeda
 * 
 * @date 9/2021
 * @version 1
 * @author "Los ultimos"
 *
 * compilacion gcc -lm tiempo.c babinario.c -o babinario
 * ejecución ./abinario size key < input
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
void search(struct node*, int);
struct node* push(int,struct node*);

/**
 * isempty 
 *
 * Evalua un arbol binario y devuelve si este es vacio o no.
 *
 * Esta funcion compara si el apuntador que le estamos pasando es vacio,
 * comparando este con nulo, si es asi, devuelve un 1 que es
 * equivalente a verdadero, si no es asi, o sea el apuntador no es
 * nulo, devuelve un 0, indicando que no es vacio
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
 * Esta funcion recibe un arbol binario y un elemento y busca si es vacio
 * el arbol, si lo es lo inserta, si no va comparando con el elemento del
 * nodo hasta ver donde lo debe de insertar dependiendo si es mas grande
 * o mas pequeño en relacion a los elementos de los nodos, de esta manera
 * los elementos mas pequeños van en el subarbol izquierdo, y los mas
 * grandes en el derecho.
 *
 * @param un arbol binario y el elemento a insertar
 * @return un arbol binario con el nuevo elemento insertado.
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
 * va comparando el elemento de la raiz con el numero a buscar y si es
 * mas grande el nodo entonces recorre a su subarbol izquierdo y sino
 * al derecho. asi hasta encontrar el numero o llegar a un nodo vacio,
 * al final nos dice si el numero se encontro o no.
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
	printf("El elemento %d no se encontro en el arbol", key);
    else
	printf("El elemento %d se encontro en el arbol", key);
}

int main(int argc, char* argv[]){
    double utime0, stime0, wtime0, utime1, stime1, wtime1;
    int size = atoi(argv[1]);
    int key = atoi(argv[2]);
    struct node *root = NULL; // Inicializar el arbol binario
    int i, element;
    // Insertar los n de numeros en el arbol
    for (i = 0; i < size; i++) {
	scanf("%d", &element);
	root = push(element, root);
    }
    printf("Busqueda arbol binario (key:%d size:%d): ", key, size);
    //******************************************************************
    // Iniciar el conteo del tiempo para las evaluaciones de rendimiento
    //******************************************************************;
    uswtime(&utime0, &stime0, &wtime0);
    //******************************************************************
    // Evaluar los tiempos de ejecución
    //******************************************************************
    search(root, key);
    uswtime(&utime1, &stime1, &wtime1);
    // Cálculo del tiempo de ejecución del programa
    printf(" %.10e s\n", wtime1 - wtime0); 
    return 0;
}
