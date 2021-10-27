#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HuffmanStructures.h"

//leer y almacenar en un arreglo la frecuencia de cada simbolo
unsigned char* readFile(const char* fileToOpen, struct data symbolFrecuency[], int* fileSize){
    FILE* file;
    unsigned char c; //variable para guardar lo que leamos del file
    int i;
    file = fopen(fileToOpen, "rb");//Abrimos el archivo
    //Verificamos que el archivo se haya abierto correctamente.
    if(file == NULL){
        puts("The file could not be opened.\n");
        exit(1);
    }
    //Obtenemos el tamaño del archivo.
    fseek(file, 0L, SEEK_END);
    (*fileSize) = ftell(file);
    rewind(file);
    //Reservamos memoria para la cadena de bytes leidos
    unsigned char* bytesRead = malloc((*fileSize) * sizeof(unsigned char));
    //Guardamos los bytes leidos y su frecuencia
    for(i = 0; i < (*fileSize); i++){
    	fread(&c, sizeof(unsigned char), 1, file);
        bytesRead[i] = c;
	symbolFrecuency[c].symbol = c;
	symbolFrecuency[c].frequency ++;//frecuencia de apariciones
    }
    fclose(file);
    printf("\nTamaño del archivo a comprimir: %d.\n", (*fileSize));
    return bytesRead;
}

//Funcion que escribe la tabla de frecuencias en un txt
void writeFrecuenyTable(struct data symbolFrecuency[], int fileSize){
    int i;
    FILE* frecuencyTable;
    frecuencyTable = fopen("frecuencyTable.txt", "wt");
    //Verificamos que el archivo se haya abierto correctamente.
    if(frecuencyTable == NULL){
        puts("The file could not be opened.\n");
        exit(1);
    }
    fprintf(frecuencyTable, "%d\n", fileSize);//Escribimos el tamaño original
    for(i = 0; i < 256; i++)
	if(symbolFrecuency[i].frequency > 0) //Si el simbolo aparecio en el archivo
            fprintf(frecuencyTable, "%d %d\n", symbolFrecuency[i].symbol, symbolFrecuency[i].frequency);
    
    fclose(frecuencyTable);
}

//corimiento arriba de 32 bits
void writeBinaryCode(unsigned char* bytesRead, struct node* mainTree, int fileSize, struct bits* frecuencyTable){
    int i, j, bitsExtraWritten = 0;

    FILE* binaryCode;
    binaryCode = fopen("byteCode.dat", "wb");
    if(binaryCode == NULL){
        puts("The file could not be opened.\n");
        exit(1);
    }
    int tempSize = 0;
    int bitsSize, sizeByteToWrite;
    long bits, tempBits, tempBits2, tempBitsAux;
    unsigned char byteToWrite;
    for(i = 0; i < fileSize; i++){
	bitsSize = frecuencyTable[bytesRead[i]].sizebits;
	bits = frecuencyTable[bytesRead[i]].bits;
	//Checamos si hay una variable temporal
	if(tempSize != 0){
	    bits = (tempBits << bitsSize) + bits;
	    bitsSize += tempSize;
	    tempBits = 0;
	    tempSize = 0;
	}
	//Si podemos o no escribir el byte
	if(bitsSize >= 8){
	    if(bitsSize > 8){
		//Tenemos mas bits de los que podemos escribir, hay que reducir
		tempSize = bitsSize - 8;
		//Guardamos el exceso en una variable temporal
		for(j = 0; j < tempSize; j++){
		    tempBits2 = (CONSULTARBIT(bits, j)) << j;
		    tempBits = tempBits2 + tempBits;
		}
		bits = bits >> tempSize;//ajustamos los bits
	    }
	    sizeByteToWrite = 8;
	    byteToWrite = bits;//Estamos listos para escribir
	}
	else{
	    tempBits = bits;//Guardamos en una variable temporal
	    tempSize = bitsSize;
	}
	
	if(sizeByteToWrite == 8){
	    //Escribimos el byte
	    sizeByteToWrite = 0;
	    fwrite(&byteToWrite, sizeof(unsigned char), 1, binaryCode);
	}


	while(tempSize >= 8){
	    tempSize = tempSize - 8;
	    tempBitsAux = tempBits;
	    bits = tempBits >> tempSize;//ajustamos los bits
	    tempBits = 0;
	    //Guardamos el exceso en una variable temporal
	    for(j = 0; j < tempSize; j++){
		tempBits2 = ((CONSULTARBIT(tempBitsAux, j)) << j);
		tempBits = tempBits2 + tempBits;
	    }
	    byteToWrite = bits;
	    fwrite(&byteToWrite, sizeof(unsigned char), 1, binaryCode);
	}
    }
    //Faltaron bits por escribir?
    if(tempBits != 0){
	tempBits = (tempBits << (8 - tempSize));
	byteToWrite = tempBits;
        fwrite(&byteToWrite, sizeof(unsigned char), 1, binaryCode);
	bitsExtraWritten = 8 - tempSize;//Bits extra escritos
    }
    //En el ultimo byte, indica cuantos bits extra escribimos
    byteToWrite = bitsExtraWritten;
    fwrite(&byteToWrite, sizeof(unsigned char), 1, binaryCode);
    fclose(binaryCode);
}

int main(int argc, char* argv[]){
    struct data* symbolFrecuency = malloc(256 * sizeof(struct data));
    struct bits* frecuencyCode = malloc(256* sizeof(struct bits));
    struct node* roots = (struct node*)malloc(256 * sizeof(struct node));
    struct node* mainTree;
    unsigned char* bytesRead;
    Heap* heap = CreateHeap(511);
    int fileSize, i = 0;
    
    //Guardamos en un arreglo todos los bytes leidos
    bytesRead = readFile(argv[1], symbolFrecuency, &fileSize);
    //formar en el arbol las frecuencias y formar esos arboles en la cola
    insertTree(symbolFrecuency, roots, heap);
    //unir los arboles en un solo
    mainTree = mergeTrees(heap);
    //Obtener los bits que vale cada simbolo
    getBits(mainTree, frecuencyCode, 0, 0);
    //escribir el .dat con los bits de cada simbolo
    writeBinaryCode(bytesRead, mainTree, fileSize, frecuencyCode);
    //escribir la tabla de frecuencias y el tamaño
    writeFrecuenyTable(symbolFrecuency, fileSize);
    
    return 0;
}
