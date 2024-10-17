 class Solution {
public: // code written by sunny
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> bannedSet(bannedWords.begin(), bannedWords.end());
    int count = 0;

    for (const string& word : message) {
        if (bannedSet.find(word) != bannedSet.end()) {
            count++;
            if (count >= 2) {
                return true; // If at least two words match, it's spam
            }
        }
    }

    return false; // Less than two m
    }
};