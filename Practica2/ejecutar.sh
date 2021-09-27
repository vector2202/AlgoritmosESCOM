#!/bin/bash

lista=$(cat $1)
numero=$2
numero1=$3
for busqueda in $lista
do
    ./$busqueda $numero $numero1 < 10milloneso.txt
done		
