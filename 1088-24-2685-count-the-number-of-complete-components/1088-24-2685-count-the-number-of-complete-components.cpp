// #include <iostream>
// #include <vector>
// #include <unordered_set>

// using namespace std;

class Solution {
public: // code written by sunny
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adj(n);   
        vector<bool> visited(n, false); 
        for (auto& edge : edges) {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }

        int completeCount = 0; 
        function<void(int, vector<int>&)> dfs = [&](int node, vector<int>& component) {
            visited[node] = true;
            component.push_back(node);
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    dfs(neighbor, component);
                }
            }
        }; 
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> component;
                dfs(i, component); 
                int size = component.size();
                int expectedEdges = size * (size - 1) / 2;   
                int edgeCount = 0;
                for (int node : component) {
                    edgeCount += adj[node].size();
                }
                edgeCount /= 2;  
                if (edgeCount == expectedEdges) {
                    completeCount++;
                }
            }
        }

        return completeCount;
    }
};