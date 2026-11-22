#include "parser.hpp"
#include <filesystem>
#include <iostream>

inline string trim_copy(string_view sv){
    const auto first = find_if_not(sv.begin(), sv.end(), [](unsigned char ch){
            return std::isspace(ch);
    });
    const auto last = find_if_not(sv.rbegin(), sv.rend(), [](unsigned char ch) {
        return isspace(ch);
    }).base();
    if (first >= last) {
        return {};
    }
    return string(first, last);
}
map<string, string> into_map(string& buf){
    map<string, string> f_map;
    istringstream stream{string(buf)};
    string line;
    while(getline(stream, line)){
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }
        const string trimmed_line = trim_copy(line);
        if (trimmed_line.empty()) {
            continue;
        }
        const auto colon_pos = trimmed_line.find(':');
        if (colon_pos == string::npos) {
            continue;
        }
        string key = trim_copy(string_view(trimmed_line).substr(0, colon_pos));
        string value = trim_copy(string_view(trimmed_line).substr(colon_pos + 1));

        if (!key.empty()) {
            f_map[std::move(key)] = std::move(value);
        }
    }
    return f_map;
}
void print_map(map<string, string>& m){
    for(const auto& [k, v] : m){
        std::cout << '[' << k << "] = [" << v << "]\n";
    }
}

