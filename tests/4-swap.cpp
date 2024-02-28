#include <gtest/gtest.h>
#include <stack-library/Stack.hpp>

TEST(StackTest, Swap) {
    Stack<int> stack1;
    for(int i = 0; i < 10; ++i) {
        stack1.push(i);
    }

    Stack<int> stack2;
    for(int i = 10; i < 20; ++i) {
        stack2.push(i);
    }

    // Обмениваем элементы местами
    swap(stack1, stack2);

    // Проверяем, что элементы успешно обменялись местами
    for(int i = 19; i >= 10; --i) {
        EXPECT_EQ(stack1.top(), i);
        stack1.pop();
    }

    for(int i = 9; i >= 0; --i) {
        EXPECT_EQ(stack2.top(), i);
        stack2.pop();
    }

    // Проверяем, что оба стека пусты
    EXPECT_THROW(stack1.top(), std::out_of_range);
    EXPECT_THROW(stack2.top(), std::out_of_range);
}