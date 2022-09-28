#include <string.h> 
#include <stdio.h>
#include <stdlib.h>
#include "alg1.h"

int alg1(char* x, char* y, int n){
    //unsigned n = strlen(x);

   // int matrix[n+1][n+1];
    int **matrix = malloc((n+1) * sizeof *matrix);
    int i, j;

    // Se pide memoria del Heap, ya que con n muy grande produce Stack Overflow
    for (i = 0; i <= n; i++)
        matrix[i] = malloc((n+1) * sizeof *matrix[i]);

    // Inicialización de matriz
    for (i=0; i<=n; i++){
        matrix[i][0]=i;
        matrix[0][i]=i;
    }

    //
    int w[3]; //pesos
    int min;
    for (j=1;j<=n;j++){
        for (i=1; i<=n; i++){

            w[0] = matrix[i][j-1] +1;
            w[1] = matrix[i-1][j] +1;
            w[2] = matrix[i-1][j-1];
            
            if (x[j-1]!=y[i-1]){
                w[2]+=1; // La arista SE adquiere peso
            }

            min = w[0];
            for (int k=1; k<3;k++){
                if (w[k]<min){
                    min = w[k];
                }
            }
             matrix[i][j]=min; // Se asigna la menor distancia
        }
    }
    int result = matrix[n][n];

    //Liberar memoria
    for (i = 0; i <= n; i++)
        free(matrix[i]);
    free(matrix);
    
    return result;
}
