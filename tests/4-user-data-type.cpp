#include <gtest/gtest.h>
#include <Stack.hpp>
#include <string>

struct Person {
    std::string name;
    int age;

    Person() : name(""), age(0) {}
    Person(const std::string& name, int age) : name(name), age(age) {}
};

TEST(StackTest, UserDefinedType) {
    Stack<Person> stack;

    // Создаем и добавляем несколько элементов
    stack.push(Person("Alice", 30));
    stack.push(Person("Bob", 40));
    stack.push(Person("Catherine", 50));
    stack.push(Person("David", 60));

    // Тест операции top
    EXPECT_EQ(stack.top().name, "David");
    EXPECT_EQ(stack.top().age, 60);

    // Проверяем, что после копирования из исходного стека элементы корректно копируются
    Stack<Person> copiedStack(stack);
    stack.pop();
    EXPECT_EQ(copiedStack.top().name, "David");
    EXPECT_EQ(copiedStack.top().age, 60);

    // Проверяем, что после использования оператора присваивания для копирования элементы корректно копируются
    Stack<Person> copiedStack2 = copiedStack;
    EXPECT_EQ(copiedStack2.top().name, "David");
    EXPECT_EQ(copiedStack2.top().age, 60);

    // Проверяем, что после использования конструктора перемещения исходный стек становится пустым
    Stack<Person> movedStack(std::move(copiedStack));
    EXPECT_THROW(copiedStack.top(), std::out_of_range);
    EXPECT_EQ(movedStack.top().name, "David");
    EXPECT_EQ(movedStack.top().age, 60);

    // Проверяем, что после использования оператора присваивания для перемещения, исходный стек становится пустым
    Stack<Person> movedStack2 = std::move(movedStack);
    EXPECT_THROW(movedStack.top(), std::out_of_range);
    EXPECT_EQ(movedStack2.top().name, "David");
    EXPECT_EQ(movedStack2.top().age, 60);
}