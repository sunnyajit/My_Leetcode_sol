class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, pair<int, int>> position;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                position[mat[i][j]] = {i, j};
            }
        }
        
        vector<int> rowPainted(m, 0), colPainted(n, 0);
        
        for (int i = 0; i < arr.size(); ++i) {
            auto [row, col] = position[arr[i]];
            rowPainted[row]++;
            colPainted[col]++;
            
            if (rowPainted[row] == n || colPainted[col] == m) {
                return i;
            }
        }
        
        return -1;
    }
};
