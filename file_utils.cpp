#include "file_utils.hpp"

auto read_file(const char *path) -> std::expected<std::string, KindError>{
    std::fstream file(path);
    if(!file.is_open()){
        return std::unexpected(KindError::IO_FILE);
    }
    std::string buffer((std::istreambuf_iterator<char>(file)),
                        std::istreambuf_iterator<char>());
    if(buffer.empty()){
        return std::unexpected(KindError::EMPTY_BUF);
    }
    return buffer;
}
