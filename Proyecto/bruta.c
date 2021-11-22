#include <stdlib.h>
#include <stdio.h>
#define n 5
int min(int a, int b) { return (a <= b) ? a : b; }

int solbruta(int a[2][n], int t[2][n-1], int x[], int i, int camino, int linea)
{
    if(i >= n)
	return camino + x[linea];
    int quedarse = 0, cambiarse = 0;
    //nos quedamos en la linea
    quedarse = solbruta(a, t, x, i+1, camino + a[linea][i], linea);
    //nos cambiamos de linea
    cambiarse = solbruta(a, t, x, i+1, camino + t[linea][i] + a[linea][i], (linea == 0) ? 1 : 0);
    return min(quedarse, cambiarse);
}

int main() {
    
    int a[2][n] = {{8, 10, 4, 5, 9}, {9, 6, 7, 5, 6}};
    int t[2][n-1] = {{2, 3, 1, 3}, {2, 1, 2, 2}};
    int e[2] = {3, 5};
    int x[2] = {2, 1};
    int i;

    int camino = ((e[0] + a[0][0]) <= (e[1] + a[1][0])) ? (e[0]) : (e[1]);
	//((e[0] + a[0][0]) <= (e[1] + a[1][0])) ? (e[0] + a[0][0]) : (e[1] + a[1][0]);
    int lp = ((e[0]) == camino) ? 0 : 1;
    printf("%d", solbruta(a, t, x, 0, camino, lp));
    /* int camino1, camino2, camino3, camino4, caminomax; */
	
    /* for(i = 0; i < n-2; i++) */
    /* { */
    /* 	//detectar en que lp estamos */
    /* 	if(lp == 0) */
    /* 	{ */
    /* 	    camino1 = a[0][i+1] + a[0][i+2]; */
    /* 	    camino2 = t[0][i] + a[1][i+1] + a[1][i+2]; */
    /* 	    camino3 = a[0][i+1] + t[0][i+1] + a[1][i+2]; */
    /* 	    camino4 = t[0][i] + a[1][i+1] + t[1][i+1] + a[0][i+2]; */
    /* 	    caminomax = max(camino1, max(camino2, max(camino3, camino4))); */
    /* 	    if(caminomax == camino2 || caminomax == camino3) */
    /* 		lp = 1; */
    /* 	} */
    /* 	else{ */
    /* 	    camino1 = a[1][i+1] + a[1][i+2]; */
    /* 	    camino2 = t[1][i] + a[0][i+1] + a[0][i+2]; */
    /* 	    camino3 = a[1][i+1] + t[1][i+1] + a[0][i+2]; */
    /* 	    camino4 = t[1][i] + a[0][i+1] + t[0][i+1] + a[1][i+2]; */
    /* 	    caminomax = max(camino1, max(camino2, max(camino3, camino4))); */
    /* 	    if(caminomax == camino2 || caminomax == camino3) */
    /* 		lp = 0; */
    /* 	} */
    /* } */
    
  return 0;
}
