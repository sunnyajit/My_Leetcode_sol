class Solution {
public: // code written by sunny
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);
        
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> color(n + 1, 0);
        vector<bool> visited(n + 1, false);
        int maxGroups = 0;
        
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                vector<int> component;
                queue<int> q;
                q.push(i);
                visited[i] = true;
                component.push_back(i);
                color[i] = 1;
                
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    
                    for (int neighbor : adj[node]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            color[neighbor] = -color[node];
                            q.push(neighbor);
                            component.push_back(neighbor);
                        } else if (color[neighbor] == color[node]) {
                            return -1;
                        }
                    }
                }
                
                int longest = 0;
                for (int node : component) {
                    longest = max(longest, bfsMaxDepth(node, adj));
                }
                maxGroups += longest;
            }
        }
        
        return maxGroups;
    }
    
    int bfsMaxDepth(int start, vector<vector<int>>& adj) {
        queue<int> q;
        unordered_map<int, int> depth;
        q.push(start);
        depth[start] = 1;
        int maxDepth = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : adj[node]) {
                if (!depth.count(neighbor)) {
                    depth[neighbor] = depth[node] + 1;
                    maxDepth = max(maxDepth, depth[neighbor]);
                    q.push(neighbor);
                }
            }
        }
        return maxDepth;
    }
};
