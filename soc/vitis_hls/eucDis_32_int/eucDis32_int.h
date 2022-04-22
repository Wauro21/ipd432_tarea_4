#ifndef EUCDIS32INT_H
#define EUCDIS32INT_H

#define VECTOR_LENGTH 1024

#include "ap_int.h"
#include "hls_math.h"

typedef ap_int<32> INPUT;
typedef ap_int<32> OUTPUT;
typedef ap_int<32> INTER;
void eucDis32_int(INPUT A[VECTOR_LENGTH], INPUT B[VECTOR_LENGTH], OUTPUT *C);

#endif
