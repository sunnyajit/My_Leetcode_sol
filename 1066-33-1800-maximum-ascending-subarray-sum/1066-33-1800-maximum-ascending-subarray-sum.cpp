 class Solution { 
public: // code written by sunny
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = 0, currentSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                currentSum += nums[i];
            } else {
                maxSum = max(maxSum, currentSum);
                currentSum = nums[i];
            }
        }
        
        return max(maxSum, currentSum);
    }
};
