#!/bin/bash

lista=$(cat $1)
size=$2
key=$3
for busqueda in $lista
do
    ./$busqueda $size $key < 10millonesord.txt
done		
