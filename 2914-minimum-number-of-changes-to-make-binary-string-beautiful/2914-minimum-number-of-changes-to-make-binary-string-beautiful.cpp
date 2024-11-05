class Solution {
public: // code written by sunny
    int minChanges(string s) {
         int n = s.length();
        int changesToMakeUniformBlocks = 0;
        for (int i = 0; i < n; i += 2) {
            if (s[i] != s[i + 1]) {
                changesToMakeUniformBlocks++;
            }
        }
        return changesToMakeUniformBlocks;
    }
};