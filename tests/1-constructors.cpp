#include <gtest/gtest.h>
#include <Stack.hpp>

TEST(StackTest, DefaultConstructor) {
    Stack<int> stack;

    // После создания стек должен быть пустым
    EXPECT_THROW(stack.top(), std::out_of_range);
}

TEST(StackTest, CopyConstructor) {
    // Создаем и заполняем стек
    Stack<int> stackOriginal;
    for(int i = 0; i < 10; ++i) {
        stackOriginal.push(i);
    }

    // Копируем стек
    Stack<int> stackCopy(stackOriginal);

    // Проверяем, что в копии и в оригинале те же самые элементы
    for(int i = 9; i >= 0; --i) {
        EXPECT_EQ(stackCopy.top(), i);
        stackCopy.pop();
    }

    // Проверяем, что после копирования оригинал остался без изменений
    for(int i = 9; i >= 0; --i) {
        EXPECT_EQ(stackOriginal.top(), i);
        stackOriginal.pop();
    }

    // Проверяем, что оба стека пусты
    EXPECT_THROW(stackOriginal.top(), std::out_of_range);
    EXPECT_THROW(stackCopy.top(), std::out_of_range);
}
TEST(StackTest, CopyAssignmentOperator) {
    // Заполняем один стек
    Stack<int> stackOriginal;
    for(int i = 0; i < 10; ++i) {
        stackOriginal.push(i);
    }

    // Пользуемся оператором присваивания для копирования
    Stack<int> stackCopy;
    stackCopy = stackOriginal;

    // Проверяем, что в копии и в оригинале те же элементы
    for(int i = 9; i >= 0; --i) {
        EXPECT_EQ(stackCopy.top(), i);
        stackCopy.pop();
    }

    // Проверяем, что после копирования оригинал остался без изменений
    for(int i = 9; i >= 0; --i) {
        EXPECT_EQ(stackOriginal.top(), i);
        stackOriginal.pop();
    }

    // Проверяем, что оба стека пусты
    EXPECT_THROW(stackOriginal.top(), std::out_of_range);
    EXPECT_THROW(stackCopy.top(), std::out_of_range);
}

TEST(StackTest, MoveConstructorAndAssignmentOperator) {
    // Заполняем один стек
    Stack<int> stackOriginal;
    for(int i = 0; i < 10; ++i) {
        stackOriginal.push(i);
    }

    // Запускаем конструктор перемещения
    Stack<int> stackMoved(std::move(stackOriginal));

    // Запускаем оператор присваивания перемещения
    Stack<int> stackAssigned;
    stackAssigned = std::move(stackMoved);

    // Проверяем, что данные были корректно перемещены
    for(int i = 9; i >= 0; --i) {
        EXPECT_EQ(stackAssigned.top(), i);
        stackAssigned.pop();
    }

    // Проверяем, что исходный стек и стек после перемещения теперь пусты
    EXPECT_THROW(stackOriginal.top(), std::out_of_range);
    EXPECT_THROW(stackMoved.top(), std::out_of_range);
}

TEST(StackTest, Destructor) {
    // Создаем стек в блоке scope. Когда он закончится, деструктор будет вызван
    {
        Stack<int> stack;
        for(int i = 0; i < 10; ++i) {
            stack.push(i);
        }
    }
    // этот тест просто убеждается, что деструктор не вызывает никаких ошибок или исключений при вызове.
}
