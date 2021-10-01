#!/bin/bash

lista=$(cat $1)
listsize=$(cat $2)
input=$3
for ordenamiento in $lista
do
    for size in $listsize
    do
   	./$ordenamiento $size < $input
    done
done
