cmake_minimum_required (VERSION 3.16)
project (ECS)
include(CheckCXXCompilerFlag)

set(ECS_BUILD_STATIC ON)
set(ECS_BUILD_SHARED OFF)
set(ECS_BUILD_EXAMPLES ON)
set(ECS_BUILD_TESTS ON)
add_subdirectory("lib")

if(ECS_BUILD_EXAMPLES)
	add_subdirectory("sample")
endif(ECS_BUILD_EXAMPLES)

if(ECS_BUILD_TESTS)
	add_subdirectory("Tests")
endif(ECS_BUILD_TESTS)
