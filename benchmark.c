#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "rand_string.h"
#include "benchmark.h"

typedef int (*func)(char*, char*, int);

void benchmark(int min, int max, int iter, func f, char* filename){
    /*
    Recibe minina y maxima potencia (2^(min o max)) para largo de string
    Número de iteraciones por largo
    Función (debe recibir dos char* y un int)
    Escribe los resultados en el archivo filename
    */
    char *s1;
    char *s2;
    double ti, tf, delta;
    double mean;
    double means[max-min +1];

    for (int i = min; i<=max; i++){
        int p = pow(2, i);
        mean = 0;
        for (int j=0; j<iter; j++){
            // Crear strings de largo 2^i
            s1 = rand_string_2n(i);
            s2 = rand_string_2n(i);

            ti = (double)clock()/CLOCKS_PER_SEC;
            (void) f(s1, s2, p); // No necesitamos el valor de retorno
            tf = (double)clock()/CLOCKS_PER_SEC;
            delta = tf-ti;
            mean +=delta;
               
            free(s1);
            free(s2);
        }
        mean /= iter;
        printf("Iter: %d, Tpromedio: %f\n", i, mean);
        means[i-min] = mean;
    }
    FILE *fp;
    fp = fopen(filename, "w");
    for (int i = min; i <= max; i++) {
            fprintf(fp, "%d, %f\n", i, means[i-min]);
        }

    fclose(fp);
}

