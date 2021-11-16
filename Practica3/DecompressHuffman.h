/**
 * @file
 * @brief Este programa descomprime un archivo usando el algoritmo de Huffman
 *
 * @author Victor Torres
 * @author Leilani Sotelo
 * @author Guillermo Sanchez
 * @version 1.0
 */
// compilacion: gcc -lm tiempo.c HuffmanStructures.c DecompressHuffman.c -o
// DecompressHuffman
// ejecución: ./DecompressHuffman nombreDelArchivo
/**
 *
 * Lee y guarda la tabla de frecuencias. A partir de la tabla de frecuencia
 * generada al comprimir el archivo, leemos las veces que se se repitio
 * cada bit, ademas al principio del archivo leemos el tamaño original del
 * archivo, las frecuencias las guardamos en un arreglo, con su respectivo
 * byte aplicando hash, donde la llave es el byte.
 *
 * @param bytesFrecuency arreglo donde esta la frecuencia de repeticion de bits
 * @param fileSize direccion de memoria de la variable del tamaño del archivo
 */
void readFrecuencyTable(struct data bytesFrecuency[], int *fileSize);

/**
 *
 * Lee el archivo comprimido. Obtenemos el tamaño del archivo comprimido
 * y los bytes que lo componen, esto lo guardamos en una cadena.
 *
 * @param fileSize direccion de memoria de la variable del tamaño del archivo
 * @param byteFileSize direccion de memoria de la variable del tamaño del
 * archivo comprimido
 * @return el arreglo donde estan los bytes leidos
 */
unsigned char *readByteCode(int *fileSize, int *byteFileSize);

/**
 *
 * Escribimos el archivo original a partir de la decodificacion de los bytes.
 * Vamos recorriendo bit a bit de los bytes leidos en el archivo comprimido,
 * y recorremos el arbol de Huffman, en base a esto nos devuelve tanto la
 * la posicion en bits de 0 a 7 en la que se quedo, como en la variable
 * byteToWrite, el byte correspondiente a cada cadena de bits, una ves que
 * tenemos esto, escribimos en el archivo el byte correspondiente.
 *
 * @param bytesRead el apuntador al inicio de la cadena de los bytes leidos
 * @param mainTree el arbol de Huffman donde unimos todos los bytes y su frecuencia
 * @param file el nombre del archivo en el que escribiremos
 * @param byteFileSize el tamaño del archivo comprimido
 * @param fileSize apuuntador de la variable del tamaño del archivo que escribiremos
 */
void writeFile(unsigned char *bytesRead, struct node *mainTree,
               const char *file, int byteFileSize, int *fileSize);
