#include "exec.hpp"
#include "file_utils.hpp"
#include "parser.hpp"
#include <print>

using namespace std;

int main(void){
    auto paths = search_build();
    if(paths){
    filesystem::path build_file = define_build(*paths, BUILD_TYPE::DEBUG);
    auto content = read_file(build_file);
        if(content){
            map<string, string> m = into_map(*content);
            vector<string> cmd = debug_cmd(m);
            if(!exec_command(cmd)){
                println(stderr,"Failed on exec_command");
            }
        }else if(content.error() == KindError::IO_FILE){
            println(stderr, "[ERROR]: Unable to read a file");
        }else if(content.error() == KindError::EMPTY_BUF){
            println(stderr, "[ERROR]: File readed but the read buffer is empty");
        }
    }
    else if(paths.error() == KindError::EMPTY_BUF){
        println(stderr, "[ERROR]: No such .build files");
    }
    return 0;
}
