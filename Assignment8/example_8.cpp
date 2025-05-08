#include <ap_int.h>
#include <hls_stream.h>

#include "example_8.h"

void example(din_t A[N][N], din_t B[N][N], din_t C[N][N]) {
#pragma HLS INLINE
#pragma HLS ARRAY_PARTITION variable=A complete dim=2
#pragma HLS ARRAY_PARTITION variable=B complete dim=1
#pragma HLS ARRAY_PARTITION variable=C complete dim=2

	for (size_t i = 0; i < N; ++i) {
#pragma HLS LOOP_TRIPCOUNT min=64 max=64
		for (size_t j = 0; j < N; ++j) {
#pragma HLS LOOP_TRIPCOUNT min=64 max=64
#pragma HLS PIPELINE II=1


      C[i][j]=0;
      for (size_t k = 0; k < N; ++k) {

	C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

