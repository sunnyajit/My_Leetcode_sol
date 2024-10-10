class Solution {
public: /// code written by sunny....
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<int>> adj;
        
        for (auto& road : roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }
        
        // Calculate degrees of each city
        vector<int> degrees(n, 0);
        for (auto& [city, neighbors] : adj) {
            degrees[city] = neighbors.size();
        }
        
        // Sort cities by degree in descending order
        vector<int> cities(n);
        iota(cities.begin(), cities.end(), 0); // fill with 0, 1, 2, ..., n-1
        sort(cities.begin(), cities.end(), [&](int a, int b) {
            return degrees[a] > degrees[b];
        });
        
        // Assign values from n downwards
        vector<int> values(n);
        for (int i = 0; i < n; ++i) {
            values[cities[i]] = n - i;
        }
        
        // Calculate total importance
        long totalImportance = 0;
        for (auto& road : roads) {
            totalImportance += values[road[0]] + values[road[1]];
        }
        
        return totalImportance;
    }
};