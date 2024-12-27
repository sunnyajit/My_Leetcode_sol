class Solution {
public: // code written by sunny
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxScore = 0;
        int maxPrefix = values[0]; 
        for (int j = 1; j < values.size(); ++j) {
            maxScore = max(maxScore, maxPrefix + values[j] - j);
            maxPrefix = max(maxPrefix, values[j] + j);
        }
        return maxScore;
    }
};
