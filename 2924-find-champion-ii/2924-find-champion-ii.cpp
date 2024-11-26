class Solution {
public: // code written by sunny
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> inDegree(n, 0);
        vector<vector<int>> graph(n);  
        for (const auto& edge : edges) {
            int from = edge[0];
            int to = edge[1];
            graph[from].push_back(to);
            inDegree[to]++;
        }
        int champion = -1;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                if (champion != -1) {
                    return -1;
                }
                champion = i;
            }
        }
        if (champion == -1) return -1;
        vector<bool> visited(n, false);
        int visitedCount = 0;
        dfs(champion, graph, visited, visitedCount);
        return (visitedCount == n) ? champion : -1;
    }

private:
    void dfs(int node, const vector<vector<int>>& graph, vector<bool>& visited, int& visitedCount) {
        visited[node] = true;
        visitedCount++;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, graph, visited, visitedCount);
            }
        }
    }
};
