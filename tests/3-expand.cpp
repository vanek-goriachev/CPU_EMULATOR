#include <gtest/gtest.h>
#include <stack-library/Stack.hpp>

TEST(StackTest, Expand) {
    Stack<int> stack;

    // Проверяем, что все элементы успешно добавляются в стек
    for(int i = 0; i < 1000; ++i) {
        EXPECT_NO_THROW(stack.push(i));
    }
}
