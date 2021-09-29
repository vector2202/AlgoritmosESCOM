#!/bin/bash

lista=$(cat $1)
for busqueda in $lista
do
   gcc -lm -lpthread tiempo.c $busqueda.c -o $busqueda

done		
