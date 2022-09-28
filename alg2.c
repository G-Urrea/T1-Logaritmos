#include <string.h> 
#include <stdio.h>
#include <stdlib.h>
#include "alg2.h"

int alg2(char* x, char* y, int n){
    int row[n+1];
    int col[n+1];

    int i,j;

    // Se inicializan fila (0) y columna (0)
    for (i=0;i<=n; i++){
        row[i] = i;
        col[i] = i;
    }

    int w[3];

    int min;
    /* La idea es ir actualizando C[j-1] cada vez que se avanza en una fila, de forma que
        sea siempre el valor de la diagonal.

        Por otro lado cada vez que se avance en una fila, los valores anteriores del arreglo de la fila
        irán "bajando", de forma que al terminar de iterar en un j, todos los valores del arreglo
        R correspondan a la fila de la altura j.  
    */
    for (j=1; j<=n; j++){
        for (i=1; i<=n; i++){
            w[1] = row[i] + 1; // El que está 'arriba' (M[i][j-1])
            w[2] = col[j-1]; // El que está en 'diagonal' (M[i-1][j-1])

            if (x[i-1]!=y[j-1]){
                w[2]+=1; // Coste de arista SE aumenta
            }

            if (i==1){
                w[0] = col[j] + 1; // El que está a la 'izquierda' (M[i-1][j])
            }
            else{
                w[0] = row[i-1] + 1; // El que está a la 'izquierda' (M[i-1][j])
            }

            min = w[0];
            for (int k=1; k<3;k++){
                if (w[k]<min){
                    min = w[k];
                }
            }

            col[j-1] = row[i]; // Se 'desplaza' col[j-1] hacia la derecha
            row[i] = min; // Se desplaza row[i] hacia abajo
            if (i==1){
                row[i-1] = col[j] ; // Sólo al empezar una iteración, se desplaza hacia abajo el inicio de la fila
            }
        
        }
    }

    return row[n];
}