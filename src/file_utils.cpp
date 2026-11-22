#include "file_utils.hpp"

namespace fs = std::filesystem;
using namespace std;

//TODO: make a parser for structed file.build, refactor all this
size_t lines_number_file(fs::path file_path){
    if(fs::exists(file_path)){
        size_t bytes = fs::file_size(file_path);
        return bytes;
    }else{
        println(stderr, "Unable to determinate the file size");
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

