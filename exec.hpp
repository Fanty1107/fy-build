#ifndef EXEC_HPP
#define EXEC_HPP
#include <print>
#include <vector>
#include <unistd.h>
#include <string>
#include <sys/wait.h>
#include "tokenizer.hpp"

bool exec_command(std::vector<std::string>& tokens);

#endif//EXEC_HPP
