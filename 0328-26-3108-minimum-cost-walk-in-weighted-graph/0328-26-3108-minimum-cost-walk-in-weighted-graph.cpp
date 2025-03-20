class Solution {
public: // code written by sunny
    vector<int> parent, comp_min_and;
    int find(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]);   
    }
    
    void unite(int u, int v, int w) {
        int pu = find(u), pv = find(v);
        if (pu != pv) {
            parent[pv] = pu;
            comp_min_and[pu] &= comp_min_and[pv];
        }
        comp_min_and[pu] &= w;
    }
    
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        comp_min_and.resize(n, INT_MAX);
        for (int i = 0; i < n; i++) parent[i] = i; 
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            unite(u, v, w);
        }
        vector<int> result;
        for (auto& q : query) {
            int si = q[0], ti = q[1];
            if (find(si) != find(ti)) result.push_back(-1);
            else result.push_back(comp_min_and[find(si)]);
        }
        
        return result;
    }
};











































































