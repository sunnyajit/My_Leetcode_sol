class Solution {
public: // code written by sunny
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;  

        int incr = 1, decr = 1, maxLen = 1;
        
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                incr++;
                decr = 1;
            } else if (nums[i] < nums[i - 1]) {
                decr++;
                incr = 1;
            } else {
                incr = 1;
                decr = 1;
            }
            maxLen = max(maxLen, max(incr, decr));
        }
        
        return maxLen;
    }
};
