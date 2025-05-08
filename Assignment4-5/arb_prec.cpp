#include "arb_prec.hpp"

void basic_arith(dout4_t a[12], dout4_t b[12],
                dout4_t out1[12], dout4_t out2[12],
                dout4_t out3[12], dout4_t out4[12]
                )
{
        int i;
        for (i = 0; i <= 12; i++){
                out1[i] = a[i] * b[i];
                out2[i] = a[i] + b[i];
                out3[i] = a[i] / b[i];
                out4[i] = a[i] % b[i];}
}
