#cmake_minimum_required(VERSION 3.24)
#set(CMAKE_CXX_STANDARD 17)
#
#project(tests)

add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(tests run_tests.cpp 1-constructors.cpp 2-methods.cpp 3-expand.cpp 4-user-data-type.cpp)
target_include_directories(tests PUBLIC ../)
target_link_libraries(tests gtest gtest_main)
