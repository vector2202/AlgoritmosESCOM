#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PESOBIT(bpos) 1<<bpos
#define CONSULTARBIT(var,bpos) (*(unsigned*)&var & PESOBIT(bpos))?1:0
#define PONE_1(var,bpos) *(unsigned*)&var |= PESOBIT(bpos)
#define PONE_0(var,bpos) *(unsigned*)&var &= ~(PESOBIT(bpos))
#define CAMBIA(var,bpos) *(unsigned*)&var ^= PESOBIT(bpos)

int giveMeBit(int x,int k){
    return x & (1<<k);
}
void showMeBits(int x, int bitsSize){
    int i;
    for(i = bitsSize; i >= 0; i--)
	printf("%d",CONSULTARBIT(x, i));
    puts("");
}
//
struct bits{
    char character;
    int sizebits;
    int bits;
};

//nodo con la frecuencia de repeticion y el caracter
struct data{
    int frequency;
    char character;
};

//arbol de frecuenicas
struct node{
    struct node* left;
    struct node* right;
    struct data data;
};

int isEmpty(struct node* root){return root == NULL;}
int isLeaf(struct node* root){return root->left == NULL && root->right == NULL;}
//unir los nodos
struct node* mergeNodes(struct node* node1, struct node* node2){
    struct node* new_node = malloc(sizeof(struct node));
    new_node->left = node1;
    new_node->right = node2;
    new_node->data.frequency = node1->data.frequency + node2->data.frequency;
    return new_node;
}
//obtener la codificacion de los caracteres
void getBits(struct node* mainTree, struct bits frequency[], int bits, int sizebits){
    if(!isEmpty(mainTree)){//if notempty
	getBits(mainTree->left, frequency, bits<<1, sizebits + 1);// irte al nodo izq, sumandole un 0
	if(isLeaf(mainTree)){
	    int hashKey = mainTree->data.character-32;
	    frequency[hashKey].bits = bits;//bits
	    frequency[hashKey].character = mainTree->data.character;
	    frequency[hashKey].sizebits = sizebits;
	    /* printf("Character: %c.\nSize: %d\n", mainTree->data.character, sizebits); */
	    /* showMeBits(bits); */
	    /* puts("\n"); */
	}
	getBits(mainTree->right, frequency, (bits<<1) + 1, sizebits + 1);//irte al nodo der sumandole un 1
    }
}

int getCharacters(struct node* tree, const char* cadena, int i){
    if(isLeaf(tree)){
	printf("%c", tree->data.character);
	return i;
    }
    else{
	if(cadena[i] == '0')
	    return getCharacters(tree->left, cadena, i+1);
	else
	    return getCharacters(tree->right, cadena, i+1);
    }
}
void writeBits(char symbol, struct bits hashTable[]){
    int hashKey = symbol - 32;
    showMeBits(hashTable[hashKey].bits, hashTable[hashKey].sizebits-1);
}


int main(){
    int i, size;

    //********************************************************+
    //formaremos manualmente el arbol
    char arraychar[14] = {'3', 'c', '5', 'l', 'j', 'g', 'p', 's', 'r', 'i', 'm', 'e', ' ', 'o'};
    int arrayint[14] = {1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4, 11};
    struct node arraydata[14];
    struct node** trees = malloc(14*sizeof(struct node));
    struct bits frequency[100];
    for(i = 0; i < 14; i++){
	arraydata[i].data.frequency = arrayint[i];
	arraydata[i].data.character = arraychar[i];
	arraydata[i].left = NULL;
	arraydata[i].right = NULL;
	
    }
    trees[0] = mergeNodes(&arraydata[0], &arraydata[1]);//3 con c
    trees[1] = mergeNodes(&arraydata[2], &arraydata[3]);//5 con l
    trees[2] = mergeNodes(&arraydata[4], &arraydata[5]);//j con g
    trees[3] = mergeNodes(trees[0], trees[1]);//2 y 2 del 3c y 5l
    trees[4] = mergeNodes(&arraydata[6], trees[2]);//p con 2 de jg
    trees[5] = mergeNodes(&arraydata[7], &arraydata[8]);//s con r
    trees[6] = mergeNodes(trees[5], trees[3]);// 4 de sr y 4 de 5l3c
    trees[7] = mergeNodes(&arraydata[9], trees[4]);//i con 3 de pjg
    trees[8] = mergeNodes(&arraydata[10], &arraydata[11]);// m con e
    trees[9] = mergeNodes(&arraydata[12], trees[7]);//espacio con 5
    trees[10] = mergeNodes(trees[8], trees[6]);//6 con 8
    trees[11] = mergeNodes(trees[9], &arraydata[13]);// 9 con o
    trees[12] = mergeNodes(trees[10], trees[11]);
    /* //obtener bits */
    i=0;
    getBits(trees[12], frequency, 0, 0);
    const char* mensaje = "3cm5";
    for(i = 0; i < 4; i++)
	writeBits(mensaje[i], frequency);
    






















    

    
    for (i = 0; i < size; i+=2) {
	//actualizarRoot(cola[i], cola[i+1])
	//desformar cola[i], cola[i+1]
	//formar nuevo nodo
    }
    return 0;
}

