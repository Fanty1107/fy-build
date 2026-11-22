#include "tokenizer.hpp"
using namespace std;

vector<string> tokenizer_cmd(const string& cmd, size_t f_size){
    vector<string> tokens;
    tokens.reserve(f_size);
    string token;
    for(unsigned char ch : cmd){
        if(isspace(ch)){
            if(!token.empty()){
                tokens.emplace_back(std::move(token));
                token.clear();
            }
        }else{
            token.push_back(static_cast<char>(ch));
        }
    }
    if(!token.empty()){
        tokens.emplace_back(std::move(token));
    }
    return tokens;
}
