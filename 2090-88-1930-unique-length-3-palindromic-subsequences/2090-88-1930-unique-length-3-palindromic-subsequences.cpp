class Solution {
public: // code written by sunny
    int countPalindromicSubsequence(string s) {
        vector<int> first(26, -1), last(26, -1);
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (first[s[i] - 'a'] == -1) {
                first[s[i] - 'a'] = i;
            }
            last[s[i] - 'a'] = i;
        }

        int count = 0;

        for (int i = 0; i < 26; i++) {
            if (first[i] != -1 && last[i] > first[i]) {
                unordered_set<char> uniqueChars;
                for (int j = first[i] + 1; j < last[i]; j++) {
                    uniqueChars.insert(s[j]);
                }
                count += uniqueChars.size();
            }
        }

        return count;
    }
};
