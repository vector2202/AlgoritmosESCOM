#!/bin/bash

archivoOrigen=$1
archivoDestino=$2

gcc -lm HuffmanStructures.c CompressHuffman.c -o CompressHuffman

gcc -lm HuffmanStructures.c DecompressHuffman.c -o DecompressHuffman

./CompressHuffman $archivoOrigen
./DecompressHuffman $archivoDestino
