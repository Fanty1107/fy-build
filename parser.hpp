#ifndef PARSER_HPP
#define PARSER_HPP
#include <string>
using namespace std;

struct Parser{
    string args;    
    size_t lines;

    string parse_buffer(string& buffer);
    string format_cmd(string& cmd);
};

#endif//PARSER_HPP
