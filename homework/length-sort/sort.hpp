#pragma once
#include <algorithm>
#include <deque>
#include <forward_list>
#include <string>

std::deque<std::string> lengthSort(std::forward_list<std::string>& flist);
bool compareStrings(const std::string& a, const std::string& b);
