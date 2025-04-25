#include "transform.hpp"

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string>& slist, std::deque<int>& ideq) {
    slist.sort();
    slist.unique();
    std::sort(ideq.begin(), ideq.end());
    ideq.erase(std::unique(ideq.begin(), ideq.end()), ideq.end());

    std::vector<std::pair<int, std::string>> tempPair;

    std::transform(slist.begin(), slist.end(), ideq.begin(), std::back_inserter(tempPair), [](const std::string& str, int num) {
        return std::make_pair(num, str);
    });

    std::map<int, std::string> resultMap;
    for (const auto& [key, val] : tempPair) {
        resultMap.emplace(key, val);
    }

    return resultMap;
}