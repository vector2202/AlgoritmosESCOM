#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HuffmanStructures.h"

void readFrecuencyTable(struct data symbolFrecuency[]){
    int symbol, frecuency;
    FILE* frecuencyTable;
    frecuencyTable = fopen("frecuencyTable.txt", "r");
    while(!feof(frecuencyTable)){
	fscanf(frecuencyTable, "%d", &symbol);
	fscanf(frecuencyTable, "%d", &frecuency);
	symbolFrecuency[symbol].symbol =  symbol;
	symbolFrecuency[symbol].frequency = frecuency;
    }
    fclose(frecuencyTable);
}

unsigned char* readByteCode(int* fileSize){
    FILE* file;
    unsigned char c;
    int i;
    //Abrimos el archivo
    file = fopen("byteCode.dat", "rb");
    if(file == NULL){
        puts("Open file Failed");
        exit(1);
    }
    //Obtenemos el tamaño del archivo y lo guardamos en un arreglo.
    fseek(file, 0L, SEEK_END);
    *(fileSize) = ftell(file) + 1;
    unsigned char* bytesRead = malloc(*(fileSize) * sizeof(unsigned char));
    fseek(file, 0, SEEK_SET);
    i = 0;
    while(!feof(file)){
	fread(&c, sizeof(unsigned char), 1, file);
        bytesRead[i] = c;
	i++;
	//printf("%d ", c);
    }
    fclose(file);
    return bytesRead;
}

void writeFile(unsigned char* bytesRead, struct node* mainTree, int fileSize, const char* file){
    puts("\n");
    FILE* finalFile;
    finalFile = fopen(file, "wb+");
    int k = 0;
    int i, posInBits = 7, bitsExtraWritten, bytesWritten = 0;
    unsigned char byteToWrite;
    bitsExtraWritten = bytesRead[fileSize-1];
    for(i = 0; i < fileSize - 3;){
	posInBits = getCharacters(mainTree, bytesRead , &i, posInBits, &byteToWrite);
	fwrite(&byteToWrite, sizeof(unsigned char), 1, finalFile);
	printf("%d ", byteToWrite);
	k++;
	if(i == fileSize - 3 && 7 - posInBits == bitsExtraWritten)
	    i++;	    
	if(posInBits < 0){
	    posInBits = 7;
	    i++;
	}
    }
    printf("Tamaño final: %d", k);
    fclose(finalFile);
}

int main(int argc, char* argv[]){
    struct data* symbolFrecuency = malloc(256* sizeof(struct bits));;
    struct bits* frecuencyCode = malloc(256* sizeof(struct bits));
    struct node* roots = (struct node*)malloc(256 * sizeof(struct node));
    struct node* mainTree;
    Heap* heap = CreateHeap(511);
    int fileSize = 0;
    unsigned char* bytesRead;
    
    readFrecuencyTable(symbolFrecuency);// leer la tabla de frecuencias
    insertTree(symbolFrecuency, roots, heap);// hacer el arbol con la tabla de frecuencias
    mainTree = mergeTrees(heap);//unir los arboles
    getBits(mainTree, frecuencyCode, 0, 0);//hacer el arbol y getbits
    bytesRead = readByteCode(&fileSize);//leer el .dat
    writeFile(bytesRead, mainTree, fileSize, argv[1]);//sustituir la cadena de .dat por su valor de arbol
    puts("");

	    
	
    return 0;
}

/*
51 99 109 53 32 101 115 32 101 108 32 109 101 106 111 111 111 111 114 105 115 105 109 111 111 111 32 103 114 112 111 111 111 111 10 10
 
51 99 109 53 32 101 115 32 101 108 32 109 101 106 111 111 111 111 114 105 115 105 109 111 111 111 32 103 114 112 111 111 111 111 10 10 112 

*/



