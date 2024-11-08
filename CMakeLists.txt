cmake_minimum_required(VERSION 3.24)

## --- lib

# -- project definition
project(fixmath LANGUAGES C VERSION 1.4) # version number to be set here
add_compile_definitions(FX_VERSION=${PROJECT_VERSION_MAJOR})
add_compile_definitions(FX_MINOR=${PROJECT_VERSION_MINOR})

# -- build the library
add_library(fixmath STATIC
    src/fixmath.c
    src/fixmath_ver.c
    src/fixmath_impl.c
    src/fixmath_str.c
)
set_target_properties(fixmath PROPERTIES INTERFACE
    include/fixmath.h
)
target_include_directories(fixmath PUBLIC include)
target_link_libraries(fixmath PUBLIC)
target_compile_features(fixmath PRIVATE c_std_90)

## --- doc

# -- build the doc
find_package(Doxygen OPTIONAL_COMPONENTS dot)
if (DOXYGEN_FOUND)
    set(DOXYGEN_GENERATE_LATEX YES)
    doxygen_add_docs(doc ${CMAKE_SOURCE_DIR})
endif(DOXYGEN_FOUND)

## --- prof

# -- profiler tool
project(prof LANGUAGES C)
add_executable(prof
    prof/fixprof.c
)
target_link_libraries(prof fixmath)
target_compile_features(prof PRIVATE c_std_90)

## --- checktests

# -- test tool

find_library(CHECK_LIB Check REQUIRED)
find_path(Check_INCLUDE_DIR check.h REQUIRED)

project(checktests LANGUAGES C)
add_executable(checktests
    checktests/fixtest.c
)
target_include_directories(checktests PRIVATE ${Check_INCLUDE_DIR})
target_link_libraries(checktests PRIVATE ${CHECK_LIB} fixmath)
target_compile_features(prof PRIVATE c_std_11)