 class Solution {
public:
    const vector<int> ds = {-1, 0, 1, 0, -1};
    int p, q;
    int minDays(vector<vector<int>>& grid) {
        p = grid.size(), q = grid[0].size();
        if (count(grid) != 1) {
            return 0;
        }
        for (int i = 0; i < p; ++i) {
            for (int j = 0; j < q; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (count(grid) != 1) {
                        return 1;
                    }
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }

    int count(vector<vector<int>>& grid) {
        int cnt = 0;
        for (int i = 0; i < p; ++i) {
            for (int j = 0; j < q; ++j) {
                if (grid[i][j] == 1) {
                    dfs(i, j, grid);
                    ++cnt;
                }
            }
        }
        for (int i = 0; i < p; ++i) {
            for (int j = 0; j < q; ++j) {
                if (grid[i][j] == 2) {
                    grid[i][j] = 1;
                }
            }
        }
        return cnt;
    }

    void dfs(int i, int j, vector<vector<int>>& grid) {
        grid[i][j] = 2;
        for (int k = 0; k < 4; ++k) {
            int x = i + ds[k], y = j + ds[k + 1];
            if (x >= 0 && x < p && y >= 0 && y < q && grid[x][y] == 1) {
                dfs(x, y, grid);
            }
        }
    }
};