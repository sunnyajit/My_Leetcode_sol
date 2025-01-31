class Solution {
public: // code written by sunny
    int n;
    vector<int> dir = {-1, 0, 1, 0, -1};

    int dfs(vector<vector<int>>& grid, int i, int j, int island_id, unordered_map<int, int>& island_sizes) {
        if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != 1) 
            return 0;
        grid[i][j] = island_id;
        int size = 1;
        
        for (int d = 0; d < 4; ++d) {
            size += dfs(grid, i + dir[d], j + dir[d + 1], island_id, island_sizes);
        }
        
        return size;
    }
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        unordered_map<int, int> island_sizes;
        int island_id = 2, max_island = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int size = dfs(grid, i, j, island_id, island_sizes);
                    island_sizes[island_id++] = size;
                    max_island = max(max_island, size);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> unique_islands;
                    int possible_size = 1;

                    for (int d = 0; d < 4; d++) {
                        int ni = i + dir[d], nj = j + dir[d + 1];
                        if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] > 1) {
                            unique_islands.insert(grid[ni][nj]);
                        }
                    }

                    for (int island : unique_islands) {
                        possible_size += island_sizes[island];
                    }

                    max_island = max(max_island, possible_size);
                }
            }
        }

        return max_island;
    }
};
