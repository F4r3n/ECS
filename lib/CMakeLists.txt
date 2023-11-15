cmake_minimum_required (VERSION 3.16)
project (ECS CXX)
include(CheckCXXCompilerFlag)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("include")
file(GLOB_RECURSE HEADERS "include/*.h" "include/*.hpp")

file(GLOB SOURCES "src/*.cpp")


add_library(ECS STATIC ${SOURCES} ${HEADERS})


