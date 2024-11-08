# fixmath

Fixed-point arithmetic math library, based on integer signed 32-bit word.

Using Q format notation that signed Qm.n with m+n = 31, also noted Q.n

The fractional size (n) is left to the user when using the function (see [Example](#example))

This is a reboot of Fixmath library using modern environement.

## Example

This is an extract from the doc using 16-bit fractional size (eg Q.16)
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

## How to build

Generate Makefile :
```bash
mkdir build
cd build
cmake ..
```
And then :
```bash
make                          # make all
make fixmath                  # build the library
make install                  # install the lib
make checktests; ./checktests # the test suite
make prof; ./prof             # profiling tool
make doc                      # gen. doc in html
make doc; cd latex; make pdf  # gen. doc in pdf
```

Example to manualy link the lib, after `make install` :
```bash
cc sandbox/test.c -o test -L/usr/local/lib/ -lfixmath -Iinclude -rpath /usr/local/lib
```
