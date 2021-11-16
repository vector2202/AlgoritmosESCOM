#include <stdio.h>
#include <stdlib.h>
#include "HuffmanStructures.h"

//***********************************************************************
//Operaciones con el arbol de Huffman.
//***********************************************************************
//Es vacio el arbol
int isEmpty(struct node *root) { return root == NULL; }
//Es un nodo hoja
int isLeaf(struct node *root) { return root->left == NULL && root->right == NULL; }

//Insertar elementos en el arbol huffman
void pushTree(struct node *root, unsigned char byte, int frecuency)
{
    root->data.frequency = frecuency;
    root->data.byte = byte;
    root->left = NULL;
    root->right = NULL;
}
//unir los nodos
struct node *mergeNodes(struct node *node1, struct node *node2)
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data.byte = 0;
    new_node->left = node1;
    new_node->right = node2;
    new_node->data.frequency = node1->data.frequency + node2->data.frequency;
    return new_node;
}
//obtener la codificacion de los caracteres
void getBits(struct node *HuffmanTree, struct bits bytesCode[], int bits,
             int sizeBits) {
  if (!isEmpty(HuffmanTree)) { // if notempty
    getBits(HuffmanTree->left, bytesCode, (bits << 1),
            sizeBits + 1); // irte al nodo izq, sumandole un 0
    if (isLeaf(HuffmanTree)) {
      int hashKey = HuffmanTree->data.byte;
      bytesCode[hashKey].bits = bits;
      bytesCode[hashKey].byte = HuffmanTree->data.byte;
      bytesCode[hashKey].sizeBits = sizeBits;
    }
    getBits(HuffmanTree->right, bytesCode, (bits << 1) + 1,
            sizeBits + 1); // irte al nodo der sumandole un 1
  }
}

int getCharacters(struct node *HuffmanTree, unsigned char *cadena,
                  int *posInString, int posInBits, unsigned char *byteToWrite) {
  if (isLeaf(HuffmanTree)) {
    *byteToWrite = HuffmanTree->data.byte;
    return posInBits;
  } else {
    if (posInBits < 0) {
      (*posInString)++;
      posInBits = 7;
    }
    if (((int)CONSULTARBIT(cadena[(*posInString)], (posInBits))) == 0)
      return getCharacters(HuffmanTree->left, cadena, posInString,
                           (posInBits)-1, byteToWrite);
    else
      return getCharacters(HuffmanTree->right, cadena, posInString,
                           posInBits - 1, byteToWrite);
  }
}

//*********************************************************************
//Funciones de heap.
//*********************************************************************
Heap *CreateHeap(int capacity)
{
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    heap->count = 0;
    heap->capacity = capacity;
    heap->arrayOfNodes = (struct node **)malloc(capacity * sizeof(struct node));
    return heap;
}

void insert(Heap *heap, struct node *node)
{
    if (heap->count < heap->capacity)
    {
        heap->arrayOfNodes[heap->count] = node;
        heapify_bottom_top(heap, heap->count);
        heap->count++;
    }
}

void heapify_bottom_top(Heap *heap, int index)
{
    struct node *temp;
    int parent_node = (index - 1) / 2;
    if (heap->arrayOfNodes[parent_node]->data.frequency >
        heap->arrayOfNodes[index]->data.frequency) {
      temp = heap->arrayOfNodes[parent_node];
      heap->arrayOfNodes[parent_node] = heap->arrayOfNodes[index];
      heap->arrayOfNodes[index] = temp;
      heapify_bottom_top(heap, parent_node);
    }
}

void heapify_top_bottom(Heap *heap, int parent_node)
{
    int left = parent_node * 2 + 1;
    int right = parent_node * 2 + 2;
    int min;
    struct node *temp;

    if (left >= heap->count || left < 0)
        left = -1;
    if (right >= heap->count || right < 0)
        right = -1;

    if (left != -1 && heap->arrayOfNodes[left]->data.frequency <
                          heap->arrayOfNodes[parent_node]->data.frequency)
      min = left;
    else
      min = parent_node;
    if (right != -1 && heap->arrayOfNodes[right]->data.frequency <
                           heap->arrayOfNodes[min]->data.frequency)
      min = right;

    if (min != parent_node)
    {
        temp = heap->arrayOfNodes[min];
        heap->arrayOfNodes[min] = heap->arrayOfNodes[parent_node];
        heap->arrayOfNodes[parent_node] = temp;

        heapify_top_bottom(heap, min);
    }
}

struct node *PopMin(Heap *heap)
{
    struct node *pop;
    if (heap->count == 0)
    {
        printf("Heap is Empty.\n");
        return NULL;
    }
    pop = heap->arrayOfNodes[0];
    heap->arrayOfNodes[0] = heap->arrayOfNodes[heap->count - 1];
    heap->count--;
    heapify_top_bottom(heap, 0);
    return pop;
}
//**********************************************************************
//Funciones con el arbol y heap
//**********************************************************************
//formar en el arbol las frecuencias y formar esos arboles en la cola
void insertTree(struct data bytesFrecuency[], struct node roots[], Heap *heap)
{
    int i;
    for (i = 0; i < 256; i++) {
      if (bytesFrecuency[i].frequency > 0) {
        pushTree(&roots[i], bytesFrecuency[i].byte,
                 bytesFrecuency[i].frequency);
        insert(heap, &roots[i]);
      }
    }
}
//unir todos los nodos en uno solo
struct node *mergeTrees(Heap *heap)
{

    while (heap->count > 1)
    {
        struct node *node1 = PopMin(heap);
        struct node *node2 = PopMin(heap);
        insert(heap, mergeNodes(node1, node2));
    }
    return PopMin(heap);
}
