#include "exec.hpp"
#include "tokenizer.hpp"
#include "file_utils.hpp"
#include "parser.hpp"

using namespace std;

int main(void){
    auto paths = search_build();
    if(paths){
    filesystem::path build_file = define_build(*paths, BUILD_TYPE::DEBUG);
    auto content = read_file(build_file);
        if(content){
            map<string, string> m = into_map(*content);
            print_map(m);
            vector<string> tokens = tokenizer_cmd(*content, lines_number_file(build_file));
            if(!exec_command(tokens)){
                println(stderr,"Failed on exec_command");
            }
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
