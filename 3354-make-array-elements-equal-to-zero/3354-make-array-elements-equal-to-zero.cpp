  class Solution {
public: // code written by sunny
    bool simulate(vector<int> nums, int curr, int direction) {
        int n = nums.size();
        while (curr >= 0 && curr < n) {
            if (nums[curr] == 0) {
                curr += direction;
            } else {
                nums[curr]--;        
                direction *= -1;    
                curr += direction;   
            }
        }
        for (int num : nums) {
            if (num != 0) return false;
        }
        return true;
    }
    
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int validSelections = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                // Try both directions
                if (simulate(nums, i, -1)) validSelections++;
                if (simulate(nums, i, 1)) validSelections++;
            }
        }

        return validSelections;
    }
};
