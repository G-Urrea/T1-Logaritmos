#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "rand_string.h"

static char *rand_string(char *str, size_t size)
{
    const char charset[] = "abcdefghijklmnopqrstuvwxyz";
    if (size) {
        --size;
        for (size_t n = 0; n < size; n++) {
            int key = rand() % (int) (sizeof charset - 1);
            str[n] = charset[key];
        }
        str[size] = '\0';
    }
    return str;
}

char* rand_string_alloc(size_t size)
{
     char *s = malloc(size + 1);
     if (s) {
         rand_string(s, size);
     }
     return s;
}

char* rand_string_2n(size_t n){
    int l = pow(2, n);
    char *s = rand_string_alloc(l);
    return s;
}
