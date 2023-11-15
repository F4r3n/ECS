set(${PROJECT_NAME2} "testECS")

include(CheckCXXCompilerFlag)

include(FetchContent)

set(BUILD_GMOCK OFF)
FetchContent_Declare(
  GTEST
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        b10fad38c4026a29ea6561ab15fc4818170d1c10
)
FETCHCONTENT_MAKEAVAILABLE(GTEST)
include_directories(SYSTEM ${gtest_SOURCE_DIR}/include)
link_directories(${gtest_BINARY_DIR})

include_directories("../lib/include")
link_directories("../bin")

enable_testing()
set(TEST_NAME TEST_1)
add_executable(${TEST_NAME} allocation_test.cpp main.cpp)
set_property(TARGET ${TEST_NAME} PROPERTY CXX_STANDARD 14)
set_property(TARGET ${TEST_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
target_link_libraries(${TEST_NAME} ECS gtest)
add_test(test1 ${TEST_NAME})

set(TEST_NAME TEST_2)
add_executable(${TEST_NAME} ComponentTest.cpp main.cpp)
set_property(TARGET ${TEST_NAME} PROPERTY CXX_STANDARD 14)
set_property(TARGET ${TEST_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
target_link_libraries(${TEST_NAME} ECS gtest)
add_test(test2 ${TEST_NAME})




