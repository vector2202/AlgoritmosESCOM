#!/bin/bash

lista=$(cat $1)
size=$2
key=$3
threads=$4
for $ordenamiento in $lista
do
   	./$ordenamiento $size $key $threads < 10millonesord.txt
done
