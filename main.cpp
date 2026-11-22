#include "exec.hpp"
#include "tokenizer.hpp"
#include "file_utils.hpp"

int main(void){
    auto paths = search_build();
    if(paths){
    filesystem::path build_file = define_build(*paths, BUILD_TYPE::DEBUG);
    auto content = read_file(build_file);
        if(content){
            vector<string> tokens = tokenizer_cmd(*content);
            exec_command(tokens);
        }else if(content.error() == KindError::IO_FILE){
            println(stderr, "Unable to read a file");
        }else if(content.error() == KindError::EMPTY_BUF){
            println(stderr, "File readed but the read buffer is empty");
        }
    }
    else if(paths.error() == KindError::EMPTY_BUF){
        println(stderr, "No such .build files");
    }
    return 0;
}
