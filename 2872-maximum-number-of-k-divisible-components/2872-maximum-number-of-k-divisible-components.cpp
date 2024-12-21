class Solution {
public: // code written by sunny
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        int components = 0;
        
        function<int(int, int)> dfs = [&](int node, int parent) {
            int sum = values[node];
            for (int neighbor : graph[node]) {
                if (neighbor != parent) {
                    sum += dfs(neighbor, node);
                }
            }
            if (sum % k == 0) {
                components++;
                return 0;
            }
            return sum % k;
        };
        
        dfs(0, -1);
        return components;
    }
};
