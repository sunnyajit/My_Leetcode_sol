 class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for (int i = 0; i < k; ++i) {
        // code written by sunny
        int minIndex = 0;
        int minValue = numeric_limits<int>::max();
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] < minValue) {
                minValue = nums[j];
                minIndex = j;
            }
        }
        nums[minIndex] = minValue * multiplier;
    }
    return nums;
    }
};