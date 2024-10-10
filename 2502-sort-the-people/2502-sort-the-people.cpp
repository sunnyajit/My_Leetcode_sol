 class Solution {
public: // code written by sunny..
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    vector<pair<int, string>> pairs;
    for (int i = 0; i < names.size(); ++i) {
        pairs.push_back({heights[i], names[i]});
    }
    sort(pairs.begin(), pairs.end(), greater<pair<int, string>>());
    vector<string> result;
    for (auto& p : pairs) {
        result.push_back(p.second);
    }
    
    return result;
    }
};