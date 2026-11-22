#ifndef EXEC_HPP
#define EXEC_HPP
#include <memory>
#include <vector>
#include <unistd.h>
#include <string>
#include <sys/wait.h>

bool exec_command(std::vector<std::string>& tokens);
std::unique_ptr<char*[]> vec_to_args(std::vector<std::string>& tokens);

#endif//EXEC_HPP
