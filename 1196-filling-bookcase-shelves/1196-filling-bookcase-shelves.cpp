 class Solution {
public: // code written by sunny.
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
    vector<int> dp(n + 1, INT_MAX);   
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int totalWidth = 0;
        int maxHeight = 0;
        for (int j = i - 1; j >= 0; --j) {
            totalWidth += books[j][0];
            if (totalWidth > shelfWidth) break;
            maxHeight = max(maxHeight, books[j][1]);
            dp[i] = min(dp[i], dp[j] + maxHeight);
        }
    }
    return dp[n];
    }
};