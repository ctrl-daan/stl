#include "sort.hpp"

std::deque<std::string> lengthSort(std::forward_list<std::string>& flist) {
    std::deque<std::string> temp(flist.begin(), flist.end());
    std::sort(temp.begin(), temp.end(), compareStrings);
    return temp;
}

bool compareStrings(const std::string& a, const std::string& b) {
    if (a.size() == b.size()) {
        return a < b;
    }

    return a.size() < b.size();
}
