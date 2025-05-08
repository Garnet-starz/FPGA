#ifndef NEW_TRY_H_
#define NEW_TRY_H_
#include <ap_int.h>

typedef ap_int<32> dout4_t;

void basic_arith(
                dout4_t a[12], dout4_t b[12],
                dout4_t out1[12], dout4_t out2[12],
                dout4_t out3[12], dout4_t out4[12]);

#endif
