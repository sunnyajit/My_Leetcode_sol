class Solution {
public: // code written by sunny
    bool isArraySpecial(vector<int>& nums) {
        if (nums.size() == 1) return true;
        for (int i = 0; i < nums.size() - 1; i++) {
            if ((nums[i] % 2) == (nums[i+1] % 2)) {
                return false;
            }
        }
        
        return true;
    }
};
