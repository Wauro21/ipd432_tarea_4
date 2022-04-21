#ifndef EUCDIS32FLOAT_H
#define EUCDIS32FLOAT_H

#define VECTOR_LENGTH 1024

#include "hls_math.h"

typedef float INPUT;
typedef float OUTPUT;
typedef float INTER;
void eucDis32_float(INPUT A[VECTOR_LENGTH], INPUT B[VECTOR_LENGTH], OUTPUT *C);

#endif
