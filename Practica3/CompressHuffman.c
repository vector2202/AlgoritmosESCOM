#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HuffmanStructures.h"
#include "CompressHuffman.h"
#include "tiempo.h"

unsigned char *readFile(const char *fileToOpen, struct data bytesFrecuency[],
                        int *fileSize) {
  int i;
  FILE *file;
  unsigned char c;

  // Abrimos y verificamos que si se abrio correctamente
  file = fopen(fileToOpen, "rb");
  if (file == NULL) {
    puts("The file could not be opened.\n");
    exit(1);
  }

  // Obtenemos el tamaño del archivo.
  fseek(file, 0L, SEEK_END);
  (*fileSize) = ftell(file);
  rewind(file);

  // Reservamos memoria para la cadena de bytes leidos
  unsigned char *bytesRead = malloc((*fileSize) * sizeof(unsigned char));

  // Guardamos los bytes leidos y su frecuencia con su valor en decimal
  for (i = 0; i < (*fileSize); i++) {
    fread(&c, sizeof(unsigned char), 1, file);
    bytesRead[i] = c;
    bytesFrecuency[c].byte = c;    // Enmascaramiento
    bytesFrecuency[c].frequency++; // frecuencia de apariciones
  }
  fclose(file);
  return bytesRead;
}

void writeFrecuenyTable(struct data bytesFrecuency[], int fileSize)
{
    int i;
    FILE *frecuencyTable;

    //Abrimos y verificamos que si se abrio correctamente
    frecuencyTable = fopen("frecuencias.txt", "wt+");
    if (frecuencyTable == NULL)
    {
        puts("The file could not be opened.\n");
        exit(1);
    }

    //Escribimos el tamaño original al inicio del txt
    fprintf(frecuencyTable, "%d\n", fileSize);
    for (i = 0; i < 256; i++)
      if (bytesFrecuency[i].frequency > 0) 
        fprintf(frecuencyTable, "%d %d\n", bytesFrecuency[i].byte,
                bytesFrecuency[i].frequency);
    // Si el simbolo aparecio en el archivo, escribelo

    fclose(frecuencyTable);
}

void writeBinaryCode(unsigned char *bytesRead, struct node *mainTree,
                     struct bits *bytesCode, int fileSize,
                     int *compressedFileSize) {
  int i, j, bitsExtraWritten = 0;
  FILE *binaryCode;

  // Abrimos y verificamos que si se abrio correctamente
  binaryCode = fopen("codificacion.dat", "wb+");
  if (binaryCode == NULL) {
    puts("The file could not be opened.\n");
    exit(1);
  }

  // Variables para poder escribir los bits
  int bitsSize, sizeByteToWrite, tempSize = 0;
  int bits, tempBits, tempBits2, tempBitsAux;
  unsigned char byteToWrite;

  for (i = 0; i < fileSize; i++) {
    bitsSize = bytesCode[bytesRead[i]].sizeBits;
    bits = bytesCode[bytesRead[i]].bits;

    // Checamos si hay bits que no escribimos
    if (tempSize != 0) {
      bits = (tempBits << bitsSize) + bits;
      bitsSize += tempSize;
      tempBits = 0;
      tempSize = 0;
    }

    // Podemos escribir o no el byte?
    if (bitsSize >= 8) {
      if (bitsSize > 8) {
        // Tenemos mas bits de los que podemos escribir, hay que reducir
        // Guardamos lo que no podemos escribir en una variable temporal
        tempSize = bitsSize - 8;
        for (j = 0; j < tempSize; j++) {
          tempBits2 = (CONSULTARBIT(bits, j)) << j;
          tempBits = tempBits2 + tempBits;
        }
        // ajustamos los bits para poder escribir los primeros 8
        bits = bits >> tempSize;
      }
      byteToWrite = bits;
      sizeByteToWrite = 8; // Podemos escribir en el .dat
    } else {
      tempBits = bits;     // Guardamos en una variable temporal
      tempSize = bitsSize; // lo que no pudimos escribir
    }

    // Hay bytes por escribir?
    if (sizeByteToWrite == 8) {
      sizeByteToWrite = 0; // Escribimos el byte
      fwrite(&byteToWrite, sizeof(unsigned char), 1, binaryCode);
    }

    // Checamos que no se desborde tempBits
    while (tempSize >= 8) {
      // Ajustamos tempsize para poder escribir los primeros 8
      tempSize = tempSize - 8;
      tempBitsAux = tempBits;
      bits = tempBits >> tempSize;
      tempBits = 0;

      // Guardamos el exceso en una variable temporal
      for (j = 0; j < tempSize; j++) {
        tempBits2 = ((CONSULTARBIT(tempBitsAux, j)) << j);
        tempBits = tempBits2 + tempBits;
      }
      byteToWrite = bits; // Escribimos el byte
      fwrite(&byteToWrite, sizeof(unsigned char), 1, binaryCode);
    }
  }

  // Faltaron bits por escribir?
  if (tempBits != 0) {
    tempBits = (tempBits << (8 - tempSize));
    byteToWrite = tempBits;
    fwrite(&byteToWrite, sizeof(unsigned char), 1, binaryCode);
    bitsExtraWritten = 8 - tempSize; // Bits extra escritos
  }

  // En el ultimo byte, indica cuantos bits extra escribimos
  byteToWrite = bitsExtraWritten;
  fwrite(&byteToWrite, sizeof(unsigned char), 1, binaryCode);

  // Obtenemos el tamaño del archivo comprimido
  fseek(binaryCode, 0L, SEEK_END);
  (*compressedFileSize) = ftell(binaryCode);
  rewind(binaryCode);
  // Cerrar el archivo
  fclose(binaryCode);
}

int main(int argc, char *argv[])
{
    //*********************************************************
    //Variables a usar en el programa

    //Variables para el control de tiempo
    double utime0, stime0, wtime0, utime1, stime1, wtime1;
    //Arreglo para almacenar la frecuencia de bytes
    struct data *bytesFrecuency = malloc(256 * sizeof(struct data));
    //Arreglo para almacenar la codificacion de Huffman
    struct bits *bytesCode = malloc(256 * sizeof(struct bits));
    //Arreglo para almacenar el byte y frecuencia en cada nodo del arbol
    struct node *roots = (struct node *)malloc(256 * sizeof(struct node));
    //Arbol de Huffman ya unificado
    struct node *HuffmanTree;
    //Cadena de bytes leidos del archivo original
    unsigned char *bytesRead;
    //Cola de prioridad
    Heap *heap = CreateHeap(511);
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
    HuffmanTree = mergeTrees(heap);
    //Obtener los bits que vale cada byte
    getBits(HuffmanTree, bytesCode, 0, 0);
    //escribir el .dat con los bits de cada byte correspondiente
    writeBinaryCode(bytesRead, HuffmanTree, bytesCode, fileSize, &compressedFileSize);
    //escribir la tabla de frecuencias y el tamaño
    writeFrecuenyTable(bytesFrecuency, fileSize);

    //******************************************************************
    // Evaluar los tiempos de ejecución
    //******************************************************************
    uswtime(&utime1, &stime1, &wtime1);

    printf("Tamaño de %s: %d bytes\n", argv[1], fileSize);
    printf("Tamaño del archivo comprimido: %d bytes\n", compressedFileSize);
    printf("Porcentaje de compresion alcanzado: %.2f%%\n",
           ((float)fileSize / (float)compressedFileSize) * 100);
    printf("Tiempo real de Ejecucion: %.10e s\n\n", wtime1 - wtime0);

    return 0;
}
