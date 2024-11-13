class Solution {
public: // code written by sunny
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
         sort(nums.begin(), nums.end());
        long long fairPairs = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            int left = std::lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            int right = std::upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();
            fairPairs += right - left;
        }
        return fairPairs;
    }
};