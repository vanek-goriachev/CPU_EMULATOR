#pragma once

#include <cstddef>

#include <string>
#include <cstdint>

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

//------------
// CPU Values
//------------

typedef int32_t Val_t;

Val_t get_value(std::string str);

static bool DEBUG_MODE = true;
