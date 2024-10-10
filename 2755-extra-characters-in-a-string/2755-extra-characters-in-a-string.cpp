class Solution {
public: // code written by sunny
    int minExtraChar(string s, vector<string>& dictionary) {
    int n = s.size();
    unordered_set<string> dict(dictionary.begin(), dictionary.end());
    vector<int> dp(n + 1, n);  
    dp[0] = 0;   
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dict.count(s.substr(j, i - j))) {
                dp[i] = min(dp[i], dp[j]);   
            }
        }
        dp[i] = min(dp[i], dp[i - 1] + 1);
    }
    
    return dp[n];
    }
};