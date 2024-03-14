#pragma once

#include <cstddef>

#include <string>
#include <cstdint>
#include <Stack.hpp>

//---------------
// CPU commands
//---------------

typedef uint8_t Cmd_t;

Cmd_t get_command_id(std::string str);

//---------------
// CPU registers
//---------------

typedef uint8_t Reg_t;

Reg_t get_register_id(std::string str);
std::string get_register_name(Reg_t reg);
void set_register_value(int val, Reg_t reg);

//------------
// CPU Values
//------------

typedef int32_t Val_t;

Val_t get_value(std::string str);

static bool DEBUG_MODE = false;

extern Stack<int> program_stack;
static int REGISTER_VALUES[] = {0, 0, 0, 0, 0, 0, 0};