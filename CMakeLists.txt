cmake_minimum_required(VERSION 3.8)
project(Algos)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c miniStart/main.mini.c miniStart/main.mini.h primeNumber/prime.main.c primeNumber/prime.main.h sumOfNumberString/sumnumber.main.c sumOfNumberString/sumnumber.main.h)
add_executable(Algos ${SOURCE_FILES})