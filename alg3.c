#include <string.h> 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "alg3.h"
#include "alg1.h"

// M es el tamaño de la memoria cache en bytes
int alg3(char* x, char* y, int n, int M){

    int result;
    // Entra todo en memoria, se puede usar directamente el algoritmo 1
    if ((n+1)*(n+1)*sizeof(int)<=M){
        result = alg1(x, y, n);
    }
    else{
        //Las submatrices son de tamaño b^2*sizeof(int)<M para que entren en memoria
        double r = sqrt(M/sizeof(int));
        int b = r; //Se castea valor a entero 

        // Las fronteras son de tamaño N+1
        int* row = malloc((n+1)*sizeof(int));      
        int* col = malloc ((n+1)*sizeof(int));
        // Aquí se va escribiendo la frontera horizontal calculada
        int* newrow = malloc((n+1)*sizeof(int));
        // Inicializar fronteras
        for (int k=0; k<=n; k++){
            row[k] = k;
            col[k] = k;
        }
        // Empezar iterando sobre toda la matriz
        int p,q;

        // Se avanza (b-1), para que se solapen las fronteras
        for (p=0; p<=n; p+=(b-1)){
            //Se copian los nuevos valores
            if(p>0){
                for (int k=0; k<=n;k++){
                    row[k] = newrow[k];
                }
            }
            for (q=0; q<=n; q+=(b-1)){    
                    int startx = q;
                    int starty = p; 
                    int lenj = b; //Largo de matriz (Numero de Columnas)
                    int leni = b; //ancho de matriz  (Numero de Filas)

                    if (startx+(b-1)>n){
                        lenj = n+1-startx;
                    }
                    if (starty + (b-1)>n){
                        leni = n+1-starty;
                    }

                    // Se pide memoria del heap para prevenir stack overflow
                    int **matrix = malloc((leni) * sizeof *matrix);
                    //int matrix[leni][lenj];
                    
                    for (int i = 0; i < leni; i++)
                        matrix[i] = malloc((lenj) * sizeof *matrix[i]);

                    if (leni>0 && leni>0){
                    // Inicializar matriz con valores de la frontera
                        for (int i=1; i<leni; i++){
                            matrix[i][0] = col[starty+i];
                        }
                        for (int j=0; j<lenj; j++){
                            matrix[0][j]=row[startx+j];
                        }
                        int w[3]; //pesos
                        int min;
                        for (int i=1;i<leni;i++){
                            for (int j=1; j<lenj; j++){
                                w[0] = matrix[i][j-1] +1;
                                w[1] = matrix[i-1][j] +1;
                                w[2] = matrix[i-1][j-1];
                                        
                                if (x[startx + j-1]!=y[starty+i-1]){
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
                        // Una vez terminado el algoritmo, se reescriben las fronteras
                        for (int i=0; i<leni;i++){
                            col[starty+i] = matrix[i][lenj-1];   
                        }
                        for (int j=0; j<lenj;j++){
                            newrow[startx+j] = matrix[leni-1][j];
                        }
                        // Liberar memoria
                        for (int i = 0; i < leni; i++)
                            free(matrix[i]);
                        free(matrix);
                    }
            }
        }
        result = newrow[n];
        free(row);
        free(newrow);
        free(col);
    }
    return result;
}