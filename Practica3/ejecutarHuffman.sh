#!/bin/bash

archivoOrigen=$1
#archivoDestino=$2

echo -e "\n Comprimir y descomprimir archivos usando el Algoritmo de Huffman\n\n"
echo -e "Archivo a comprimir: $archivoOrigen \n"
echo Tamaño del archivo a comprimir: 
wc -c $archivoOrigen

gcc -lm tiempo.c HuffmanStructures.c CompressHuffman.c -o CompressHuffman

gcc -lm tiempo.c HuffmanStructures.c DecompressHuffman.c -o DecompressHuffman

./CompressHuffman $archivoOrigen

rm $archivoOrigen

echo El archivo original ha sido removido

./DecompressHuffman $archivoOrigen

echo Tamaño del archivo descomprimido:

wc -c $archivoOrigen
