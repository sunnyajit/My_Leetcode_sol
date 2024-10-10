class Solution {
public: // code written by sunny...
    long long maxPoints(vector<vector<int>>& pts) {
        int a = pts.size(), b = pts[0].size(); 
        vector<vector<long>> dp(a, vector<long>(b, 0)); 
        for (int k = 0; k < b; ++k) dp[0][k] = pts[0][k]; 
        
        for (int i = 1; i < a; ++i) {
            for (int k = b-2; k >= 0; --k) 
                dp[i-1][k] = max(dp[i-1][k], dp[i-1][k+1]-1); 
            
            long prefix = 0; 
            for (int k = 0; k < b; ++k) {
                dp[i][k] = pts[i][k] + max(prefix, dp[i-1][k]); 
                prefix = max(prefix, dp[i-1][k]) - 1; 
            }
        }
        return *max_element(dp[a-1].begin(), dp[a-1].end()); 
    }
};