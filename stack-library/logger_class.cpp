//
// Created by Vanek on 01.02.2024.
//
#include "iostream"
#include "Stack.hpp"

using namespace std;

#pragma once

class Logger
{
public:
    Logger()  { printf("default constructor") };

    Logger(const Logger& other) { printf("copy-constructor") };
    Logger(Logger&& other) noexcept { printf("move-constructor") };

    Logger& operator=(const Logger& other) { printf("copy-assignment") };
    Logger& operator=(Logger&& other) noexcept { printf("move-assignment") };

    ~Logger() { printf("destructor") };;
};

int main() {
    Logger l;

    Stack<Logger> s;
    s.push(l);



    return 0;
}
