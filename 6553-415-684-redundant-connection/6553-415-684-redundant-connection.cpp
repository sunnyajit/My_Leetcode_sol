class Solution {
public: // code written by sunny
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        iota(parent.begin(), parent.end(), 0);
        
        function<int(int)> find = [&](int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        };
        
        auto union_sets = [&](int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                parent[rootX] = rootY;
            }
        };
        
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (find(u) == find(v)) {
                return edge;
            } else {
                union_sets(u, v);
            }
        }
        
        return {};
    }
};
