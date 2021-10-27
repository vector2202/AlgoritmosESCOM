#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HuffmanStructures.h"

//Leemos la tabla de frecuencias txt
void readFrecuencyTable(struct data symbolFrecuency[], int* fileSize){
    int symbol, frecuency, i = 0;
    FILE* frecuencyTable;
    frecuencyTable = fopen("frecuencyTable.txt", "r");
    //Verificamos que el archivo se haya abierto correctamente.
    if(frecuencyTable == NULL){
        puts("The file could not be opened.\n");
        exit(1);
    }
    while(!feof(frecuencyTable)){
	if(i == 0)
	    fscanf(frecuencyTable, "%d", fileSize);
	fscanf(frecuencyTable, "%d", &symbol);
	fscanf(frecuencyTable, "%d", &frecuency);
	symbolFrecuency[symbol].symbol =  symbol;
	symbolFrecuency[symbol].frequency = frecuency;
	i++;
    }
    fclose(frecuencyTable);
}

//leeremos del archivo.dat los bytes
unsigned char* readByteCode(int* fileSize, int* byteFileSize){
    unsigned char c;
    int i;
    FILE* file;
    file = fopen("byteCode.dat", "rb");
    //Verificamos que el archivo se haya abierto correctamente.
    if(file == NULL){
        puts("Open file Failed");
        exit(1);
    }
    //Obtenemos el tamaño del archivo .dat
    fseek(file, 0L, SEEK_END);
    (*byteFileSize) = ftell(file);
    rewind(file);//fseek(file, 0, SEEK_SET);
    //Reservamos memoria donde guardaremos los bytes leidos
    unsigned char* bytesRead = malloc((*byteFileSize) * sizeof(unsigned char));
    //leemos los bytes del .dat y los guardamos en una cadena
    for(i = 0; i < (*byteFileSize); i++){
    	fread(&c, sizeof(unsigned char), 1, file);
        bytesRead[i] = c;
    }
    fclose(file);
    //printf("Tamaño del archivo comprimido: %d.\n", (*byteFileSize));
    return bytesRead;
}
//Escribiremos el archivo original de nuevo
void writeFile(unsigned char* bytesRead, struct node* mainTree, const char* file, int byteFileSize, int fileSize){
    FILE* finalFile;
    finalFile = fopen(file, "wb+");
    //Verificamos que el archivo se haya abierto correctamente.
    if(finalFile == NULL){
        puts("The file could not be opened.\n");
        exit(1);
    }
    int i, posInBits = 7, bitsExtraWritten, bytesWritten = 0;
    unsigned char byteToWrite;
    //Leemos los bits extra que escribimos
    bitsExtraWritten = bytesRead[byteFileSize-1];
    for(i = 0; i < byteFileSize - 1 && bytesWritten < fileSize;){
	posInBits = getCharacters(mainTree, bytesRead , &i, posInBits, &byteToWrite);
	//escribimos los bytes que obtuvimos
	fwrite(&byteToWrite, sizeof(unsigned char), 1, finalFile);
	bytesWritten++;
	//Cuidamos no escribir bits extra
	if(i == fileSize - 2 && 7 - posInBits == bitsExtraWritten)
	    bytesWritten++;
	//Checamos que no nos desbordamos de posicion de bits
	if(posInBits < 0){
	    posInBits = 7;
	    i++;
	}
    }
    printf("\nTamaño final: %d.\n", bytesWritten);
    fclose(finalFile);
}

int main(int argc, char* argv[]){
    struct data* symbolFrecuency = malloc(256* sizeof(struct bits));;
    struct bits* frecuencyCode = malloc(256* sizeof(struct bits));
    struct node* roots = (struct node*)malloc(256 * sizeof(struct node));
    struct node* mainTree;
    Heap* heap = CreateHeap(511);
    int fileSize = 0, byteFileSize = 0;
    unsigned char* bytesRead;

    //leer la tabla de frecuencias
    readFrecuencyTable(symbolFrecuency, &fileSize);
    //hacer el arbol con la tabla de frecuencias
    insertTree(symbolFrecuency, roots, heap);
    //unir los arboles en uno solo
    mainTree = mergeTrees(heap);
    //Obtener el codigo de bits de cada simbolo
    getBits(mainTree, frecuencyCode, 0, 0);
    //leer el .dat generado en la compresion
    bytesRead = readByteCode(&fileSize, &byteFileSize);
    //sustituir la cadena de .dat por su valor de arbol
    writeFile(bytesRead, mainTree, argv[1], byteFileSize, fileSize);
    
    return 0;
}
