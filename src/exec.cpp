#include "exec.hpp"
#include <print>
using namespace std;

unique_ptr<char*[]> vec_to_args(vector<string>& tokens){
    unique_ptr<char*[]> args = make_unique<char*[]>(tokens.size() + 1);
    for(size_t i = 0; i < tokens.size(); ++i){
        args[i] = tokens[i].data();
    }
    args[tokens.size()] = nullptr;

    return args;
}
void print_cmd(vector<string>& args){
    for(const auto& arg : args){
        print(stdout, "{} ", arg);
    }
    print("\n");
}
bool exec_command(vector<string>& tokens){
    if(tokens.empty()){
        println(stderr, "No cmd found in file");
        return false;
    }
    pid_t pid = fork();
    if(pid == -1){
        println(stderr, "Failed in fork");
        return false;
    }
    if(pid == 0){
        auto args = vec_to_args(tokens);
        if(args[0] == nullptr || *args[0] == '\0'){
            println(stderr, "Invalid Command");
            _exit(127);
        }
        execvp(args[0], args.get());
        println(stderr, "Cmd failed");
        _exit(127);
    }
    int status = 0;
    if (waitpid(pid, &status, 0) == -1) {
        println(stderr, "waitpid failed");
        return false;
    }
    if (WIFEXITED(status)) {
        print_cmd(tokens);
        println(stdout, "Exit cmd code: {}", WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
        println(stdout, "Killed by signal: {}", WTERMSIG(status));
    }
    return true;
}

