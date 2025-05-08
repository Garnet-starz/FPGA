#include "example.h"


void read_data(int in_r[N], int out_r[N]) {
    for (int i = 0; i < N; i++) {
        out_r[i] = in_r[i];  // Simple pass-through
    }
}

void compute_blur(int in_c[N], int out_c[N]) {
#pragma HLS ALLOCATION instances=mul limit=1 operation
#pragma HLS ALLOCATION instances=div limit=1 operation
#pragma HLS ARRAY_PARTITION variable=in_c cyclic factor=2
    for (int i = 1; i < N - 1; i++) {
#pragma HLS PIPELINE II=1
        out_c[i] = (in_c[i - 1] + in_c[i] + in_c[i + 1]) / 3;  // Box blur operation
    }
}

void write_data(int in_w[N], int out_w[N]) {
    for (int i = 0; i < N; i++) {
        out_w[i] = in_w[i];  // Simple pass-through
    }
}

void example(int A[N], int B[N]) {
    int temp1[N], temp2[N];

    for (size_t i = 0; i < N; i++) {
      temp2[i]=0;}

#pragma HLS DATAFLOW
    read_data(A, temp1);
#pragma HLS DATAFLOW
    compute_blur(temp1, temp2);
#pragma HLS DATAFLOW
    write_data(temp2, B);
}
