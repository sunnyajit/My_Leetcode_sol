class Solution {
public: // code written by sunny
    long long gridGame(vector<vector<int>>& grid) {
        long long row1Remaining = accumulate(begin(grid[0]), end(grid[0]), 0LL);
        long long row2Accumulated = 0;
        long long result = LLONG_MAX;

        for (int col = 0; col < grid[0].size(); ++col) {
            row1Remaining -= grid[0][col];
            long long robot2Points = max(row1Remaining, row2Accumulated);
            result = min(result, robot2Points);
            row2Accumulated += grid[1][col];
        }

        return result;
    }
};
