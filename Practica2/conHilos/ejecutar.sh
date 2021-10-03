#!/bin/bash

lista=$(cat $1)
listsize=$(cat $2)
threads=$3
input=$4
for ordenamiento in $lista
do
    for size in $listsize
    do
   	./$ordenamiento $size $threads < $input
    done
done

# lista=$(cat $1)
# size=$2
# key=$3
# threads=$4
# input=$5
# for ordenamiento in $lista
# do
#    	./$ordenamiento $size $key $threads < $input
# done
