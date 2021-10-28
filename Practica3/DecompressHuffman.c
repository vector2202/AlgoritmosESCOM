/**
 * @file Compresion de archivos con Algoritmo de Huffman
 * @brief Este programa comprime un archivo usando el algoritmo de Huffman
 *
 * @author Victor Torres Leilani Sotelo Guillermo Sanchez
 * @version 1.0
 * compilacion: gcc -lm tiempo.c HuffmanStructures.c DecompressHuffman.c -o DecompressHuffman
 * ejecución ./DecompressHuffman nombreDelArchivo
 */
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HuffmanStructures.h"
#include "tiempo.h"

/**
 * readFrecuencyTable
 *
 * A partir de la tabla de frecuencia generada al comprimir el archivo,
 * leemos las veces que se se repitio cada bit, ademas al principio del
 * archivo leemos el tamaño original del archivo, las frecuencias las
 * guardamos en un arreglo, con su respectivo byte aplicando hash,
 * donde la llave es el byte. 
 *
 * @param bytesFrecuency[] arreglo donde esta la frecuencia de repeticion de bits
 * @param *fileSize direccion de memoria de la variable del tamaño del archivo
 * @return void
 */
void readFrecuencyTable(struct data bytesFrecuency[], int* fileSize){
    int symbol, frecuency, i = 0;
    FILE* frecuencyTable;

    //Abrimos y verificamos que si se abrio correctamente
    frecuencyTable = fopen("frecuencyTable.txt", "r");
    if(frecuencyTable == NULL){
        puts("The file could not be opened.\n");
        exit(1);
    }

    //Leemos el tamaño de archivo y las veces que se repite cada byte
    while(!feof(frecuencyTable)){
	if(i == 0)
	    fscanf(frecuencyTable, "%d", fileSize);
	fscanf(frecuencyTable, "%d", &symbol);
	fscanf(frecuencyTable, "%d", &frecuency);
	bytesFrecuency[symbol].symbol =  symbol;
	bytesFrecuency[symbol].frequency = frecuency;
	i++;
    }
    fclose(frecuencyTable);
}

/**
 * readByteCode
 *
 * Obtenemos el tamaño del archivo comprimido y los bytes que lo componen,
 * esto lo guardamos en una cadena.
 *
 * @param *fileSize direccion de memoria de la variable del tamaño del archivo
 * @param *byteFileSize direccion de memoria de la variable del tamaño del archivo comprimido
 * @return al arreglo donde guardamos los bytes leidos
 */
unsigned char* readByteCode(int* fileSize, int* byteFileSize){
    unsigned char c;
    int i;
    FILE* file;

    //Abrimos y verificamos que si se abrio correctamente
    file = fopen("byteCode.dat", "rb");
    if(file == NULL){
        puts("Open file Failed");
        exit(1);
    }
    
    //Obtenemos el tamaño del archivo .dat
    fseek(file, 0L, SEEK_END);
    (*byteFileSize) = ftell(file);
    rewind(file);
    
    //Reservamos memoria donde guardaremos los bytes leidos
    unsigned char* bytesRead = malloc((*byteFileSize) * sizeof(unsigned char));
    
    //leemos los bytes del .dat y los guardamos en un arreglo
    for(i = 0; i < (*byteFileSize); i++){
    	fread(&c, sizeof(unsigned char), 1, file);
        bytesRead[i] = c;
    }
    fclose(file);
    return bytesRead;
}


/**
 * writeFile
 *
 * vamos recorriendo bit a bit de los bytes leidos en el archivo comprimido,
 * y recorremos el arbol de Huffman, en base a esto nos devuelve tanto la
 * la posicion en bits de 0 a 7 en la que se quedo, como en la variable
 * byteToWrite, el byte correspondiente a cada cadena de bits, una ves que
 * tenemos esto, escribimos en el archivo el byte correspondiente.
 *
 * @param *bytesRead el apuntador al inicio de la cadena de los bytes leidos
 * @param *mainTree el arbol de Huffman donde unimos todos los bytes y su frecuencia
 * @param *file el nombre del archivo en el que escribiremos
 * @param byteFileSize el tamaño del archivo comprimido
 * @param fileSize apuuntador de la variable del tamaño del archivo que escribiremos
 * @return void
 */
void writeFile(unsigned char* bytesRead, struct node* mainTree, const char* file, int byteFileSize, int* fileSize){
    FILE* finalFile;

    //Abrimos y verificamos que si se abrio correctamente
    finalFile = fopen(file, "wb+");
    if(finalFile == NULL){
        puts("The file could not be opened.\n");
        exit(1);
    }

    //Variables para escribir en el archivo
    int i, posInBits = 7, bytesWritten = 0;
    unsigned char byteToWrite;
    
    //Leemos los bits extra que escribimos
    int bitsExtraWritten = bytesRead[byteFileSize-1];
    
    for(i = 0; i < byteFileSize - 1 && bytesWritten < (*fileSize);){
	posInBits = getCharacters(mainTree, bytesRead , &i, posInBits, &byteToWrite);
	//escribimos el byte correspondiente a los bits
	fwrite(&byteToWrite, sizeof(unsigned char), 1, finalFile);
	bytesWritten++;//conteo para no escribir de mas
	
	//Cuidamos no escribir los bits extra que escribimos al comprimir
	if(i == (*fileSize) - 2 && 7 - posInBits == bitsExtraWritten)
	    bytesWritten++;
	
	//Checamos que no nos desbordamos de posicion de bits
	if(posInBits < 0){
	    posInBits = 7;
	    i++;
	}
    }
    (*fileSize) = bytesWritten;
    fclose(finalFile);
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
    //Variables para almacenar los tamaños de archivos
    int fileSize = 0, byteFileSize = 0;


    puts("\nDescomprimir archivos usando el algoritmo de Huffman\n");
    //******************************************************************
    // Iniciar el conteo del tiempo para las evaluaciones de rendimiento
    //******************************************************************
    uswtime(&utime0, &stime0, &wtime0);
    
    //leer la tabla de frecuencias
    readFrecuencyTable(bytesFrecuency, &fileSize);
    //hacer el arbol con la tabla de frecuencias
    insertTree(bytesFrecuency, roots, heap);
    //unir los arboles en uno solo
    mainTree = mergeTrees(heap);
    //Obtener el codigo de bits de cada byte
    getBits(mainTree, bytesCode, 0, 0);
    //leer el .dat generado en la compresion
    bytesRead = readByteCode(&fileSize, &byteFileSize);
    //sustituir la cadena de .dat por su valor de arbol
    writeFile(bytesRead, mainTree, argv[1], byteFileSize, &fileSize);

    //******************************************************************
    // Evaluar los tiempos de ejecución
    //******************************************************************
    uswtime(&utime1, &stime1, &wtime1);

    printf("Tamaño de %s: %d bytes\n", argv[1], fileSize);
    printf("Tiempo real de Ejecucion: %.10e s\n\n", wtime1 - wtime0);
    
    return 0;
}
