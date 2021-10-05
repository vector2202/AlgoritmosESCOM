#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int size = atoi(argv[1]);
    //int pos = atoi(argv[2]);
    int i;
    int* array = malloc(size * sizeof(int));
    for(i = 0; i < size; i++)
	scanf("%d", (array+i));
    printf("%d\n", array[size-1]);
    return 0;
}
