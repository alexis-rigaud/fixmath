#include <stdio.h>
#include <math.h>
#include "fixmath.h"

int main(void)
{
    unsigned int fract = 30; // use 30-bit fract size
    unsigned int digit = floor(fract * log10(2)) + 1;
    printf("Display fractional size : %d decimal digit\n", digit);

    char a_str[8+digit];
    char b_str[8+digit];
    char c_str[8+digit];

    double a_d = 1.4l;
    double b_d = 0.311l;
    double c_d = a_d * b_d;

    printf("double mult. with 52-bit fractionnal part:\t%.*e * %.*e = %.*e\n",
        digit, a_d, digit, b_d, digit, c_d);

    float a = 1.4f;
    float b = 0.311f;
    float c = a * b;

    printf("float  mult. with 23-bit fractionnal part:\t%.*e * %.*e = %.*e\n",
        digit, a, digit, b, digit, c);

    fixed_t ax = fx_dtox(a_d, fract);
    fixed_t bx = fx_dtox(b_d, fract);
    fixed_t cx = fx_mulx(ax, bx, fract);

    fx_xtoa(a_str, ax, fract, digit);
    fx_xtoa(b_str, bx, fract, digit);
    fx_xtoa(c_str, cx, fract, digit);

    printf("fixed  mult. with %d-bit fractionnal part:\t%s     * %s = %s\n", fract, a_str, b_str, c_str);
}
