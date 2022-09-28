#ifndef BENCH_DOT_H    /* This is an "include guard" */
#define BENCH_DOT_H    /* prevents the file from being included twice. */
                     /* Including a header file twice causes all kinds */
                     /* of interesting problems.*/

typedef int (*func)(char*, char*, int);

void benchmark(int min, int max, int iter, func f, char* filename);

#endif 