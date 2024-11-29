





class Solution {
public: // code written by sunny
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    #define P pair<int, pair<int, int>>
    int minimumTime(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;
        
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        vector<vector<int>> minTime(rows, vector<int>(cols, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;
        
        pq.push({grid[0][0], {0, 0}});
        minTime[0][0] = 0;
        
        while (!pq.empty()) {
            int currentTime = pq.top().first;
            int currentRow  = pq.top().second.first;
            int currentCol  = pq.top().second.second;
            pq.pop();
            
            if (currentRow == rows - 1 && currentCol == cols - 1)
                return minTime[rows - 1][cols - 1];
            
            if (visited[currentRow][currentCol]) continue;
            visited[currentRow][currentCol] = true;
            
            for (auto& dir : directions) {
                int newRow = currentRow + dir[0];
                int newCol = currentCol + dir[1];
                
                if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols || visited[newRow][newCol])
                    continue;
                
                if (grid[newRow][newCol] <= currentTime + 1) {
                    pq.push({currentTime + 1, {newRow, newCol}});
                    minTime[newRow][newCol] = currentTime + 1;
                } else if ((grid[newRow][newCol] - currentTime) % 2 == 0) {
                    pq.push({grid[newRow][newCol] + 1, {newRow, newCol}});
                    minTime[newRow][newCol] = grid[newRow][newCol] + 1;
                } else {
                    pq.push({grid[newRow][newCol], {newRow, newCol}});
                    minTime[newRow][newCol] = grid[newRow][newCol];
                }
            }
        }
        
        return -1;
    }
};
