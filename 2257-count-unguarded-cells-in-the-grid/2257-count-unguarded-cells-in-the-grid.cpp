 class Solution {
public: // code written by sunny
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> grid(m, vector<char>(n, 'U'));  
        for (auto& wall : walls) grid[wall[0]][wall[1]] = 'W';  
        for (auto& guard : guards) grid[guard[0]][guard[1]] = 'G';  
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto& guard : guards) {
            for (auto& dir : directions) {
                int x = guard[0], y = guard[1];
                while (true) {
                    x += dir.first;
                    y += dir.second;
                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 'W' || grid[x][y] == 'G') break;
                    if (grid[x][y] == 'U') grid[x][y] = 'X';  
                }
            }
        }
        int unguardedCount = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'U') unguardedCount++;
            }
        }
        return unguardedCount;
    }
};
