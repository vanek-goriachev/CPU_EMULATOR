#include "iostream"
#include "Stack.hpp"

using namespace std;

class Logger{
public:
    Logger() {
        printf("default constructor\n");
    }

    Logger(const Logger& other) {
        printf("copy-constructor\n");
        (void)other;
    }

    Logger(Logger&& other) noexcept {
        printf("move-constructor\n");
        (void)other;
    }

    Logger& operator=(const Logger& other) {
        printf("copy-assignment\n");
        (void)other;
        return *this;
    }

    Logger& operator=(Logger&& other) noexcept {
        printf("move-assignment\n");
        (void)other;
        return *this;
    }

    ~Logger() {
        printf("destructor\n");
    }

    void log(const char* msg) const {
        printf("%s\n", msg);
    }
};


int main() {
    printf("----> Init variables\n");
    Logger l;
    Logger trash_bin;
    Stack<Logger> stack;

    printf("----> push(const T& value)\n");
    stack.push(l);

    printf("----> push(T&& value)\n");
    stack.push(Logger());

    printf("----> emplace\n");
    stack.emplace();

    printf("----> copy-constructor\n");
    Stack<Logger> copyStack = stack;

    printf("----> move-constructor\n");
    Stack<Logger> movedStack = std::move(stack);

    printf("----> copy-assignment\n");
    Stack<Logger> assignedStack;
    assignedStack = copyStack;

    printf("----> move-assignment\n");
    Stack<Logger> moveAssignedStack;
    moveAssignedStack = std::move(movedStack);

    printf("----> pop\n");
    Logger poppedLogger = assignedStack.pop();
    (void) poppedLogger;

    printf("----> top\n");
    Logger& loggerRef = assignedStack.top();
    (void) loggerRef;

    printf("----> const top\n");
    const Stack<Logger> constStack;
    const Logger& constLoggerRef = constStack.top();
    constLoggerRef.log("aaa");

    return 0;
}
