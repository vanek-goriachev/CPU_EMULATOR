#include "stack.h"
#include <stdexcept> // for std::out_of_range
#include <algorithm> // for std::swap

template <typename T>
Stack<T>::Stack() : array(nullptr), capacity(0), topIndex(-1) { }

template <typename T>
Stack<T>::Stack(const Stack& other) : array(nullptr), capacity(other.capacity), topIndex(other.topIndex) {
    array = new T[capacity] {};
    for (int i = 0; i <= topIndex; ++i) {
        array[i] = other.array[i];
    }
}


template <typename T>
Stack<T>& Stack<T>::operator=(Stack other) {
    swap(*this, other);
    return *this;
}

template <typename T>
Stack<T>::Stack(Stack&& other) noexcept : Stack() {
    swap(*this, other);
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack&& other) {
    if(this != &other) {
        delete[] array;
        array = nullptr;
        array = other.array;
        capacity = other.capacity;
        topIndex = other.topIndex;
        other.array = nullptr;
        other.capacity = 0;
        other.topIndex = -1;
    }
    return *this;
}

template <typename T>
Stack<T>::~Stack() {
    delete[] array;
}

template <typename T>
void Stack<T>::push(const T& value) {
    // Проверяем, достаточно ли в массиве места для нового элемента
    if(topIndex + 1 >= capacity) {
        // Если нет - удваиваем размер массива
        int newCapacity = (capacity == 0) ? 2 : capacity * 2;
        T* newArray = new T[newCapacity] {};

        // Копируем элементы из старого массива в новый
        for(int i = 0; i < capacity; ++i) {
            newArray[i] = std::move(array[i]);
        }

        // Удаляем старый массив и обновляем указатель
        delete[] array;
        array = newArray;

        // Обновляем вместимость массива
        capacity = newCapacity;
    }

    // Добавляем элемент в верхнюю часть стека
    array[++topIndex] = value;
}

template <typename T>
void Stack<T>::push(T&& value) {
    if(topIndex + 1 >= capacity) {
        int newCapacity = (capacity == 0) ? 2 : capacity * 2;
        T* newArray = new T[newCapacity];

        for(int i = 0; i < capacity; ++i) {
            newArray[i] = std::move(array[i]);
        }

        delete[] array;
        array = newArray;
        capacity = newCapacity;
    }

    array[++topIndex] = std::move(value);
}

template <typename T>
T Stack<T>::pop() {
    if(topIndex == -1) {
        throw std::out_of_range("Stack is empty");
    }
    T result = std::move(array[topIndex]);
    --topIndex;
    return result;
}

template <typename T>
T& Stack<T>::top() {
    if(topIndex == -1) {
        throw std::out_of_range("Stack is empty");
    }
    return array[topIndex];
}

template <typename T>
const T& Stack<T>::top() const {
    if(topIndex == -1) {
        throw std::out_of_range("Stack is empty");
    }
    return array[topIndex];
}

template <typename T>
void Stack<T>::expand() {
    int newCapacity = (capacity == 0) ? 64 : capacity * 2;
    T* newArray = new T[newCapacity];

    for (int i = 0; i < capacity; ++i) {
        newArray[i] = std::move(array[i]);
    }

    delete[] array;

    array = newArray;
    capacity = newCapacity;
}

template <typename T>
void swap(Stack<T>& a, Stack<T>& b) {
    std::swap(a.array, b.array);
    std::swap(a.capacity, b.capacity);
    std::swap(a.topIndex, b.topIndex);
}