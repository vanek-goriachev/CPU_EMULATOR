cmake_minimum_required(VERSION 3.24)

project(StackLib LANGUAGES CXX)

# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавление библиотеки
add_library(stack-library STATIC
        Stack.hpp
        Stack.cpp
)
