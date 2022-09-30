#ifndef BENCH_DOT_H    /* This is an "include guard" */
#define BENCH_DOT_H    /* prevents the file from being included twice. */
                     /* Including a header file twice causes all kinds */
                     /* of interesting problems.*/

typedef int (*func)(char*, char*, int);



void benchmark(int min, int max, int iter, func* f, int nfun, char* filename);
    /*
    Recibe:
    Minina y maxima potencia (2^(min o max)) para largo de string
    Número de iteraciones por largo
    Arreglo de punteros a funciones (deben recibir dos char* y un int)
    Número de funciones del arreglo
    Escribe los resultados en el archivo filename
    */
#endif 