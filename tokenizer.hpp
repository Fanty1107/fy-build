#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <print>
#include <vector>
#include <cstring>
#include <expected>
#include <unistd.h>
#include <sys/wait.h>
#include <memory>


std::vector<std::string> tokenizer_cmd(const std::string&, size_t);
#endif//TOKENIZER_HPP
