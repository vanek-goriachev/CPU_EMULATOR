//
// Created by Vanek on 01.02.2024.
//
#include "iostream"
#include "stack-library/Stack.hpp"
#include <ctime>
#include <string>
//#include<windows.h>           // for windows
#include<unistd.h>               // for linux

using namespace std;

//BigNumber clock_decorator(int precision, BigNumber func(int)) {
//    clock_t start = clock();
//
//    BigNumber result = func(precision);
//
//    clock_t end = clock();
//    double seconds = (double) (end - start) / CLOCKS_PER_SEC;
//    printf("The time: %f seconds\n", seconds);
//
//    return result;
//}
//
//BigNumber calculate_pi(int precision) {
//    precision += 10;
//    BigNumber one("1", precision), two("2", precision),
//            three("3", precision), four("4", precision);
//
//    BigNumber Pi1 = four * ((one / two).arctan() + (one / three).arctan());
//    Pi1.change_precision(precision - 10);
//
//
//    return Pi1;
//}

void run_progress_bar(float sleep_time) {
    float progress = 0.0;
    while (progress <= 1.0) {
        int barWidth = 70;
        std::cout << "[";
        int pos = barWidth * progress;
        for (int i = 0; i < barWidth; ++i) {
            if (i < pos) std::cout << "=";
            else if (i == pos) std::cout << ">";
            else std::cout << " ";
        }
        std::cout << "] " << int(progress * 100.0) << " %\r";
        std::cout.flush();
        progress += 0.2; // for demonstration only
        sleep(sleep_time);
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[]) {
    string buffer;
    cout << "Это калькулятор который работает безошибочно. \nВведите первое число: ";
    cin >> buffer;
    cout << "Введите второе число: ";
    cin >> buffer;
    cout << "Введите оператор: ";
    cin >> buffer;

    run_progress_bar(1);

    cout << "Hello world!\n";
//    BigNumber magicNumber = clock_decorator(precision, calculate_pi);
//    cout << magicNumber.ToString() << endl;
    return 0;
}
