class Solution {
public: //code written by sunny
    pair<int, int> BFS(unordered_map<int, vector<int>>& graph, int startNode) {
        queue<int> nodeQueue; 
        nodeQueue.push(startNode);
        unordered_map<int, bool> visited; 
        visited[startNode] = true;
        int maxDistance = 0, farthestNode = startNode;

        while (!nodeQueue.empty()) {
            int levelSize = nodeQueue.size();
            while (levelSize--) {
                int currentNode = nodeQueue.front(); 
                nodeQueue.pop();
                farthestNode = currentNode;

                for (int neighbor : graph[currentNode]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        nodeQueue.push(neighbor);
                    }
                }
            }
            if (!nodeQueue.empty()) maxDistance++;
        }
        return {farthestNode, maxDistance};
    }

    int findDiameter(unordered_map<int, vector<int>> graph) { 
        auto [farthestNode, _] = BFS(graph, 0);
        return BFS(graph, farthestNode).second;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& tree1Edges, vector<vector<int>>& tree2Edges) {
        auto buildGraph = [](vector<vector<int>>& edges) {
            unordered_map<int, vector<int>> graph;
            for (auto& edge : edges) {
                graph[edge[0]].push_back(edge[1]);
                graph[edge[1]].push_back(edge[0]);
            }
            return graph;
        };

        int tree1Diameter = findDiameter(buildGraph(tree1Edges));
        int tree2Diameter = findDiameter(buildGraph(tree2Edges));
        int combinedDiameter = (tree1Diameter + 1) / 2 + (tree2Diameter + 1) / 2 + 1;

        return max({tree1Diameter, tree2Diameter, combinedDiameter});
    }
};

