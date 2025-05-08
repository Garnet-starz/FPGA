#include <stdio.h>
#include <math.h>
#include "new_array.h"

int main() {
	FILE *oFile;

	char a;
	char b;
	char c;
	int in[3] = {0, 1, 2};
	int out[3];

	a = 1;
	b = 2;
	c = 3;

	foo(in, a, b, c, out);

	oFile= fopen("new_array_out.dat", "w");

	int i;

	for(i = 0; i <= 2; i++){
		fprintf(oFile, "%i %d %d\n", i, in[i], out[i]);}

	fclose(oFile);

	printf("Comparing against output data \n");
	if (system("diff -w new_array_out.dat new_array_ref.dat"))
	{
	fprintf(stdout, "*******************************************\n");
	fprintf(stdout, "FAIL: Output DOES NOT match the reference output\n");
	fprintf(stdout, "*******************************************\n");
	return 1;
	}
	else
	{
	fprintf(stdout, "*******************************************\n");
	fprintf(stdout, "PASS: The output matches the reference output!\n");
	fprintf(stdout, "*******************************************\n");
	return 0;
	}}
