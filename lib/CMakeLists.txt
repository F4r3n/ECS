cmake_minimum_required (VERSION 2.8.11)
project (ECS)
include(CheckCXXCompilerFlag)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++14 -g")

#add_subdirectory (src)
include_directories("include")
file(GLOB SOURCES "src/*.cpp")
add_library(ECS SHARED ${SOURCES})


