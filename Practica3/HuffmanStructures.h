//*****************************************************************
//HuffmanStructures.h 
//*****************************************************************
//Integrantes del equipo:
//Torres Trejo Victor
//Sotelo Padron Leilani
//Sanchez Flores Guillermo
//
//Curso: Análisis de algoritmos
//(C) Octube 2021
//ESCOM-IPN
//Estructuras de datos y funciones auxiliares para ejecutar el algoritmo de huffman
//*****************************************************************


//*****************************************************************
//Estructuras utilizadas en el programa

// Estructura para almacenar un simbolo, su tamaño de bits y sus bits correspondientes
struct bits{
    unsigned char symbol;
    int sizebits;
    int bits; 
};

//Estructura para almacenar un simbolo y su frecuencia dada
struct data{
    int frequency;
    int symbol;
};

//Estructura del arbol de Huffman
struct node{
    struct node* left;
    struct node* right;
    struct data data;
};

//Estructura del heap utilizado
struct Heap{
    struct node** arrayOfNodes;
    int count;
    int capacity;
};
//Alias del heap
typedef struct Heap Heap;


//*****************************************************************
//Funciones con bits
//Nos da los bits dado un tamaño y un valor x
void showMeBits(unsigned long long x, int bitsSize);
//Escribe los bits de un simbolo
void writeBits(unsigned char symbol, struct bits hashTable[]);
//*****************************************************************
//Funciones con el arbol de Huffman
//Funcion de es vacio
int isEmpty(struct node* root);
//Funcion de es nodo hoja
int isLeaf(struct node* root);
//Funcion que inserta en el arbol de huffman nodos
void pushTree(struct node* root, unsigned char symbol, int frecuency);
//Funcion de unir dos nodos junto con sus frecuencias
struct node* mergeNodes(struct node* node1, struct node* node2);
//Funcion de obtener los bits equivalentes
void getBits(struct node* mainTree, struct bits frecuencyCode[], int bits, int bitsSize);
//Funcion que nos da los bits correspondientes dada una cadena binaria
int getCharacters(struct node* tree, unsigned char* cadena, int* posInString, int posInBits, unsigned char* byteToWrite);

//*****************************************************************
//Funciones con heap

//Crea un espacio en memoria para el heap
Heap *CreateHeap(int capacity);
//Inserta elementos en el heap
void insert(Heap *heap, struct node* node);
//
void heapify_bottom_top(Heap *heap, int index);
//
void heapify_top_bottom(Heap *heap, int parent_node);
//Elimina el primer elemento de la cola de prioridad
struct node* PopMin(Heap *heap);

//**********************************************************************
//Funciones con el arbol de huffman y heap

//Funcion que inserta los nodos de frecuencia en la cola de prioridad
void insertTree(struct data symbolFrecuency[], struct node roots[], Heap* heap);
//unir todos los nodos en uno solo
struct node* mergeTrees(Heap* heap);

//**********************************************************************
//Macros para trabajas con bits
#define PESOBIT(bpos) 1<<bpos
#define CONSULTARBIT(var,bpos) (*(unsigned*)&var & PESOBIT(bpos))?1:0
#define PONE_1(var,bpos) *(unsigned*)&var |= PESOBIT(bpos)
#define PONE_0(var,bpos) *(unsigned*)&var &= ~(PESOBIT(bpos))
#define CAMBIA(var,bpos) *(unsigned*)&var ^= PESOBIT(bpos)
