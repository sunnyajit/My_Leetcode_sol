class Solution {
public:// code written by sunny
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for (int i = 0; i < k; ++i) { 
            int minIndex = min_element(nums.begin(), nums.end()) - nums.begin();
            nums[minIndex] *= multiplier;
        }
        return nums;
    }
};
