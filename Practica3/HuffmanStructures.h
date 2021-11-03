/**
 * @file
 * @brief Las esctructuras y funciones usadas en el Algoritmo de Huffman
 *
 * @author Victor Torres
 * @author Leilani Sotelo
 * @author Guillermo Sanchez
 * @version 1.0
 */

//*****************************************************************
//Estructuras utilizadas en el programa

/** @struct bits
 * @brief Almacena el byte correspondiente, su tamaño y sus bits de la codificacion de Huffman
 * @var bits::byte
 * 'byte' contiene el valor decimal del byte leido
 * @var bits::bits
 * 'bits' contiene el valor en entero de los bits correspondientes a la codifiacion 
 * @var bits::sizeBits
 * 'sizeBits' contiene el tamaño de los bits correspondientes a la codifcacion
 */

struct bits
{
    unsigned char byte;
    int sizeBits;
    int bits;
};

/** @struct data
 * @brief Almacena un byte y las veces que aparecio en el archivo
 * @var data::byte
 * 'byte' contiene el valor decimal del byte leido
 * @var data::frecuency
 * 'frecuency' contiene las veces que aparecio el byte en el archivo leido
 */
struct data
{
    int frequency;
    int byte;
};

/** @struct node
 * @brief Estructura del arbol de Huffman
 * @var node::left
 * 'left' contiene el nodo hijo izquierdo
 * @var node::right
 * 'right' contiene el nodo hijo derecho
 * @var node::data
 * 'data' contiene el byte correspondiente y su frecuencia
 */
struct node
{
    struct node *left;
    struct node *right;
    struct data data;
};

/** @struct Heap
 * @brief Almacena un arreglo de nodos
 * @var node::arrayOfNodes
 * 'arrayOfNodes' contiene un arreglo de nodos
 * @var Heap::count
 * 'count' contiene los nodos existentes en el arreglo
 * @var Heap::capacity 
 * 'capacity' contiene la capacidad maxima del arreglo
 */
struct Heap
{
    struct node **arrayOfNodes;
    int count;
    int capacity;
};
//Alias de Heap
typedef struct Heap Heap;

//*****************************************************************
//Funciones con el arbol de Huffman

/**
 * Nos dice si nodo en el arbol de Huffman es vacio o no.
 *
 * @param root el nodo a comparar
 * @return 1 si el arbol es vacio
 * @return 0 si el arbol no es vacio
 */
int isEmpty(struct node *root);
/**
 * Nos dice si nodo en el que estamos es un nodo hoja.
 *
 * @param root el nodo a analizar
 * @return 1 si el nodo es hoja
 * @return 0 si el nodo no es hoja
 */
int isLeaf(struct node *root);
/**
 * Inserta dado un byte y una frecuencia, las inserta en el nodo del arbol
 *
 * @param root el arbol de Huffman donde se insertara
 * @param byte el byte correspondiente de su frecuencia
 * @param frecuency la frecuencia correspondiente del byte
 */
void pushTree(struct node *root, unsigned char byte, int frecuency);
/**
 * Une dos nodos en un nodo ancestro comun
 *
 * @param node1 el primer nodo a unir que estara del lado izquierdo
 * @param node2 el segundo nodo a unir que estara del lado derecho
 * @return el nodo comun que tiene como hijos a ambos nodos
 */
struct node *mergeNodes(struct node *node1, struct node *node2);
/**
 * Obtiene la codificaciond de Huffman correspondiente a los bytes.
 * La guarda en un arreglo de struct junto con el tamaño de bits
 * correspondiente. La codificacion se obtiene recorriendo el arbol
 * inorder y cada vez registramos un 0 o un 1 si nos vamos a la
 * izquierda o derecha, al final si es nodo hoja, guardamos lo que
 * llevamos
 *
 * @param HuffmanTree el arbol de Huffman
 * @param bytesCode el arreglo donde se guarda el byte, su codificacion y tamaño
 * @param bits los bits con los que inicia el nodo que por defecto es 0
 * @param bitsSize el tamaño de los bits que por defecto es 0
 */
