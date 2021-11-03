#!/bin/bash

archivoOrigen=$1
#archivoDestino=$2

echo -e "\nComprimir y descomprimir archivos usando el Algoritmo de Huffman\n\n"
echo -e "Archivo a comprimir: $archivoOrigen."

gcc -lm tiempo.c HuffmanStructures.c CompressHuffman.c -o CompressHuffman

gcc -lm tiempo.c HuffmanStructures.c DecompressHuffman.c -o DecompressHuffman

./CompressHuffman $archivoOrigen

rm $archivoOrigen

echo El archivo original ha sido removido

./DecompressHuffman $archivoOrigen

