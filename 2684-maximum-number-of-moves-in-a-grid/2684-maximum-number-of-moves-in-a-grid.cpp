class Solution {
public: // code written by sunny
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        auto dfs = [&](int row, int col, auto&& dfs) -> int {
            if (dp[row][col] != -1) {
                return dp[row][col];
            }
            dp[row][col] = 0;
             vector<pair<int, int>> directions = {{-1, 1}, {0, 1}, {1, 1}};
            for (const auto& dir : directions) {
                int newRow = row + dir.first;
                int newCol = col + dir.second;
                if (newRow >= 0 && newRow < m && newCol < n && grid[newRow][newCol] > grid[row][col]) {
                    dp[row][col] =  max(dp[row][col], 1 + dfs(newRow, newCol, dfs));
                }
            }
            return dp[row][col];
        };
        int maxMoves = 0;
        for (int i = 0; i < m; i++) {
            maxMoves =  max(maxMoves, dfs(i, 0, dfs));
        }
        return maxMoves;
    }
};
