#!/bin/bash

#./ejecutar.sh listadeordenamiento size key threads archivoentrada
lista=$(cat $1)
size=$2
threads=$4
key=$3
input=$5
for ordenamiento in $lista
do
    ./$ordenamiento $size $key $threads < $input
done
