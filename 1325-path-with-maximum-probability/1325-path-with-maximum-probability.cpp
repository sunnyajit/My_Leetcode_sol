class Solution {
public: // code written by sunny
typedef pair<double, int> PDI; 
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> adj(n);
    for (int i = 0; i < edges.size(); ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        double prob = succProb[i];
        adj[u].emplace_back(v, prob);
        adj[v].emplace_back(u, prob);
    }
    priority_queue<PDI> pq;
    vector<double> probabilities(n, 0.0);
    probabilities[start] = 1.0;
    pq.push({1.0, start});
    
    while (!pq.empty()) {
        double prob = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (node == end) {
            return prob;
        }
        for (const auto& neighbor : adj[node]) {
            int nextNode = neighbor.first;
            double edgeProb = neighbor.second;
            double newProb = prob * edgeProb;
            if (newProb > probabilities[nextNode]) {
                probabilities[nextNode] = newProb;
                pq.push({newProb, nextNode});
            }
        }
    }
    return 0.0;
    }
};