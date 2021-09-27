#!/bin/bash

lista=$(cat $1)
for busqueda in $lista
do
    gcc tiempo.c $busqueda.c -o $busqueda
done		
