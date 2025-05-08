#include "matrix_mult_both.hpp"

void matrix_mult(int matrix_1[first_dim][second_dim], int matrix_2[second_dim][first_dim], int matrix_out[first_dim][first_dim]){
#pragma HLS INTERFACE s_axilite port = return
#pragma HLS INTERFACE bram port = matrix_1
#pragma HLS INTERFACE bram port = matrix_2
#pragma HLS INTERFACE bram port = matrix_out

#pragma HLS ARRAY_PARTITION variable = matrix_1 complete dim = 0
#pragma HLS ARRAY_PARTITION variable = matrix_2 complete dim = 0

	for (int i = 0; i < first_dim; i++){
		for (int j = 0; j < second_dim; j++){
			for (int k = 0; k < second_dim; k++){
			matrix_out[i][j] += matrix_1[i][k] * matrix_2[k][j];
			}
		}
	}
}	
