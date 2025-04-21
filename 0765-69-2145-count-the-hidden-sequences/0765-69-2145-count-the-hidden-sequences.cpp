class Solution {
public: // code written by sunny
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long prefixSum = 0;
        long long minPrefix = 0;
        long long maxPrefix = 0; 
        for (int diff : differences) {
            prefixSum += diff;
            minPrefix = min(minPrefix, prefixSum);
            maxPrefix = max(maxPrefix, prefixSum);
        } 
        long long startMin = lower - minPrefix;
        long long startMax = upper - maxPrefix; 
        if (startMin > startMax) {
            return 0;
        } else {
            return static_cast<int>(startMax - startMin + 1);
        }
    }
};
