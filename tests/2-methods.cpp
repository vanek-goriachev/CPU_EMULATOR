#include <gtest/gtest.h>
#include <stack-library/Stack.hpp>

TEST(StackTest, PushLvalueAndTop) {
    Stack<int> stack;

    int value = 5;

    // Используем push с lvalue
    stack.push(value);

    // Проверяем, что в вершине стека находится наше значение
    EXPECT_EQ(stack.top(), value);
}

TEST(StackTest, PushRvalueAndTop) {
    Stack<int> stack;

    // Используем push с rvalue
    stack.push(int(5));

    // Проверяем, что в вершине стека находится наше значение
    EXPECT_EQ(stack.top(), 5);
}

TEST(StackTest, PushMoveAndTop) {
    Stack<std::vector<int>> stack;

    std::vector<int> value = {1, 2, 3, 4, 5};

    // Используем push (со смещением) с lvalue
    stack.push(std::move(value));

    // Проверяем, что в вершине стека находится наше значение
    EXPECT_EQ(stack.top(), (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(StackTest, PopAndTop) {
    Stack<int> stack;

    for(int i = 0; i < 10; ++i) {
        stack.push(i);
    }

    // Удаляем верхний элемент стека
    stack.pop();

    // Теперь на вершине стека должно быть значение 8
    EXPECT_EQ(stack.top(), 8);
}