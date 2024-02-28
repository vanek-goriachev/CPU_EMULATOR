//
// Created by Vanek on 01.02.2024.
//
#pragma once

template <typename T>
class Stack {
public:
    Stack();
    Stack(const Stack& other);
    Stack& operator=(const Stack& other);
    Stack(Stack&& other) noexcept;
    Stack& operator=(Stack&& other);
    ~Stack();

    void push(const T& value);
    void push(T&& value);
    T pop();
    T& top();
    const T& top() const;

private:
    void expand();

    T* array;
    int capacity;
    int topIndex;
};

template <typename T>
void swap(Stack<T>& a, Stack<T>& b);