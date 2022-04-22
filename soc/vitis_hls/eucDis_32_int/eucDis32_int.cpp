#include "eucDis32_int.h"

void eucDis32_int(INPUT A[VECTOR_LENGTH], INPUT B[VECTOR_LENGTH], OUTPUT *C){
  #pragma HLS INTERFACE mode=s_axilite port=A storage_impl=bram
  #pragma HLS INTERFACE mode=s_axilite port=B storage_impl=bram
  #pragma HLS INTERFACE mode=s_axilite port=C
  #pragma HLS INTERFACE mode=s_axilite port=return
  #pragma HLS ARRAY_PARTITION variable=A type=cyclic factor=16
  #pragma HLS ARRAY_PARTITION variable=B type=cyclic factor=16

  INTER inter_result = 0;
  eachElement:for(int index = 0; index < VECTOR_LENGTH; index++){
    #pragma HLS unroll factor = 64
    #pragma HLS pipeline II=4
    inter_result += (A[index]-B[index])*(A[index]-B[index]);

  }
  C[0] = hls::sqrt(inter_result);
}
