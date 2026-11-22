#include "tokenizer.hpp"
using namespace std;

vector<string> tokenizer_cmd(string cmd){
    vector<string> tokens;
    string token;
    for(unsigned char ch : cmd){
        if(isspace(ch)){
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
unique_ptr<char*[]> vec_to_args(vector<string>& tokens){
    unique_ptr<char*[]> args = make_unique<char*[]>(tokens.size() + 1);
    for(size_t i = 0; i < tokens.size(); ++i){
        args[i] = tokens[i].data();
    }
    args[tokens.size()] = nullptr;

    return args;
}
