#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "benchmark.h"
#include "alg2.h"
#include "alg1.h"

typedef int (*func)(char*, char*, int);

int main(){
    func f[2] = {&alg1, &alg2};
    benchmark(3, 12, 50, f, 2, "resultados.txt");
    return 0;
}