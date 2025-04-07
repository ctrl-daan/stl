#include "vowel.hpp"

void removeVowels(std::vector<std::string> &v)
{
    for (auto& str : v)
    str.erase(std::remove_if(str.begin(), str.end(), isVowel), str.end());
}

bool isVowel(char c)
{
    char s = std::tolower(c);
    return (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u' || s == 'y');
}