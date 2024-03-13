#pragma once
#include <arch.hpp>

//------------------
// Command subtypes
//------------------

enum CommandType : Cmd_t
{
    NOTHING = 0,
    BEGIN   = 1,
    END     = 2,
    PUSH    = 3,
    POP     = 4,
    PUSHR   = 5,
    POPR    = 6,
    ADD    = 7,
    SUB    = 8,
    MUL    = 9,
    DIV    = 10,
    OUT    = 11,
    IN    = 12,
};

class CommandBegin
{
public:
    CommandBegin() = default;

    void execute() const;
};

class CommandEnd
{
public:
    CommandEnd() = default;

    void execute() const;
};

class CommandPush
{
public:
    CommandPush(Val_t val);

    void execute() const;
private:
    Val_t val_;
};

class CommandPop
{
public:
    CommandPop() = default;

    void execute() const;
};

class CommandPushr
{
public:
    CommandPushr(Reg_t reg);

    void execute() const;
private:
    Reg_t reg_;
};

class CommandPopr
{
public:
    CommandPopr(Reg_t reg);

    void execute() const;
private:
    Reg_t reg_;
};

class CommandAdd
{
public:
    CommandAdd() = default;

    void execute() const;
};

class CommandSub
{
public:
    CommandSub() = default;

    void execute() const;
};

class CommandMul
{
public:
    CommandMul() = default;

    void execute() const;
};

class CommandDiv
{
public:
    CommandDiv() = default;

    void execute() const;
};

class CommandOut
{
public:
    CommandOut() = default;

    void execute() const;
};

class CommandIn
{
public:
    CommandIn() = default;

    void execute() const;
};

//--------------------------
// Polymorphic command type
//--------------------------

class Command
{
public:
    // Existance management:
    Command();
    Command(CommandBegin* cmd);
    Command(CommandEnd*   cmd);
    Command(CommandPush*  cmd);
    Command(CommandPop*   cmd);
    Command(CommandPushr* cmd);
    Command(CommandPopr*  cmd);
    Command(CommandAdd*  cmd);
    Command(CommandSub*  cmd);
    Command(CommandMul*  cmd);
    Command(CommandDiv*  cmd);
    Command(CommandOut*  cmd);
    Command(CommandIn*  cmd);

    ~Command();

    // Ensure command is never copied:
    Command(const Command&) = delete;
    Command(Command&&);

    Command& operator=(const Command&) = delete;
    Command& operator=(Command&&);

    // Command execution:
    void execute() const;

private:
    // Memory management utility:
    void release();

    CommandType type_;

    void* ptr_;
};
