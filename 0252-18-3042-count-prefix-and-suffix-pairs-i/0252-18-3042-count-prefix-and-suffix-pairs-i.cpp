class Solution {
public: // code written by sunny
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (words[i].length() > words[j].length()) continue;
                
                bool isPrefix = true, isSuffix = true;
                int n1 = words[i].length(), n2 = words[j].length();
                
                for (int k = 0; k < n1; k++) {
                    if (words[i][k] != words[j][k]) isPrefix = false;
                    if (words[i][n1 - k - 1] != words[j][n2 - k - 1]) isSuffix = false;
                }
                
                if (isPrefix && isSuffix) ans++;
            }
        }
        
        return ans;
    }
};