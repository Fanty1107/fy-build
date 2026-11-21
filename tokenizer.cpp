#include "tokenizer.hpp"

std::vector<std::string> tokenizer_cmd(std::string cmd){
    std::vector<std::string> tokens;
    std::string token;
    for(unsigned char ch : cmd){
        if(std::isspace(ch)){
            if(!token.empty()){
                tokens.push_back(std::move(token));
                token.clear();
            }
        }else{
            token.push_back(static_cast<char>(ch));
        }
    }
    if(!token.empty()){
        tokens.push_back(std::move(token));
    }
    return tokens;
}
std::unique_ptr<char*[]> vec_to_args(std::vector<std::string>& tokens){

    std::unique_ptr<char*[]> args = std::make_unique<char*[]>(tokens.size() + 1);
    for(size_t i = 0; i < tokens.size(); ++i){
        args[i] = tokens[i].data();
    }
    args[tokens.size()] = nullptr;

    return args;
}
