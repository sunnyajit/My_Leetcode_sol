 class Solution {
public: // code written by sunny
    int largestCombination(vector<int>& candidates) {
          int maxCombination = 0;
        for (int bit = 0; bit < 24; ++bit) {
            int count = 0;
            for (int num : candidates) {
                if (num & (1 << bit)) {
                    count++;
                }
            }
            maxCombination = max(maxCombination, count);
        }
        return maxCombination;
    }
};