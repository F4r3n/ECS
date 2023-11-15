cmake_minimum_required (VERSION 3.16)
project (ECS)
include(CheckCXXCompilerFlag)

option(ECS_BUILD_STATIC ON)
option(ECS_BUILD_SHARED OFF)
option(ECS_BUILD_EXAMPLES OFF)
option(ECS_BUILD_TESTS OFF)
add_subdirectory("lib")

if(ECS_BUILD_EXAMPLES)
	add_subdirectory("sample")
endif(ECS_BUILD_EXAMPLES)

if(ECS_BUILD_TESTS)
	add_subdirectory("Tests")
endif(ECS_BUILD_TESTS)