void getBits(struct node *HuffmanTree, struct bits bytesCode[], int bits, int bitsSize);
/**
 * Obtiene el byte correspondiente a la codificacion de Huffman. Recorre
 * el arbol analizando si es 0 o 1 el bit en el que esta para irse
 * a la izquierda o a la derecha, cuando detecta que ya ha llegado a un
 * nodo hoja, regresa en byteToWrite el valor del byte dado la cadena
 * de bits
 *
 * @param HuffmanTree el arbol de Huffman
 * @param cadena la cadena de bytes leidos del archivo comprimido
 * @param posInString la posicion del arreglo de la cadena
 * @param posInBits la posicion de bits en la que vamos en relacion a un byte
 * @param byteToWrite la variable donde guardaremos el byte correspondiente
 * @return la posicion en bits en donde nos quedamos en relacion a un byte
 */
int getCharacters(struct node *HuffmanTree, unsigned char *cadena, int *posInString, int posInBits, unsigned char *byteToWrite);

//*****************************************************************
//Funciones con heap

//Crea un espacio en memoria para el heap
/**
 * Crea una estructura Heap en memoria dinamica dada su
 * capacidad, la cual es un arreglo de nodos.
 *
 * @param capacity es la capacidad que queremos que tenga heap
 * @return el apuntador a la estructura heap creada
*/
Heap *CreateHeap(int capacity);
//Inserta elementos en el heap
/**
 * Inserta Nodos en la estructura de datos, indicando el Heap donde se desea
 * hacer la incersion, seguido del nodo que se desea insertar, simempre y cuando
 * la capacidad de Heap no haya sido exedida.
 *
 * @param heap es el monticulo donde vamos a insertar el nodo
 * @param node es el nodo a insertar dentro del monticulo 
*/
void insert(Heap *heap, struct node *node);
/**
 * Ordena los elementos del arreglo de nodos, haciendo que el elemento mas
 * pequeño sea la rama principal de nuestro arbol.
 *
 * @param Heap es el monticulo al que vamos a ordenar su arreglo de nodos
 * @param index es el indice en este caso el numero de elementos que hay que ordenar 
*/
void heapify_bottom_top(Heap *heap, int index);
/**
 * Ordena los elementos del arreglo de nodos, haciendo que el elemento mas
 * pequeño sea la rama principal de nuestro arbol,este lo usamos al momento de
 * retirar el elemento principal de nuestro Heap, debido a que el ordenamiento
 * lo realiza a partir de nuestra raiz hacia los elementos hijos del arbol.
 *
 * @param Heap es el monticulo al que vamos a ordenar su arreglo de nodos
 * @param parent_node es el indice del elemento padre de nuestro nodo para
realizar
 *
*/
void heapify_top_bottom(Heap *heap, int parent_node);
//Elimina el primer elemento de la cola de prioridad

/**
 * Elmina el elemento mas pequeño de una cola de prioridad
 *
 * @param Heap Es la estructura heap
 * @return nodo eliminado
*/
struct node *PopMin(Heap *heap);

//**********************************************************************
//Funciones con el arbol de huffman y heap

/**
 * Inserta en la cola de prioridad los nodos. EL numero de nodos
 * que inserta son los bytes distintos que aparecieron en el archivo
 *
 * @param bytesFrecuency el arreglo de struct donde viene el byte y su frecuencia
 * @param roots el arreglo de nodos que trae todos los bytes y su frecuencia
 * @param heap la cola de prioridad
 */
void insertTree(struct data bytesFrecuency[], struct node roots[], Heap *heap);
/**
 * Une todos los nodos hoja en un solo, llamado Arbol de Huffman.
 * Usando la cola de prioridad saca los dos nodos de menor frecuencia
 * suma sus dos frecuencia y los une en un nodo padre, haciendo esto
 * hasta que solo quede un nodo padre el cual contiene a todos los nodos
 * de los bytes leidos
 *
 * @param heap la cola de prioridad con los nodos de los bytes leidos
 * @return el Arbol de Huffman
 */
struct node *mergeTrees(Heap *heap);

//**********************************************************************
//Macros para trabajas con bits
#define PESOBIT(bpos) 1 << bpos
#define CONSULTARBIT(var, bpos) (*(unsigned *)&var & PESOBIT(bpos)) ? 1 : 0
