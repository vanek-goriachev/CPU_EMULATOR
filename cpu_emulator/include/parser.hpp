#pragma once
#include <arch.hpp>
#include <command.hpp>

#include <fstream>
#include <iterator>
#include <vector>
#include <regex>

//-----------------------
// Parser representation
//-----------------------

// Maximum allowed line width:
#define MAX_LINE_SIZE 120U

class Parser
{
public:
    // Existance management:
    Parser() = delete;
    Parser(const char* filename);

    ~Parser() = default;

    // Ensure parser is never copied:
    Parser(const Parser&) = delete;
    Parser(Parser&&) = default;

    Parser& operator=(const Parser&) = delete;
    Parser& operator=(Parser&&) = default;

    // Parsing utilites:
    std::vector<Command> parse_command_sequence();

private:
    // File reading utilities:
    void read_line_from_file();

    // Regular expression usage:
    bool parse_pattern(std::regex regexp);
    bool parse_pattern(std::regex regexp, std::string& ret);

    // Parsing utilites:
    bool parse_space_sequence();
    bool parse_newline_sequence();
    bool parse_end_of_file();
    bool skip_comment_line();

    Cmd_t parse_command_name();
    Reg_t parse_register_name();
    Val_t parse_integral_value();
    Command parse_command_line();

    // Parser state:
    std::ifstream file_;
    char line_[MAX_LINE_SIZE];
    const char* pos_;
    const char* end_;
};
