#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <print>
#include <vector>
#include <cstring>
#include <expected>
#include <unistd.h>
#include <sys/wait.h>
#include <memory>


std::vector<std::string> tokenizer_cmd(std::string cmd);
std::unique_ptr<char*[]> vec_to_args(std::vector<std::string>& tokens);
#endif//TOKENIZER_HPP
