#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <vector>
#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/wait.h>

std::vector<std::string> tokenizer_cmd(const std::string&, size_t);
#endif//TOKENIZER_HPP
