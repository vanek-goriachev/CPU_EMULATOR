cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 17)

project(tests)

add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(tests run_tests.cpp 1-constructors.cpp)
target_include_directories(tests PUBLIC ../)
target_link_libraries(tests stack-library gtest gtest_main)
