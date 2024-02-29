cmake_minimum_required(VERSION 3.24)

# Имя проекта и указание используемого языка программирования.
project(CPU_EMULATOR  LANGUAGES CXX)

# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_DEBUG "-fsanitize=undefined,address -g3 -O0")

add_executable(${PROJECT_NAME} main.cpp)

#add_subdirectory(stack-library)
add_subdirectory(tests)

#target_link_libraries(${PROJECT_NAME} stack-library)

add_custom_target(run COMMAND ${PROJECT_NAME})
