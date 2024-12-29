class Solution {
public: // code written by sunny
    int numWays(vector<string>& words, string target) {
        const int MOD = 1e9 + 7;
        int m = words[0].size(); 
        int n = target.size();   
        vector<vector<int>> frequency(26, vector<int>(m, 0));
        for (const string& word : words) {
            for (int j = 0; j < m; ++j) {
                frequency[word[j] - 'a'][j]++;
            }
        } 
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
        for (int j = 0; j <= m; ++j) {
            dp[0][j] = 1;
        } 
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = dp[i][j - 1]; 
                char targetChar = target[i - 1];
                if (frequency[targetChar - 'a'][j - 1] > 0) {
                    dp[i][j] += dp[i - 1][j - 1] * frequency[targetChar - 'a'][j - 1];
                    dp[i][j] %= MOD;
                }
            }
        }
        
        return dp[n][m];
    }
};