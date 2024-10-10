 class Solution {
public: /// code written by sunny..
    vector<int> topologicalSort(int k, const vector<vector<int>>& conditions) {
    vector<int> inDegree(k + 1, 0);
    unordered_map<int, vector<int>> adjList;
    for (const auto& condition : conditions) {
        int u = condition[0], v = condition[1];
        adjList[u].push_back(v);
        inDegree[v]++;
    }
    
    queue<int> q;
    for (int i = 1; i <= k; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    
    vector<int> order;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        order.push_back(node);
        for (int neighbor : adjList[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    if (order.size() == k) return order;
    return {}; 
}

vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
    vector<int> rowOrder = topologicalSort(k, rowConditions);
    vector<int> colOrder = topologicalSort(k, colConditions);
    
    if (rowOrder.empty() || colOrder.empty()) return {};
    
    unordered_map<int, int> rowIndex, colIndex;
    for (int i = 0; i < k; i++) {
        rowIndex[rowOrder[i]] = i;
        colIndex[colOrder[i]] = i;
    }
    
    vector<vector<int>> matrix(k, vector<int>(k, 0));
    for (int i = 1; i <= k; i++) {
        matrix[rowIndex[i]][colIndex[i]] = i;
    }
    
    return matrix;
}
};