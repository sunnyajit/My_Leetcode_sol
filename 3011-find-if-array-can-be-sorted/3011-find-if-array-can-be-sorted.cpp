class Solution {
public: // code written by sunny
    bool canSortArray(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = 0; j < nums.size() - i - 1; j++) {
                if (nums[j] > nums[j + 1] && __builtin_popcount(nums[j]) == __builtin_popcount(nums[j + 1])) {
                    swap(nums[j], nums[j + 1]);
                } else if (nums[j] > nums[j + 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};

