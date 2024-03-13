#include <gtest/gtest.h>
#include "Stack.hpp"

TEST(StackTests, EmplaceTest) {
    Stack<int> stack;

    // Эмулирует push для упрощения (ассерт не обязательный, сам тест - emplace)
    stack.push(5);
    ASSERT_EQ(stack.top(), 5);

    // Использование emplace
    stack.emplace(10);
    EXPECT_EQ(stack.top(), 10);

    // Проверка, что стек расширяется
    for (int i = 0; i < 1000; i++){
        stack.emplace(i);
    }
    ASSERT_EQ(stack.top(), 999);
}
