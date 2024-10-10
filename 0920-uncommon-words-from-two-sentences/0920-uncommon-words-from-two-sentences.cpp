class Solution {
public: // code written by sunny
    vector<string> uncommonFromSentences(string s1, string s2) {
    unordered_map<string, int> wordCount;
    vector<string> result;
    string word;
    stringstream ss(s1 + " " + s2);
    while (ss >> word) {
        wordCount[word]++;
    }
    for (auto& pair : wordCount) {
        if (pair.second == 1) {
            result.push_back(pair.first);
        }
    }

    return result;
    }
};