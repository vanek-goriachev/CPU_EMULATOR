#include <arch.hpp>
#include <command.hpp>

#include <cstdio>
#include <stdexcept>

#include "iostream"

#define DEBUG_MODE false

//----------------------
// Command construction
//----------------------

CommandPush::CommandPush(Val_t val) :
        val_ (val)
{ }

CommandPushr::CommandPushr(Reg_t reg) :
        reg_ (reg)
{ }

CommandPopr::CommandPopr(Reg_t reg) :
        reg_ (reg)
{ }

//-------------------
// Command execution
//-------------------

void CommandBegin::execute() const
{
    if (DEBUG_MODE) {printf("BEGIN\n");}
}

void CommandEnd::execute() const
{
    if (DEBUG_MODE) {printf("END\n");}
}

void CommandPush::execute() const
{
    if (DEBUG_MODE) {printf("PUSH %d\n", val_);}
    program_stack.push(val_);
}

void CommandPop::execute() const
{
    if (DEBUG_MODE) {printf("POP\n");}
    program_stack.pop();
}

void CommandPushr::execute() const
{
    if (DEBUG_MODE) {printf("PUSHR %s\n", get_register_name(reg_).c_str());}
    program_stack.push(reg_);
}

void CommandPopr::execute() const
{
    if (DEBUG_MODE) {printf("POPR %s\n", get_register_name(reg_).c_str());}
    set_register_value(program_stack.pop(), reg_);
}

void CommandAdd::execute() const
{
    if (DEBUG_MODE) {printf("ADD\n");}
    int a = program_stack.pop(), b = program_stack.top();
    program_stack.push(a);
    // TODO check overflow
    program_stack.push(a+b);
}

void CommandSub::execute() const
{
    if (DEBUG_MODE) {printf("SUB\n");}
    int a = program_stack.pop(), b = program_stack.top();
    program_stack.push(a);
    // TODO check overflow
    program_stack.push(a-b);
}

void CommandMul::execute() const
{
    if (DEBUG_MODE) {printf("MUL\n");}
    int a = program_stack.pop(), b = program_stack.top();
    program_stack.push(a);
    // TODO check overflow
    program_stack.push(a*b);
}

void CommandDiv::execute() const
{
    if (DEBUG_MODE) {printf("DIV\n");}
    int a = program_stack.pop(), b = program_stack.top();
    program_stack.push(a);
    // TODO check overflow
    program_stack.push(a/b);
}

void CommandOut::execute() const
{
    if (DEBUG_MODE) {printf("OUT\n");}
    int a = program_stack.pop();
    std::cout << a << std::endl;
}

void CommandIn::execute() const
{
    if (DEBUG_MODE) {printf("IN\n");}
    int a;
    std::cin >> a;
    program_stack.push(a);
}
//--------------------------
// Polymorphic command type
//--------------------------

Command::Command() :
        type_ (CommandType::NOTHING),
        ptr_  (nullptr)
{ }

Command::Command(CommandBegin* cmd) :
        type_ (CommandType::BEGIN),
        ptr_  (cmd)
{ }

Command::Command(CommandEnd* cmd) :
        type_ (CommandType::END),
        ptr_  (cmd)
{ }

Command::Command(CommandPush* cmd) :
        type_ (CommandType::PUSH),
        ptr_  (cmd)
{ }

Command::Command(CommandPop* cmd) :
        type_ (CommandType::POP),
        ptr_  (cmd)
{ }

Command::Command(CommandPushr* cmd) :
        type_ (CommandType::PUSHR),
        ptr_  (cmd)
{ }

Command::Command(CommandPopr* cmd) :
        type_ (CommandType::POPR),
        ptr_  (cmd)
{ }


Command::Command(CommandAdd* cmd) :
        type_ (CommandType::ADD),
        ptr_  (cmd)
{ }

Command::Command(CommandSub* cmd) :
        type_ (CommandType::SUB),
        ptr_  (cmd)
{ }

Command::Command(CommandMul* cmd) :
        type_ (CommandType::MUL),
        ptr_  (cmd)
{ }

Command::Command(CommandDiv* cmd) :
        type_ (CommandType::DIV),
        ptr_  (cmd)
{ }

Command::Command(CommandOut* cmd) :
        type_ (CommandType::OUT),
        ptr_  (cmd)
{ }

Command::Command(CommandIn* cmd) :
        type_ (CommandType::IN),
        ptr_  (cmd)
{ }

Command::Command(Command&& that) :
        type_ (that.type_),
        ptr_  (that.ptr_)
{
    that.type_ = CommandType::NOTHING;
    that.ptr_  = nullptr;
}

