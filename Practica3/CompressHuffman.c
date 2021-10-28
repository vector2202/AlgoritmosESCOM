/**
 * Compresion de archivos con Algoritmo de Huffman
 * Este programa comprime un archivo usando el algoritmo de Huffman
 *
 * @author Victor Torres Leilani Sotelo Guillermo Sanchez
 * @version 1
 * compilacion: gcc -lm tiempo.c HuffmanStructures.c CompressHuffman.c -o CompressHuffman
 * ejecución ./CompressHuffman nombreDelArchivo
 */
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HuffmanStructures.h"
#include "tiempo.h"

/**
 * readFile
 *
 * Esta funcion lee un archivo de entrada, calcula el tamaño del
 * archivo, lee los bytes del archivo y los guarda en una cadena
 * ademas registra la frecuencia de aparicion de cada byte
 * aplicando el concepto de Hash, donde la llave es el valor
 * en decimal del byte que leimos
 *
 * @param fileToOpen nombre del archivo a abrir
 * @param bytesFrecuency[] arreglo donde esta la frecuencia de repeticion de bits
 * @param *fileSize direccion de memoria de la variable del tamaño del archivo
 * @return unsigned char* el apuntador de la cadena de los bytes leidos
 */
unsigned char* readFile(const char* fileToOpen, struct data bytesFrecuency[], int* fileSize)
{
    int i;
    FILE* file;
    unsigned char c;
    
    //Abrimos y verificamos que si se abrio correctamente
    file = fopen(fileToOpen, "rb");
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

    //Guardamos los bytes leidos y su frecuencia con su valor en decimal
    for(i = 0; i < (*fileSize); i++){
    	fread(&c, sizeof(unsigned char), 1, file);
        bytesRead[i] = c; 
	bytesFrecuency[c].symbol = c;// Enmascaramiento
	bytesFrecuency[c].frequency ++;// frecuencia de apariciones
    }
    fclose(file);
    return bytesRead;
}

/**
 * writeFrecuencyTable
 *
 * Escribe en un txt, el tamaño original del archivo ademas de
 * el valor en decimal de cada bit que aparecio seguida de las
 * veces que aparecio solo si la frecuencia de aparicion es 
 * mayor a 0, esto es, que el byte esta en el archivo original
 *
 * @param symbolFrecuency[] arreglo donde esta la frecuencia de repeticion de bits
 * @param *fileSize direccion de memoria de la variable del tamaño del archivo
 * @return void
 */
void writeFrecuenyTable(struct data bytesFrecuency[], int fileSize)
{
    int i;
    FILE* frecuencyTable;
    
    //Abrimos y verificamos que si se abrio correctamente
    frecuencyTable = fopen("frecuencyTable.txt", "wt+");
    if(frecuencyTable == NULL){
        puts("The file could not be opened.\n");
        exit(1);
    }
    
    //Escribimos el tamaño original al inicio del txt
    fprintf(frecuencyTable, "%d\n", fileSize);
    for(i = 0; i < 256; i++)
	if(bytesFrecuency[i].frequency > 0) //Si el simbolo aparecio en el archivo, escribelo
            fprintf(frecuencyTable, "%d %d\n", bytesFrecuency[i].symbol, bytesFrecuency[i].frequency);
    
    fclose(frecuencyTable);
}

/**
 * writeBinaryCode
 *
 * En un archivo llamado byteCode.dat, escribe el equivalente de
 * la codificacion de Huffman de los bytes leidos del archivo original,
 * esto lo hace mediante corrimientos de bits y con una bandera llamada
 * sizeByteToWrite que nos indica si tenemos los 8 bits para escribir
 * en el .dat, si no la guarda y mediante corrimeintos la suma con la 
 * codificacion del siguiente byte, en el ultimo byte del .dat, escribe
 * cuantos bits extra escribimos que no corresponden a la codificacion
 * de Huffman
 *
 * @param *bytesRead el apuntador al inicio de la cadena de los bytes leidos
 * @param *mainTree el arbol de Huffman donde unimos todos los bytes y su frecuencia
 * @param *frecuencyTable un arreglo donde temenos la codificacion de Huffman de los bytes
 * @param fileSize el tamaño del archivo original
 * @return void
 */

