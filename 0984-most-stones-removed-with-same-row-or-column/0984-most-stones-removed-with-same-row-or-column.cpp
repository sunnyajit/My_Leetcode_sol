class Solution {
public: // code written by sunny
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, vector<int>> row_map;
        unordered_map<int, vector<int>> col_map;
        for (int i = 0; i < stones.size(); ++i) {
            int x = stones[i][0];
            int y = stones[i][1];
            row_map[x].push_back(i);
            col_map[y].push_back(i);
        }
        vector<bool> visited(stones.size(), false);
        function<void(int)> dfs = [&](int idx) {
            stack<int> stk;
            stk.push(idx);
            while (!stk.empty()) {
                int curr = stk.top();
                stk.pop();
                if (visited[curr]) continue;
                visited[curr] = true;
                
                int x = stones[curr][0];
                int y = stones[curr][1];
                for (int neighbor : row_map[x]) {
                    if (!visited[neighbor]) stk.push(neighbor);
                }
                for (int neighbor : col_map[y]) {
                    if (!visited[neighbor]) stk.push(neighbor);
                }
            }
        };
        int removable_stones = 0;
        for (int i = 0; i < stones.size(); ++i) {
            if (!visited[i]) {
                int component_size = 0;
                stack<int> stk;
                stk.push(i);
                while (!stk.empty()) {
                    int curr = stk.top();
                    stk.pop();
                    if (visited[curr]) continue;
                    visited[curr] = true;
                    ++component_size;
                    
                    int x = stones[curr][0];
                    int y = stones[curr][1];
                    
                    for (int neighbor : row_map[x]) {
                        if (!visited[neighbor]) stk.push(neighbor);
                    }
                    for (int neighbor : col_map[y]) {
                        if (!visited[neighbor]) stk.push(neighbor);
                    }
                }
                removable_stones += (component_size - 1);
            }
        }
        
        return removable_stones;
    }
};