struct bits{
    char symbol;
    int sizebits;
    int bits;
};

//nodo con la frecuencia de repeticion y el caracter
struct data{
    int frequency;
    int symbol;
};

//arbol de frecuenicas
struct node{
    struct node* left;
    struct node* right;
    struct data data;
};

struct Heap{
    struct node** arrayOfNodes;
    int count;
    int capacity;

};

typedef struct Heap Heap;
//bits
int giveMeBit(int x,int k);
void showMeBits(int x, int bitsSize);
//tree
int isEmpty(struct node* root);
int isLeaf(struct node* root);
struct node* mergeNodes(struct node* node1, struct node* node2);
void getBits(struct node* , struct bits [], int, int);
int getCharacters(struct node*, unsigned char*, int*, int, unsigned char*); 
void writeBits(unsigned char, struct bits []);
void pushTree(struct node* root, unsigned char symbol, int frecuency);
//heap
Heap *CreateHeap(int capacity);
void insert(Heap *heap, struct node* node);
void heapify_bottom_top(Heap *heap, int index);
void heapify_top_bottom(Heap *heap, int parent_node);
struct node* PopMin(Heap *heap);
void insertTree(struct data symbolFrecuency[], struct node roots[], Heap* heap);
//unir todos los nodos en uno solo
struct node* mergeTrees(Heap* heap);
void print(Heap *h);
void recorrerArbol(struct node* root, int* i);

#define PESOBIT(bpos) 1<<bpos
#define CONSULTARBIT(var,bpos) (*(unsigned*)&var & PESOBIT(bpos))?1:0
#define PONE_1(var,bpos) *(unsigned*)&var |= PESOBIT(bpos)
#define PONE_0(var,bpos) *(unsigned*)&var &= ~(PESOBIT(bpos))
#define CAMBIA(var,bpos) *(unsigned*)&var ^= PESOBIT(bpos)
