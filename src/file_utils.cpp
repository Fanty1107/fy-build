#include "file_utils.hpp"
#include <print>
#include <fstream>

namespace fs = std::filesystem;
using namespace std;

//TODO: make a parser for structed file.build, refactor all this
size_t lines_number_file(fs::path file_path){
    if(fs::exists(file_path)){
        size_t bytes = fs::file_size(file_path);
        return bytes;
    }else{
        println(stderr, "[LOG]: Unable to determinate the file size");
        return 70;
    }
    return 70;
}
auto read_file(fs::path path) -> expected<string, KindError>{
    fstream file(path);
    if(!file.is_open()){
        return unexpected(KindError::IO_FILE);
    }
    string buffer((istreambuf_iterator<char>(file)),
                        istreambuf_iterator<char>());
    if(buffer.empty()){
        return unexpected(KindError::EMPTY_BUF);
    }
    return buffer;
}
auto search_build() -> expected<vector<fs::path>, KindError>{
    const string target_extantion(".build");
    vector<fs::path> build_vec;
    build_vec.reserve(5);
    fs::path cur_path = fs::current_path();
    fs::directory_iterator dir_iter(cur_path);
    for(const auto &entry : dir_iter){
       if(entry.is_regular_file() && entry.path().extension() == ".build"){
            build_vec.emplace_back(entry.path());   
       } 
    }
    if(build_vec.empty()){
        return unexpected(KindError::EMPTY_BUF);
    }
    return build_vec;
}
 
fs::path define_build(const vector<fs::path>& build_files, BUILD_TYPE b_type){
    if(b_type == BUILD_TYPE::DEBUG){
        for(const auto& file : build_files){
        if(file.stem() == "debug"){
            return file;
        }
    }
}
    if(b_type == BUILD_TYPE::OPT){
    for(const auto& file : build_files){
        if(file.stem() == "prod"){
            return file;
        }
    }
}
    return build_files[0];
}
vector<string> search_cpp_files(fs::path src_dir){
    std::vector<std::string> files_cpp;

    fs::path target_dir = src_dir.empty()
        ? fs::current_path()
        : (fs::current_path() / src_dir);

    if (!fs::exists(target_dir) || !fs::is_directory(target_dir)) {
        return files_cpp;
    }

    for (const auto& entry : fs::recursive_directory_iterator(target_dir)) {
        if (!entry.is_regular_file()) {
            continue;
        }

        const auto ext = entry.path().extension();
        if (ext == ".cpp" || ext == ".cc") {
            files_cpp.push_back(entry.path().string());
        }
    }

    return files_cpp;
}
