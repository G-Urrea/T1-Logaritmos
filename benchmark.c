#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "rand_string.h"
#include "benchmark.h"

typedef int (*func)(char*, char*, int);

void benchmark(int min, int max, int iter, func* f, int nfun, char* filename){

    char *s1;
    char *s2;
    double ti, tf, delta;
    double mean[nfun];

    FILE *fp;
    fp = fopen(filename, "w");
    fprintf(fp, "n,alg,t\n");

    for (int i = min; i<=max; i++){
        int p = pow(2, i);

        for (int k=0; k<nfun; k++){
            mean[k] = 0;
        }
        
        for (int j=0; j<iter; j++){
            // Crear strings de largo 2^i
            s1 = rand_string_2n(i);
            s2 = rand_string_2n(i);

            for (int k = 0; k<nfun; k++){
                ti = (double)clock()/CLOCKS_PER_SEC;
                (void) f[k](s1, s2, p); // No necesitamos el valor de retorno
                tf = (double)clock()/CLOCKS_PER_SEC;
                delta = tf-ti;
                mean[k] += delta/iter;
            }
            free(s1);
            free(s2);
        }
        for (int k = 0; k<nfun; k++){
            printf("n: %d, Alg: %d, T: %f\n", i, k, mean[k]);
            fprintf(fp, "%d,%d,%f\n", i, k, mean[k]);
        }     
    }
    fclose(fp);
}

