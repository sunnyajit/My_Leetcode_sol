class Solution {
public: //  code written by sunny
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        int totalCells = m * n;
        vector<int> ans(queries.size(), 0); 
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); i++) {
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end()); 
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;
        minHeap.push({grid[0][0], {0, 0}}); 
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;
        int count = 0;  
        int lastQueryValue = 0; 
        vector<int> dirX = {0, 0, 1, -1};
        vector<int> dirY = {1, -1, 0, 0};

        for (auto &[query, idx] : sortedQueries) {
            while (!minHeap.empty() && minHeap.top().first < query) {
                auto [val, pos] = minHeap.top();
                minHeap.pop();

                int x = pos.first, y = pos.second;
                count++;  
                for (int d = 0; d < 4; d++) {
                    int newX = x + dirX[d], newY = y + dirY[d];
                    if (newX >= 0 && newX < m && newY >= 0 && newY < n && !visited[newX][newY]) {
                        visited[newX][newY] = true;
                        minHeap.push({grid[newX][newY], {newX, newY}});
                    }
                }
            }
            ans[idx] = count;
        }

        return ans;
    }
};
