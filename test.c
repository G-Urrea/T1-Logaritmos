#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "benchmark.h"
#include "alg2.h"
#include "alg1.h"

typedef int (*func)(char*, char*, int);

int main(){

    func f1 = &alg1;
    func f2 = &alg2;
    benchmark(3, 15, 1, f1, "resultados1.txt");

    benchmark(3, 15, 1, f2, "resultados2.txt");

    return 0;
}