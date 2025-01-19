class Solution {
public: // code written by sunny
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        if (m <= 2 || n <= 2) return 0;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }

        int waterTrapped = 0;
        vector<int> dirX = {-1, 1, 0, 0};
        vector<int> dirY = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [height, cell] = pq.top();
            pq.pop();
            int x = cell.first, y = cell.second;

            for (int k = 0; k < 4; ++k) {
                int nx = x + dirX[k], ny = y + dirY[k];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    waterTrapped += max(0, height - heightMap[nx][ny]);
                    pq.push({max(height, heightMap[nx][ny]), {nx, ny}});
                    visited[nx][ny] = true;
                }
            }
        }

        return waterTrapped;
    }
};