Command& Command::operator=(Command&& that)
{
    this->release();

    type_ = that.type_;
    ptr_  = that.ptr_;

    that.type_ = CommandType::NOTHING;
    that.ptr_  = nullptr;

    return *this;
}

void Command::execute() const
{
    // Dispatch function based on it's type.
    // NOTE: this is a boilerplate code a compiler
    //       is definitely able to produce for us.
    // NOTE: use virtual functions and dynamic_cast
    switch (type_)
    {
        case CommandType::BEGIN:
        {
            CommandBegin* ptr = static_cast<CommandBegin*>(ptr_);
            ptr->execute();
            break;
        }
        case CommandType::END:
        {
            CommandEnd* ptr = static_cast<CommandEnd*>(ptr_);
            ptr->execute();
            break;
        }
        case CommandType::PUSH:
        {
            CommandPush* ptr = static_cast<CommandPush*>(ptr_);
            ptr->execute();
            break;
        }
        case CommandType::POP:
        {
            CommandPop* ptr = static_cast<CommandPop*>(ptr_);
            ptr->execute();
            break;
        }
        case CommandType::PUSHR:
        {
            CommandPushr* ptr = static_cast<CommandPushr*>(ptr_);
            ptr->execute();
            break;
        }
        case CommandType::POPR:
        {
            CommandPopr* ptr = static_cast<CommandPopr*>(ptr_);
            ptr->execute();
            break;
        }
        case CommandType::ADD:
        {
            CommandAdd* ptr = static_cast<CommandAdd*>(ptr_);
            ptr->execute();
            break;
        }
        case CommandType::SUB:
        {
            CommandSub* ptr = static_cast<CommandSub*>(ptr_);
            ptr->execute();
            break;
        }
        case CommandType::MUL:
        {
            CommandMul* ptr = static_cast<CommandMul*>(ptr_);
            ptr->execute();
            break;
        }
        case CommandType::DIV:
        {
            CommandDiv* ptr = static_cast<CommandDiv*>(ptr_);
            ptr->execute();
            break;
        }
        case CommandType::OUT:
        {
            CommandOut* ptr = static_cast<CommandOut*>(ptr_);
            ptr->execute();
            break;
        }
        case CommandType::IN:
        {
            CommandIn* ptr = static_cast<CommandIn*>(ptr_);
            ptr->execute();
            break;
        }
        default:
        {
            throw std::runtime_error("Command::execute(): invalid Command type");
        }
    }
}

void Command::release()
{
    if (type_ == CommandType::NOTHING)
    {
        return;
    }

    // Dispatch destructor based on it's type:
    // NOTE: oh sh*t here we go again.
    switch (type_)
    {
        case CommandType::BEGIN:
        {
            CommandBegin* ptr = static_cast<CommandBegin*>(ptr_);
            delete ptr;
            break;
        }
        case CommandType::END:
        {
            CommandEnd* ptr = static_cast<CommandEnd*>(ptr_);
            delete ptr;
            break;
        }
        case CommandType::PUSH:
        {
            CommandPush* ptr = static_cast<CommandPush*>(ptr_);
            delete ptr;
            break;
        }
        case CommandType::POP:
        {
            CommandPop* ptr = static_cast<CommandPop*>(ptr_);
            delete ptr;
            break;
        }
        case CommandType::PUSHR:
        {
            CommandPushr* ptr = static_cast<CommandPushr*>(ptr_);
            delete ptr;
            break;
        }
        case CommandType::POPR:
        {
            CommandPopr* ptr = static_cast<CommandPopr*>(ptr_);
            delete ptr;
            break;
        }
        case CommandType::ADD:
        {
            CommandAdd* ptr = static_cast<CommandAdd*>(ptr_);
            delete ptr;
            break;
        }
        case CommandType::SUB:
        {
            CommandSub* ptr = static_cast<CommandSub*>(ptr_);
            delete ptr;
            break;
        }
        case CommandType::MUL:
        {
            CommandMul* ptr = static_cast<CommandMul*>(ptr_);
            delete ptr;
            break;
        }
        case CommandType::DIV:
        {
            CommandDiv* ptr = static_cast<CommandDiv*>(ptr_);
            delete ptr;
            break;
        }
        case CommandType::OUT:
        {
            CommandOut* ptr = static_cast<CommandOut*>(ptr_);
            delete ptr;
            break;
        }
        case CommandType::IN:
        {
            CommandIn* ptr = static_cast<CommandIn*>(ptr_);
            delete ptr;
            break;
        }
        default:
        {
            // NOTE: from C++11 destructors are ‘noexcept’ by default
            // throw std::runtime_error("Command::~Command(): invalid Command type");
        }
    }

    type_ = CommandType::NOTHING;
    ptr_ = nullptr;
}

Command::~Command()
{
    release();
}
