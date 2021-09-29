#!/bin/bash

lista=$(cat $1)
lista2=$(cat $2)
for busqueda in $lista
do
   gcc -lm -lpthread tiempo.c $busqueda.c -o $busqueda

done
for busqueda in $lista2
do
   gcc -lm -lpthread tiempo.c $busqueda.c -o $busqueda

done		

