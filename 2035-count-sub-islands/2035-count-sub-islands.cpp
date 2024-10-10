class Solution {
public: // code written by sunny
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        int count = 0;
        auto dfs = [&](int i, int j, auto&& dfs_ref) -> bool {
            if (i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] == 0) {
                return true;
            }
            grid2[i][j] = 0;
            bool isSubIsland = grid1[i][j] == 1;
            isSubIsland &= dfs_ref(i + 1, j, dfs_ref);
            isSubIsland &= dfs_ref(i - 1, j, dfs_ref);
            isSubIsland &= dfs_ref(i, j + 1, dfs_ref);
            isSubIsland &= dfs_ref(i, j - 1, dfs_ref);

            return isSubIsland;
        };
        
        // Iterate over every cell in grid2
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j] == 1) {
                    // If we found a sub-island, increase the count
                    if (dfs(i, j, dfs)) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};