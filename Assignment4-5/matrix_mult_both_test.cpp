#include "matrix_mult_both.hpp"

int main(){
	int matrix_1[first_dim][second_dim] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 1, 2, 3}};
	int matrix_2[second_dim][first_dim] = {{4, 5, 6}, {7, 8, 9}, {1, 2, 3}, {4, 5, 6}};
	int matrix_out[first_dim][first_dim] = {{0}};

	matrix_mult(matrix_1, matrix_2, matrix_out);
}
