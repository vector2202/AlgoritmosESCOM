#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HuffmanStructures.h"

//leer y almacenar en un arreglo la frecuencia de cada simbolo
unsigned char* readFile(const char* fileToOpen, struct data symbolFrecuency[], int* fileSize){
    FILE* file;
    unsigned char c;
    int i;
    //Abrimos el archivo
    file = fopen(fileToOpen, "rb");
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
	symbolFrecuency[c].symbol = c;
	symbolFrecuency[c].frequency ++;
	i++;
	printf("%d ", c);
    }
    printf("\nTamaño del archivo: %d.\n", *(fileSize));
    fclose(file);
    return bytesRead;
}

void writeFrecuenyTable(struct data symbolFrecuency[]){
    FILE* frecuencyTable;
    frecuencyTable = fopen("frecuencyTable.txt", "wt");
    int i;
    for(i = 0; i < 256; i++){
	if(symbolFrecuency[i].frequency > 0)
            fprintf(frecuencyTable, "%d %d\n", symbolFrecuency[i].symbol, symbolFrecuency[i].frequency);
    }
    fclose(frecuencyTable);
}

void writeBinaryCode(unsigned char* bytesRead, struct node* mainTree, int fileSize, struct bits* frecuencyTable){
    //escribir el .dat
    int i, j, bitsExtraWritten = 0;
    FILE* binaryCode;
    binaryCode = fopen("byteCode.dat", "wb");
    int tempBits, tempBits2, tempSize = 0;
    int bitsSize, bits;
    int sizeByteToWrite;
    unsigned char byteToWrite;

    for(i = 0; i < fileSize; i++){
	bitsSize = frecuencyTable[bytesRead[i]].sizebits;
	bits = frecuencyTable[bytesRead[i]].bits;

	if(tempSize != 0){
	    bits = (tempBits << bitsSize) + bits;
	    bitsSize += tempSize;
	    tempBits = 0;
	    tempSize = 0;
	}
	
	if(bitsSize >= 8){
	    if(bitsSize > 8){
		tempSize = bitsSize - 8;
		for(j = 0; j < tempSize; j++){
		    tempBits2 = (CONSULTARBIT(bits, j)) << j;
		    tempBits = tempBits2 + tempBits;
		}
		bits = bits >> tempSize;//recorrer el exceso
	    }
	    sizeByteToWrite = 8;
	    byteToWrite = bits;
	}
	else{
	    tempBits = bits;
	    tempSize = bitsSize;
	}
	
	if(sizeByteToWrite == 8){
	    sizeByteToWrite = 0;
	    //printf("%d ", byteToWrite);
	    fwrite(&byteToWrite, sizeof(unsigned char), 1, binaryCode);
	}
    }
    if(tempBits != 0){
	tempBits = (tempBits << (8 - tempSize));
	byteToWrite = tempBits;
        fwrite(&byteToWrite, sizeof(unsigned char), 1, binaryCode);
	bitsExtraWritten = 8 - tempSize;//escribir en el ultimo byte.
    }
    byteToWrite = bitsExtraWritten;
    fwrite(&byteToWrite, sizeof(unsigned char), 1, binaryCode);
    fclose(binaryCode);
}

int main(int argc, char* argv[]){
    struct data* symbolFrecuency = malloc(256 * sizeof(struct data));
    struct bits* frecuencyCode = malloc(256* sizeof(struct bits));
    unsigned char* bytesRead;
    struct node* roots = (struct node*)malloc(256 * sizeof(struct node));
    struct node* mainTree;
    int fileSize, i = 0;
    Heap* heap = CreateHeap(511);

    bytesRead = readFile(argv[1], symbolFrecuency, &fileSize);
    insertTree(symbolFrecuency, roots, heap);//formar en el arbol las frecuencias y formar esos arboles en la cola
    mainTree = mergeTrees(heap);//unir los arboles
    getBits(mainTree, frecuencyCode, 0, 0);
    writeBinaryCode(bytesRead, mainTree, fileSize, frecuencyCode); //escribir el .dat
    writeFrecuenyTable(symbolFrecuency);//recribir la tabla de frecuencias
    
    return 0;
}
