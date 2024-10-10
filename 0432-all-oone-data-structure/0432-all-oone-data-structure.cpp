// code written by sunny
class AllOne {
    list<pair<int, unordered_set<string>>> countList;
    unordered_map<string, list<pair<int, unordered_set<string>>>::iterator> keyCountMap;

public:
    AllOne() { }
    void inc(string key) {
        if (keyCountMap.find(key) == keyCountMap.end()) {
            if (countList.empty() || countList.front().first != 1) {
                countList.push_front({1, {key}});
            } else {
                countList.front().second.insert(key);
            }
            keyCountMap[key] = countList.begin();
        } else {
            auto curr = keyCountMap[key];
            int currCount = curr->first;
            auto nextIt = std::next(curr);
            if (nextIt == countList.end() || nextIt->first != currCount + 1) {
                nextIt = countList.insert(nextIt, {currCount + 1, {}});
            }
            nextIt->second.insert(key);
            keyCountMap[key] = nextIt;
            curr->second.erase(key);
            if (curr->second.empty()) {
                countList.erase(curr);
            }
        }
    }
    void dec(string key) {
        auto curr = keyCountMap[key];
        int currCount = curr->first;
        if (currCount == 1) {
            keyCountMap.erase(key);
        } else {
            auto prevIt = std::prev(curr);
            if (curr == countList.begin() || prevIt->first != currCount - 1) {
                prevIt = countList.insert(curr, {currCount - 1, {}});
            }
            prevIt->second.insert(key);
            keyCountMap[key] = prevIt;
        }
        curr->second.erase(key);
        if (curr->second.empty()) {
            countList.erase(curr);
        }
    }
    string getMaxKey() {
        if (countList.empty()) return "";
        return *countList.back().second.begin();
    }
    string getMinKey() {
        if (countList.empty()) return "";
        return *countList.front().second.begin();
    }
};