#include <string.h> 
#include <stdio.h>
#include <stdlib.h>
#include "alg3.h"
 //#include "alg1.h" pensé que podría usar el alg1 para hacerlo unu



int alg3(char* x, char* y, int n, int B){
    //pedimos espacio donde se almacenarán 
    //los resultados de las fronteras solapadas
    int **horizontales = malloc((n/B)*sizeof *horizontales); //las fronteras horizontales
    //necesitamos las de la última fila de submatrices
    int *f2 = malloc((B+1)*sizeof(int)); //la frontera vertical
    
    //inicializamos los indices que vamos a usar para recorrer las submatrices 
    int l;// _ filas de submatrices
    int m;// | columnas de submatrices
    for(l=0;l<n/B;l++){
        for(m=0;m<n/B;m++){
            int i,j;
            int **matrix = malloc((B+1) * sizeof *matrix);
            
            // Se pide memoria del Heap, ya que con B muy grande produce Stack Overflow
            for (i = 0; i <= B; i++)
                matrix[i] = malloc((B+1) * sizeof *matrix[i]);

            // Inicializar matriz
            if(l == 0 && m = 0){
                for (i=0; i<=B; i++){
                    matrix[i][0]=i;
                    matrix[0][i]=i;
                }
            }else if(l == 0){ //conozco los valores de arriba
                for (i=B*m; i<=B*(m+1); i++){
                    matrix[0][i] = i;
                    matrix[i][0] = f2[i-B*m];
                }
            }else if(m == 0){ //conozco los valores de la izquierda
                for (i=B*l; i<=B*(l+1); i++){
                    matrix[i][0] = i;
                    matrix[0] = *horizontales[0];
                }
            }else{
                for(i=0; i<=B; i++){
                    matrix[i][0] = f2[i-B*m];
                    matrix[0] = *horizontales[m];
                }
            }
            
            //aplicamos el algoritmo 1
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
                    //se busca el mínimo de los 3 pesos
                    min = w[0];
                    for (int k=1; k<3;k++){
                        if (w[k]<min){
                            min = w[k];
                        }
                    }
                     matrix[i][j]=min; // Se asigna la menor distancia
                }
            }
            for(i=0;i<B;i++){
                horizontales[m][i] = matrix[B][i];
                f2[i] = matrix[i][B]; 
            }
            
            //Liberar memoria de la matriz que usamos
            for (i = 0; i <= B; i++)
                free(matrix[i]);
            free(matrix);
        }
    }
    int aux = sizeof(f2);
    int result = f2[aux];
    
    return result;
}
