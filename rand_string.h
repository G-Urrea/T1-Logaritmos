#ifndef RAND_DOT_H    /* This is an "include guard" */
#define RAND_DOT_H    /* prevents the file from being included twice. */
                     /* Including a header file twice causes all kinds */
                     /* of interesting problems.*/
#include <stdlib.h>
/**
 
 */
// Crea un string aleatorio, dado un char* y tamaño de string
char *rand_string(char *str, size_t size); 

// Crea un string aleatorio de largo size, requiere hacer free
char* rand_string_alloc(size_t size); 

// Crea un string aleatorio de largo 2^n, requiere hacer free
char* rand_string_2n(size_t n);
#endif 