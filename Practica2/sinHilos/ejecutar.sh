#!/bin/bash

#./ejecutar.sh listaAejecutar size key archivodeentrada
lista=$(cat $1)
size=$2
key=$3
input=$4
for ordenamiento in $lista
do
	./$ordenamiento $size $key < $input
done
