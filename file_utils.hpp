#ifndef FILE_UTILS_HPP
#define FILE_UTILS_HPP

#include <string>
#include <expected>
#include <fstream>

enum KindError{
    IO_FILE,
    EMPTY_BUF,
    FORK_ERR,
    CMD_ERR,
    UNFOUND_FILE,
};

auto read_file(const char *path) -> std::expected<std::string, KindError>;
auto search_build() -> std::expected<std::string, KindError>;

#endif//FILE_UTILS_HPP
