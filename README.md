# Fixmath

This is a reboot of Fixmath library (from v1.4).

- [x] cleanup
- [ ] move to CMake instead of autotools
- [x] README
- [x] LICENCE
- [x] COPYRIGHT
- [ ] is building
- [ ] is linking
- [ ] is tested
- [ ] is documented

## Origin
From :
- [gnu](https://savannah.nongnu.org/projects/fixmath/)
- [doc](https://www.nongnu.org/fixmath/doc/index.html)
- [src](http://download-mirror.savannah.gnu.org/releases/fixmath/)
- [git](https://git.savannah.nongnu.org/cgit/fixmath.git)

## Licence
See [LICENCE.md](LICENCE.md)

## Copyright
See [COPYRIGHT.md](COPYRIGHT.md)

## Org
- src : lib files --> libfixmath.a
```bash
libfixmath_la_SOURCES = fixmath.c      \
                        fixmath_ver.c  \
                        fixmath_impl.c \
                        fixmath_str.c

```
- tools : matlab files
- include : API for the lib
```bash
fx_include_HEADERS = include/fixmath.h         \
                     include/fixmath_ver.h     \
                     include/fixmath_export.h  \
                     include/fixmath_arch.h    \
                     include/fixmath_impl.h    \
                     include/fixmath_macro.h
```
- doxygen :  html doc files
- prof : profiling tool
```bash
fixprof.c
```
- checktests : test suite
```bash
fixtest.c
```

## Build info
```bash
# Major version number
FX_VERSION=1

# Minor version number
FX_MINOR=4

Libs: -L${libdir} -lfixmath
Cflags: -I${includedir}/fixmath
```

## Make
```bash
make all
make lib
make doc
make tst
make prof
make install
```