cmake_minimum_required (VERSION 2.8.11)
project (ECS)
include(CheckCXXCompilerFlag)

option(BUILD_EXAMPLES OFF)
option(BUILD_TESTS OFF)
add_subdirectory("lib")

if(BUILD_EXAMPLES)
add_subdirectory("sample")
endif(BUILD_EXAMPLES)

if(BUILD_TESTS)
add_subdirectory("Tests")
endif(BUILD_TESTS)
