 class Solution {
public:  // code written by sunny
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
    int maxVal = *max_element(nums.begin(), nums.end());
    
    int longest = 0;
    int currentLength = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] == maxVal) {
            currentLength++; 
            longest = max(longest, currentLength);   
        } else {
            currentLength = 0; 
        }
    }
    
    return longest;
    }
};