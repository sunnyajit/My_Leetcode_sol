class Solution {
public:// code written by sunny..
    string kthDistinct(vector<string>& arr, int k) {
          unordered_map<string, int> countMap;
    for (const string& s : arr) {
        countMap[s]++;
    }
    vector<string> distinctStrings;
    for (const string& s : arr) {
        if (countMap[s] == 1) {
            distinctStrings.push_back(s);
        }
    }
    if (k > distinctStrings.size()) {
        return "";  
    }
    return distinctStrings[k - 1];  
    }
};