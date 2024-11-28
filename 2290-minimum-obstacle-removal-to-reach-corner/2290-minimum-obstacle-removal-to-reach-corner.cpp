class Solution { 
public: //  code written by sunny
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dq;
        dq.push_front({0, 0});
        dist[0][0] = 0;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int cost = grid[nx][ny];
                    
                    if (dist[x][y] + cost < dist[nx][ny]) {
                        dist[nx][ny] = dist[x][y] + cost;
                        
                        if (cost == 0) {
                            dq.push_front({nx, ny});  
                        } else {
                            dq.push_back({nx, ny});  
                        }
                    }
                }
            }
        }
        
        return dist[m - 1][n - 1];
    }
};