# Fixmath

Fixed-point math library, using signed 32-bit Qn.m format with n+m = 31

This is a reboot of Fixmath library using modern environement.

## Example (Q15.16)
```c
fixed_t norm2(fixed_t *buf, int len)
{
    fixed_t sum = 0;
    int     k;
    for (k = 0; k < len; k++) {
        fixed_t val = buf[k];
        sum += fx_mulx(val, val, 16);
    }
    return fx_sqrtx(sum, 16);
}
```
## Matlab 
Under the tools dir :
- remez.m : an implementation of the Remez algorithm for function approximation
- encode.m : fixed point encoding of the obtained coefs

## Origin
From :
- [gnu](https://savannah.nongnu.org/projects/fixmath/)
- [doc](https://www.nongnu.org/fixmath/doc/index.html)
- [src](http://download-mirror.savannah.gnu.org/releases/fixmath/)
- [git](https://git.savannah.nongnu.org/cgit/fixmath.git)

## How to build
```bash
mkdir build
cd build
cmake ..
make # make all all
make fixmath # build the library
make doc     # doc in html
make doc; cd latex; make pdf  # doc in pdf
make checktests;  # the test suite
make prof    # profiling tool
```