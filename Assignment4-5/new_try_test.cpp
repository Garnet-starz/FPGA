#include <stdio.h>
#include <math.h>
#include "new_try.hpp"

int main() {

        dout4_t a[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
        dout4_t b[12] = {2,3,4,5,6,7,8,9,10,11,12,13};
        dout4_t out1[12];
        dout4_t out2[12];
        dout4_t out3[12];
        dout4_t out4[12];

        basic_arith(
                a, b,
               out1, out2, out3, out4);}
