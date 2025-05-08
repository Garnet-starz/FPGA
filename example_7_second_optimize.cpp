#include <ap_int.h>
#include <hls_stream.h>

#include "example_7.h"

// Top-level function for HLS
void example(din_t A[N][N], din_t B[N], din_t C[N]) {

#pragma HLS INLINE off
#pragma HLS ARRAY_PARTITION variable = A complete dim=2
#pragma HLS ARRAY_PARTITION variable = B complete dim=1
#pragma HLS ALLOCATION instances=mul limit=1 operation
	// Matrix multiplication
  for (size_t i = 0; i < N; i++) {
#pragma HLS PIPELINE II=1
    float prod = 0;
    for (size_t j = 0; j < N; j++) {
#pragma HLS LATENCY min=1 max=20

      prod += A[i][j] * B[j];
    }
    C[i] = prod;
  }
  bubble_sort(C);
}

void bubble_sort(din_t arr[SORT_N]) {
#pragma HLS INLINE

    for (int i = 0; i < SORT_N - 1; i++) {
        for (int j = 0; j < SORT_N - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

