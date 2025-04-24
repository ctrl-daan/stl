#include "ispalindrom.hpp"

bool is_palindrome(const std::string& str) {
    std::string clean_str;

    std::copy_if(str.begin(), str.end(), std::back_inserter(clean_str), [](char c) { return std::isalnum(c); });
    std::transform(clean_str.begin(), clean_str.end(), clean_str.begin(), [](char c) { return std::tolower(c); });

    return std::equal(clean_str.begin(), clean_str.begin() + clean_str.size() / 2, clean_str.rbegin());
}