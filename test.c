#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "benchmark.h"
#include "alg2.h"
#include "alg1.h"
#include "alg3.h"

#define KB 1024
typedef int (*func)(char*, char*, int);

int alg3wrapper(char*x, char*y, int n){
    //Cache obtenido con lscpu
    return alg3(x, y, n, 256*KB);
}
int main(){

    func f[3] = {&alg1, &alg2, &alg3wrapper};
    benchmark(3, 12, 10, f, 3, "resultados.txt");
    return 0;
}