void writeBinaryCode(unsigned char* bytesRead, struct node* mainTree, struct bits* bytesCode, int fileSize, int* compressedFileSize)
{
    int i, j, bitsExtraWritten = 0;
    FILE* binaryCode;
    
    //Abrimos y verificamos que si se abrio correctamente
    binaryCode = fopen("byteCode.dat", "wb+");
    if(binaryCode == NULL){
        puts("The file could not be opened.\n");
        exit(1);
    }

    //Variables para poder escribir los bits
    int bitsSize, sizeByteToWrite, tempSize = 0;
    int bits, tempBits, tempBits2, tempBitsAux;
    unsigned char byteToWrite;

    for(i = 0; i < fileSize; i++){
	bitsSize = bytesCode[bytesRead[i]].sizebits;
	bits = bytesCode[bytesRead[i]].bits;

	//Checamos si hay bits que no escribimos
	if(tempSize != 0){
	    bits = (tempBits << bitsSize) + bits;
	    bitsSize += tempSize;
	    tempBits = 0;
	    tempSize = 0;
	}

	//Podemos escribir o no el byte?
	if(bitsSize >= 8){
	    if(bitsSize > 8){
		//Tenemos mas bits de los que podemos escribir, hay que reducir
		//Guardamos lo que no podemos escribir en una variable temporal
		tempSize = bitsSize - 8;
		for(j = 0; j < tempSize; j++){
		    tempBits2 = (CONSULTARBIT(bits, j)) << j;
		    tempBits = tempBits2 + tempBits;
		}
		//ajustamos los bits para poder escribir los primeros 8
		bits = bits >> tempSize;
	    }
	    byteToWrite = bits;
	    sizeByteToWrite = 8;// Podemos escribir en el .dat
	}
	else{
	    tempBits = bits;// Guardamos en una variable temporal
	    tempSize = bitsSize;// lo que no pudimos escribir
	}

	// Hay bytes por escribir?
	if(sizeByteToWrite == 8){
	    sizeByteToWrite = 0; //Escribimos el byte
	    fwrite(&byteToWrite, sizeof(unsigned char), 1, binaryCode);
	}
	
	//Checamos que no se desborde tempBits
	while(tempSize >= 8){
	    //Ajustamos tempsize para poder escribir los primeros 8
	    tempSize = tempSize - 8;
	    tempBitsAux = tempBits;
	    bits = tempBits >> tempSize;
	    tempBits = 0;
	    
	    //Guardamos el exceso en una variable temporal
	    for(j = 0; j < tempSize; j++){
		tempBits2 = ((CONSULTARBIT(tempBitsAux, j)) << j);
		tempBits = tempBits2 + tempBits;
	    }
	    byteToWrite = bits; // Escribimos el byte
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

    //Obtenemos el tamaño del archivo comprimido
    fseek(binaryCode, 0L, SEEK_END);
    (*compressedFileSize) = ftell(binaryCode);
    rewind(binaryCode);
    //Cerrar el archivo
    fclose(binaryCode);
}

int main(int argc, char* argv[]){
    //*********************************************************
    //Variables a usar en el programa
    
    //Variables para el control de tiempo
    double utime0, stime0, wtime0, utime1, stime1, wtime1;
    //Arreglo para almacenar la frecuencia de bytes
    struct data* bytesFrecuency = malloc(256 * sizeof(struct data));
    //Arreglo para almacenar la codificacion de Huffman
    struct bits* bytesCode = malloc(256* sizeof(struct bits));
    //Arreglo para almacenar el byte y frecuencia en cada nodo del arbol
    struct node* roots = (struct node*)malloc(256 * sizeof(struct node));
    //Arbol de Huffman ya unificado
    struct node* mainTree;
    //Cadena de bytes leidos del archivo original
    unsigned char* bytesRead;
    //Cola de prioridad
    Heap* heap = CreateHeap(511);
    //Variable para almacenar el tamaño del archivo y del comprimido
    int fileSize, compressedFileSize;


    puts("\nComprimir archivos usando el algoritmo de Huffman.\n");
    //******************************************************************
    // Iniciar el conteo del tiempo para las evaluaciones de rendimiento
    //******************************************************************
    uswtime(&utime0, &stime0, &wtime0);
    
    //Guardamos en un arreglo todos los bytes leidos
    bytesRead = readFile(argv[1], bytesFrecuency, &fileSize);
    //formar en el arbol las frecuencias y formar esos arboles en la cola
    insertTree(bytesFrecuency, roots, heap);
    //unir los arboles en el arbol de Huffman
    mainTree = mergeTrees(heap);
    //Obtener los bits que vale cada byte
    getBits(mainTree, bytesCode, 0, 0);
    //escribir el .dat con los bits de cada byte correspondiente
    writeBinaryCode(bytesRead, mainTree, bytesCode, fileSize, &compressedFileSize);
    //escribir la tabla de frecuencias y el tamaño
    writeFrecuenyTable(bytesFrecuency, fileSize);

    //******************************************************************
    // Evaluar los tiempos de ejecución
    //******************************************************************
    uswtime(&utime1, &stime1, &wtime1);

    printf("Tamaño de %s: %d bytes\n", argv[1], fileSize);
    printf("Tamaño del archivo comprimido: %d bytes\n", compressedFileSize);
    printf("Porcentaje de compresion alcanzado: %.2f%%\n", ((float)fileSize/(float)compressedFileSize)*100);
    printf("Tiempo real de Ejecucion: %.10e s\n\n", wtime1 - wtime0);
    
    return 0;
}
