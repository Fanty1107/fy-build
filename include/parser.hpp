#ifndef PARSER_HPP
#define PARSER_HPP
#include <string>
#include <string_view>
#include <map>
#include <vector>
using namespace std;

map<string, string> into_map(string& buf);
inline string trim_copy(string_view sv);
void print_map(map<string, string>& m);
vector<string> sort_map(map<string, string>);
#endif//PARSER_HPP
