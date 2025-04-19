class Solution {
public: // code written by sunny
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long count = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int low = lower - nums[i];
            int high = upper - nums[i];

            // Use binary search to find valid range [left, right]
            int left = lower_bound(nums.begin() + i + 1, nums.end(), low) - nums.begin();
            int right = upper_bound(nums.begin() + i + 1, nums.end(), high) - nums.begin();

            count += (right - left);
        }

        return count;
    }
};
