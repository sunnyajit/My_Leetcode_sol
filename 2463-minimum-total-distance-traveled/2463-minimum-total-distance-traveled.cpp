class Solution { 
    // code written by sunny
    using ll = long long;                          
    static constexpr ll MAX_DISTANCE = 10000000000000LL; 
    ll calculateMinCost(vector<int>& robots, int robotIndex, vector<int>& factoryPositions, int factoryIndex, vector<vector<ll>>& memo) {
        if (robotIndex < 0) return 0;    
        if (factoryIndex < 0) return MAX_DISTANCE;  
        if (memo[robotIndex][factoryIndex] != -1)
            return memo[robotIndex][factoryIndex];
        ll includeCost = abs(robots[robotIndex] - factoryPositions[factoryIndex])
                         + calculateMinCost(robots, robotIndex - 1, factoryPositions, factoryIndex - 1, memo);
        ll excludeCost = calculateMinCost(robots, robotIndex, factoryPositions, factoryIndex - 1, memo);
        return memo[robotIndex][factoryIndex] = min(includeCost, excludeCost);
    }

public:
    long long minimumTotalDistance(vector<int>& robots, vector<vector<int>>& factories) {
        sort(robots.begin(), robots.end());
        sort(factories.begin(), factories.end());
        vector<int> factoryPositions;
        for (const auto& factory : factories) {
            int position = factory[0];
            int count = factory[1];
            for (int j = 0; j < count; ++j)
                factoryPositions.push_back(position);
        }
        vector<vector<ll>> memo(robots.size(), vector<ll>(factoryPositions.size(), -1));
        return calculateMinCost(robots, robots.size() - 1, factoryPositions, factoryPositions.size() - 1, memo);
    }
};
