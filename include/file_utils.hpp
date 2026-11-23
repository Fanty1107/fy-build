#ifndef FILE_UTILS_HPP
#define FILE_UTILS_HPP

#include <string>
#include <expected>
#include <vector>
#include <filesystem>
using namespace std;

enum KindError{
    IO_FILE,
    EMPTY_BUF,
    FORK_ERR,
    CMD_ERR,
    UNFOUND_FILE,
};
enum BUILD_TYPE{
    OPT,
    DEBUG,
};

auto read_file(filesystem::path path) -> expected<string, KindError>;
auto search_build() -> expected<vector<filesystem::path>, KindError>;
filesystem::path define_build(const vector<filesystem::path>& build_files, BUILD_TYPE b_type);
size_t lines_number_file(filesystem::path file_path);
vector<string> search_cpp_files(filesystem::path src_dir);

#endif//FILE_UTILS_HPP
