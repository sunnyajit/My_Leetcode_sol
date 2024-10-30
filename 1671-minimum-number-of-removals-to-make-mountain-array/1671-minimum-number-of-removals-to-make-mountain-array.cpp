class Solution {
public: // code written by sunny
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
         vector<int> dp_inc(n, 1);
         vector<int> dp_dec(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp_inc[i] =  max(dp_inc[i], dp_inc[j] + 1);
                }
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (nums[i] > nums[j]) {
                    dp_dec[i] =  max(dp_dec[i], dp_dec[j] + 1);
                }
            }
        }
        int maxMountainLength = 0;
        for (int i = 1; i < n - 1; i++) {
            if (dp_inc[i] > 1 && dp_dec[i] > 1) {
                maxMountainLength = std::max(maxMountainLength, dp_inc[i] + dp_dec[i] - 1);
            }
        }
        return n - maxMountainLength;
    }
};