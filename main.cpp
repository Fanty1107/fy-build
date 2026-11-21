#include "exec.hpp"
#include "tokenizer.hpp"
#include "file_utils.hpp"

int main(int argc, char **argv){
    if(argc > 1){
        auto content = read_file(argv[1]);
        if(content){
            std::vector<std::string> tokens = tokenizer_cmd(*content);
            exec_command(tokens);
        }else if(content.error() == KindError::IO_FILE){
            std::println(stderr, "Unable to read a file");
        }else if(content.error() == KindError::EMPTY_BUF){
            std::println(stderr, "File readed but the read buffer is empty");
        }
    }else{
        std::println(stderr,"Enter args pls");
    }
    return 0;
}
