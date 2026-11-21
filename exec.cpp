#include "exec.hpp"

bool exec_command(std::vector<std::string>& tokens){
    if(tokens.empty()){
        std::println(stderr, "No cmd found in file");
        return false;
    }
    pid_t pid = fork();
    if(pid == -1){
        std::println(stderr, "Failed in fork");
        return false;
    }
    if(pid == 0){
        auto args = vec_to_args(tokens);
        if(args[0] == nullptr || *args[0] == '\0'){
            std::println(stderr, "Invalid Command");
            _exit(127);
        }
        execvp(args[0], args.get());
        std::println(stderr, "Cmd failed");
        _exit(127);
    }
    int status = 0;
    if (waitpid(pid, &status, 0) == -1) {
        std::println(stderr, "waitpid failed");
        return false;
    }
    if (WIFEXITED(status)) {
        std::println(stdout, "Exit cmd code: {}", WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
        std::println(stdout, "Killed by signal: {}", WTERMSIG(status));
    }
    return true;
}

