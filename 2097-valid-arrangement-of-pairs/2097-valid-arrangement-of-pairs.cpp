class Solution {
public: // code written by sunny
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> indegree, outdegree;  
        for (auto& pair : pairs) {
            int u = pair[0], v = pair[1];
            graph[u].push_back(v);
            outdegree[u]++;
            indegree[v]++;
        }
        int start = pairs[0][0];
        for (auto& [node, _] : graph) {
            if (outdegree[node] > indegree[node]) {
                start = node;
                break;
            }
        }
        
        // Step 3: Hierholzer's algorithm to find the Eulerian path
        stack<int> stk;
        deque<int> path;
        stk.push(start);
        
        while (!stk.empty()) {
            int node = stk.top();
            if (!graph[node].empty()) {
                int next = graph[node].back();
                graph[node].pop_back();
                stk.push(next);
            } else {
                path.push_front(node);
                stk.pop();
            }
        }
        vector<vector<int>> result;
        auto it = path.begin();
        int prev = *it++;
        while (it != path.end()) {
            result.push_back({prev, *it});
            prev = *it++;
        }
        
        return result;
    }
};
