 class Solution {
public: // code written by sunny......
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
    int atMost(vector<int>& nums, int k) {
        int count = 0;
        int left = 0;
        int result = 0;
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] % 2 != 0) {
                count++;
            }
            while (count > k) {
                if (nums[left] % 2 != 0) {
                    count--;
                }
                left++;
            }
            
            result += (right - left + 1);
        }
        
        return result;
    }
};