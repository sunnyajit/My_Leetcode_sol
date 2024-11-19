class Solution {
public:  // code written by sunny
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> windowSet; 
        long long maxSum = 0, currentSum = 0;
        int n = nums.size();
        int start = 0;
        for (int end = 0; end < n; ++end) {
            while (windowSet.count(nums[end])) {
                windowSet.erase(nums[start]);
                currentSum -= nums[start];
                ++start;
            }
                        windowSet.insert(nums[end]);
            currentSum += nums[end];
            if (end - start + 1 == k) {
                maxSum = max(maxSum, currentSum);
                windowSet.erase(nums[start]);
                currentSum -= nums[start];
                ++start;
            }
        }  
        return maxSum;
    }
};

