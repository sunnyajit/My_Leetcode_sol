class Solution {
public: // code written by sunny 
    int getLargestOutlier(vector<int>& nums) {
        long long totalSum = 0;
        unordered_map<int, int> countMap;
        for (int num : nums) {
            totalSum += num;
            countMap[num]++;
        }

        int largestOutlier = INT_MIN;
        for (int num : nums) {
            long long specialSum = num; 
            long long potentialOutlier = totalSum - 2 * specialSum;
            if (countMap.find(potentialOutlier) != countMap.end()) {
                if (potentialOutlier == num && countMap[num] < 2) continue;
                largestOutlier = max(largestOutlier, (int)potentialOutlier);
            }
        }

        return largestOutlier;
    }
};
