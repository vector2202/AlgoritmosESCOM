/**
 * @file
 * @brief Este programa comprime un archivo usando el algoritmo de Huffman
 *
 * @author Victor Torres
 * @author Leilani Sotelo
 * @author Guillermo Sanchez
 * @version 1.0
 */
//compilacion: gcc -lm tiempo.c HuffmanStructures.c CompressHuffman.c -o CompressHuffman
//ejecución ./CompressHuffman nombreDelArchivo
/**
 * Lee los bytes del archivo de entrada y lo guarda en una cadena.
 * Esta funcion lee un archivo de entrada, calcula el tamaño del
 * archivo, lee los bytes del archivo y los guarda en una cadena
 * ademas registra la frecuencia de aparicion de cada byte
 * aplicando el concepto de Hash, donde la llave es el valor
 * en decimal del byte que leimos
 *
 * @param fileToOpen nombre del archivo a abrir
 * @param bytesFrecuency arreglo donde esta la frecuencia de repeticion de bits
 * @param fileSize direccion de memoria de la variable del tamaño del archivo
 * @return el apuntador de la cadena de los bytes leidos
 */
unsigned char* readFile(const char* fileToOpen, struct data bytesFrecuency[], int* fileSize);
/**
 *
 * Escribe la tabla de frecuencias y el tamaño del archivo leido.
 * Escribe en un txt, el tamaño original del archivo ademas de
 * el valor en decimal de cada bit que aparecio seguida de las
 * veces que aparecio solo si la frecuencia de aparicion es 
 * mayor a 0, esto es, que el byte esta en el archivo original
 *
 * @param symbolFrecuency arreglo donde esta la frecuencia de repeticion de bits
 * @param fileSize direccion de memoria de la variable del tamaño del archivo
 */
void writeFrecuenyTable(struct data bytesFrecuency[], int fileSize);
/**
 * Escribe la codificacion de Huffman de cada byte correspondiente.
 * En un archivo llamado byteCode.dat, escribe el equivalente de
 * la codificacion de Huffman de los bytes leidos del archivo original,
 * esto lo hace mediante corrimientos de bits y con una bandera llamada
 * sizeByteToWrite que nos indica si tenemos los 8 bits para escribir
 * en el .dat, si no la guarda y mediante corrimeintos la suma con la 
 * codificacion del siguiente byte, en el ultimo byte del .dat, escribe
 * cuantos bits extra escribimos que no corresponden a la codificacion
 * de Huffman
 *
 * @param bytesRead el apuntador al inicio de la cadena de los bytes leidos
 * @param mainTree el arbol de Huffman donde unimos todos los bytes y su frecuencia
 * @param frecuencyTable un arreglo donde temenos la codificacion de Huffman de los bytes
 * @param fileSize el tamaño del archivo original
 */
void writeBinaryCode(unsigned char* bytesRead, struct node* mainTree, struct bits* bytesCode, int fileSize, int* compressedFileSize);
