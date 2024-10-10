 class Solution {
public: // code written by sunny...
    const int INF = numeric_limits<int>::max();
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
         vector<vector<int>> dist(n, vector<int>(n, INF));
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }
    
    for (const auto& edge : edges) {
        int from = edge[0];
        int to = edge[1];
        int weight = edge[2];
        dist[from][to] = weight;
        dist[to][from] = weight;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    int resultCity = -1;
    int minReachableCount = n;
    for (int i = 0; i < n; ++i) {
        int reachableCount = 0;
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] <= distanceThreshold) {
                ++reachableCount;
            }
        }
        if (reachableCount < minReachableCount || (reachableCount == minReachableCount && i > resultCity)) {
            minReachableCount = reachableCount;
            resultCity = i;
        }
    }
    return resultCity;
    }
};