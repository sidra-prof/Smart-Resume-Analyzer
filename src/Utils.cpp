#include "../inc/Utils.h"
#include<string>
#include<vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string Utils::toLowerCase(
    string text)
{
    transform(
        text.begin(),
        text.end(),
        text.begin(),
        ::tolower);

    return text;
}

string Utils::normalizeWord(
    string word)
{
    static unordered_map<string,string>
    aliases =
    {
        {"cpp","c++"},
        {"cplusplus","c++"},
        {"c++","c++"},

        {"py","python"},
        {"python","python"},

        {"node.js","nodejs"},
        {"nodejs","nodejs"},

        {"js","javascript"},
        {"javascript","javascript"}
    };

    auto it = aliases.find(word);

    if(it != aliases.end())
    {
        return it->second;
    }

    return word;
}